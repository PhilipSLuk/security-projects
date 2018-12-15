# NATAS LEVEL 11

```
http://overthewire.org/wargames/natas/natas11.html
```

```
Username: natas11
Password: U82q5TCMMQ9xuFoI3dYX61s7OZD9JKoK
URL:      http://natas11.natas.labs.overthewire.org
```

<img src='index.jpg' width=500px>

### SOLUTION

#### CODE INSPECTION

```
<?

$defaultdata = array( "showpassword"=>"no", "bgcolor"=>"#ffffff");

function xor_encrypt($in) {
    $key = '<censored>';
    $text = $in;
    $outText = '';

    // Iterate through each character
    for($i=0;$i<strlen($text);$i++) {
    $outText .= $text[$i] ^ $key[$i % strlen($key)];
    }

    return $outText;
}

function loadData($def) {
    global $_COOKIE;
    $mydata = $def;
    if(array_key_exists("data", $_COOKIE)) {
    $tempdata = json_decode(xor_encrypt(base64_decode($_COOKIE["data"])), true);
    if(is_array($tempdata) && array_key_exists("showpassword", $tempdata) && array_key_exists("bgcolor", $tempdata)) {
        if (preg_match('/^#(?:[a-f\d]{6})$/i', $tempdata['bgcolor'])) {
        $mydata['showpassword'] = $tempdata['showpassword'];
        $mydata['bgcolor'] = $tempdata['bgcolor'];
        }
    }
    }
    return $mydata;
}

function saveData($d) {
    setcookie("data", base64_encode(xor_encrypt(json_encode($d))));
}

$data = loadData($defaultdata);

if(array_key_exists("bgcolor",$_REQUEST)) {
    if (preg_match('/^#(?:[a-f\d]{6})$/i', $_REQUEST['bgcolor'])) {
        $data['bgcolor'] = $_REQUEST['bgcolor'];
    }
}

saveData($data);

?>

<h1>natas11</h1>
<div id="content">
<body style="background: <?=$data['bgcolor']?>;">
Cookies are protected with XOR encryption<br/><br/>

<?
if($data["showpassword"] == "yes") {
    print "The password for natas12 is <censored><br>";
}

?>

<form>
Background color: <input name=bgcolor value="<?=$data['bgcolor']?>">
<input type=submit value="Set color">
</form>

<div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

So an inspection of the code seems to yield the following:

- the code expects a cookie in the form of a hash with two keys: `showpassword` and
  `bgcolor`
- upon page load, we have a default value of `showpassword=no` and `bgcolor=#ffffff`
- if the cookie contains a hash value in the expected format, it checks to see if `bgcolor`
  matches on a pattern. if a match, it adopts the value of the cookie value of
  `showpassword` and `bgcolor`
- there is another check if bgcolor from `$_REQUEST` matches the pattern and if so, it
  updates the value it eventually writes to the cookie.
- the cookie is a BASE64 encoded string of an XOR encrypted with an unknown key JSON
- if `$data["showpassword"] = "yes"` then the password is revealed in the HTML

#### XOR ENCRYPTION KEY

One important property to note about XOR is:

```
Orig_Data XOR KEY = Encrypted_Data
Orig_Data XOR Encrypted_Data = KEY
```

So since we know what the default data is from code inspection and we can
observe the default cookie value from running the webapp, we should be able to
determine what the encryption key is.

The default cookie value is `ClVLIh4ASCsCBE8lAxMacFMZV2hdVVotEhhUJQNVAmhSEV4sFxFeaAw`.
From reading the code, that is the base64_encoded string of the xor_encrypted
JSON `{"showpassword":"no","bgcolor":"#ffffff"}`.

Reusing the `xor_encrypt()` function we inspected in the application code, we
can write a little piece of code to calculate the original key:

```
$ cat gen_xor_encode_key.php
<?
 function xor_encrypt($key, $text) {
   $outText = '';
   // Iterate through each character
   for ($i=0; $i < strlen($text); $i++) {
     $outText .= $text[$i] ^ $key[$i % strlen($key)];
   }
   return $outText;
 }

 $defaultdata = json_encode(array( "showpassword"=>"no", "bgcolor"=>"#ffffff"));
 $defaultcookie = "ClVLIh4ASCsCBE8lAxMacFMZV2hdVVotEhhUJQNVAmhSEV4sFxFeaAw";

 // obtain encrypted data
 $encrypteddata = base64_decode($defaultcookie);
 // exploit the fact that: Orig_Data XOR Encrypted_Data = KEY
 $key = xor_encrypt($defaultdata, $encrypteddata);

 print "$key\n"
?>
$ php gen_xor_encode_key.php
qw8Jqw8Jqw8Jqw8Jqw8Jqw8Jqw8Jqw8Jqw8Jqw8Jq
```

From the output, we can guess that `qw8J` is likely our key. With the key, we
can calculate the new cookie value that would correspond to
`{"showpassword":"yes","bgcolor":"#ffffff"}`.

#### MODIFIED COOKIE

```
$ cat gen_modified_cookie_val.php
<?

$defaultdata = array( "showpassword"=>"yes", "bgcolor"=>"#ffffff");

function xor_encrypt($in) {
  $key = 'qw8J';
  $text = $in;
  $outText = '';

  // Iterate through each character
  for ($i=0; $i < strlen($text); $i++) {
    $outText .= $text[$i] ^ $key[$i % strlen($key)];
  }

  return $outText;
}

function loadData($def) {
  $mydata = $def;
  return $mydata;
}

function saveData($d) {
  $json_d = json_encode($d);
  print("saveData(): json_encode(d) $json_d\n");
  $cookie = base64_encode(xor_encrypt(json_encode($d)));
  print "saveData(): $cookie\n";
}

$data = loadData($defaultdata);
saveData($data);

?>
$ php gen_modified_cookie_val.php
saveData(): json_encode(d) {"showpassword":"yes","bgcolor":"#ffffff"}
saveData(): ClVLIh4ASCsCBE8lAxMacFMOXTlTWxooFhRXJh4FGnBTVF4sFxFeLFMK
```

So let's set our cookie to `ClVLIh4ASCsCBE8lAxMacFMOXTlTWxooFhRXJh4FGnBTVF4sFxFeLFMK` and
see what happens..

```
$ curl 'http://natas11.natas.labs.overthewire.org/?bgcolor=%23ffffff' -H 'Authorization: Basic bmF0YXMxMTpVODJxNVRDTU1ROXh1Rm9JM2RZWDYxczdPWkQ5SktvSw==' -H 'Cookie: data=ClVLIh4ASCsCBE8lAxMacFMOXTlTWxooFhRXJh4FGnBTVF4sFxFeLFMK' --compressed
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas11", "pass": "U82q5TCMMQ9xuFoI3dYX61s7OZD9JKoK" };</script></head>

<h1>natas11</h1>
<div id="content">
<body style="background: #ffffff;">
Cookies are protected with XOR encryption<br/><br/>

The password for natas12 is EDXp0pS26wLKHZy1rDBPUZk0RKfLGIR3<br>
<form>
Background color: <input name=bgcolor value="#ffffff">
<input type=submit value="Set color">
</form>

<div id="viewsource"><a href="index-source.html">View sourcecode</a></div>
</div>
</body>
</html>
```

<img src='index_solved.jpg' width=500px>

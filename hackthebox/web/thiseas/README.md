# WEB CHALLENGE: THISEAS

## Challenge Description
We believe a certain individual uses this website for shady business. Can you find out
who that is and send him an email to check, using the web site's functionality?
Note: The flag is not an e-mail address. 

```
host: 88.198.233.174 port:41124
```

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/web/thiseas/login.jpg" width=500px/>

### BURPSUITE

Let's see what does burpsuite tell us..

```
<REQUEST>
GET / HTTP/1.1
Host: 88.198.233.174:41124
User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:52.0) Gecko/20100101 Firefox/52.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
Connection: close
Upgrade-Insecure-Requests: 1
</REQUEST>
```

```
<RESPONSE>
HTTP/1.1 200 OK
Date: Mon, 25 Dec 2017 21:57:36 GMT
Server: Apache/2.4.18 (Ubuntu)
Vary: Accept-Encoding
Content-Length: 2053
Connection: close
Content-Type: text/html; charset=UTF-8
<html>
<head>
<meta http-equiv="Content-Language" content="en-us">
<meta name="GENERATOR" content="Microsoft GiveMeA_Break 12.0">
<meta name="ProgId" content="UnfrontPage.Editor.Document :)">
<meta http-equiv="Content-Type" content="text/html;">
<title>HDC</title>
<style type="text/css">
.style2 {
	font-size: xx-large;
	color: #0000FF;
}
.style3 {
	color: #808000;
}
</style>
<script src="jquery-3.2.1.js"></script>
<script src="myscripts.js"></script>
</head>

<body >
<table border="1" cellpadding="0" cellspacing="0" style="border-collapse: collapse" bordercolor="#111111" width="101%" id="AutoNumber1" height="104">
  <tr>
    <td width="85%" height="104">
      <div style="background-color: #C0C0C0">
      <p align="center"><img border="0" src="logo2.gif" width="26" height="25"><span lang="us" class="style2">HADES DISTRIBUTION COMPANY</span><img border="0" src="logo2.gif" width="26" height="25"><b><font size="7" color="#0000FF"><span lang="us"><br>
      </span></font></b><span lang="us"><font size="2" color="#FF0000">We are the first company since 1990 to provide people distribution over the </font></span><font size="2" color="#FF0000"> Internet</font></div>
    </td>
  </tr>
</table>
<p><i><span class="style3"><span lang="us"></span></span><b><font color="#808000"> </font>&nbsp;<font color="#FFFFFF"><span lang="us">&nbsp;</span></font></b></i></p>
<form id='formaki' name='formaki' action="./main/index.php" method="post">
  <p align="center">Enter Username / Password
    <input type="text" name="name1" size="20">
    <input type="text" Name="name2" size="20">
  </p>
  <p align="center">
    <input type="hidden" value= name="name1">
    <input type="hidden" value= name="name2">
    <input type="button" value="Submit" onclick="doProcess()"/>
  </p>
</form>

<p align="left"><b><span lang="us"><i>Enter your credentials and press [Submit] to access the company's Control Panel</i></span><i><span lang="us">.</span></i></b></p>
<p align="left">&nbsp;</p>
</body>
</html>
</RESPONSE>
```

So we learn there is a `myscripts.js` that gets loaded and a `main/index.php`
that gets called upon form submit.

```
http://88.198.233.174:41124/myscripts.js

function doProcess()
{
	document.forms["formaki"].submit();
}
```

Feeding the form `testuser` and `testpasswd` just to see what the behaviour is.

```
<REQUEST>
POST /main/index.php HTTP/1.1
Host: 88.198.233.174:41124
User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:52.0) Gecko/20100101 Firefox/52.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
Referer: http://88.198.233.174:41124/
Connection: close
Upgrade-Insecure-Requests: 1
Content-Type: application/x-www-form-urlencoded
Content-Length: 33
name1=testuser&name2=testpassword
</REQUEST>
```

We see that our username is passed along as `name1` and password is `name2`.

```
<RESPONSE>
HTTP/1.1 200 OK
Date: Mon, 25 Dec 2017 22:06:40 GMT
Server: Apache/2.4.18 (Ubuntu)
Vary: Accept-Encoding
Content-Length: 501
Connection: close
Content-Type: text/html; charset=UTF-8
<head>
<meta http-equiv="Content-Language" content="en-us">
<meta name="GENERATOR" content="Microsoft FrontPage 12.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<meta http-equiv="Content-Type" content="text/html; charset=windows-1253">
<title>Challennge 001</title>
<style type="text/css">
.style2 {
	font-size: xx-large;
	color: #0000FF;
}
.style3 {
	color: #808000;
}
</style>
</head>
<html>
<h1>Wrong Credentials baby!</h1>
<h3>Try harder...</h3>
</html>
</RESPONSE>
```

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/web/thiseas/login-failed.jpg" width=500px/>

### NMAP

Unlikely we'll need this, but out of curiousity.. let's see what services
are running..

```
$ sudo nmap -A -sS -T4 88.198.233.174 > nmap.out
```

```
Starting Nmap 7.60 ( https://nmap.org ) at 2017-12-25 17:27 EST
Nmap scan report for docker.hackthebox.eu (88.198.233.174)
Host is up (0.0087s latency).
Not shown: 961 filtered ports, 36 closed ports
PORT    STATE SERVICE     VERSION
53/tcp  open  domain      dnsmasq 2.45
| dns-nsid: 
|_  bind.version: dnsmasq-2.45
139/tcp open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: HIRON)
445/tcp open  netbios-ssn Samba smbd 3.0.37 (workgroup: HIRON)
Device type: general purpose|bridge|switch
Running (JUST GUESSING): QEMU (98%), Oracle Virtualbox (96%), Bay Networks embedded (88%)
OS CPE: cpe:/a:qemu:qemu cpe:/o:oracle:virtualbox cpe:/h:baynetworks:baystack_450
Aggressive OS guesses: QEMU user mode network gateway (98%), Oracle Virtualbox (96%), Bay Networks BayStack 450 switch (software version 3.1.0.22) (88%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 2 hops
```

Hm.. based on the challenge, doesn't seem like we should be attacking the
netbios-ssn services running on port 139 or 445.

### DIRBUSTER

Also unlikely we'll need this, but let's enumerate the webserver just to see
what we have..

```
$ dirb http://88.198.233.174:41124 /usr/share/wordlists/dirb/small.txt -x /usr/share/wordlists/dirb/extensions_common.txt
```

```
-----------------
DIRB v2.22    
By The Dark Raver
-----------------

START_TIME: Mon Dec 25 17:34:35 2017
URL_BASE: http://88.198.233.174:41124/
WORDLIST_FILES: /usr/share/wordlists/dirb/small.txt
EXTENSIONS_FILE: /usr/share/wordlists/dirb/extensions_common.txt | ()(.asp)(.aspx)(.bat)(.c)(.cfm)(.cgi)(.com)(.dll)(.exe)(.htm)(.html)(.inc)(.jhtml)(.jsa)(.jsp)(.log)(.mdb)(.nsf)(.php)(.phtml)(.pl)(.reg)(.sh)(.shtml)(.sql)(.txt)(.xml)(/) [NUM = 29]

-----------------

GENERATED WORDS: 959                                                           

---- Scanning URL: http://88.198.233.174:41124/ ----
+ http://88.198.233.174:41124/icons/ (CODE:403|SIZE:298)                       
+ http://88.198.233.174:41124/index.php (CODE:200|SIZE:2053)                   
==> DIRECTORY: http://88.198.233.174:41124/main/                               
+ http://88.198.233.174:41124/main/ (CODE:200|SIZE:501)                        
                                                                               
---- Entering directory: http://88.198.233.174:41124/main/ ----
-----------------
END_TIME: Mon Dec 25 19:44:07 2017
DOWNLOADED: 36621 - FOUND: 3

```

Nothing we didn't already know.

### SQLMAP

```
sqlmap -u http://88.198.233.174:411245/ --forms --batch --crawl=10 --level 5 --risk 3
```

```
       ___
       __H__
 ___ ___[']_____ ___ ___  {1.1.11#stable}
|_ -| . [.]     | .'| . |
|___|_  [,]_|_|_|__,|  _|
      |_|V          |_|   http://sqlmap.org

[!] legal disclaimer: Usage of sqlmap for attacking targets without prior mutual consent is illegal. It is the end user's responsibility to obey all applicable local, state and federal laws. Developers assume no liability and are not responsible for any misuse or damage caused by this program

[*] starting at 20:33:07

do you want to check for the existence of site's sitemap(.xml) [y/N] N

<...>

[20:21:50] [INFO] POST parameter 'name2' appears to be 'SAP MaxDB OR time-based blind (heavy query)' injectable 
```

Didn't find anything for us..

### HYDRA

Let's give `hydra` brute force attack a go and see if we find anything..

```
$ hydra 88.198.233.174 -s 41124 http-form-post "/main/index.php:name1=^USER^&name2=^PASS^:Wrong Credentials baby" -l /usr/share/wordlists/dirb/common.txt -P /usr/share/wordlists/rockyou.txt
```

Took too long and got impatient and gave up..

### JQUERY

I took a closer look at the login page with an eye on `jquery-3.2.1.js`. Looking
at `myscripts.js` we saw a `doProcess()` function and automatically assumed we
were calling that function. However, downloading the actual jquery-3.2.1.js
file from `https://code.jquery.com/jquery-3.2.1.js` and comparing it to the one
this particular site is using leads us to find another function called
`doProcess()` defined in it!!! (and since jquery is pulled in before myscripts,
this would be the actual function used...).. note there also seems to be some
random code from some sort of "bidding" or auction site thrown in there to
confuse and obfuscate.

```
function doProcess() {
  var form=document.createElement("form");
  form.setAttribute("method","post");
  form.setAttribute("action","main/index.php");
  form.setAttribute("target","view");
  var hiddenField=document.createElement("input");
  hiddenField.setAttribute("type","hidden");
  hiddenField.setAttribute("name","name1");
  hiddenField.setAttribute("value","TXlMaXR0bGU");
  var hiddenField2=document.createElement("input");
  hiddenField2.setAttribute("type","hidden");
  hiddenField2.setAttribute("name","name2");
  hiddenField2.setAttribute("value","cDB3bmll");
  form.appendChild(hiddenField2);
  form.appendChild(hiddenField);
  form.appendChild(hiddenField2);
  document.body.appendChild(form);
  window.open('','view');
  form.submit();
}
```

Using the values we find in this function for `name1` and `name2`, we are able
to login successfully! (no wonder my dictionary attack never worked..)

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/web/thiseas/login-success.jpg" width=500px/>

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/web/thiseas/console.jpg" width=500px/>

### MAILS.PHP

Now that we are logged in, if we examine the landing page.. we see that we have
a `VBanner.php` and a `main.htm`. Looking more closely at `VBanner.php`, we find
more options to explore..

```
  <ul type="square">
    <li><span lang="us" class="style3"><a href="Diaxirisths.php">Send EMail</a></span></li>
    <li><a href="mails.php"><span lang="en-us" class="style3">Mailbox of </span>
	<span class="style3">Special Customers</span><font size="2"><span lang="us"> </span></font></a></li>
  </ul>
```

Looking at `mails.php`, we get:

```
<html>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1253">
<meta http-equiv="Content-Language" content="us">
<meta name="ProgId" content="FrontPage.Editor.Document">

<font size="6"><span lang="en-us">Special Customers' Mailbox</font><b><font size="6">&nbsp;&nbsp;&nbsp; </font></b><body>
<img border="1" src="./secret_area_/mails.gif" width="21" height="20"></body><hr><p><body>
</p>
<p>Up to now we have 5 special customers who will help us to achieve our goals.<br>
<br>
This list will soon be expanded with the new 'expansion program' for our corporate goals.<br>
<br>
It is planned that within the next six months we will have reached 20 dedicated Special Customers.<br>
</p>
<p><span lang="us"><a href="main.htm">���������</a></span></p>
</body>
</html>
```

So what's up with those characters in the hotlink to `main.html`?

```
$xxd mails.php

000002b0: 5370 6563 6961 6c20 4375 7374 6f6d 6572  Special Customer
000002c0: 732e 3c62 723e 0d0a 3c2f 703e 0d0a 3c70  s.<br>..</p>..<p
000002d0: 3e3c 7370 616e 206c 616e 673d 2275 7322  ><span lang="us"
000002e0: 3e3c 6120 6872 6566 3d22 6d61 696e 2e68  ><a href="main.h
000002f0: 746d 223e c5f0 e9f3 f4f1 eff6 de3c 2f61  tm">.........</a
00000300: 3e3c 2f73 7061 6e3e 3c2f 703e 0d0a 3c2f  ></span></p>..</
00000310: 626f 6479 3e0d 0a0d 0a3c 2f68 746d 6c3e  body>....</html>
```

The HEX code we for those special characters are:

```
c5f0 e9f3 f4f1 eff6 de
```

Since this appears to be a Greek-themed website, we feed this into the
HEX-to-Greek-ASCII conversion to get:

```
https://www.ascii-codes.com/cp869.html

Box drawings light vertical and horizontal
Soft hyphen
Greek lower case omicron
Greek lower case phi
Greek lower case chi
Plus-minus sign
Box drawings light vertical and left
Greek lower case psi
Degree sign
```

None of which means anything to me. So let's go back to `mails.php` and we
notice..

```
<img border="1" src="./secret_area_/mails.gif" width="21" height="20">
```

So there is a folder called `.secret_area_`??? Diving into that folder we find
two files, `mails.gif` and `mails.txt`.

```
http://88.198.233.174:41149/main/secret_area_/mails.txt

All good boys are here... hehehehehehe!
----------------------------------------
Peter Punk CallMePink@newmail.com
Nabuchodonosor BabyNavou@mailpost.gr
Ilias Magkakos imagkakos@badmail.com
Nick Pipshow NickTheGreek@mail.tr.gr
Don Quixote Windmill@mail.gr 
Crazy Priest SeVaftise@hotmail.com
Fishroe Salad fishroesalad@mail.com
TaPanta Ola OlaMaziLeme@mail.gr
Laertis George I8aki@mail.gr
Thiseas Sparrow Pirates@mail.gr
Black Dreamer SupaHacka@mail.com
Callme Daddy FuckthemALL@mail.com
Aggeliki Lykolouli FwsStoTounel@Traino.pourxetai
Kompinadoros Yannnnis YannisWith4N@rolf.com
Serafino Titamola Ombrax@mail.gr
Joe Hard Soft@Butter.gr
Bond James MyNameIsBond@JamesBond.com
Endof Text EndOfLine@mail.com
```

Going through the list and trying each email one-by-one in the "Send EMail"
form from the console, eventually we find that `fishroesalad@mail.com` is
the magic email we are looking for as it yields:

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/web/thiseas/email.jpg" width=500px/>

```
HTB{FuckTheB3stAndPlayWithTheRest!!}
```

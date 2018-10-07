# MACHINE CHALLENGE: CANAPE

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
IP Address: 10.10.10.70
OS: Linux
```

### PORTSCANNING w/ NMAP

As always, we start with a `nmap` portscan..

```
nmap -p0-10000 -n -sS -T4 10.10.10.70 -A
[sudo] password for fortyfunbobby:
Starting Nmap 7.70 ( https://nmap.org ) at 2018-09-12 17:35 EDT
Nmap scan report for 10.10.10.70
Host is up (0.55s latency).
Not shown: 10000 filtered ports
PORT   STATE SERVICE VERSION
80/tcp open  http    Apache httpd 2.4.18 ((Ubuntu))
| http-git:
|   10.10.10.70:80/.git/
|     Git repository found!
|     Repository description: Unnamed repository; edit this file 'description' to name the...
|     Last commit message: final # Please enter the commit message for your changes. Li...
|     Remotes:
|_      http://git.canape.htb/simpsons.git
|_http-server-header: Apache/2.4.18 (Ubuntu)
|_http-title: Simpsons Fan Site
|_http-trane-info: Problem with XML parsing of /evox/about
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Aggressive OS guesses: Linux 3.10 - 4.11 (92%), Linux 3.12 (92%), Linux 3.13 (92%), Linux 3.13 or 4.2 (92%), Linux 3.16 - 4.6 (92%), Linux 3.2 - 4.9 (92%), Linux 3.8 - 3.11 (92%), Linux 4.2 (92%), Linux 4.4 (92%), Linux 4.8 (92%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 2 hops

TRACEROUTE (using port 80/tcp)
HOP RTT       ADDRESS
1   659.23 ms 10.10.16.1
2   659.35 ms 10.10.10.70

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 98.93 seconds
```

So we have port 80 opened (HTTP), but what is particularly interesting is that we've
appeared to discover a GIT repo there.

One thing to note is that `canape` in French translates to `couch` in English.

### ENUMERATE

Manually browsing through the site, we see three pages: 1. home 2. a display page 3.
a submit page.

<img src="browser-index.jpg" width=500px>
<img src="browser-quotes.jpg" width=500px>
<img src="browser-submit.jpg" width=500px>

Attempting to `gobuster` didn't seem to work..

```
$ gobuster -e -u 10.10.10.70 -w /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt

=====================================================
Gobuster v2.0.0              OJ Reeves (@TheColonial)
=====================================================
[+] Mode         : dir
[+] Url/Domain   : http://10.10.10.70/
[+] Threads      : 10
[+] Wordlist     : /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt
[+] Status codes : 200,204,301,302,307,403
[+] Expanded     : true
[+] Timeout      : 10s
=====================================================
2018/09/10 23:43:23 Starting gobuster
=====================================================
2018/09/10 23:43:26 [-] Wildcard response found: http://10.10.10.70/7337eca9-2e89-41e5-a58e-f32d482d5886 => 200
2018/09/10 23:43:26 [!] To force processing of Wildcard responses, specify the '-fw' switch.
=====================================================
2018/09/10 23:43:26 Finished
=====================================================
```

On the home page, we make a note that the "View Quotes" page is advertised as a
"CouchDB-powered quotes database" and ties into the theme of the name of the box.
Could it be we are looking at a `couchdb` type of vulnerability?

```
msf > search couchdb
[!] Module database cache not built yet, using slow search

Matching Modules
================

   Name                                        Disclosure Date  Rank       Description
   ----                                        ---------------  ----       -----------
   auxiliary/scanner/couchdb/couchdb_enum                       normal     CouchDB Enum Utility
   auxiliary/scanner/couchdb/couchdb_login                      normal     CouchDB Login Utility
   exploit/linux/http/apache_couchdb_cmd_exec  2016-04-06       excellent  Apache CouchDB Arbitrary Command Execution
msf > use auxiliary/scanner/couchdb/couchdb_enum
```

### GIT

Let's investigate that GIT repository a bit further. Found a set of scripts that can
help us enumerate the `git` repository (`https://github.com/internetwache/GitTools`)

```
$ python3 gitfinder.py -i git-domains.txt

###########
# Finder is part of https://github.com/internetwache/GitTools
#
# Developed and maintained by @gehaxelt from @internetwache
#
# Use at your own risk. Usage might be illegal in certain circumstances.
# Only for educational purposes!
###########

Scanning...
[*] Found: 10.10.10.70
Finished
```

Just playing around with the first script. It confirms what we already know - that
`canape` has a publicly accessible `.git` repository.

Now let's use the "dumper" tool to try and download as much as we can from the `.git`
repository..

```
$ ../../scripts/enum-tools/gittools/Dumper/gitdumper.sh http://10.10.10.70/.git/ git-extract
###########
# GitDumper is part of https://github.com/internetwache/GitTools
#
# Developed and maintained by @gehaxelt from @internetwache
#
# Use at your own risk. Usage might be illegal in certain circumstances.
# Only for educational purposes!
###########

[*] Destination folder does not exist
[+] Creating git-extract/.git/
[+] Downloaded: HEAD
[-] Downloaded: objects/info/packs
[+] Downloaded: description
[+] Downloaded: config
[+] Downloaded: COMMIT_EDITMSG
[+] Downloaded: index
[-] Downloaded: packed-refs
[+] Downloaded: refs/heads/master
[-] Downloaded: refs/remotes/origin/HEAD

<...>

[+] Downloaded: objects/8f/f4a29c06d1548800ab1d5a2a3cdca0c2d5a775
[+] Downloaded: objects/70/9903c653c0d38384f7ca0a5718153f18ec2b34
[+] Downloaded: objects/3e/f8376074e55faaaa9c7b13907f006f90041a75
[+] Downloaded: objects/b0/aa5f89568b2b0753f873a7c59ca2b784c2e600
[+] Downloaded: objects/a7/3c17a0f0709cf6771324811a8a1b60d82b9e36
```

And finally, now that we have pulled down the `.git` repo, we try the "extractor"
script to recover the `.git` commits and their contents..

```
extractor.sh git-extract git-dump
```

```
$ ../../scripts/enum-tools/gittools/Extractor/extractor.sh git-extract git-dump
###########
# Extractor is part of https://github.com/internetwache/GitTools
#
# Developed and maintained by @gehaxelt from @internetwache
#
# Use at your own risk. Usage might be illegal in certain circumstances.
# Only for educational purposes!
###########
[*] Destination folder does not exist
[*] Creating...
[+] Found commit: 92eb5eb61f16b7b89be0a7ac0a6c2455d377bb41
[+] Found file: /home/fortyfunbobby/hackthebox/machines/canape/git-dump/0-92eb5eb61f16b7b89be0a7ac0a6c2455d377bb41/__init__.py

<...>

[+] Found file: /home/fortyfunbobby/hackthebox/machines/canape/git-dump/12-e7bfbcf62cb61ca9f679d5fbfc82a491f580fccd/templates/index.html
[+] Found file: /home/fortyfunbobby/hackthebox/machines/canape/git-dump/12-e7bfbcf62cb61ca9f679d5fbfc82a491f580fccd/templates/layout.html
[+] Found file: /home/fortyfunbobby/hackthebox/machines/canape/git-dump/12-e7bfbcf62cb61ca9f679d5fbfc82a491f580fccd/templates/quotes.html
[+] Found file: /home/fortyfunbobby/hackthebox/machines/canape/git-dump/12-e7bfbcf62cb61ca9f679d5fbfc82a491f580fccd/templates/submit.html
```

### NMAP REVISITED

After chasing the `couchdb` and `git` lead and getting frustrated, decided to run a
full `nmap` scan and look what we found hidden all the way at the end of the port
range.. `ssh`~

```
$ sudo nmap -p65535 -n -sS -T4 10.10.10.70 -A
Starting Nmap 7.70 ( https://nmap.org ) at 2018-09-16 01:28 EDT
Nmap scan report for 10.10.10.70
Host is up (0.70s latency).

PORT      STATE SERVICE VERSION
65535/tcp open  ssh     OpenSSH 7.2p2 Ubuntu 4ubuntu2.4 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   2048 8d:82:0b:31:90:e4:c8:85:b2:53:8b:a1:7c:3b:65:e1 (RSA)
|   256 22:fc:6e:c3:55:00:85:0f:24:bf:f5:79:6c:92:8b:68 (ECDSA)
|_  256 0d:91:27:51:80:5e:2b:a3:81:0d:e9:d8:5c:9b:77:35 (ED25519)
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Aggressive OS guesses: Linux 3.2 - 4.9 (92%), Crestron XPanel control system (90%), Linux 3.13 (89%), Linux 3.16 (89%), ASUS RT-N56U WAP (Linux 3.4) (87%), Linux 3.1 (87%), Linux 3.2 (87%), HP P2000 G3 NAS device (87%), AXIS 210A or 211 Network Camera (Linux 2.6.17) (87%), Android 4.1.1 (86%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 2 hops
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

TRACEROUTE (using port 65535/tcp)
HOP RTT       ADDRESS
1   715.93 ms 10.10.16.1
2   715.99 ms 10.10.10.70

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 31.13 seconds
```

### RETIRED

So the machine was retired before I could make any further progress, but I assume
the next steps would have been to analyze the webapp source code we had just
pulled and likely that would have allowed us to find some way to get a foothold
into the machine (probably something to do with couchdb).

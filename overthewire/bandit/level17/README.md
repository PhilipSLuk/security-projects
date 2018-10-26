# BANDIT LEVEL 16 --> LEVEL 17

```
http://overthewire.org/wargames/bandit/bandit17.html
```

### Level Goal

The credentials for the next level can be retrieved by submitting the password of the current
level to a port on localhost in the range 31000 to 32000. First find out which of these ports
have a server listening on them. Then find out which of those speak SSL and which don’t.
There is only 1 server that will give the next credentials, the others will simply send back
to you whatever you send to it.

### Commands you may need to solve this level

```
ssh, telnet, nc, openssl, s_client, nmap
```

### Helpful Reading Material

- Port scanner on Wikipedia

### SOLUTION

Let's start off by grabbing the password we need..

```
bandit16@bandit:~$ cat /etc/bandit_pass/bandit16
cluFn7wTiGryunymYOu4RcffSxQluehd
```

.. and what is running in the range of ports `31000` to `32000`?

```
bandit16@bandit:~$ nmap -p 31000-32000 --open localhost

Starting Nmap 7.40 ( https://nmap.org ) at 2018-10-20 16:40 CEST
Nmap scan report for localhost (127.0.0.1)
Host is up (0.00023s latency).
Not shown: 999 closed ports
Some closed ports may be reported as filtered due to --defeat-rst-ratelimit
PORT      STATE SERVICE
31518/tcp open  unknown
31790/tcp open  unknown

Nmap done: 1 IP address (1 host up) scanned in 0.08 seconds
```

Two ports (`31518` and `31790`).. let's connect to each and see what they say..

```
bandit16@bandit:~$ openssl s_client -connect localhost:31518
CONNECTED(00000003)
depth=0 CN = localhost
verify error:num=18:self signed certificate
verify return:1
depth=0 CN = localhost
verify return:1

<...>

    Start Time: 1540046482
    Timeout   : 7200 (sec)
    Verify return code: 18 (self signed certificate)
    Extended master secret: yes
---
hi
hi
bye
bye
```

Okay.. port `31518` seems to be the port that just echos back our input.

```
bandit16@bandit:~$ openssl s_client -connect localhost:31790
CONNECTED(00000003)
depth=0 CN = localhost
verify error:num=18:self signed certificate
verify return:1
depth=0 CN = localhost
verify return:1

<...>

    Start Time: 1540046584
    Timeout   : 7200 (sec)
    Verify return code: 18 (self signed certificate)
    Extended master secret: yes
---
hi
Wrong! Please enter the correct current password
closed
```

Bingo.. this is the port we need. Let's try that again with the correct input instead.

```
bandit16@bandit:~$ openssl s_client -connect localhost:31790
CONNECTED(00000003)
depth=0 CN = localhost
verify error:num=18:self signed certificate
verify return:1
depth=0 CN = localhost
verify return:1

<...>

    Start Time: 1540046644
    Timeout   : 7200 (sec)
    Verify return code: 18 (self signed certificate)
    Extended master secret: yes
---
cluFn7wTiGryunymYOu4RcffSxQluehd
Correct!
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEAvmOkuifmMg6HL2YPIOjon6iWfbp7c3jx34YkYWqUH57SUdyJ
imZzeyGC0gtZPGujUSxiJSWI/oTqexh+cAMTSMlOJf7+BrJObArnxd9Y7YT2bRPQ
Ja6Lzb558YW3FZl87ORiO+rW4LCDCNd2lUvLE/GL2GWyuKN0K5iCd5TbtJzEkQTu
DSt2mcNn4rhAL+JFr56o4T6z8WWAW18BR6yGrMq7Q/kALHYW3OekePQAzL0VUYbW
JGTi65CxbCnzc/w4+mqQyvmzpWtMAzJTzAzQxNbkR2MBGySxDLrjg0LWN6sK7wNX
x0YVztz/zbIkPjfkU1jHS+9EbVNj+D1XFOJuaQIDAQABAoIBABagpxpM1aoLWfvD
KHcj10nqcoBc4oE11aFYQwik7xfW+24pRNuDE6SFthOar69jp5RlLwD1NhPx3iBl
J9nOM8OJ0VToum43UOS8YxF8WwhXriYGnc1sskbwpXOUDc9uX4+UESzH22P29ovd
d8WErY0gPxun8pbJLmxkAtWNhpMvfe0050vk9TL5wqbu9AlbssgTcCXkMQnPw9nC
YNN6DDP2lbcBrvgT9YCNL6C+ZKufD52yOQ9qOkwFTEQpjtF4uNtJom+asvlpmS8A
vLY9r60wYSvmZhNqBUrj7lyCtXMIu1kkd4w7F77k+DjHoAXyxcUp1DGL51sOmama
+TOWWgECgYEA8JtPxP0GRJ+IQkX262jM3dEIkza8ky5moIwUqYdsx0NxHgRRhORT
8c8hAuRBb2G82so8vUHk/fur85OEfc9TncnCY2crpoqsghifKLxrLgtT+qDpfZnx
SatLdt8GfQ85yA7hnWWJ2MxF3NaeSDm75Lsm+tBbAiyc9P2jGRNtMSkCgYEAypHd
HCctNi/FwjulhttFx/rHYKhLidZDFYeiE/v45bN4yFm8x7R/b0iE7KaszX+Exdvt
SghaTdcG0Knyw1bpJVyusavPzpaJMjdJ6tcFhVAbAjm7enCIvGCSx+X3l5SiWg0A
R57hJglezIiVjv3aGwHwvlZvtszK6zV6oXFAu0ECgYAbjo46T4hyP5tJi93V5HDi
Ttiek7xRVxUl+iU7rWkGAXFpMLFteQEsRr7PJ/lemmEY5eTDAFMLy9FL2m9oQWCg
R8VdwSk8r9FGLS+9aKcV5PI/WEKlwgXinB3OhYimtiG2Cg5JCqIZFHxD6MjEGOiu
L8ktHMPvodBwNsSBULpG0QKBgBAplTfC1HOnWiMGOU3KPwYWt0O6CdTkmJOmL8Ni
blh9elyZ9FsGxsgtRBXRsqXuz7wtsQAgLHxbdLq/ZJQ7YfzOKU4ZxEnabvXnvWkU
YOdjHdSOoKvDQNWu6ucyLRAWFuISeXw9a/9p7ftpxm0TSgyvmfLF2MIAEwyzRqaM
77pBAoGAMmjmIJdjp+Ez8duyn3ieo36yrttF5NSsJLAbxFpdlc1gvtGCWW+9Cq0b
dxviW8+TFVEBl1O4f7HVm6EpTscdDxU+bCXWkfjuRb7Dy9GOtt9JPsX8MBTakzh3
vBgsyi/sN3RqRBcGU40fOoZyfAMT8s1m/uYv52O6IgeuZ/ujbjY=
-----END RSA PRIVATE KEY-----

closed
```

Now let's use the private key we just received to advance to the next level.

```
$ ls -l sshkey.private
-rw-r--r--  1 u6065044  staff  1675 20 Oct 10:46 sshkey.private
$ chmod go-r sshkey.private
$ ls -l sshkey.private
-rw-------  1 u6065044  staff  1675 20 Oct 10:46 sshkey.private
$ cat script.sh
#! /bin/bash

ssh bandit17@bandit.labs.overthewire.org -p 2220 -i sshkey.private
$ ./script.sh
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

Linux bandit 4.18.12 x86_64 GNU/Linux

<...>

  For support, questions or comments, contact us through IRC on
  irc.overthewire.org #wargames.

  Enjoy your stay!

bandit17@bandit:~$ whoami
bandit17
bandit17@bandit:~$ cat /etc/bandit_pass/bandit17
xLYVMN9WE5zQ5vHacb0sZEVqbrp7nBTn
```

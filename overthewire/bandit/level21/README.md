# BANDIT LEVEL 20 --> LEVEL 21

```
http://overthewire.org/wargames/bandit/bandit21.html
```

### Level Goal

There is a setuid binary in the homedirectory that does the following: it makes a connection
to localhost on the port you specify as a commandline argument. It then reads a line of text
from the connection and compares it to the password in the previous level (bandit20). If the
password is correct, it will transmit the password for the next level (bandit21).

NOTE: Try connecting to your own network daemon to see if it works as you think

### Commands you may need to solve this level

```
ssh, nc, cat, bash, screen, tmux, Unix ‘job control’ (bg, fg, jobs, &, CTRL-Z, …)
```

### SOLUTION

Let's grab the password we need first..

```
bandit20@bandit:~$ cat /etc/bandit_pass/bandit20
GbKksEFF4yrVs6il55v6gwY5aVje5f0j
```

```
bandit20@bandit:~$ whoami
bandit20
bandit20@bandit:~$ pwd
/home/bandit20
bandit20@bandit:~$ ls
suconnect
bandit20@bandit:~$ ls -l
total 12
-rwsr-x--- 1 bandit21 bandit20 12088 Oct 16 14:00 suconnect
bandit20@bandit:~$ ./suconnect
Usage: ./suconnect <portnumber>
This program will connect to the given port on localhost using TCP. If it receives the correct password from the other side, the next password is transmitted back.
```

As the instructions suggested, we can test the utility by setting up our own listner against
an arbitrary port (I chose `4444`).

```
bandit20@bandit:~$ nc -v -l -p 4444
listening on [any] 4444 ...
connect to [127.0.0.1] from localhost [127.0.0.1] 40196
```

.. and using the executable to connect to that port..

```
bandit20@bandit:~$ nmap -p 1-65535 --open localhost

Starting Nmap 7.40 ( https://nmap.org ) at 2018-10-23 05:19 CEST
Nmap scan report for localhost (127.0.0.1)
Host is up (0.00016s latency).
Not shown: 65524 closed ports
Some closed ports may be reported as filtered due to --defeat-rst-ratelimit
PORT      STATE SERVICE
22/tcp    open  ssh
113/tcp   open  ident
4444/tcp  open  krb524
6969/tcp  open  acmsoda
30000/tcp open  ndmps
30001/tcp open  pago-services1
30002/tcp open  pago-services2
31518/tcp open  unknown
31790/tcp open  unknown
38101/tcp open  unknown
41111/tcp open  fs-qos

Nmap done: 1 IP address (1 host up) scanned in 2.22 seconds
bandit20@bandit:~$ ./suconnect 4444
hi
bye
Read:
ERROR: This doesn't match the current password!
```

Looks like it made the connection and does the application itself know and check for the
password?.

```
bandit20@bandit:~$ ./suconnect 4444
GbKksEFF4yrVs6il55v6gwY5aVje5f0j
```

No.. that didn't seem to work as it's waiting for a response from the server to compare
against. So what if we had our "server" send the password back?

```
bandit20@bandit:~$ echo "password" | nc -v -l -p 4444
```

```
bandit20@bandit:~$ ./suconnect 4444
Read: password
ERROR: This doesn't match the current password!
```

Okay.. we're getting closer.  We see that the program "reads" our `password` input and claims
it is the wrong password. So let's pass it the correct level 20 password.

```
bandit20@bandit:~$ echo "GbKksEFF4yrVs6il55v6gwY5aVje5f0j" | nc -v -l -p 4444
```

```
bandit20@bandit:~$ ./suconnect 4444
Read: GbKksEFF4yrVs6il55v6gwY5aVje5f0j
Password matches, sending next password
```

Flipping back to the terminal where we launched `netcat` we see the `suconnect` program
sent back the password to the next level..

```
bandit20@bandit:~$ echo "GbKksEFF4yrVs6il55v6gwY5aVje5f0j" | nc -v -l -p 4444
listening on [any] 4444 ...
connect to [127.0.0.1] from localhost [127.0.0.1] 55238
gE269g2h3mw3pwgrj0Ha9Uoqen1c9DGr
```

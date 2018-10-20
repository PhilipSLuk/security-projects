# BANDIT LEVEL 14 --> LEVEL 15

```
http://overthewire.org/wargames/bandit/bandit15.html
```

### Level Goal

The password for the next level can be retrieved by submitting the password of the current
level to port 30000 on localhost.

### Commands you may need to solve this level

```
ssh, telnet, nc, openssl, s_client, nmap
```

### Helpful Reading Material

- How the Internet works in 5 minutes (YouTube) (Not completely accurate, but good enough for beginners)
- IP Addresses
- IP Address on Wikipedia
- Localhost on Wikipedia
- Ports
- Port (computer networking) on Wikipedia

### SOLUTION

Let's grab the password we require..

```
bandit14@bandit:~$ cat /etc/bandit_pass/bandit14
4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e
```

Now go figure out what is listening on `port 30000` on `localhost`..

```
bandit14@bandit:~$ nmap -p 1-65535 --open localhost

Starting Nmap 7.40 ( https://nmap.org ) at 2018-10-20 06:56 CEST
Nmap scan report for localhost (127.0.0.1)
Host is up (0.00019s latency).
Not shown: 65528 closed ports
Some closed ports may be reported as filtered due to --defeat-rst-ratelimit
PORT      STATE SERVICE
22/tcp    open  ssh
113/tcp   open  ident
30000/tcp open  ndmps
30001/tcp open  pago-services1
30002/tcp open  pago-services2
31518/tcp open  unknown
31790/tcp open  unknown

Nmap done: 1 IP address (1 host up) scanned in 3.27 seconds
```

So we have something called NDMP running on port 30000. What is that?

```
https://en.wikipedia.org/wiki/NDMP

NDMP, or Network Data Management Protocol, is a protocol meant to transport data between
network attached storage (NAS) devices and backup devices. This removes the need for
transporting the data through the backup server itself, thus enhancing speed and removing
load from the backup server.
```

Okay.. now what? 

Thought to try using `telnet` to connect to the port to see what happens..

```
bandit14@bandit:~$ telnet localhost 30000
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e
Correct!
BfMYroe26WYalil77FoDi9qh59eK5xNr

Connection closed by foreign host.
```

.. and feeding in the password, it spits back out what appears to be the next levels
passphrase!

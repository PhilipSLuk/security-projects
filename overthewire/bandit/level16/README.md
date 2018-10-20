# BANDIT LEVEL 15 --> LEVEL 16

```
http://overthewire.org/wargames/bandit/bandit16.html
```

### Level Goal

The password for the next level can be retrieved by submitting the password of the current
level to port 30001 on localhost using SSL encryption.

Helpful note: Getting “HEARTBEATING” and “Read R BLOCK”? Use -ign_eof and read the
“CONNECTED COMMANDS” section in the manpage. Next to ‘R’ and ‘Q’, the ‘B’ command also works
in this version of that command…

### Commands you may need to solve this level

```
ssh, telnet, nc, openssl, s_client, nmap
```

### Helpful Reading Material

- Secure Socket Layer/Transport Layer Security on Wikipedia
- OpenSSL Cookbook - Testing with OpenSSL

### SOLUTION

Let's start off by grabbing the password we need..

```
bandit15@bandit:~$ cat /etc/bandit_pass/bandit15
BfMYroe26WYalil77FoDi9qh59eK5xNr
```

.. and what is running on port `30001`?

```
bandit15@bandit:~$ nmap -p 30001 --open localhost

Starting Nmap 7.40 ( https://nmap.org ) at 2018-10-20 07:08 CEST
Nmap scan report for localhost (127.0.0.1)
Host is up (0.00012s latency).
PORT      STATE SERVICE
30001/tcp open  pago-services1

Nmap done: 1 IP address (1 host up) scanned in 0.05 seconds
```

We use the reference to the `-no_ign_eof` option as a hint and dig into the `s_client`
command..

```
$ man s_client
S_CLIENT(1SSL)                            OpenSSL                           S_CLIENT(1SSL)

NAME
       openssl-s_client, s_client - SSL/TLS client program

SYNOPSIS
       openssl s_client [-help] [-connect host:port] [-proxy host:port] [-unix path] [-4]

<...>

DESCRIPTION
       The s_client command implements a generic SSL/TLS client which connects to a remote
       host using SSL/TLS. It is a very useful diagnostic tool for SSL servers.
```

```
bandit15@bandit:~$ openssl s_client -connect localhost:30001
CONNECTED(00000003)
depth=0 CN = localhost
verify error:num=18:self signed certificate
verify return:1
depth=0 CN = localhost
verify return:1
---
Certificate chain
 0 s:/CN=localhost
   i:/CN=localhost
---
Server certificate
-----BEGIN CERTIFICATE-----
MIICBjCCAW+gAwIBAgIEBuAgAjANBgkqhkiG9w0BAQUFADAUMRIwEAYDVQQDDAls
b2NhbGhvc3QwHhcNMTgxMDE2MTIwMzI3WhcNMTkxMDE2MTIwMzI3WjAUMRIwEAYD
VQQDDAlsb2NhbGhvc3QwgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBAMAzS7Wa
lf+m6OTRah6FDYL0q/DxznPWB4sF5gs5IQwtGO4SqNODkhck/xz1EvJK+rSpAx0H
qRWS6n12gs0xt0amU+krwitJ1XeZ4IZGpd5EwTMU7+AR0KO6Z9Xvmfs4TsOFvfHF
vBMYM04V3/O6P+/DBtD75nYLrflqLwVLDwo1AgMBAAGjZTBjMBQGA1UdEQQNMAuC
CWxvY2FsaG9zdDBLBglghkgBhvhCAQ0EPhY8QXV0b21hdGljYWxseSBnZW5lcmF0
ZWQgYnkgTmNhdC4gU2VlIGh0dHBzOi8vbm1hcC5vcmcvbmNhdC8uMA0GCSqGSIb3
DQEBBQUAA4GBAF+BtyNMesHZTXXKxhJhv7e4WYMcFGPiUlhM/O8DGRuA4UoMeXpO
iSocOtYnOcDiOGzJmFWAwMFz6qAUSwb0lkKpbY2kNJHJ6jmSI2j+houZmVLUgvQr
vCoD6KL5krLQ9JFjIhyBzIVq2C3HV15N0miFFBTVOI/6FC/TTEeZZxzB
-----END CERTIFICATE-----
subject=/CN=localhost
issuer=/CN=localhost
---
No client certificate CA names sent
Peer signing digest: SHA512
Server Temp Key: X25519, 253 bits
---
SSL handshake has read 1019 bytes and written 269 bytes
Verification error: self signed certificate
---
New, TLSv1.2, Cipher is ECDHE-RSA-AES256-GCM-SHA384
Server public key is 1024 bit
Secure Renegotiation IS supported
Compression: NONE
Expansion: NONE
No ALPN negotiated
SSL-Session:
    Protocol  : TLSv1.2
    Cipher    : ECDHE-RSA-AES256-GCM-SHA384
    Session-ID: ADD8E250A6C4A30B1E9A2A08C0CBD65D1C8DDB1E5E355045E18E74A5F5C96724
    Session-ID-ctx:
    Master-Key: 18EB3EB0547DDE01E0847D10BA1FA0E599C5CC036D340606CDAA0E89974CE2871F1DD48D29ECF57737A1F5601E7BA223
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    TLS session ticket lifetime hint: 7200 (seconds)
    TLS session ticket:
    0000 - 4d 71 e2 4a 89 ec b5 87-ae 3b 55 9c 1b 55 0b bc   Mq.J.....;U..U..
    0010 - 61 d8 04 2c 7a d6 9e cc-44 89 d3 b8 37 fd 9b da   a..,z...D...7...
    0020 - 33 02 e0 41 c3 8f 39 fb-32 1b a0 02 78 09 fc 7e   3..A..9.2...x..~
    0030 - 17 96 d0 70 be a6 a1 bd-e7 4d 10 77 e9 d7 b5 96   ...p.....M.w....
    0040 - 28 72 50 77 8d 68 69 5a-ee 95 d1 1b 0c 4a 52 2b   (rPw.hiZ.....JR+
    0050 - c1 e9 08 30 11 e9 03 d6-72 2b 92 c0 d9 5b 8d ea   ...0....r+...[..
    0060 - 14 b9 94 cc 11 a9 29 fe-99 32 ba fd e3 ca b1 06   ......)..2......
    0070 - d7 2b 54 be 0d a8 63 91-f1 8d c7 96 c4 f5 a2 cd   .+T...c.........
    0080 - eb 6d bb 9e cc 78 46 5e-31 77 c8 3a 5a 46 2e c0   .m...xF^1w.:ZF..
    0090 - c1 b9 13 ef 93 7a 9b 42-2c 16 d2 1d 85 cf 13 cc   .....z.B,.......

    Start Time: 1540045876
    Timeout   : 7200 (sec)
    Verify return code: 18 (self signed certificate)
    Extended master secret: yes
---
BfMYroe26WYalil77FoDi9qh59eK5xNr
Correct!
cluFn7wTiGryunymYOu4RcffSxQluehd

closed
bandit15@bandit:~$
```


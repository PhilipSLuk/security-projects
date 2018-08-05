# CRYPTO CHALLENGE: WEAK RSA

## Challenge Description
Can you decrypt the message and get the flag?

```
$ cat key.pub 
-----BEGIN PUBLIC KEY-----
MIIBHzANBgkqhkiG9w0BAQEFAAOCAQwAMIIBBwKBgQMwO3kPsUnaNAbUlaubn7ip
4pNEXjvUOxjvLwUhtybr6Ng4undLtSQPCPf7ygoUKh1KYeqXMpTmhKjRos3xioTy
23CZuOl3WIsLiRKSVYyqBc9d8rxjNMXuUIOiNO38ealcR4p44zfHI66INPuKmTG3
RQP/6p5hv1PYcWmErEeDewKBgGEXxgRIsTlFGrW2C2JXoSvakMCWD60eAH0W2PpD
qlqqOFD8JA5UFK0roQkOjhLWSVu8c6DLpWJQQlXHPqP702qIg/gx2o0bm4EzrCEJ
4gYo6Ax+U7q6TOWhQpiBHnC0ojE8kUoqMhfALpUaruTJ6zmj8IA1e1M6bMqVF8sr
lb/N
-----END PUBLIC KEY-----
```

```
$ cat flag.enc 
?_?vc[??~?kZ?1?Ĩ?4?I?9V?ֿ?^G???(?+3Lu"?T$???F0?VP?־j@?????|j?????{¾?,?????YE?????Xx??,??c?N&Hl2?Ӎ??[o??
```

### RSA ENCRYPTION

```
RSA (Rivest–Shamir–Adleman) is one of the first practical public-key cryptosystems and is
widely used for secure data transmission. In such a cryptosystem, the encryption key is
public and it is different from the decryption key which is kept secret (private). In RSA,
this asymmetry is based on the practical difficulty of the factorization of the product of
two large prime numbers, the "factoring problem".

A user of RSA creates and then publishes a public key based on two large prime numbers, along
with an auxiliary value. The prime numbers must be kept secret. Anyone can use the public key
to encrypt a message, but with currently published methods, and if the public key is large
enough, only someone with knowledge of the prime numbers can decode the message feasibly.
Breaking RSA encryption is known as the RSA problem. Whether it is as difficult as the
factoring problem remains an open question.

https://en.wikipedia.org/wiki/RSA_(cryptosystem)
```

Hm.. so we have the `public key` and we have the cipher text.  I guess we need to figure out
the two prime numbers? The modulus? The exponent? The name of the challenge suggests the RSA
is breakable.

```
$ openssl rsa  -pubin -in key.pub -text -modulus -noout
Public-Key: (1026 bit)
Modulus:
    03:30:3b:79:0f:b1:49:da:34:06:d4:95:ab:9b:9f:
    b8:a9:e2:93:44:5e:3b:d4:3b:18:ef:2f:05:21:b7:
    26:eb:e8:d8:38:ba:77:4b:b5:24:0f:08:f7:fb:ca:
    0a:14:2a:1d:4a:61:ea:97:32:94:e6:84:a8:d1:a2:
    cd:f1:8a:84:f2:db:70:99:b8:e9:77:58:8b:0b:89:
    12:92:55:8c:aa:05:cf:5d:f2:bc:63:34:c5:ee:50:
    83:a2:34:ed:fc:79:a9:5c:47:8a:78:e3:37:c7:23:
    ae:88:34:fb:8a:99:31:b7:45:03:ff:ea:9e:61:bf:
    53:d8:71:69:84:ac:47:83:7b
Exponent:
    61:17:c6:04:48:b1:39:45:1a:b5:b6:0b:62:57:a1:
    2b:da:90:c0:96:0f:ad:1e:00:7d:16:d8:fa:43:aa:
    5a:aa:38:50:fc:24:0e:54:14:ad:2b:a1:09:0e:8e:
    12:d6:49:5b:bc:73:a0:cb:a5:62:50:42:55:c7:3e:
    a3:fb:d3:6a:88:83:f8:31:da:8d:1b:9b:81:33:ac:
    21:09:e2:06:28:e8:0c:7e:53:ba:ba:4c:e5:a1:42:
    98:81:1e:70:b4:a2:31:3c:91:4a:2a:32:17:c0:2e:
    95:1a:ae:e4:c9:eb:39:a3:f0:80:35:7b:53:3a:6c:
    ca:95:17:cb:2b:95:bf:cd
Modulus=3303B790FB149DA3406D495AB9B9FB8A9E293445E3BD43B18EF2F0521B726EBE8D838BA774BB5240F08F7FBCA0A142A1D4A61EA973294E684A8D1A2CDF18A84F2DB7099B8E977588B0B891292558CAA05CF5DF2BC6334C5EE5083A234EDFC79A95C478A78E337C723AE8834FB8A9931B74503FFEA9E61BF53D8716984AC47837B
```

The modulus is a 1024-bit number and does not factorize easily implying both the primes are
large. The public key exponent is also large.

### CRACKING RSA

Searching around the interweb reveals a popular CTF tool for cracking RSA encryption..

```
RSA tool for ctf - uncipher data from weak public key and try to recover private key
Automatic selection of best attack for the given public key

https://github.com/Ganapati/RsaCtfTool
```

Let's first try using the tool to dump the parameters from our public key..

```
$ ./RsaCtfTool.py --dumpkey --key key.pub 
[*] n: 573177824579630911668469272712547865443556654086190104722795509756891670023259031275433509121481030331598569379383505928315495462888788593695945321417676298471525243254143375622365552296949413920679290535717172319562064308937342567483690486592868352763021360051776130919666984258847567032959931761686072492923
[*] e: 68180928631284147212820507192605734632035524131139938618069575375591806315288775310503696874509130847529572462608728019290710149661300246138036579342079580434777344111245495187927881132138357958744974243365962204835089753987667395511682829391276714359582055290140617797814443530797154040685978229936907206605
```

.. the output of the tool for our `modulus` and `exponent` is what we saw from out use of
the `openssl` tool.

Now let's try using the tool to obtain the private key..

```
$ ./RsaCtfTool.py --publickey key.pub --verbose --private
[*] Performing hastads attack.
[*] Performing factordb attack.
-----BEGIN RSA PRIVATE KEY-----
MIICOQIBAAKBgQMwO3kPsUnaNAbUlaubn7ip4pNEXjvUOxjvLwUhtybr6Ng4undL
tSQPCPf7ygoUKh1KYeqXMpTmhKjRos3xioTy23CZuOl3WIsLiRKSVYyqBc9d8rxj
NMXuUIOiNO38ealcR4p44zfHI66INPuKmTG3RQP/6p5hv1PYcWmErEeDewKBgGEX
xgRIsTlFGrW2C2JXoSvakMCWD60eAH0W2PpDqlqqOFD8JA5UFK0roQkOjhLWSVu8
c6DLpWJQQlXHPqP702qIg/gx2o0bm4EzrCEJ4gYo6Ax+U7q6TOWhQpiBHnC0ojE8
kUoqMhfALpUaruTJ6zmj8IA1e1M6bMqVF8srlb/NAiBhwngxi+Cbie3YBogNzGJV
h10vAgw+i7cQqiiwEiPFNQJBAYXzr5r2KkHVjGcZNCLRAoXrzJjVhb7knZE5oEYo
nEI+h2gQSt1bavv3YVxhcisTVuNrlgQo58eGb4c9dtY2blMCQQIX2W9IbtJ26KzZ
C/5HPsVqgxWtuP5hN8OLf3ohhojr1NigJwc6o68dtKScaEQ5A33vmNpuWqKucecT
0HEVxuE5AiBhwngxi+Cbie3YBogNzGJVh10vAgw+i7cQqiiwEiPFNQIgYcJ4MYvg
m4nt2AaIDcxiVYddLwIMPou3EKoosBIjxTUCQQCnqbJMPEQHpg5lI6MQi8ixFRqo
+KwoBrwYfZlGEwZxdK2Ms0jgeta5jFFS11Fwk5+GyimnRzVcEbADJno/8BKe
-----END RSA PRIVATE KEY-----
```

Neat! Let's examine our private key..

```
$ openssl rsa -in key.private -text -noout
Private-Key: (1026 bit)
modulus:
    03:30:3b:79:0f:b1:49:da:34:06:d4:95:ab:9b:9f:
    b8:a9:e2:93:44:5e:3b:d4:3b:18:ef:2f:05:21:b7:
    26:eb:e8:d8:38:ba:77:4b:b5:24:0f:08:f7:fb:ca:
    0a:14:2a:1d:4a:61:ea:97:32:94:e6:84:a8:d1:a2:
    cd:f1:8a:84:f2:db:70:99:b8:e9:77:58:8b:0b:89:
    12:92:55:8c:aa:05:cf:5d:f2:bc:63:34:c5:ee:50:
    83:a2:34:ed:fc:79:a9:5c:47:8a:78:e3:37:c7:23:
    ae:88:34:fb:8a:99:31:b7:45:03:ff:ea:9e:61:bf:
    53:d8:71:69:84:ac:47:83:7b
publicExponent:
    61:17:c6:04:48:b1:39:45:1a:b5:b6:0b:62:57:a1:
    2b:da:90:c0:96:0f:ad:1e:00:7d:16:d8:fa:43:aa:
    5a:aa:38:50:fc:24:0e:54:14:ad:2b:a1:09:0e:8e:
    12:d6:49:5b:bc:73:a0:cb:a5:62:50:42:55:c7:3e:
    a3:fb:d3:6a:88:83:f8:31:da:8d:1b:9b:81:33:ac:
    21:09:e2:06:28:e8:0c:7e:53:ba:ba:4c:e5:a1:42:
    98:81:1e:70:b4:a2:31:3c:91:4a:2a:32:17:c0:2e:
    95:1a:ae:e4:c9:eb:39:a3:f0:80:35:7b:53:3a:6c:
    ca:95:17:cb:2b:95:bf:cd
privateExponent:
    61:c2:78:31:8b:e0:9b:89:ed:d8:06:88:0d:cc:62:
    55:87:5d:2f:02:0c:3e:8b:b7:10:aa:28:b0:12:23:
    c5:35
prime1:
    01:85:f3:af:9a:f6:2a:41:d5:8c:67:19:34:22:d1:
    02:85:eb:cc:98:d5:85:be:e4:9d:91:39:a0:46:28:
    9c:42:3e:87:68:10:4a:dd:5b:6a:fb:f7:61:5c:61:
    72:2b:13:56:e3:6b:96:04:28:e7:c7:86:6f:87:3d:
    76:d6:36:6e:53
prime2:
    02:17:d9:6f:48:6e:d2:76:e8:ac:d9:0b:fe:47:3e:
    c5:6a:83:15:ad:b8:fe:61:37:c3:8b:7f:7a:21:86:
    88:eb:d4:d8:a0:27:07:3a:a3:af:1d:b4:a4:9c:68:
    44:39:03:7d:ef:98:da:6e:5a:a2:ae:71:e7:13:d0:
    71:15:c6:e1:39
exponent1:
    61:c2:78:31:8b:e0:9b:89:ed:d8:06:88:0d:cc:62:
    55:87:5d:2f:02:0c:3e:8b:b7:10:aa:28:b0:12:23:
    c5:35
exponent2:
    61:c2:78:31:8b:e0:9b:89:ed:d8:06:88:0d:cc:62:
    55:87:5d:2f:02:0c:3e:8b:b7:10:aa:28:b0:12:23:
    c5:35
coefficient:
    00:a7:a9:b2:4c:3c:44:07:a6:0e:65:23:a3:10:8b:
    c8:b1:15:1a:a8:f8:ac:28:06:bc:18:7d:99:46:13:
    06:71:74:ad:8c:b3:48:e0:7a:d6:b9:8c:51:52:d7:
    51:70:93:9f:86:ca:29:a7:47:35:5c:11:b0:03:26:
    7a:3f:f0:12:9e
```

### DECRYPTION

Using our newly found private key, let's try and decrypt our cipher text!

```
$ openssl rsautl -decrypt -inkey key.private -in flag.enc 
HTB{s1mpl3_Wi3n3rs_4tt4ck}
```

Cool. Note that the CTF tool we used to obtain the private key could have also helped us
directly decipher the text, but I wanted to try and use the private key myself for fun.

```
$ ./RsaCtfTool.py --publickey key.pub --uncipherfile flag.enc 
[+] Clear text : b'HTB{s1mpl3_Wi3n3rs_4tt4ck}'
```

# STEGO CHALLENGE: HACKERMAN

## Challenge Description
There should be something hidden inside this photo.. Can you find out?

```
hackerman.jpg
```
<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/hackerman/hackerman.jpg" width=200px/>

### FILTERS

```
https://29a.ch/photo-forensics/
```

Standard filters doesn't yield anything interesting..

### STRING ANALYSIS

```
$ strings hackerman.jpg | tail
n?ZH
g?6:
R`S_/
J7$&
jo+b
'r]+
,g52
o3n=
2<co;
5634275d694f8665957746c9619132f0
```

Hm... `5634275d694f8665957746c9619132f0` is the MD5 hash for `almost`..

```
https://hashkiller.co.uk/md5-decrypter.aspx

5634275d694f8665957746c9619132f0 MD5 : almost
```

.. but yet that isn't the flag.

### STEGHIDE

Let's see if `almost` might be the password used with `steghide`..

```
$ steghide extract -sf hackerman.jpg 
Enter passphrase: 
wrote extracted data to "hackerman.txt".
```
Awesome! We found `hackerman.txt` hidden inside the JPG..

```
$ cat hackerman.txt 
SFRCezN2MWxfYzBycH0=
```

### BASE64 DECODE

```
$ base64 --d hackerman.txt 
HTB{3v1l_c0rp}
```

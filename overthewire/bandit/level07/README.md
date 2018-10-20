# BANDIT LEVEL 6 --> LEVEL 7

```
http://overthewire.org/wargames/bandit/bandit7.html
```

### Level Goal

The password for the next level is stored somewhere on the server and has all of the
following properties:

- owned by user bandit7
- owned by group bandit6
- 33 bytes in size

### Commands you may need to solve this level

```
ls, cd, cat, file, du, find
```

### SOLUTION

```
bandit6@bandit:~$ whoami
bandit6
bandit6@bandit:~$ pwd
/home/bandit6
bandit6@bandit:~$ find / -exec ls -l {} \; 2>&1 | grep bandit7 | grep -v "Permission denied"
-rw-r----- 1 bandit7 bandit6      33 Oct 16 14:00 bandit7.password
-rw-r----- 1 bandit7 bandit6 33 Oct 16 14:00 /var/lib/dpkg/info/bandit7.password
bandit6@bandit:~$ cat /var/lib/dpkg/info/bandit7.password
HKBPTKQnIay4Fw76bEy8PVxKEDQRKTzs
```

We found our password in `/var/lib/dpkg/info/bandit7.password`..

```
$ cat script.sh
#! /usr/bin/bash

ssh bandit7@bandit.labs.overthewire.org -p 2220

# passwd: HKBPTKQnIay4Fw76bEy8PVxKEDQRKTzs
$ ./script.sh
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit7@bandit.labs.overthewire.org's password:
Linux bandit 4.18.12 x86_64 GNU/Linux

bandit7@bandit:~$
```

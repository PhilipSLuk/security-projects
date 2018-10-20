# BANDIT LEVEL 2 --> LEVEL 3

```
http://overthewire.org/wargames/bandit/bandit3.html
```

### Level Goal

The password for the next level is stored in a file called spaces in this filename located
in the home directory

### Commands you may need to solve this level

```
ls, cd, cat, file, du, find
```

### Helpful Reading Material

- Google Search for “spaces in filename”

### SOLUTION

```
andit2@bandit:~$ whoami
bandit2
bandit2@bandit:~$ pwd
/home/bandit2
bandit2@bandit:~$ ls
spaces in this filename
bandit2@bandit:~$ cat "spaces in this filename"
UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK
```

```
$ cat script.sh
#! /usr/bin/bash

ssh bandit3@bandit.labs.overthewire.org -p 2220

# passwd: UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK
$ ./script.sh
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit3@bandit.labs.overthewire.org's password:
Linux bandit 4.18.12 x86_64 GNU/Linux
bandit3@bandit:~$ whoami
bandit3
```

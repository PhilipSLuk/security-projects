# BANDIT LEVEL 3 --> LEVEL 4

```
http://overthewire.org/wargames/bandit/bandit4.html
```

### Level Goal

The password for the next level is stored in a hidden file in the `inhere` directory.

### Commands you may need to solve this level

```
ls, cd, cat, file, du, find
```

### SOLUTION

```
bandit3@bandit:~$ whoami
bandit3
bandit3@bandit:~$ ls -al
total 24
drwxr-xr-x  3 root root 4096 Oct 16 14:00 .
drwxr-xr-x 41 root root 4096 Oct 16 14:00 ..
-rw-r--r--  1 root root  220 May 15  2017 .bash_logout
-rw-r--r--  1 root root 3526 May 15  2017 .bashrc
drwxr-xr-x  2 root root 4096 Oct 16 14:00 inhere
-rw-r--r--  1 root root  675 May 15  2017 .profile
bandit3@bandit:~$ cd inhere/
bandit3@bandit:~/inhere$ ls -al
total 12
drwxr-xr-x 2 root    root    4096 Oct 16 14:00 .
drwxr-xr-x 3 root    root    4096 Oct 16 14:00 ..
-rw-r----- 1 bandit4 bandit3   33 Oct 16 14:00 .hidden
bandit3@bandit:~/inhere$ cat .hidden
pIwrPrtPN36QITSp3EQaw936yaFoFgAB
```

```
$ cat script.sh
#! /usr/bin/bash

ssh bandit4@bandit.labs.overthewire.org -p 2220

# passwd: pIwrPrtPN36QITSp3EQaw936yaFoFgAB
fortyfunbobby@kali:/mnt/host/Development/security-projects/overthewire/bandit/level03-04$ ./script.sh
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit4@bandit.labs.overthewire.org's password:

bandit3@bandit:~$ whoami
bandit4
```

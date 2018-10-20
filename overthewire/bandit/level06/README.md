# BANDIT LEVEL 5 --> LEVEL 6

```
http://overthewire.org/wargames/bandit/bandit6.html
```

### Level Goal

The password for the next level is stored in a file somewhere under the inhere directory and
has all of the following properties:

- human-readable
- 1033 bytes in size
- not executable

### Commands you may need to solve this level

```
ls, cd, cat, file, du, find
```

### SOLUTION

```
bandit5@bandit:~$ whoami
bandit5
bandit5@bandit:~$ pwd
/home/bandit5
bandit5@bandit:~$ ls -al
total 24
drwxr-xr-x  3 root root    4096 Oct 16 14:00 .
drwxr-xr-x 41 root root    4096 Oct 16 14:00 ..
-rw-r--r--  1 root root     220 May 15  2017 .bash_logout
-rw-r--r--  1 root root    3526 May 15  2017 .bashrc
drwxr-x--- 22 root bandit5 4096 Oct 16 14:00 inhere
-rw-r--r--  1 root root     675 May 15  2017 .profile
bandit5@bandit:~$ find inhere -exec ls -l {} \; | grep 1033
-rw-r----- 1 root bandit5 1033 Oct 16 14:00 inhere/maybehere07/.file2
bandit5@bandit:~$ cat inhere/maybehere07/.file2
DXjZPULLxYr17uwoI01bNLQbtFemEgo7
```

We found our password in `maybehere07/.file2`..

```
$ cat script.sh
#! /usr/bin/bash

ssh bandit6@bandit.labs.overthewire.org -p 2220

# passwd: DXjZPULLxYr17uwoI01bNLQbtFemEgo7
$ ./script.sh
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit6@bandit.labs.overthewire.org's password:
Linux bandit 4.18.12 x86_64 GNU/Linux
bandit6@bandit:~$
```

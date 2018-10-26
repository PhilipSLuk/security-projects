# BANDIT LEVEL 18 --> LEVEL 19

```
http://overthewire.org/wargames/bandit/bandit19.html
```

### Level Goal

The password for the next level is stored in a file readme in the homedirectory.
Unfortunately, someone has modified .bashrc to log you out when you log in with SSH.

### Commands you may need to solve this level

```
ssh, ls, cat
```

### SOLUTION

```
$ cat script.sh
#! /bin/bash

ssh bandit18@bandit.labs.overthewire.org -p 2220

# passwd: kfBf3eYk5BPBRzwjqutbbfE887SVc5Yd
mashimaro:level18 u6065044$ ./script.sh
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit18@bandit.labs.overthewire.org's password:
Linux bandit 4.18.12 x86_64 GNU/Linux

<...

  For support, questions or comments, contact us through IRC on
  irc.overthewire.org #wargames.

  Enjoy your stay!

Byebye !
Connection to bandit.labs.overthewire.org closed.
mashimaro:level18 u6065044$
```

Let's try again with `bash --norc`

```
$ ssh bandit18@bandit.labs.overthewire.org -p 2220 -t bash --norc
$ ssh bandit18@bandit.labs.overthewire.org -p 2220 -t bash --norc
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit18@bandit.labs.overthewire.org's password:
bash-4.4$ whoami
bandit18
bash-4.4$ pwd
/home/bandit18
bash-4.4$ ls
readme
bash-4.4$ cat readme
IueksS7Ubh8G3DCwVzrTd8rAVOwq3M5x
```

# BANDIT LEVEL 1 --> LEVEL 2

```
http://overthewire.org/wargames/bandit/bandit2.html
```

### Level Goal

The password for the next level is stored in a file called - located in the home directory

### Commands you may need to solve this level

```
ls, cd, cat, file, du, find
```

### Helpful Reading Material

- Google Search for “dashed filename”
- Advanced Bash-scripting Guide - Chapter 3 - Special Characters

### SOLUTION

```
bandit1@bandit:~$ pwd
/home/bandit1
bandit1@bandit:~$ ls
-
```

So the trick here is that the `cat` command interprets the `-` as a command to read from
`stdin` instead of a filename..

```
CAT(1)                                 User Commands                                CAT(1)

NAME
       cat - concatenate files and print on the standard output

SYNOPSIS
       cat [OPTION]... [FILE]...

DESCRIPTION
       Concatenate FILE(s) to standard output.

       With no FILE, or when FILE is -, read standard input.
```

Giving it a path name in front of it should do the trick..

```
bandit1@bandit:~$ cat ./-
CV1DtqXWVFXTvM2F0k09SHz0YwRINYA9
```

```
$ cat script.sh
#! /usr/bin/bash

ssh bandit2@bandit.labs.overthewire.org -p 2220

# passwd: CV1DtqXWVFXTvM2F0k09SHz0YwRINYA9
$ ./script.sh
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit2@bandit.labs.overthewire.org's password:

bandit2@bandit:~$ whoami
bandit2
```

# BANDIT LEVEL 0 --> LEVEL 1

```
http://overthewire.org/wargames/bandit/bandit1.html
```

### Level Goal

The password for the next level is stored in a file called readme located in the home
directory. Use this password to log into bandit1 using SSH. Whenever you find a password for
a level, use SSH (on port 2220) to log into that level and continue the game.

### Commands you may need to solve this level

```
ls, cd, cat, file, du, find
```

### SOLUTION

```
bandit0@bandit:~$ pwd
/home/bandit0
bandit0@bandit:~$ cat readme
boJ9jbbUNNfktd78OOpsqOltutMc3MY1
```

```
$ cat script.sh
#! /usr/bin/bash

ssh bandit1@bandit.labs.overthewire.org -p 2220

# passwd: boJ9jbbUNNfktd78OOpsqOltutMc3MY1
```

```
$ ./script.sh
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit1@bandit.labs.overthewire.org's password:
Linux bandit 4.18.12 x86_64 GNU/Linux


      ,----..            ,----,          .---.
     /   /   \         ,/   .`|         /. ./|
    /   .     :      ,`   .'  :     .--'.  ' ;
   .   /   ;.  \   ;    ;     /    /__./ \ : |
  .   ;   /  ` ; .'___,/    ,' .--'.  '   \' .
  ;   |  ; \ ; | |    :     | /___/ \ |    ' '
  |   :  | ; | ' ;    |.';  ; ;   \  \;      :
  .   |  ' ' ' : `----'  |  |  \   ;  `      |
  '   ;  \; /  |     '   :  ;   .   \    .\  ;
   \   \  ',  /      |   |  '    \   \   ' \ |
    ;   :    /       '   :  |     :   '  |--"
     \   \ .'        ;   |.'       \   \ ;
  www. `---` ver     '---' he       '---" ire.org


Welcome to OverTheWire!

bandit1@bandit:~$ whoami
bandit1
```

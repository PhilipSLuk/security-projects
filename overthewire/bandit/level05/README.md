# BANDIT LEVEL 4 --> LEVEL 5

```
http://overthewire.org/wargames/bandit/bandit5.html
```

### Level Goal

The password for the next level is stored in the only human-readable file in the `inhere`
directory. Tip: if your terminal is messed up, try the “reset” command.

### Commands you may need to solve this level

```
ls, cd, cat, file, du, find
```

### SOLUTION

```
bandit4@bandit:~$ whoami
bandit4
bandit4@bandit:~$ pwd
/home/bandit4
bandit4@bandit:~$ ls
inhere
bandit4@bandit:~$ cd inhere/
bandit4@bandit:~/inhere$ ls
-file00  -file01  -file02  -file03  -file04  -file05  -file06  -file07  -file08  -file09
bandit4@bandit:~/inhere$ cat /tmp/filo-level4/loop.sh
#! /usr/bin/bash

for i in $( ls ); do
  echo file: $i
  cat ./$i
done
bandit4@bandit:~/inhere$ chmod +x /tmp/filo-level4/loop.sh
bandit4@bandit:~/inhere$ /tmp/filo-level4/loop.sh
bandit4@bandit:~/inhere$ /tmp/filo-level4/loop.sh
file: -file00
���������~%    C[�걱>��| �file: -file01
���U"7�w���H��ê�Q��(���#���file: -file02
�T�v��(�ִ�����A*�
2J�Ş؇_�y7file: -file03
�.A��u��#���w$N?c�-��Db3��=��file: -file04
�=<�W�����ht�Z��!��{�U
                      �file: -file05
+��pm���;��:D��^��@�gl�Q�file: -file06
��@�%@���ZP*E��1�V���̫*����file: -file07
koReBOKuIDDepwhWk7jZC0RTdopnAYKh
file: -file08
FPn�
    '�U���M��/u
               XS
�mu�z���хfile: -file09
N�{��Y�d4���]3�����9(�
```

We find our password in `-file07`..

```
$ cat script.sh
#! /usr/bin/bash

ssh bandit5@bandit.labs.overthewire.org -p 2220

# passwd: koReBOKuIDDepwhWk7jZC0RTdopnAYKh
$ ./script.sh
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit5@bandit.labs.overthewire.org's password:
Linux bandit 4.18.12 x86_64 GNU/Linux

bandit5@bandit:~$
```

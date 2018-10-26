# BANDIT LEVEL 17 --> LEVEL 18

```
http://overthewire.org/wargames/bandit/bandit18.html
```

### Level Goal

There are 2 files in the homedirectory: passwords.old and passwords.new. The password for
the next level is in passwords.new and is the only line that has been changed between
passwords.old and passwords.new

NOTE: if you have solved this level and see ‘Byebye!’ when trying to log into bandit18,
this is related to the next level, bandit19

### Commands you may need to solve this level

```
cat, grep, ls, diff
```

### SOLUTION

```
bandit17@bandit:~$ whoami
bandit17
bandit17@bandit:~$ pwd
/home/bandit17
bandit17@bandit:~$ ls
passwords.new  passwords.old
bandit17@bandit:~$ diff passwords.old passwords.new
42c42
< hlbSBPAWJmL6WFDb06gpTx1pPButblOA
---
> kfBf3eYk5BPBRzwjqutbbfE887SVc5Yd
```

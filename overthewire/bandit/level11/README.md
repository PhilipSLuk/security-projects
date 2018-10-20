# BANDIT LEVEL 10 --> LEVEL 11

```
http://overthewire.org/wargames/bandit/bandit11.html
```

### Level Goal

The password for the next level is stored in the file `data.txt`, which contains base64
encoded data.

### Commands you may need to solve this level

```
grep, sort, uniq, strings, base64, tr, tar, gzip, bzip2, xxd
```

### SOLUTION

```
bandit10@bandit:~$ ls
data.txt
bandit10@bandit:~$ cat data.txt
VGhlIHBhc3N3b3JkIGlzIElGdWt3S0dzRlc4TU9xM0lSRnFyeEUxaHhUTkViVVBSCg==
bandit10@bandit:~$ cat data.txt | base64 -d
The password is IFukwKGsFW8MOq3IRFqrxE1hxTNEbUPR
```

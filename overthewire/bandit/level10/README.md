# BANDIT LEVEL 9 --> LEVEL 10

```
http://overthewire.org/wargames/bandit/bandit10.html
```

### Level Goal

The password for the next level is stored in the file `data.txt` in one of the few
human-readable strings, beginning with several ‘=’ characters.

### Commands you may need to solve this level

```
grep, sort, uniq, strings, base64, tr, tar, gzip, bzip2, xxd
```

### SOLUTION

```
bandit9@bandit:~$ ls
data.txt
bandit9@bandit:~$ strings data.txt | grep ===
2========== the
========== password
========== isa
========== truKLdjsbJ5g7yyJ2X2R0o3a5HQJFuLk
```

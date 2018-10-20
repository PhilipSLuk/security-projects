# BANDIT LEVEL 8 --> LEVEL 9

```
http://overthewire.org/wargames/bandit/bandit9.html
```

### Level Goal

The password for the next level is stored in the file `data.txt` and is the only line of
text that occurs only once

### Commands you may need to solve this level

```
grep, sort, uniq, strings, base64, tr, tar, gzip, bzip2, xxd
```

### SOLUTION

```
$ man uniq
UNIQ(1)                                User Commands                               UNIQ(1)

NAME
       uniq - report or omit repeated lines

SYNOPSIS
       uniq [OPTION]... [INPUT [OUTPUT]]

DESCRIPTION
       Filter  adjacent  matching  lines from INPUT (or standard input), writing to OUTPUT
       (or standard output).

       With no options, matching lines are merged to the first occurrence.

       Mandatory arguments to long options are mandatory for short options too.

<...>

       Note: 'uniq' does not detect repeated lines unless they are adjacent.  You may want
       to sort the input first, or use 'sort -u' without 'uniq'.  Also, comparisons  honor
       the rules specified by 'LC_COLLATE'.
```

```
bandit8@bandit:~$ ls
data.txt
bandit8@bandit:~$ head data.txt
KerqNiDbY0zV2VxnOCmWX5XWxumldlAe
MsxcvOe3PGrt78wpZG2bBNF5wfXpZhET
L0nxAwlfV9V3J5onKIT8KYQ9InTcQ7yE
4c7EsUtqLnLR9hiepV5EQVhdMgyi8onL
1drBmDT7PYS7hVgoTWkJSjUZUK7ZAIAa
L0nxAwlfV9V3J5onKIT8KYQ9InTcQ7yE
78rgduVcLZjLzZmooObdaN541MKV6IfQ
x0bga8Oxz5lgM8k52HrYy4ez7XJI0lM0
irGm6F73sbUrFhHukhp6JXgMQyLxJTz1
YzZX7E35vOa6IQ9SRUGdlEpyaiyjvWXE
bandit8@bandit:~$ sort data.txt | uniq -u
UsvVyFSfZZWbi6wgC7dAFyFuR6jQQUhR
```

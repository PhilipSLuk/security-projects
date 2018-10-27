# BANDIT LEVEL 26 --> LEVEL 27

```
http://overthewire.org/wargames/bandit/bandit27.html
```

### Level Goal

Good job getting a shell! Now hurry and grab the password for bandit27!

### Commands you may need to solve this level

```
ls
```

### SOLUTION

```
bandit26@bandit:~$ whoami
bandit26
bandit26@bandit:~$ ls -al
total 36
drwxr-xr-x  3 root     root     4096 Oct 16 14:00 .
drwxr-xr-x 41 root     root     4096 Oct 16 14:00 ..
-rwsr-x---  1 bandit27 bandit26 7296 Oct 16 14:00 bandit27-do
-rw-r--r--  1 root     root      220 May 15  2017 .bash_logout
-rw-r--r--  1 root     root     3526 May 15  2017 .bashrc
-rw-r--r--  1 root     root      675 May 15  2017 .profile
drwxr-xr-x  2 root     root     4096 Oct 16 14:00 .ssh
-rw-r-----  1 bandit26 bandit26  258 Oct 16 14:00 text.txt
bandit26@bandit:~$ ./bandit27-do
Run a command as another user.
  Example: ./bandit27-do id
bandit26@bandit:~$ ./bandit27-do cat /etc/bandit_pass/bandit27
3ba3118a22e93127a4ed485be72ef5ea
```

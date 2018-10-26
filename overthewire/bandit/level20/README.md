# BANDIT LEVEL 19 --> LEVEL 20

```
http://overthewire.org/wargames/bandit/bandit20.html
```

### Level Goal

To gain access to the next level, you should use the `setuid` binary in the homedirectory.
Execute it without arguments to find out how to use it. The password for this level can be
found in the usual place (`/etc/bandit_pass`), after you have used the setuid binary

### Helpful Reading Material

- setuid on Wikipedia

### SOLUTION

```
bandit19@bandit:~$ whoami
bandit19
bandit19@bandit:~$ pwd
/home/bandit19
bandit19@bandit:~$ ls
bandit20-do
bandit19@bandit:~$ ls -l
total 8
-rwsr-x--- 1 bandit20 bandit19 7296 Oct 16 14:00 bandit20-do
bandit19@bandit:~$ ./bandit20-do
Run a command as another user.
  Example: ./bandit20-do id
```

```
$ man setuid
SETUID(2)                        Linux Programmer's Manual                       SETUID(2)

NAME
       setuid - set user identity

SYNOPSIS
       #include <sys/types.h>
       #include <unistd.h>

       int setuid(uid_t uid);

DESCRIPTION
       setuid() sets the effective user ID of the calling process.  If the calling process
       is privileged (more precisely: if the process has the CAP_SETUID capability in  its
       user namespace), the real UID and saved set-user-ID are also set.
```

Okay, so we have a binary that will execute as if it were run by `bandit20` and this binary
allows us to input arbitrary commands for us to execute.. which means effectively we can run
any command we want as `bandit20`.

```
bandit19@bandit:~$ cat /etc/bandit_pass/bandit20
cat: /etc/bandit_pass/bandit20: Permission denied
bandit19@bandit:~$ ./bandit20-do cat /etc/bandit_pass/bandit20
GbKksEFF4yrVs6il55v6gwY5aVje5f0j
```

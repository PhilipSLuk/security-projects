# BANDIT LEVEL 27 --> LEVEL 28

```
http://overthewire.org/wargames/bandit/bandit28.html
```

### Level Goal

There is a git repository at `ssh://bandit27-git@localhost/home/bandit27-git/repo`.
The password for the user `bandit27-git` is the same as for the user `bandit27`.

Clone the repository and find the password for the next level.

### Commands you may need to solve this level

```
git
```

### SOLUTION

First grab the password we need..

```
bandit27@bandit:~$ cat /etc/bandit_pass/bandit27
3ba3118a22e93127a4ed485be72ef5ea
```

```
bandit27@bandit:~$ whoami
bandit27
bandit27@bandit:~$ pwd
/home/bandit27
bandit27@bandit:~$ ls -al
total 20
drwxr-xr-x  2 root root 4096 Oct 16 14:00 .
drwxr-xr-x 41 root root 4096 Oct 16 14:00 ..
-rw-r--r--  1 root root  220 May 15  2017 .bash_logout
-rw-r--r--  1 root root 3526 May 15  2017 .bashrc
-rw-r--r--  1 root root  675 May 15  2017 .profile
```

Alright.. let's go create ourselves a temp directory and clone the repository.

```
bandit27@bandit:~$ cd /tmp
bandit27@bandit:/tmp$ mkdir filo27
bandit27@bandit:/tmp$ cd filo27
bandit27@bandit:/tmp/filo27$ git clone ssh://bandit27-git@localhost/home/bandit27-git/repo
Cloning into 'repo'...
Could not create directory '/home/bandit27/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit27/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit27-git@localhost's password:
remote: Counting objects: 3, done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 3 (delta 0), reused 0 (delta 0)
Receiving objects: 100% (3/3), done.
bandit27@bandit:/tmp/filo27$ ls
repo
bandit27@bandit:/tmp/filo27$ cd repo/
bandit27@bandit:/tmp/filo27/repo$ ls
README
bandit27@bandit:/tmp/filo27/repo$ cat README
The password to the next level is: 0ef186ac70e04ea33b4c1853d2526fa2
```

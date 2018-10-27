# BANDIT LEVEL 28 --> LEVEL 29

```
http://overthewire.org/wargames/bandit/bandit29.html
```

### Level Goal

There is a git repository at `ssh://bandit28-git@localhost/home/bandit28-git/repo`.
The password for the user `bandit28-git` is the same as for the user `bandit28`.

Clone the repository and find the password for the next level.

### Commands you may need to solve this level

```
git
```

### SOLUTION

First grab the password we need..

```
bandit28@bandit:~$ cat /etc/bandit_pass/bandit28
0ef186ac70e04ea33b4c1853d2526fa2
```

Default exploration..

```
bandit28@bandit:~$ whoami
bandit28
bandit28@bandit:~$ pwd
/home/bandit28
bandit28@bandit:~$ ls -al
total 20
drwxr-xr-x  2 root root 4096 Oct 16 14:00 .
drwxr-xr-x 41 root root 4096 Oct 16 14:00 ..
-rw-r--r--  1 root root  220 May 15  2017 .bash_logout
-rw-r--r--  1 root root 3526 May 15  2017 .bashrc
-rw-r--r--  1 root root  675 May 15  2017 .profile
```

Alright.. let's go create ourselves a temp directory and clone the repository.

```
bandit28@bandit:~$ cd /tmp
bandit28@bandit:/tmp$ mkdir filo28
bandit28@bandit:/tmp$ cd filo28
bandit28@bandit:/tmp/filo28$ git clone ssh://bandit28-git@localhost/home/bandit28-git/repo
Cloning into 'repo'...
Could not create directory '/home/bandit28/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit28/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit28-git@localhost's password:
remote: Counting objects: 9, done.
remote: Compressing objects: 100% (6/6), done.
remote: Total 9 (delta 2), reused 0 (delta 0)
Receiving objects: 100% (9/9), done.
Resolving deltas: 100% (2/2), done.
bandit28@bandit:/tmp/filo28$ ls
repo
bandit28@bandit:/tmp/filo28$ cd repo/
bandit28@bandit:/tmp/filo28/repo$ ls
README.md
bandit28@bandit:/tmp/filo28/repo$ cat README.md
# Bandit Notes
Some notes for level29 of bandit.

## credentials

- username: bandit29
- password: xxxxxxxxxx
```

So we have a README file with the credentials blanked out. Let's look into the commit
history of this file..

```
commit 073c27c130e6ee407e12faad1dd3848a110c4f95
Author: Morla Porla <morla@overthewire.org>
Date:   Tue Oct 16 14:00:39 2018 +0200

    fix info leak

diff --git a/README.md b/README.md
index 3f7cee8..5c6457b 100644
--- a/README.md
+++ b/README.md
@@ -4,5 +4,5 @@ Some notes for level29 of bandit.
 ## credentials

 - username: bandit29
-- password: bbc96594b4e001778eee9975372716b2
+- password: xxxxxxxxxx

commit 186a1038cc54d1358d42d468cdc8e3cc28a93fcb
Author: Morla Porla <morla@overthewire.org>
Date:   Tue Oct 16 14:00:39 2018 +0200

    add missing data

diff --git a/README.md b/README.md
index 7ba2d2f..3f7cee8 100644
--- a/README.md
+++ b/README.md
@@ -4,5 +4,5 @@ Some notes for level29 of bandit.
 ## credentials

 - username: bandit29
-- password: <TBD>
+- password: bbc96594b4e001778eee9975372716b2

commit b67405defc6ef44210c53345fc953e6a21338cc7
Author: Ben Dover <noone@overthewire.org>
Date:   Tue Oct 16 14:00:39 2018 +0200

    initial commit of README.md

diff --git a/README.md b/README.md
new file mode 100644
index 0000000..7ba2d2f
--- /dev/null
+++ b/README.md
@@ -0,0 +1,8 @@
+# Bandit Notes
+Some notes for level29 of bandit.
+
+## credentials
+
+- username: bandit29
+- password: <TBD>
+
```

Looking through the commit history with the `-p` patch option, we can see the exact
changes this README file went through. Initially the password was documented as
"<TBD>", then it was updated to "bbc96594b4e001778eee9975372716b2" and finally
"xxxxxxxxxx" as part of a commit called "fix info leak".

# BANDIT LEVEL 29 --> LEVEL 30

```
http://overthewire.org/wargames/bandit/bandit30.html
```

### Level Goal

There is a git repository at `ssh://bandit29-git@localhost/home/bandit29-git/repo`.
The password for the user `bandit29-git` is the same as for the user `bandit29`.

Clone the repository and find the password for the next level.

### Commands you may need to solve this level

```
git
```

### SOLUTION

First grab the password we need..

```
bandit29@bandit:~$ cat /etc/bandit_pass/bandit29
bbc96594b4e001778eee9975372716b2
```

Alright.. let's go create ourselves a temp directory and clone the repository.

```
bandit29@bandit:~$ cd /tmp
bandit29@bandit:/tmp$ mkdir filo29
bandit29@bandit:/tmp$ cd filo29
bandit29@bandit:/tmp/filo29$ git clone ssh://bandit29-git@localhost/home/bandit29-git/repo
Cloning into 'repo'...
Could not create directory '/home/bandit29/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit29/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit29-git@localhost's password:
remote: Counting objects: 16, done.
remote: Compressing objects: 100% (11/11), done.
remote: Total 16 (delta 2), reused 0 (delta 0)
Receiving objects: 100% (16/16), done.
Resolving deltas: 100% (2/2), done.
bandit29@bandit:/tmp/filo29$ ls
repo
bandit29@bandit:/tmp/filo29$ cd repo
bandit29@bandit:/tmp/filo29/repo$ ls
README.md
bandit29@bandit:/tmp/filo29/repo$ cat README.md
# Bandit Notes
Some notes for bandit30 of bandit.

## credentials

- username: bandit30
- password: <no passwords in production!>
```

Let's consult the git commit history..

```
bandit29@bandit:/tmp/filo29/repo$ git log -p
commit 84abedc104bbc0c65cb9eb74eb1d3057753e70f8
Author: Ben Dover <noone@overthewire.org>
Date:   Tue Oct 16 14:00:41 2018 +0200

    fix username

diff --git a/README.md b/README.md
index 2da2f39..1af21d3 100644
--- a/README.md
+++ b/README.md
@@ -3,6 +3,6 @@ Some notes for bandit30 of bandit.

 ## credentials

-- username: bandit29
+- username: bandit30
 - password: <no passwords in production!>

commit 9b19e7d8c1aadf4edcc5b15ba8107329ad6c5650
Author: Ben Dover <noone@overthewire.org>
Date:   Tue Oct 16 14:00:41 2018 +0200

    initial commit of README.md

diff --git a/README.md b/README.md
new file mode 100644
index 0000000..2da2f39
--- /dev/null
+++ b/README.md
@@ -0,0 +1,8 @@
+# Bandit Notes
+Some notes for bandit30 of bandit.
+
+## credentials
+
+- username: bandit29
+- password: <no passwords in production!>
+
```

Alright.. the commit history doesn't show anything interesting, but the text does
state "no passwords in production".. so is there a non-production branch?

```
bandit29@bandit:/tmp/filo29/repo$ git branch
* master
bandit29@bandit:/tmp/filo29/repo$ git remote show origin
Could not create directory '/home/bandit29/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit29/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit29-git@localhost's password:
* remote origin
  Fetch URL: ssh://bandit29-git@localhost/home/bandit29-git/repo
  Push  URL: ssh://bandit29-git@localhost/home/bandit29-git/repo
  HEAD branch: master
  Remote branches:
    dev         tracked
    master      tracked
    sploits-dev tracked
  Local branch configured for 'git pull':
    master merges with remote master
  Local ref configured for 'git push':
    master pushes to master (up to date)
```

So we see we've cloned the `master` branch, but there are other branches of the repo.
The branch `sploits-dev` sounds suspicious..

```
bandit29@bandit:/tmp/filo29/repo$ git checkout sploits-dev
Branch sploits-dev set up to track remote branch sploits-dev from origin.
Switched to a new branch 'sploits-dev'
bandit29@bandit:/tmp/filo29/repo$ git log --pretty=oneline
2af54c57b2cb29a72e8f3e84a9e60c019c252b75 add some silly exploit, just for shit and giggles
84abedc104bbc0c65cb9eb74eb1d3057753e70f8 fix username
9b19e7d8c1aadf4edcc5b15ba8107329ad6c5650 initial commit of README.md
bandit29@bandit:/tmp/filo29/repo$ ls
exploits  README.md
bandit29@bandit:/tmp/filo29/repo$ cat README.md
# Bandit Notes
Some notes for bandit30 of bandit.

## credentials

- username: bandit30
- password: <no passwords in production!>

bandit29@bandit:/tmp/filo29/repo$ ls exploits/
horde5.md
bandit29@bandit:/tmp/filo29/repo$ cat exploits/horde5.md
```

Nope.. just a troll. Let's go look at the `dev` branch.

```
bandit29@bandit:/tmp/filo29/repo$ git checkout dev
Branch dev set up to track remote branch dev from origin.
Switched to a new branch 'dev'
bandit29@bandit:/tmp/filo29/repo$ git log --pretty=oneline
33ce2e95d9c5d6fb0a40e5ee9a2926903646b4e3 add data needed for development
a8af722fccd4206fc3780bd3ede35b2c03886d9b add gif2ascii
84abedc104bbc0c65cb9eb74eb1d3057753e70f8 fix username
9b19e7d8c1aadf4edcc5b15ba8107329ad6c5650 initial commit of README.md
commit 33ce2e95d9c5d6fb0a40e5ee9a2926903646b4e3
Author: Morla Porla <morla@overthewire.org>
Date:   Tue Oct 16 14:00:41 2018 +0200

    add data needed for development

diff --git a/README.md b/README.md
index 1af21d3..39b87a8 100644
--- a/README.md
+++ b/README.md
@@ -4,5 +4,5 @@ Some notes for bandit30 of bandit.
 ## credentials

 - username: bandit30
-- password: <no passwords in production!>
+- password: 5b90576bedb2cc04c86a9e924ce42faf
bandit29@bandit:/tmp/filo29/repo$ cat README.md
# Bandit Notes
Some notes for bandit30 of bandit.

## credentials

- username: bandit30
- password: 5b90576bedb2cc04c86a9e924ce42faf
```

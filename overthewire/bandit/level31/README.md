# BANDIT LEVEL 30 --> LEVEL 31

```
http://overthewire.org/wargames/bandit/bandit31.html
```

### Level Goal

There is a git repository at `ssh://bandit30-git@localhost/home/bandit30-git/repo`.
The password for the user `bandit30-git` is the same as for the user `bandit30`.

Clone the repository and find the password for the next level.

### Commands you may need to solve this level

```
git
```

### SOLUTION

First grab the password we need..

```
bandit30@bandit:~$ cat /etc/bandit_pass/bandit30
5b90576bedb2cc04c86a9e924ce42faf
```

Alright.. let's go create ourselves a temp directory and clone the repository.

```
bandit30@bandit:~$ cd /tmp
bandit30@bandit:/tmp$ mkdir filo30
bandit30@bandit:/tmp$ cd filo30
bandit30@bandit:/tmp/filo30$ git clone ssh://bandit30-git@localhost/home/bandit30-git/repo
Cloning into 'repo'...
Could not create directory '/home/bandit30/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit30/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit30-git@localhost's password:
remote: Counting objects: 4, done.
remote: Total 4 (delta 0), reused 0 (delta 0)
Receiving objects: 100% (4/4), done.
bandit30@bandit:/tmp/filo30/repo$ git log --stat
commit 3aa4c239f729b07deb99a52f125893e162daac9e
Author: Ben Dover <noone@overthewire.org>
Date:   Tue Oct 16 14:00:44 2018 +0200

    initial commit of README.md

 README.md | 1 +
 1 file changed, 1 insertion(+)
bandit30@bandit:/tmp/filo30$ ls
repo
bandit30@bandit:/tmp/filo30$ cd repo/
bandit30@bandit:/tmp/filo30/repo$ ls
README.md
bandit30@bandit:/tmp/filo30/repo$ cat README.md
just an epmty file... muahaha
```

Let's see if there is anything interesting with the branches..

```
bandit30@bandit:/tmp/filo30/repo$ git branch
* master
bandit30@bandit:/tmp/filo30/repo$ git branch -r
  origin/HEAD -> origin/master
  origin/master
```

Nope.

Taking a look at the "tags" in this repository (specific points the developer marked
in the history as being important) we find something weird..

```
bandit30@bandit:/tmp/filo30/repo$ git tag -l
secret
```

Let's see if this is an annotated tag with any interesting information..

```
bandit30@bandit:/tmp/filo30/repo$ git show secret
47e603bb428404d265f59c42920d81e5

```

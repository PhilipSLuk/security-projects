# BANDIT LEVEL 31 --> LEVEL 32

```
http://overthewire.org/wargames/bandit/bandit32.html
```

### Level Goal

There is a git repository at `ssh://bandit31-git@localhost/home/bandit31-git/repo`.
The password for the user `bandit31-git` is the same as for the user `bandit31`.

Clone the repository and find the password for the next level.

### Commands you may need to solve this level

```
git
```

### SOLUTION

First grab the password we need..

```
bandit31@bandit:~$ cat /etc/bandit_pass/bandit31
47e603bb428404d265f59c42920d81e5
```

Alright.. let's go create ourselves a temp directory and clone the repository.

```
bandit31@bandit:~$ cd /tmp
bandit31@bandit:/tmp$ mkdir filo31
bandit31@bandit:/tmp$ cd filo31
bandit31@bandit:/tmp/filo31$ git clone ssh://bandit31-git@localhost/home/bandit31-git/repo
Cloning into 'repo'...
Could not create directory '/home/bandit31/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit31/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit31-git@localhost's password:
remote: Counting objects: 4, done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 4 (delta 0), reused 0 (delta 0)
Receiving objects: 100% (4/4), done.
bandit31@bandit:/tmp/filo31/repo$ git log --pretty=oneline
df6c5eb91615c6dc9c99f99ca5fd79addfe62594 initial commit
bandit31@bandit:/tmp/filo31/repo$ git branch
* master
bandit31@bandit:/tmp/filo31/repo$ git branch -r
  origin/HEAD -> origin/master
  origin/master
bandit31@bandit:/tmp/filo31/repo$ git tag
bandit31@bandit:/tmp/filo31/repo$ cat README.md
This time your task is to push a file to the remote repository.

Details:
    File name: key.txt
    Content: 'May I come in?'
    Branch: master
```

Okay.. so it's asking us to checkin a new file called `key.txt`?

```
bandit31@bandit:/tmp/filo31/repo$ echo "May I come in?" > key.tndit31@bandit:/tmp/filo31/repo$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
nothing to commit, working tree clean
bandit31@bandit:/tmp/filo31/repo$ ls
key.txt  README.md
bandit31@bandit:/tmp/filo31/repo$ git add key.txt
The following paths are ignored by one of your .gitignore files:
key.txt
Use -f if you really want to add them.xt
bandit31@bandit:/tmp/filo31/repo$ cat .gitignore
*.txt
```

Sneaky buggers..

```
bandit31@bandit:/tmp/filo31/repo$ git add key.txt -f
bandit31@bandit:/tmp/filo31/repo$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

    new file:   key.txt

bandit31@bandit:/tmp/filo31/repo$ git commit -m "push key.txt"
[master c2afc0d] push key.txt
 1 file changed, 1 insertion(+)
 create mode 100644 key.txt
bandit31@bandit:/tmp/filo31/repo$ git push
Could not create directory '/home/bandit31/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit31/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit31-git@localhost's password:
Counting objects: 3, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 324 bytes | 0 bytes/s, done.
Total 3 (delta 0), reused 0 (delta 0)
remote: ### Attempting to validate files... ####
remote:
remote: .oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
remote:
remote: Well done! Here is the password for the next level:
remote: 56a9bf19c63d650ce78e6ec0354ee45e
remote:
remote: .oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
remote:
To ssh://localhost/home/bandit31-git/repo
 ! [remote rejected] master -> master (pre-receive hook declined)
error: failed to push some refs to 'ssh://bandit31-git@localhost/home/bandit31-git/repo'
```

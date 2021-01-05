# TRYHACKME: ADVENTOFCYBER2 [DAY 23] BLUE TEAMING - The Grinch strikes again!

```
The mayhem at Best Festival Company continues. McEager receives numerous emails and phone calls about a possible ransomware attack affecting all the endpoints in the network. McEager knows that the endpoints which are infected with the malware don't have any backup copies but luckily on his workstation he has backups enabled.

Task: Investigate the malware and restore the files to their original state.
```

TOPICS: Ransomware, Task Scheduler, Volume Shadow Copy Service (VSS)

### QUESTIONS

Decrypt the fake 'bitcoin address' within the ransom note. What is the plain text value?

```
# Base64 Encoded
bm9tb3JlYmVzdGZlc3RpdmFsY29tcGFueQ==

nomorebestfestivalcompany
```

At times ransomware changes the file extensions of the encrypted files. What is the file extension for each of the encrypted files?

```
.grinch
```

What is the name of the suspicious scheduled task?

```
opidsfsdf
```

Inspect the properties of the scheduled task. What is the location of the executable that is run at login?

```
C:\Users\Administrator\Desktop\opidsfsdf.exe
```

There is another scheduled task that is related to VSS. What is the ShadowCopyVolume ID?

```
7a9eea15-0000-0000-0000-010000000000
```

Assign the hidden partition a letter. What is the name of the hidden folder?

```
confidential
```

Right-click and inspect the properties for the hidden folder. Use the 'Previous Versions' tab to restore the encrypted file that is within this hidden folder to the previous version. What is the password within the file?

```
m33pa55w0rdIZseecure!
```

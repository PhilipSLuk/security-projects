# TRYHACKME: ADVENTOFCYBER2 [DAY 20] BLUE TEAMING - PowershELlF to the rescue

```
Someone is mischievous at The Best Festival Company. The contents within the stockings have been removed. A clue was left in one of the stockings that hints that the contents have been hidden within Elfstation1. McEager moves quickly and attempts to RDP into the machine. Yikes! He is unable to log in.

Luckily, he has been learning PowerShell, and he can remote into the workstation using PowerShell over SSH.

Task: Use the PowerShell console to navigate throughout the endpoint to find the hidden contents to reveal what was hidden in the stockings.
```

TOPICS: PowerShell

```
Get-ChildItem -File -ErrorAction SilentlyContinue
Get-Content -Path file.txt | Measure-Object -Word
Set-Location -Path c:\users\administrator\desktop
Select-String -Path c:\users\administrator\desktop' -Pattern '*.pdf'
Get-Help Select-String
```

### QUESTIONS

Search for the first hidden elf file within the Documents folder. Read the contents of this file. What does Elf 1 want?

```
PS C:\Users\mceager> Get-ChildItem -Path Documents -Hidden


    Directory: C:\Users\mceager\Documents


Mode                LastWriteTime         Length Name
----                -------------         ------ ----                                                    
d--hsl        12/7/2020  10:28 AM                My Music
d--hsl        12/7/2020  10:28 AM                My Pictures
d--hsl        12/7/2020  10:28 AM                My Videos
-a-hs-        12/7/2020  10:29 AM            402 desktop.ini                                             
-arh--       11/18/2020   5:05 PM             35 e1fone.txt

PS C:\Users\mceager\Documents> Get-Content e1fone.txt
All I want is my '2 front teeth'!!! 
```

Search on the desktop for a hidden folder that contains the file for Elf 2. Read the contents of this file. What is the name of that movie that Elf 2 wants?

```
PS C:\Users\mceager\Desktop> Get-ChildItem -Directory -Hidden


    Directory: C:\Users\mceager\Desktop


Mode                LastWriteTime         Length Name
----                -------------         ------ ----
d--h--        12/7/2020  11:26 AM                elf2wo

PS C:\Users\mceager\Desktop> cd elf2wo
PS C:\Users\mceager\Desktop\elf2wo> dir


    Directory: C:\Users\mceager\Desktop\elf2wo


Mode                LastWriteTime         Length Name
----                -------------         ------ ----
-a----       11/17/2020  10:26 AM             64 e70smsW10Y4k.txt


PS C:\Users\mceager\Desktop\elf2wo> Get-Content e70smsW10Y4k.txt
I want the movie Scrooged <3! 
```

Search the Windows directory for a hidden folder that contains files for Elf 3. What is the name of the hidden folder? (This command will take a while)

```
PS C:\Windows> Get-ChildItem -Directory -Hidden -Path C:\Windows -Recurse -ErrorAction SilentlyContinue -F
ilter '*3*'


    Directory: C:\Windows\System32


Mode                LastWriteTime         Length Name
----                -------------         ------ ----
d--h--       11/23/2020   3:26 PM                3lfthr3e
```

How many words does the first file contain?

```
PS C:\Windows\system32\3lfthr3e> Get-ChildItem -Hidden


    Directory: C:\Windows\system32\3lfthr3e


Mode                LastWriteTime         Length Name
----                -------------         ------ ----
-arh--       11/17/2020  10:58 AM          85887 1.txt
-arh--       11/23/2020   3:26 PM       12061168 2.txt

PS C:\Windows\system32\3lfthr3e> Get-Content .\1.txt | Measure-Object -Word

Lines Words Characters Property 
----- ----- ---------- --------
       9999

```

What 2 words are at index 551 and 6991 in the first file?

```
PS C:\Windows\system32\3lfthr3e> (Get-Content -Path .\1.txt)[551,6991]
Red 
Ryder 
```

This is only half the answer. Search in the 2nd file for the phrase from the previous question to get the full answer. What does Elf 3 want? (use spaces when submitting the answer)

```
PS C:\Windows\system32\3lfthr3e> Select-String -Path .\2.txt -Pattern 'Ryder'

2.txt:558704:redryderbbgun 
```

# TRYHACKME: ADVENTOFCYBER2 [DAY 21] BLUE TEAMING - Time for some ELForensics

```
One of the 'little helpers' logged into his workstation only to realize that the database connector file has been replaced, and he can't find the naughty list anymore. Furthermore, upon executing the database connector file, a taunting message was displayed, hinting that the file was moved to another location.

McEager has been notified, and he will put the pieces together to find the database connector file.
```

TOPICS: PowerShell, File Hash, Strings.exe, NTFS Alternate Data Streams, Windows Management Instrumentation (wmic)

```
Get-FileHash -Algorithm MD5 file.txt
Get-Item -Path file.exe -Stream *
```

### QUESTIONS

Read the contents of the text file within the Documents folder. What is the file hash for db.exe?

```
PS C:\Users\littlehelper\Documents> type '.\db file hash.txt'
Filename:       db.exe
MD5 Hash:       596690FFC54AB6101932856E6A78E3A1
```

What is the file hash of the mysterious executable within the Documents folder?

```
PS C:\Users\littlehelper\Documents> Get-FileHash -Algorithm MD5 .\deebee.exe

Algorithm       Hash                                                                   Path
---------       ----                                                                   ----
MD5             5F037501FB542AD2D9B06EB12AED09F0                                       C:\Users\littlehelper\Documen...
```

Using Strings find the hidden flag within the executable?

```
PS C:\Users\littlehelper\Documents> C:\Tools\Strings64.exe '.\deebee.exe'

THM{f6187e6cbeb1214139ef313e108cb6f9}
```

What is the flag that is displayed when you run the database connector file?

```
PS C:\Users\littlehelper\Documents> Get-Item -Path .\deebee.exe -Stream *


PSPath        : Microsoft.PowerShell.Core\FileSystem::C:\Users\littlehelper\Documents\deebee.exe::$DATA
PSParentPath  : Microsoft.PowerShell.Core\FileSystem::C:\Users\littlehelper\Documents
PSChildName   : deebee.exe::$DATA
PSDrive       : C
PSProvider    : Microsoft.PowerShell.Core\FileSystem
PSIsContainer : False
FileName      : C:\Users\littlehelper\Documents\deebee.exe
Stream        : :$DATA
Length        : 5632

PSPath        : Microsoft.PowerShell.Core\FileSystem::C:\Users\littlehelper\Documents\deebee.exe:hidedb
PSParentPath  : Microsoft.PowerShell.Core\FileSystem::C:\Users\littlehelper\Documents
PSChildName   : deebee.exe:hidedb
PSDrive       : C
PSProvider    : Microsoft.PowerShell.Core\FileSystem
PSIsContainer : False
FileName      : C:\Users\littlehelper\Documents\deebee.exe
Stream        : hidedb
Length        : 6144

PS C:\Users\littlehelper\Documents> wmic process call create $(Resolve-Path ./deebee.exe:hidedb)
Executing (Win32_Process)->Create()
Method execution successful.
Out Parameters:
instance of __PARAMETERS
{
        ProcessId = 3340;
        ReturnValue = 0;
};

Choose an option:
1) Nice List
2) Naughty List
3) Exit

THM{088731ddc7b9fdeccaed982b07c297c}

Select an option:
```


# REVERSING CHALLENGE: IMPOSSIBLE PASSWORD

## Challenge Description
Are you able to cheat me and get the flag?

```
impossible_password.bin
```

### FILE

```
$ file impossible_password.bin 
impossible_password.bin: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 2.6.32, BuildID[sha1]=ba116ba1912a8c3779ddeb579404e2fdf34b1568, stripped
```

Looks like it is a Linux executable. I wonder if that `BuildID` will play a
role later......


### EXECUTION - TEST

```
$ chmod +x impossible_password.bin 
fortyfunbobby@kali:~/Development/impossible$ ./impossible_password.bin 
* test
[test]
```

Some simple experimentation appears to show the program takes in an input and
outputs back the same input in square parenthesis? I'm guessing there is a
passphrase that will generate a unique response that we need to discover.

### GDB

I wonder this was compiled with debug flag.. as that would give us an easy way
to analyze the program..

```
$ gdb impossible_password.bin
GNU gdb (Debian 7.12-6+b1) 7.12.0.20161007-git
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from impossible_password.bin...(no debugging symbols found)...done.
(gdb) 

```

.. Nope.

### STRING ANALYSIS

```
$ strings impossible_password.bin
<...>
UH-x
[]A\A]A^A_
SuperSeKretKey
%20s
[%s]
<...>
```

Neat, we found something that looks promising..

### EXECUTION - STAGE 1

Trying the passphrase we found in string analysis, we seem to get to a second
stage where another passphrase is required.

```
$ ./impossible_password.bin 
* SuperSeKretKey
[SuperSeKretKey]
** test
```

### BINARY REVERSE ENGINEERING

Read up a bit on binary reverse engineering techniques from here that served
as a guide for the next few things I tried..

```
http://manoharvanga.com/hackme/
```

### READELF

Using `readelf` allows us to see what the entry point of the executable is
which will be useful in helping us get a landmark if we need to read the
assembly..

```
$ readelf -h impossible_password.bin
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x4006a0
  Start of program headers:          64 (bytes into file)
  Start of section headers:          4512 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         9
  Size of section headers:           64 (bytes)
  Number of section headers:         28
  Section header string table index: 27
```

### STRACE

Tried using `strace` to trace system calls and signals to see if I could get
any additional information..

```
$ strace ./impossible_password.bin 
execve("./impossible_password.bin", ["./impossible_password.bin"], 0x7ffe362759d0 /* 43 vars */) = 0
brk(NULL)                               = 0x8ac000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f5c8ce20000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=183949, ...}) = 0
mmap(NULL, 183949, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f5c8cdf3000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\4\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=1681176, ...}) = 0
mmap(NULL, 3787104, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f5c8c863000
mprotect(0x7f5c8c9f6000, 2097152, PROT_NONE) = 0
mmap(0x7f5c8cbf6000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x193000) = 0x7f5c8cbf6000
mmap(0x7f5c8cbfc000, 14688, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f5c8cbfc000
close(3)                                = 0
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f5c8cdf1000
arch_prctl(ARCH_SET_FS, 0x7f5c8cdf1700) = 0
mprotect(0x7f5c8cbf6000, 16384, PROT_READ) = 0
mprotect(0x600000, 4096, PROT_READ)     = 0
mprotect(0x7f5c8ce23000, 4096, PROT_READ) = 0
munmap(0x7f5c8cdf3000, 183949)          = 0
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 0), ...}) = 0
brk(NULL)                               = 0x8ac000
brk(0x8cd000)                           = 0x8cd000
fstat(0, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 0), ...}) = 0
write(1, "* ", 2* )                       = 2
read(0, SuperSeKretKey
"SuperSeKretKey\n", 1024)       = 15
write(1, "[SuperSeKretKey]\n", 17[SuperSeKretKey]
)      = 17
write(1, "** ", 3** )                      = 3
read(0, SuperSeKretKey
"SuperSeKretKey\n", 1024)       = 15
lseek(0, -1, SEEK_CUR)                  = -1 ESPIPE (Illegal seek)
exit_group(38)                          = ?
+++ exited with 38 +++
```

.. but not sure what I am seeing here is all that useful.

### LTRACE

Tried `ltrace` to trace library calls and we find that the second stage seems
to do a `strcmp()` against a value generated by `srand()`?!?!

```
$ ltrace ./impossible_password.bin  
__libc_start_main(0x40085d, 1, 0x7fff2018e958, 0x4009e0 <unfinished ...>
printf("* ")                                                                    = 2
__isoc99_scanf(0x400a82, 0x7fff2018e850, 0x7fcd60cc3760, 0xfbad2a84* SuperSeKretKey
)            = 1
printf("[%s]\n", "SuperSeKretKey"[SuperSeKretKey]
)                                              = 17
strcmp("SuperSeKretKey", "SuperSeKretKey")                                      = 0
printf("** ")                                                                   = 3
__isoc99_scanf(0x400a82, 0x7fff2018e850, 0x7fcd60cc3760, 8234** SuperSeKretKey
)                  = 1
time(0)                                                                         = 1512574089
srand(0xc9ea1c5, 1, 0xb20fab4, 0)                                               = 0
malloc(21)                                                                      = 0x2283830
rand(4, 0x2283840, 0x2283830, 0x7fcd60cc1b00)                                   = 0x50c830a4
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283830, 94)                             = 0x278e9f93
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283831, 94)                             = 0x61435628
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283832, 94)                             = 0x3d88dd80
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283833, 94)                             = 0x3de54220
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283834, 94)                             = 0x2caa25b8
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283835, 94)                             = 0x3264fa33
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283836, 94)                             = 0x7667bcf5
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283837, 94)                             = 0x51635263
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283838, 94)                             = 0x2a0e5f6b
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283839, 94)                             = 0x438daef2
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x228383a, 94)                             = 0x78ed3335
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x228383b, 94)                             = 0x2e31c947
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x228383c, 94)                             = 0x757d0ee9
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x228383d, 94)                             = 0x4f12ab4
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x228383e, 94)                             = 0x453713ce
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x228383f, 94)                             = 0x66361b2e
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283840, 94)                             = 0x6ac0996e
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283841, 94)                             = 0x3cf45435
rand(0x7fcd60cc1600, 0x7fff2018e7bc, 0x2283842, 94)                             = 0x6ab8a3e6
strcmp("SuperSeKretKey", "MZSW75Zp&JsFR$SySs@q")                                = 6
+++ exited (status 6) +++
```

### OBJECT DISASSEMBLY

```
$ objdump -D ./impossible_password.bin > out.asm
```

We need to identify the part of the program that deals with the second secret
phrase. From our tests so far, I know that the prompt for the second pass phrase
is "**" which in hexidecimal is `0x2A 0x2A`.

```
$ grep "2a 2a" out.asm 
  400a8d:	2a 2a                	sub    (%rdx),%ch
```

So we see the address of this string is `400a8d` which is stored in the
`.rodata` section. We'll search for this address to see where it is used in the
code in a minute. Let's look for other landmarks in the code to help us get
our bearings..

Looking for `[` (0x5b) as a clue from the first pass phrase as well yields..

```
  400a87:       5b                      pop    %rbx
```

Looking for the first passphrase SuperSeKretKey (0x53 0x75 0x70 0x65 0x72 0x53
0x65 0x4b 0x72 0x65 0x74 0x4b 0x65 0x79)..

```
  400a70:       53                      push   %rbx
  400a71:       75 70                   jne    400ae3 <rand@plt+0x453>
  400a73:       65 72 53                gs jb  400ac9 <rand@plt+0x439>
  400a76:       65 4b 72 65             gs rex.WXB jb 400adf <rand@plt+0x44f>
  400a7a:       74 4b                   je     400ac7 <rand@plt+0x437>
  400a7c:       65 79 00                gs jns 400a7f <rand@plt+0x3ef>

```

Now going back to the disassembly to annonate with these landmarks in mind..

```
  4008c0:       c6 45 d3 74             movb   $0x74,-0x2d(%rbp)
# print of first passphrase prompt "*"
  4008c4:       bf 7f 0a 40 00          mov    $0x400a7f,%edi
  4008c9:       b8 00 00 00 00          mov    $0x0,%eax
  4008ce:       e8 2d fd ff ff          callq  400600 <printf@plt>
  4008d3:       48 8d 45 e0             lea    -0x20(%rbp),%rax
  4008d7:       48 89 c6                mov    %rax,%rsi
  4008da:       bf 82 0a 40 00          mov    $0x400a82,%edi
  4008df:       b8 00 00 00 00          mov    $0x0,%eax
  4008e4:       e8 87 fd ff ff          callq  400670 <__isoc99_scanf@plt>
  4008e9:       48 8d 45 e0             lea    -0x20(%rbp),%rax
  4008ed:       48 89 c6                mov    %rax,%rsi
# print of "[%s]" to output user response
  4008f0:       bf 87 0a 40 00          mov    $0x400a87,%edi
  4008f5:       b8 00 00 00 00          mov    $0x0,%eax
  4008fa:       e8 01 fd ff ff          callq  400600 <printf@plt>
  4008ff:       48 8b 55 f8             mov    -0x8(%rbp),%rdx
  400903:       48 8d 45 e0             lea    -0x20(%rbp),%rax
# strcmp of first passphrase prompt
  400907:       48 89 d6                mov    %rdx,%rsi
  40090a:       48 89 c7                mov    %rax,%rdi
  40090d:       e8 1e fd ff ff          callq  400630 <strcmp@plt>
  400912:       89 45 f4                mov    %eax,-0xc(%rbp)
  400915:       83 7d f4 00             cmpl   $0x0,-0xc(%rbp)
# if equal comparison (jump to 400925 if equal)
  400919:       74 0a                   je     400925 <rand@plt+0x295>
  40091b:       bf 01 00 00 00          mov    $0x1,%edi
# TERMINATE PROGRAM (if equal comparison failed above)
  400920:       e8 5b fd ff ff          callq  400680 <exit@plt>
# print of second passphrase prompt "**"
  400925:       bf 8d 0a 40 00          mov    $0x400a8d,%edi
  40092a:       b8 00 00 00 00          mov    $0x0,%eax
  40092f:       e8 cc fc ff ff          callq  400600 <printf@plt>
  400934:       48 8d 45 e0             lea    -0x20(%rbp),%rax
  400938:       48 89 c6                mov    %rax,%rsi
  40093b:       bf 82 0a 40 00          mov    $0x400a82,%edi
  400940:       b8 00 00 00 00          mov    $0x0,%eax
# scanf of second passphrase from user 
  400945:       e8 26 fd ff ff          callq  400670 <__isoc99_scanf@plt>
  40094a:       bf 14 00 00 00          mov    $0x14,%edi
# call to rand() to generate second passphrase??
  40094f:       e8 39 fe ff ff          callq  40078d <rand@plt+0xfd>
  400954:       48 89 c2                mov    %rax,%rdx
  400957:       48 8d 45 e0             lea    -0x20(%rbp),%rax
  40095b:       48 89 d6                mov    %rdx,%rsi
  40095e:       48 89 c7                mov    %rax,%rdi
# strcmp of second passphrase attempt
  400961:       e8 ca fc ff ff          callq  400630 <strcmp@plt>
  400966:       85 c0                   test   %eax,%eax
# if not equal comparison (jump to 400976 if not equal)
  400968:       75 0c                   jne    400976 <rand@plt+0x2e6>
  40096a:       48 8d 45 c0             lea    -0x40(%rbp),%rax
  40096e:       48 89 c7                mov    %rax,%rdi
# looks like this function at 0x0400978 is called if correct passphrase?
  400971:       e8 02 00 00 00          callq  400978 <rand@plt+0x2e8>
# GOTO: if not equal lands here..
  400976:       c9                      leaveq 
  400977:       c3                      retq   
```

Okay, so after all that, I can sort of see how the first passphrase
SuperSeKretKey is compared against the user response and then the second
passphrase. I guess if I was smart (and patient enough), I could sit here and
try and trace the program flow after a correct response to see what is next..

### LD_PRELOAD

Found a neat technique to try after reading this posting on overriding library
calls - namely, what if I could override the lib.c version of `strcmp()` to
something that always returned true?

```
http://www.thegeekstuff.com/2012/03/reverse-engineering-tools/?utm_source=feedburner
```

First we need to write up a simple `strcmp()` function that always returns true.

```
$ cat mylibrary.c 
/*****************************************************************************
 * File:    mylibrary.c
 * Purpose: our own library to intercept the strcmp() library function to
 *          one that always returns true!
 * Date:    December 6, 2017
 * Author:  fortyfunbobby
 *****************************************************************************/

#include <stdio.h>
int strcmp(const char *s1, const char *s2) {
  /* always return 0 */
  return 0;
}
$ gcc -o mylib.so -shared mylibrary.c -ldl
```

Now let's execute the program with our new `strcmp()` function..

```
$ LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
$ LD_PRELOAD=./mylib.so ./impossible_password.bin 
* test
[test]
** test
HTB{40b949f92b86b18}
```

Neat! We see the `strcmp()` is always returning true since even using the wrong
passphrase "test" as our first input instead of "SuperSeKretKey" gets us past
the first gate!

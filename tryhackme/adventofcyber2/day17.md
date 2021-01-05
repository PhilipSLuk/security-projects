# TRYHACKME: ADVENTOFCYBER2 [DAY 17] REVERSE ENGINEERING - ReverseELFneering

```
McSkidy has never really touched low-level languages - this is something they must learn in their quest to defeat the Christmas monster.
```

TOPICS: Reverse Engineering, radare2

```
r2 -d <exe>
aa: analyze
afl: function list
pdf @<func>: display function
db <addr>: debug break
dc: debug run
ds: debug step
dr: examine registers
px @<addr>: examine memory
ood: reload program
```

### QUESTIONS


What is the value of local_ch when its corresponding movl instruction is called (first if multiple)?

```
0x00400b51 b    c745f4010000.  mov dword [local_ch], 1
```

What is the value of eax when the imull instruction is called?

```
[0x00400b51]> dr
rax = 0x00000006
```

What is the value of local_4h before eax is set to 0?

```
[0x00400b51]> px @rbp-0x4
- offset -       0 1  2 3  4 5  6 7  8 9  A B  C D  E F  0123456789ABCDEF
0x7ffda3ff35ec  0600 0000 4018 4000 0000 0000 e910 4000  ....@.@.......@.
```

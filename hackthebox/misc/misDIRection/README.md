# MISC CHALLENGE: MISDIRECTION

## Challenge Description
During an assessment of a unix system the HTB team found a suspicious
directory. They looked at everything within but couldn't find any files with
malicious intent. 

```
$ ls .secret/
0  2  4  6  8  A  c  e  g  i  k  m  o  q  S  U  W  y
1  3  5  7  9  B  d  F  H  j  l  N  P  r  t  V  X  z
```

### FIND

So what we have is a bunch of directories that map to the letters of the
alphabet - upper and lower case - and the digits.. and some of the directories
have numeric empty files.

```
$ find .secret/
.secret/
.secret/r/7
.secret/r/3
.secret/U/20
.secret/U/9
.secret/U/28
.secret/9/36
.secret/0/6
.secret/7
.secret/i
.secret/N/33
.secret/N/11
.secret/N/31
.secret/N/25
.secret/g
.secret/6
.secret/z/18
.secret/1/30
.secret/1/22
.secret/8
.secret/t
.secret/S/1
.secret/S/24
.secret/A
.secret/F/27
.secret/F/19
.secret/F/2
.secret/o
.secret/H
.secret/m
.secret/j/10
.secret/j/8
.secret/j/12
.secret/c/4
.secret/d/26
.secret/d/13
.secret/V/35
.secret/q
.secret/4
.secret/X/29
.secret/X/17
.secret/X/21
.secret/X/15
.secret/3
.secret/e/5
.secret/e/14
.secret/B/23
.secret/k
.secret/l
.secret/2/34
.secret/y
.secret/5/16
.secret/P/32
.secret/W
```

Hm.. the numbers map to a code of some sort?

### SORT

My initial instinct is to take the files within the directories to be some sort
of order of the letters to perhaps arrange them into a code.  We can use the
following command to get our sequence..

```
$ find .secret | grep '/.*/.*[0-9]$' | sort -t / -nk3 | cut -f 2 -d '/'
```

That command gives us the following ordering of the directories..

```
SFrce0rjUjNjdeX5XzFUX1BSNdFUX1NPN2V9
```

If we decode this string as a `base64` string, we get something almost like a
flag format.. but not quite..

```
$ echo SFrce0rjUjNjdeX5XzFUX1BSNdFUX1NPN2V9 | base64 -d
HZ?{J?R3cu??_1T_PR5?T_SO7e}
```

### UPPER AND LOWER CASE?

Going back to the original zip file we had, I noticed that there are upper and
lower case letters..

```
$ unzip -l misDIRection.zip | grep U
        0  2018-05-02 12:03   .secret/U/
        0  2018-05-02 12:03   .secret/U/9
$ unzip -l misDIRection.zip | grep u
        0  2018-05-02 12:03   .secret/u/
        0  2018-05-02 12:03   .secret/u/20
        0  2018-05-02 12:03   .secret/u/28
```

.. but when I unzipped, all the case distinction was lost?!

```
$ ls .secret/U
20  28  9
```

I guess the "misDIRection" was a hint towards Windows `DIR` where files are
case insensitive.

While I could try and figure out how to preserve the casing with my unzip,
instead I could just work off of the `unzip -l` output..

```
$ unzip -l misDIRection.zip | grep '/.*/.*[0-9]$' | sort -t / -nk3 | cut -f 2 -d '/'
```

Now I get a slightly different sequence of letters..

```
SFRCe0RJUjNjdEx5XzFuX1BsNDFuX1NpN2V9
```

Decoding this finally gets us the flag..

```
$ echo SFRCe0RJUjNjdEx5XzFuX1BsNDFuX1NpN2V9 | base64 -d
HTB{DIR3ctLy_1n_Pl41n_Si7e}
```

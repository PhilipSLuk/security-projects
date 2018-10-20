# BANDIT LEVEL 12 --> LEVEL 13

```
http://overthewire.org/wargames/bandit/bandit13.html
```

### Level Goal

The password for the next level is stored in the file `data.txt`, which is a `hexdump` of a
file that has been repeatedly compressed. For this level it may be useful to create a
directory under `/tmp` in which you can work using `mkdir`.
For example: `mkdir /tmp/myname123`. Then copy the datafile using `cp`, and rename it using
`mv` (read the manpages!)

### Commands you may need to solve this level

```
grep, sort, uniq, strings, base64, tr, tar, gzip, bzip2, xxd, mkdir, cp, mv
```

### Helpful Reading Material

- Hex dump on Wikipedia

### SOLUTION

```
$ scp -P 2220 bandit12@bandit.labs.overthewire.org:/home/bandit12/data.txt .
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit12@bandit.labs.overthewire.org's password:
data.txt                                                   100% 2581    12.2KB/s   00:00
$ cat data.txt | xxd -r > out
$ file out
out: gzip compressed data, was "data2.bin", last modified: Tue Oct 16 12:00:23 2018, max compression, from Unix, original size 572
$ mv out out.gz
$ gunzip out.gz
$ file out
out: bzip2 compressed data, block size = 900k
$ mv out out.bz2
$ bzip2 -d out.bz2
$ file out
out: gzip compressed data, was "data4.bin", last modified: Tue Oct 16 12:00:23 2018, max compression, from Unix, original size 20480
$ mv out out.gz
$ gunzip out.gz
$ file out
out: POSIX tar archive (GNU)
$ mv out out.tar
$ tar -xvf out.tar
data5.bin
$ file data5.bin
data5.bin: POSIX tar archive (GNU)
$ tar -xvf data5.bin
data6.bin
$ file data6.bin
data6.bin: bzip2 compressed data, block size = 900k
 bzip2 -d data6.bin
bzip2: Can't guess original name for data6.bin -- using data6.bin.out
$ file data6.bin.out
data6.bin.out: POSIX tar archive (GNU)
$ tar -xvf data6.bin.out
data8.bin
$ file data8.bin
data8.bin: gzip compressed data, was "data9.bin", last modified: Tue Oct 16 12:00:23 2018, max compression, from Unix, original size 49
$ mv data8.bin data8.bin.gz
$ gunzip data8.bin.gz
$ file data8.bin
$ data8.bin: ASCII text
 cat data8.bin
The password is 8ZjyCRiBWFYkneahHwxCv3wb2a1ORpYL
```

# STEGO CHALLENGE: BEATLES

## Challenge Description
John Lennon send a secret message to Paul McCartney about the next music tour
of Beatles... Could you find the message and sumbit the flag? 

```
BAND.zip
```
```
$ unzip -l BAND.zip 
Archive:  BAND.zip
  Length      Date    Time    Name
---------  ---------- -----   ----
    77643  09-24-2017 07:15   BAND.JPG
---------                     -------
    77643                     1 file
```

```
m3ss\@g#_f0r_pAuL 
```

```
$ cat m3ss\@g#_f0r_pAuL 
Url Cnhy,

Zl Sbyqre unf cnffcuenfr jvgu sbhe (4) punenpgref.

Pbhyq lbh spenpx vg sbe zr???

V fraq lbh n zrffntr sbe bhe Gbhe arkg zbagu...

Qba'g Funer vg jvgu bgure zrzoref bs bhe onaq...

-Wbua Yraaba


CF: Crnpr naq Ybir zl sevraq... Orngyrf Onaq sbe rire!
```

### DECIPHERING

Looking at the coded message, we can make some guesses. We are told it is a 
letter from John Lennon to Paul McCartney, so we can make the following 
substitutions..

```
-Wbua Yraaba
-JOHN LENNON
```

With further educated guesses, we end up with the following decryption..

```
Url Cnhy,
HEY PAUL

Zl Sbyqre unf cnffcuenfr jvgu sbhe (4) punenpgref.
MY FOLDER HAS PASSPHRASE WITH FOUR (4) CHARACTERS.

Pbhyq lbh spenpx vg sbe zr???
COULD YOU FCRACK IT FOR ME???

V fraq lbh n zrffntr sbe bhe Gbhe arkg zbagu...
I SEND YOU A MESSAGE FOR OUR TOUR NEXT MONTH

Qba'g Funer vg jvgu bgure zrzoref bs bhe onaq...
DON'T SHARE IT WITH OTHER MEMBERS OF OUR BAND...

-Wbua Yraaba
-JOHN LENNON

CF: Crnpr naq Ybir zl sevraq... Orngyrf Onaq sbe rire!
PS: PEACE AND LOVE MY FRIEND... BEATLES BAND FOR EVER!
```

### FCRACKZIP

Let's resort to cracking the zip file using `fcrackzip` (as per John's letter)..

```
$ fcrackzip -u -D -p /usr/share/wordlists/rockyou.txt BAND.zip 


PASSWORD FOUND!!!!: pw == pass
```

Great.. it's a four character passphrase just like John said. Now let's see
what `BAND.JPG` is..

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/beatles/BAND.JPG" width=200px/>

### STRING ANALYSIS

Simple string analysis seems to yield a code..

```
$ strings BAND.JPG | tail -3
QIK@
QIK@
VkhKNUlFaGhjbVJsY2lFPQ==
```

```
$ echo "VkhKNUlFaGhjbVJsY2lFPQ==" | base64 --d | base64 --d
Try Harder!
```

Okay.. boo, we just got trolled.

### FILTERS

```
https://29a.ch/photo-forensics/
```

Standard filters doesn't yield anything interesting.

### STEGHIDE

What if there is another four "character" password.. like LITERALLY four
CHARACTERS as the four figures in the image appear to be forming letters..

Let's see if we can brute force our way through `steghide` with "TY??"..

```
$ steghide extract -sf BAND.jpg -p TY??
```

Tried downloading a steghide brute forcing tool `steg_brute` to iterate through
common word lists and even tried a custom word list based on the assumption
that the password is something like "TYxx" to no avail.

```
git clone https://github.com/Va5c0/Steghide-Brute-Force-Tool.git
$ python steg_brute.py -b -d /usr/share/wordlists/wfuzz/general/common.txt -f BAND.JPG
```

Then staring at the image a bit more, I thought.. what if the password is just
written in plain sight in front of me...

```
$ steghide extract -sf BAND.JPG -p THEBEATLES
wrote extracted data to "testabeatle.out".
```

* slaps * forehead *

### EXECUTABLE

What we find is an executable named `testabeatle.out`..

```
$ file testabeatle.out 
testabeatle.out: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 2.6.32, BuildID[sha1]=ca68ea305ff7d393662ef8ce4e5eed0b478c8b4e, not stripped
$ chmod +x testabeatle.out 
```

Using `strings` command, we could've harvested the encoded string, but we play
along with the game just for fun.

```
$ ./testabeatle.out 
Hey Paul! If you are here... Give my your favourite character!

Ok Paul... A little challenge for you mate, cause last month someone crazy man hacked...WTF! Let's Begin!
########################################Challenge############################################################
Tell me PAul! The result of  5+5?
10
Ok!ok! it was easy... Tell me now... The result of: 5+5-5*(5/5)?
5
Last one! The result of: (2.5*16.8+1.25*10.2+40*0.65+1.5*7.5+1.25*3.2):40
2.4
Hey Paul! nice!!! this is  the message
VGhlIHRvdXIgd2FzIGNhbmNlbGVkIGZvciB0aGUgZm9sbG93aW5nIG1vbnRoLi4uIQ0KDQpJJ2xsIGdvIG91dCBmb3IgZGlubmVyIHdpdGggbXkgZ2lybGZyaWVuZCBuYW1lZCBZb2NvISA7KQ0KDQpIVEJ7UzByUnlfTXlfRlIxM25EfQ0K
########################################END OF CHALLENGE############################################################
```

So we now have to go decode that message, but just for fun.. let's try giving
some wrong answers to see what would've happened..

```
$ ./testabeatle.out 
Hey Paul! If you are here... Give my your favourite character!

Ok Paul... A little challenge for you mate, cause last month someone crazy man hacked...WTF! Let's Begin!
########################################Challenge############################################################
Tell me PAul! The result of  5+5?
10000!    
WTF! You are not Paul!! SOS SOS SOS HACKER HERE!! I will call the police someone want to steal my data!!!
########################################END OF CHALLENGE############################################################
```

Neato..

### BASE64

Okay.. final step is to decode this string and see what we got! (trying base64
first before attempting others like MD5, etc..)

```
$ echo "VGhlIHRvdXIgd2FzIGNhbmNlbGVkIGZvciB0aGUgZm9sbG93aW5nIG1vbnRoLi4uIQ0KDQpJJ2xsIGdvIG91dCBmb3IgZGlubmVyIHdpdGggbXkgZ2lybGZyaWVuZCBuYW1lZCBZb2NvISA7KQ0KDQpIVEJ7UzByUnlfTXlfRlIxM25EfQ0K" | base64 -d
The tour was canceled for the following month...!

I'll go out for dinner with my girlfriend named Yoco! ;)

HTB{S0rRy_My_FR13nD}
```

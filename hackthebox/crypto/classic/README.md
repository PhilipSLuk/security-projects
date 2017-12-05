# CRYPTO CHALLENGE: CLASSIC, YET COMPLICATED

## Challenge Description
Find the plaintext, the key is your flag! Flag format: HTB{key in lowercase}

```
$ cat ciphertext.txt 
alp gwcsepul gtavaf, nlv prgpbpsu mb h jcpbyvdlq, ipltga rv glniypfa we ekl 16xs nsjhlcb. px td o lccjdstslpahzn fptspf xstlxzi te iosj ezv sc xcns ttsoic lzlvrmhaw ez sjqijsa xsp rwhr. tq vxspf sciov, alp wsphvcv pr ess rwxpqlvp nwlvvc dyi dswbhvo ef htqtafvyw hqzfbpg, ezutewwm zcep xzmyr o scio ry tscoos rd woi pyqnmgelvr vpm . qbctnl xsp akbflowllmspwt nlwlpcg, lccjdstslpahzn fptspfo oip qvx dfgysgelipp ec bfvbxlrnj ojocjvpw, ld akfv ekhr zys hskehy my eva dclluxpih yoe mh yiacsoseehk fj l gebxwh sieesn we ekl iynfudktru. xsp yam zd woi qwoc.
```

### VIGENERE CIPHER

If the `key` is our flag, that seems to imply a Vigenere Cipher..

```
The Vigenère cipher is a method of encrypting alphabetic text by using a series of interwoven Caesar ciphers based on the letters of a keyword.

(reference: https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
```

Searching for online tools to help with the analysis, found this one that did
some sort of probability analysis on the length of the key:

```
https://f00l.de/hacking/vigenere.php
```

```
Checking key length of  2: min   1, max  30 (  3.33 % ) --> 13.45 -  0.45 = 13.00 %
Checking key length of  3: min   1, max  12 (  8.33 % ) -->  8.07 -  0.67 =  7.40 %
Checking key length of  4: min   1, max  14 (  7.14 % ) --> 12.56 -  0.90 = 11.66 %
Checking key length of  5: min   1, max  12 (  8.33 % ) --> 13.45 -  1.12 = 12.33 %
Checking key length of  6: min   1, max  10 ( 10.00 % ) --> 13.45 -  1.35 = 12.11 %
Checking key length of  7: min   1, max   8 ( 12.50 % ) --> 12.56 -  1.57 = 10.99 %
Checking key length of  8: min   1, max   7 ( 14.29 % ) --> 12.56 -  1.79 = 10.76 %
Checking key length of  9: min   1, max   4 ( 25.00 % ) -->  8.07 -  2.02 =  6.05 %
Checking key length of 10: min   1, max   6 ( 16.67 % ) --> 13.45 -  2.24 = 11.21 %
Checking key length of 11: min   1, max   3 ( 33.33 % ) -->  7.40 -  2.47 =  4.93 %
Checking key length of 12: min   1, max   5 ( 20.00 % ) --> 13.45 -  2.69 = 10.76 %
Checking key length of 13: min   1, max   4 ( 25.00 % ) --> 11.66 -  2.91 =  8.74 %
Checking key length of 14: min   1, max   5 ( 20.00 % ) --> 15.70 -  3.14 = 12.56 %
Checking key length of 15: min   1, max   5 ( 20.00 % ) --> 16.82 -  3.36 = 13.45 %
Checking key length of 16: min   1, max   5 ( 20.00 % ) --> 17.94 -  3.59 = 14.35 %
Checking key length of 17: min   1, max   3 ( 33.33 % ) --> 11.43 -  3.81 =  7.62 %
Checking key length of 18: min   1, max   4 ( 25.00 % ) --> 16.14 -  4.04 = 12.11 %
Checking key length of 19: min   1, max   3 ( 33.33 % ) --> 12.78 -  4.26 =  8.52 %
Checking key length of 20: min   1, max   4 ( 25.00 % ) --> 17.94 -  4.48 = 13.45 %
```

It seemed to imply that a key length of 11, 17 or 19 was the most likely, but
attempting to use that tool to try and crack the key didn't go anywhere.

Found this other online tool that allowed you to enter an assumed key length
and it would list probable keys based on frequency analysis of cipher text.

```
http://www.mygeocachingprofile.com/codebreaker.vigenerecipher.aspx
```

Using the assumed key length of 11, 17 or 19 didn't lead any where, but when I
tried key length of 10 it found a plausible sounding key:

```
Key size = 10

Here is a list of the most probable keys based on frequency analysis of the letters in the cipher:

Key #1: helloworld
Key #2: helloworlh
Key #3: helloworad
Key #4: helloworah
Key #5: hellowocld
Key #6: hellowoclh
Key #7: hellowocad
Key #8: hellowocah
Key #9: hellowzrld
Key #10: hellowzrlh
```

Trying `helloworld` as the cipher key unlocked the text!

```
-- MESSAGE w/Key #1 = 'helloworld' ----------------
the vigenere cipher, was invented by a frenchman, blaise de vigenere in the 16th century. it is a polyalphabetic cipher because it uses two or more cipher alphabets to encrypt the data. in other words, the letters in the vigenere cipher are shifted by different amounts, normally done using a word or phrase as the encryption key . unlike the monoalphabetic ciphers, polyalphabetic ciphers are not susceptible to frequency analysis, as more than one letter in the plaintext can be represented by a single letter in the encryption. the key is the flag.
```

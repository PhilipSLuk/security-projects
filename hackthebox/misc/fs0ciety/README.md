# MISC CHALLENGE: FS0CIETY

## Challenge Description
We believe that there is an SSH Password inside password protected 'ZIP' folder.
Can you crack the 'ZIP' folder and get the SSH password? 

```
fsociety.zip
```

### FCRACKZIP
First, let's try to crack the password on the zip file..

```
$ unzip -l fsociety.zip 
Archive:  fsociety.zip
  Length      Date    Time    Name
---------  ---------- -----   ----
      729  2017-08-15 17:44   sshcreds_datacenter.txt
---------                     -------
      729                     1 file
```

Looks like we need to get at the file sshcreds_datacenter.txt..

```
$ fcrackzip -u -D -p /usr/share/wordlists/rockyou.txt fsociety.zip 

PASSWORD FOUND!!!!: pw == justdoit
```

## DECODING

Hm.. so now what to do with what we found inside this file.. decode? decrypt?
De-obfuscate?

```
$ cat sshcreds_datacenter.txt
*****************************************************************************************
Encrypted SSH credentials to access Blume ctOS : 

MDExMDEwMDEgMDExMDAxMTAgMDEwMTExMTEgMDExMTEwMDEgMDAxMTAwMDAgMDExMTAxMDEgMDEwMTExMTEgMDExMDAwMTEgMDEwMDAwMDAgMDExMDExMTAgMDEwMTExMTEgMDAxMDAxMDAgMDExMDExMDEgMDAxMTAwMTEgMDExMDExMDAgMDExMDExMDAgMDEwMTExMTEgMDExMTAxMTEgMDExMDEwMDAgMDEwMDAwMDAgMDExMTAxMDAgMDEwMTExMTEgMDExMTAxMDAgMDExMDEwMDAgMDAxMTAwMTEgMDEwMTExMTEgMDExMTAwMTAgMDAxMTAwMDAgMDExMDAwMTEgMDExMDEwMTEgMDEwMTExMTEgMDExMDEwMDEgMDExMTAwMTEgMDEwMTExMTEgMDExMDAwMTEgMDAxMTAwMDAgMDAxMTAwMDAgMDExMDEwMTEgMDExMDEwMDEgMDExMDExMTAgMDExMDAxMTE=

*****************************************************************************************
```

I've seen strings that end in "=" before that were base64 encoded. Let's see if
that works?

```
$ base64 -d input.txt 
01101001 01100110 01011111 01111001 00110000 01110101 01011111 01100011 01000000 01101110 01011111 00100100 01101101 00110011 01101100 01101100 01011111 01110111 01101000 01000000 01110100 01011111 01110100 01101000 00110011 01011111 01110010 00110000 01100011 01101011 01011111 01101001 01110011 01011111 01100011 00110000 00110000 01101011 01101001 01101110 01100111
```

Neat.. looks like we are on the right track. Binary data? Used `https://www.convertbinary.com/` at first, but then found this fun little command line that also
does the trick as well.

```
$ echo 0110100101100110010111110111100100110000011101010101111101100011010000000110111001011111001001000110110100110011011011000110110001011111011101110110100001000000011101000101111101110100011010000011001101011111011100100011000001100011011010110101111101101001011100110101111101100011001100000011000001101011011010010110111001100111 | perl -lpe '$_=pack"B*",$_'
if_y0u_c@n_$m3ll_wh@t_th3_r0ck_is_c00king
```

Yay~~~


# STEGO CHALLENGE: DA VINCI

## Challenge Description
Try to find out the secret which is hiding inside of these pictures and learn
the truth about Mona Lisa!

```
monalisa.jpg
```
<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/davinci/monalisa.jpg" width=200px/>

```
Plans.jpg
```
<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/davinci/Plans.jpg" width=200px/>

```
Thepassword_is_the_small_name_of_the_actor_named_Hanks.jpg
```
<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/davinci/Thepassword_is_the_small_name_of_the_actor_named_Hanks.jpg" width=200px;/>


### STRING ANALYSIS

Performing strings analysis on each of the photos, we find a few interesting
things.

1. In the `Plans.jpg` file we find a URL to a YouTube clip on Picasso's
Guernica (just an Easter egg with no real relevance?)

```
$ strings Plans.jpg | tail
krrCr1a\
k]]@-
Tw#p
]]AN>y
,FUh*I
[JO#
WPPr
S&U`
k]]@
https://www.youtube.com/watch?v=jc1Nfx4c5LQ
```

2. In the `monalisa.jpg` file, we find evidence that there is a file hidden
inside this file.

```
$ strings monalisa.jpg | tail
S/-R?
N64dP4
x^[E
+hI$}
"bMe,L
fGS:>
$`"_
#d)$
Mona.jpgUT
famous.zipUT
```

### UNZIP

```
$ unzip -l monalisa.jpg 
Archive:  monalisa.jpg
warning [monalisa.jpg]:  450363 extra bytes at beginning or within zipfile
  (attempting to process anyway)
  Length      Date    Time    Name
---------  ---------- -----   ----
   117958  09-22-2017 14:59   famous.zip
---------                     -------
   117958                     1 file
```

Unzipping the `monalisa.jpg` file, we find a zip archive called `famous.zip`
embedded within.

```
$ unzip monalisa.jpg 
Archive:  monalisa.jpg
warning [monalisa.jpg]:  450363 extra bytes at beginning or within zipfile
  (attempting to process anyway)
  inflating: famous.zip           
```

Looks like there is another JPG within this zip file.

```
$ unzip -l famous.zip 
Archive:  famous.zip
  Length      Date    Time    Name
---------  ---------- -----   ----
   122869  09-22-2017 14:57   Mona.jpg
---------                     -------
   122869                     1 file
```

When we try to unzip `famous.zip`, it prompts us for a password. Recalling that
one of the other files given to us is named `Thepassword_is_the_small_name_of_the_actor_named_Hanks.jpg` and opening the file shows a picture of Tom Hanks with
the word `TOM` stamped on his forehead leads us to believe this is the password?

```
$ unzip famous.zip 
Archive:  famous.zip
[famous.zip] Mona.jpg password: 
password incorrect--reenter: 
password incorrect--reenter: 
   skipping: Mona.jpg                incorrect password
```

Doh.. but of course not. Misdirection. Sneaky bastards.

### FCRACKZIP

Let's resort to cracking the zip file using `fcrackzip`.


```
$ fcrackzip -u -D -p /usr/share/wordlists/rockyou.txt famous.zip 

PASSWORD FOUND!!!!: pw == leonardo
```

Great.. now let's see what we got here. Looks like Mona Lisa with an iPhone...

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/davinci/Mona.jpg" width=200px/>


### STEGHIDE

Looking at the phone doesn't appear to give any meaning. Tried a bunch of
analysis on the photo (error level analysis, contrast, strings, etc) but
couldn't see anything. Eventually decided to try steghide to see if any file
was hidden in the photo that way and tried both `tom` and `Guernica` as the
password (since those were pieces of information given from the other so far
unused files) and....

```
$ steghide extract -sf Mona.jpg -p Guernica
wrote extracted data to "key".
```

.. mind blown! There was a file hidden using `Guernica` as the password!

```
$ cat key 
VTBaU1EyVXdNSGRpYTBKbVZFUkdObEZHT0doak1UbEZUVEJDUldaUlBUMD0=
```

### DECODING

But what the heck do we do with this string? Feeding it through a BASE64
decoding several times yields the answer!

```
$ base64 --d key | base64 --d | base64 --d
HTB{M0n@_L1z@_!s_D3@D}
```

### DECODING RESOURCES I TRIED

```
https://ringzer0team.com/tool
https://tech.pookey.co.uk/non-wp/encoder-decoder.php
https://encoder.mattiasgeniar.be/
```

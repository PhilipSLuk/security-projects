# CRYPTO CHALLENGE: DECEITFUL BATMAN

## Challenge Description
This text appeared on a Batman show but we suspect that it is actually code. It's your job to find out what it says!
(The flag is in uppercase).

```
$ cat finale.txt 
NAANAAANNNAANAAAANANANANAAAAAAAANNAANAAANAAANANNAAAAAAAANNNAANAAAAANAANAAAA
```
75 characters in total

### MORSE CODE?

Nope..

```
NAA NAA ANN NAA NAA AAN ANA NAN AAA AAA AAN NAA NAA ANA AAN ANN AAA AAA AAN NNA ANA AAA ANA ANA AAA

-.. -.. .-- -.. -.. ..- .-. -.- ... ... ..- -.. -.. .-. ..- .-- ... ... ..- --. .-. ... .-. .-. ...
DDWDDURKSSUDDRUWSSUGRSRRS

.-- .-- -.. .-- .-- --. -.- .-. --- --- --. .-- .-- -.- --. -.. --- --- --. ..- -.- --- -.- -.- ---
WWDWWGKROOGWWKGDOOGUKOKKO
```

### BINARY?

Nope..

```
NAAN AAAN NNAA NAAA ANAN ANAN AAAA AAAA NNAA NAAA NAAA NANN AAAA AAAA NNNA ANAA AAAN AANA AAA

		ASCII	EBCDIC	HEX
1001 0001		j	91
1100 1000		H	C8
0101 0111 	W		57
0000 0000			00
1100 1000		H	C8
1000 1011			8B
0000 0000			00
1110 0100		U	E4
0001 0010			12
000				0

0110 1110 	n		6E
0011 0111 	7		37
1010 1000		y	A8
1111 1111			FF
0011 0111 	7		37
0111 0100 	t		74
1111 1111			FF
0001 1011			1B
1110 1101			ED
111				7
```

### BACON'S CIPHER

```
To encode a message, each letter of the plaintext is replaced by a group of
five of the letters 'A' or 'B'. This replacement is a binary encoding and is
done according to the alphabet of the Baconian cipher (from the Latin Alphabet)

https://en.wikipedia.org/wiki/Bacon%27s_cipher
```

If we assume A=A and N=B of the Baconian alphabet..

NAANA	T
AANNN	H
AANAA	E
AANAN	F
ANANA	L
AAAAA	A
AANNA	G
ANAAA	I,J
NAAAN	S`
ANNAA	N
AAAAA	A
ANNNA	P
ANAAA	I,J
AANAA	E
NAAAA	R

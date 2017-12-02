# STEGO CHALLENGE: UNIFIED

## Challenge Description
This file seems to contain innocuous information. What is the true message?

```
$ cat BOD_30079.txt
<<-----UTF-8 MESSAGE BOD_30079 BEGINS---->>

Unicode is a computing industry standard for the consistent encoding, representation, and handling of text expressed in most of the world's writing systems.

The system works in many languages. 该系统以许多语言工作. يعمل النظام في العديد من اللغات. 
󠁈󠁔󠁂󠁻󠁴󠁲󠀱󠁴󠁨󠀳󠁭󠀱󠁵󠀵󠁟󠀱󠀴󠀹󠀹󠁽���� ���� �� �������� ��� ����� � ���� ��� ��
Το σύστημα λειτουργεί σε πολλές γλώσσες.Система работает на многих языках.

Steganography is the practice of concealing messages within other non-secret text or data.
The cover media may appear unremarkable at first glance and will require close investigation.

<<-----UTF-8 MESSAGE BOD_30079 ENDS----->>
```

## UTF8 ENCODING

The `replacement character` is what stands out the most in that file.

```
https://en.wikipedia.org/wiki/Specials_(Unicode_block)#Replacement_character
```

So, let's see what the underlying binary encoding looks like..

```
$ xxd interesting.txt
00000000: f3a0 8188 f3a0 8194 f3a0 8182 f3a0 81bb  ................
00000010: f3a0 81b4 f3a0 81b2 f3a0 80b1 f3a0 81b4  ................
00000020: f3a0 81a8 f3a0 80b3 f3a0 81ad f3a0 80b1  ................
00000030: f3a0 81b5 f3a0 80b5 f3a0 819f f3a0 80b1  ................
00000040: f3a0 80b4 f3a0 80b9 f3a0 80b9 f3a0 81bd  ................
00000050: efbf bdef bfbd efbf bdef bfbd 20ef bfbd  ............ ...
00000060: efbf bdef bfbd efbf bd20 efbf bdef bfbd  ......... ......
00000070: 20ef bfbd efbf bdef bfbd efbf bdef bfbd   ...............
00000080: efbf bdef bfbd efbf bd20 efbf bdef bfbd  ......... ......
00000090: efbf bd20 efbf bdef bfbd efbf bdef bfbd  ... ............
000000a0: efbf bd20 efbf bd20 efbf bdef bfbd efbf  ... ... ........
000000b0: bdef bfbd 20ef bfbd efbf bdef bfbd 20ef  .... ......... .
000000c0: bfbd efbf bd0a                           ......
```

## TAG LATIN?

Searching `http://www.fileformat.info/info/unicode/char/search.htm` allows
us to make the following mapping..

```
f3a08188 Unicode Character 'TAG LATIN CAPITAL LETTER H' (U+E0048)
f3a08194 Unicode Character 'TAG LATIN CAPITAL LETTER T' (U+E0054)
f3a08182 Unicode Character 'TAG LATIN CAPITAL LETTER B' (U+E0042)
f3a081bb Unicode Character 'TAG LEFT CURLY BRACKET'     (U+E007B)

f3a081b4 Unicode Character 'TAG LATIN SMALL LETTER T'   (U+E0074)
f3a081b2 Unicode Character 'TAG LATIN SMALL LETTER R'   (U+E0072)
f3a080b1 Unicode Character 'TAG DIGIT ONE'              (U+E0031)
f3a081b4 Unicode Character 'TAG LATIN SMALL LETTER T'   (U+E0074)

f3a081a8 Unicode Character 'TAG LATIN SMALL LETTER H'   (U+E0068)
f3a080b3 Unicode Character 'TAG DIGIT THREE'            (U+E0033)
f3a081ad Unicode Character 'TAG LATIN SMALL LETTER M'   (U+E006D)
f3a080b1 Unicode Character 'TAG DIGIT ONE'              (U+E0031)

f3a081b5 Unicode Character 'TAG LATIN SMALL LETTER U'   (U+E0075)
f3a080b5 Unicode Character 'TAG DIGIT FIVE'             (U+E0035)
f3a0819f Unicode Character 'TAG LOW LINE'               (U+E005F)
f3a080b1 Unicode Character 'TAG DIGIT ONE'              (U+E0031)

f3a080b4 Unicode Character 'TAG DIGIT FOUR'             (U+E0034)
f3a080b9 Unicode Character 'TAG DIGIT NINE'             (U+E0039)
f3a080b9 Unicode Character 'TAG DIGIT NINE'             (U+E0039)
f3a081bd Unicode Character 'TAG RIGHT CURLY BRACKET'    (U+E007D)
```

```
HTB{tr1th3m1u5_1499}
```

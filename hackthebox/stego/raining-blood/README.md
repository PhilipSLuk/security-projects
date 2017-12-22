# STEGO CHALLENGE: RAINING BLOOD

## Challenge Description
Can you find the hidden message?

```
RainingBlood.mp3
```

Appears to be the track "Raining Blood" by "Slayer".

### STRING ANALYSIS

Performing a strings analysis against the MP3 file, we find a few interesting
things..

```
$ strings RainingBlood.mp3
```

We find a few instances of the string "LAME"..

```
LAME3.99.5
```

.. and what could be a BASE64 encoded string..

```
(J,P)
 *@S
f<SFRCe2gxZGQxbmdfZDR0NF9iM3R3MzNuX21wM19mcjRtM3NfaXNfbm90X2Z1bm55ISF9Cg==
"sY$
~_/n
```

### MP3 ID3 INFO TAGS

Let's see if we find anything interesting in the MP3 metadata..

```
$ kid3-cli -c get RainingBlood.mp3 
File: MPEG 1 Layer 3 320 kbps 44100 Hz Joint Stereo 4:16
  Name: RainingBlood.mp3
Tag 2: ID3v2.3.0
  Title                   Slayer - Raining Blood
  Comment                 www.dvdvideosoft.com
  Track Number            1
  Picture: Cover (front)  C:\Users\hpylarinos\Videos\tmp_cover477.jpeg
```

Nothing particularly interesting here.

### SPECTRUM ANALYSIS

Running the MP3 through a spectrum analyzer to see if anything is there..

```
https://academo.org/demos/spectrum-analyzer/
```

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/raining-blood/spectrum-analysis.jpg" width=500px/>

Nothing appears to jump out.

### BASE64 DECODE

Going back to that weird string we found in string analysis, let's see if it
does in fact resolve to meaningful ascii after base64 decoding..

```
$ echo "f<SFRCe2gxZGQxbmdfZDR0NF9iM3R3MzNuX21wM19mcjRtM3NfaXNfbm90X2Z1bm55ISF9Cg==" | base64 -D
Invalid character in input stream.
```

Hm.. so what if we dropped the leading "f<" from the string..

```
$ echo "SFRCe2gxZGQxbmdfZDR0NF9iM3R3MzNuX21wM19mcjRtM3NfaXNfbm90X2Z1bm55ISF9Cg==" | base64 -D
HTB{h1dd1ng_d4t4_b3tw33n_mp3_fr4m3s_is_not_funny!!}
```

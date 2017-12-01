# STEGO CHALLENGE: MILKSHAKE

## Challenge Description
Can you bring all the boys to the yard?

```
Milkshake.mp3
```

### MP3 ID3 INFO TAGS

Not sure where to start, so let's see if we find anything interesting in the MP3
metadata..

```
https://en.wikipedia.org/wiki/ID3
```

```
$ kid3-cli -c get Milkshake.mp3 
File: MPEG 1 Layer 3 295 kbps 44100 Hz Joint Stereo 0:40
  Name: Milkshake.mp3
Tag 2: ID3v2.4.0
  Title         Milkshake
  Artist        Kelis
  Album         The Neptunes Present-Clones-AD
  Comment        000007A5 000006CA 00007311 000075EA 0001A567 0001A567 00008000 00008000 0000005C 0000005C
  Comment        000007A5 000006CA 00007311 000075EA 0001A567 0001A567 00008000 00008000 0000005C 0000005C
  Date          2003
  Track Number  7
  Genre         Hip-Hop
  Band          Kelis
  Composer      Chad Hugo/Pharrell Williams
  Publisher     Virgin UK
```

Found potentially interesting information as the `comment` that could be
HEXADECIMAL, but that doesn't appear to convert to meaningful ASCII.

### SPECTRUM ANALYSIS

A Google search of MP3 analysis techniques led me to look into 'spectrum analysis'.

```
https://academo.org/demos/spectrum-analyzer/
```

Performing spectrum analysis against the MP3 file reveals hidden text! Amazing!
(screen captures of the spectrum analysis saved as PDF file).

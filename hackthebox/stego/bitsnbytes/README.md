# STEGO CHALLENGE: BITSNBYTES

## Challenge Description
We have intercepted an email sent by a terrorist cell. It contains only an
image. Can you compare the modified image to its original and see if it has any
meaning? 

```
original.png
```
<img src="original.png" width=500px/>

```
intercepted.png
```
<img src="intercepted.png" width=500px/>

### LEAST SIGNIFICANT BIT?

```
The Least Significant Bit (LSB) is one of the main techniques in spatial domain image Steganography. The LSB is the lowest significant bit in the byte value of the image pixel. The LSB based image steganography embeds the secret in the least significant bits of pixel values of the cover image (CVR).
```

##### ZSTEG

```
https://github.com/zed-0xff/zsteg

Detect stegano-hidden data in PNG & BMP
Usage: zsteg [options] filename.png [param_string]
```

```
$ zsteg intercepted.png 
imagedata           .. text: "gMVU>HS;IT<IU>H_JQU@GT?HU<BZ@IW=JV>LW?MS;HT=GV?E^BP^DQV<GP9CP9AU;DT:CU:AW?LU?KP?GP;BS9BY>GY?JP;DN9BP;DR=DQ<CP;@Q<AQ=?N:<R<?Q;>R<?O8>M6<N7?L5=K4<H46J47J47L37P7;N7=I49L7<K6?L36O62T87S8?R8CQ6=R59O9ET?HQ=FJ9AH7?J6AM7CQ;HQ9FR8CQ7@R9?O6<O6<R9?O6<K6=L6BH4?K8<I6<K7CN7GM7CI49I4;F39C28G6<G6>D3;L8AC2<?.8B.7C.7C.5A,5E1:J6?N16P7=I6<?07<17F;AA59<-2B0<=.5:.26+1:,9D3CF1@F0<D4>B2<B19B17?.4@/78)0?294*24*33+62*7:2?8-;:.:1%11&.:*49,52+36/78+5;+8;1<<-27+/7,29371*10&/4(21$.4'.3)40*85-:6*44)/9/771;/(05+43)43)46,72(31)6.&3+*01,30&/-#,5-80(5.&5+ 02(31&./\")2%,4*3.&1*\"/-\"01)8)&1(&1*)1/)3-#..\"./%0*$2($2&$/'&.&%-(\",.$/.\"0'"
b1,bgr,msb,xy       .. text: "8n_]\n!V(o"
b3,g,msb,xy         .. text: "c*%9N,Rf["
b4,r,lsb,xy         .. text: "u4_TZvsF"
b4,r,msb,xy         .. text: "Q5p9=/LH/XQ"
b4,g,lsb,xy         .. text: "gTDCwGch"
b4,rgb,msb,xy       .. text: ")9>m?lo$"
b4,bgr,msb,xy       .. text: "~)9>om<d"
```

##### STEGLSB

```
https://github.com/SST-CTF/lsb-steganography

Steglsb allows for two functions - encoding and decoding. Encoding masks a secret image in a cover image using LSB. Decoding recovers a secret image from an encoded image using LSB.
Usage: steglsb -e [cover_image] [secret_image] [output_image_name]
```

```
$ ./lsb-steganography/steglsb.py -d intercepted.png result-steglsb.lsb-2bit.png
How many bits do you wish to use?
> 2
```

##### GREYC'S MAGIC FOR IMAGE COMPUTING (GMIC)

```
http://gmic.eu/

G'MIC is a full-featured open-source framework for image processing, distributed under the CeCILL license (GPL-compatible). It provides several different user interfaces to convert / manipulate / filter / visualize generic image datasets, ranging from 1d scalar signals to 3d+t sequences of multi-spectral volumetric images, thus including 2d color images.
```

```
gmic original.png intercepted.png -blend xor -o result-gmic.xor.png
```

##### PNGCHECK

```
http://www.libpng.org/pub/png/apps/pngcheck.html

pngcheck verifies the integrity of PNG, JNG and MNG files (by checking the internal 32-bit CRCs [checksums] and decompressing the image data); it can optionally dump almost all of the chunk-level information in the image in human-readable form.
```

```
$ pngcheck intercepted.png 
OK: intercepted.png (775x550, 24-bit RGB, non-interlaced, 24.1%).
```

##### BINWALK

```
$ binwalk -e original.png 

DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
0             0x0             PNG image, 775 x 550, 8-bit/color RGB, non-interlaced
41            0x29            Zlib compressed data, best compression
546410        0x8566A         MySQL MISAM compressed data file Version 10
```

```
$ binwalk -e intercepted.png 

DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
0             0x0             PNG image, 775 x 550, 8-bit/color RGB, non-interlaced
41            0x29            Zlib compressed data, best compression
```

##### STEGSOLVE

```
java -jar stegosolve.jar
```

### REFERENCE

```
https://security.stackexchange.com/questions/77290/steganography-retreive-secret-text-by-comparing-original-and-text-containing-p
```

```
https://pequalsnp-team.github.io/cheatsheet/steganography-101
```

```
http://gmic.eu/
```

### HINTS

There are definitely differences between the two image (their file size is slightly different). Are you sure you found nothing different between them?
I highly recommend making a short script instead of doing everything by hand, once you figure out what needs to be done
patience and a ruler are enough

# STEGO CHALLENGE: WIDESCREEN

## Challenge Description
Someone has leaked pictures of our unreleased movie. Can you help identify him?

```
widescreen.png
```

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/widescreen/widescreen.png" width=200px/>

### ERROR LEVEL ANALYSIS (ELA)

```
Error Level Analysis (ELA) permits identifying areas within an image that are at
different compression levels. With JPEG images, the entire picture should be at
roughly the same level. If a section of the image is at a significantly different
error level, then it likely indicates a digital modification.
```

Performing ELA analysis on the PNG file shows some anomolies in the black banner
at the bottom of the image.

```
widescreen-fotoforensics.com-error.level.analysis.png
```

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/widescreen/widescreen-fotoforensics.com-error.level.analysis.png" width=200px/>

### INCREASING EXPOSURE

Increasing the photo's exposure allows us to clearly read the hidden text within
the black banner!

```
widescreen-phixr.com-exposure.jpg
```
<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/widescreen/widescreen-phixr.com-exposure.jpg" width=200px/>

# MISC CHALLENGE: 0LD IS G0LD

## Challenge Description
Old algorithms are not a waste, but are really precious..

```
0ld is g0ld.pdf
```

### PDFCRACK
First, we have to crack the password on the PDF file to view its contents..

```
$ pdfcrack 0ld_is_g0ld.pdf -w /usr/share/wordlists/rockyou.txt 

PDF version 1.6
Security Handler: Standard
V: 2
R: 3
P: -1060
Length: 128
Encrypted Metadata: True
FileID: 5c8f37d2a45eb64e9dbbf71ca3e86861
U: 9cba5cfb1c536f1384bba7458aae3f8100000000000000000000000000000000
O: 702cc7ced92b595274b7918dcb6dc74bedef6ef851b4b4b5b8c88732ba4dac0c
Average Speed: 46455.7 w/s. Current Word: 'hounds07'
Average Speed: 46099.2 w/s. Current Word: 'dominique1998'
Average Speed: 43134.2 w/s. Current Word: 'wordisgold1'
Average Speed: 46068.9 w/s. Current Word: 'soma7ruby'
Average Speed: 46085.8 w/s. Current Word: 'potatopen191'
Average Speed: 46043.2 w/s. Current Word: 'mitamana'
Average Speed: 45505.8 w/s. Current Word: 'lacry1990'
found user-password: 'jumanji69'
```

### MORSE CODE

After view the PDF file, we see a portrait of Samuel Morse, but looking
carefully at the bottom of the file we see something in fine print..

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/misc/0ld-is-g0ld/0ld_is_g0ld.cracked.jpg" width=200px/>

```
.-. .---- .--. ... .- -- ..- ...-- .-.. -- ----- .-. ... ...--
```

Shoving the string into a morse code translator (`https://morsecode.scphillips.com/translator.html`), we find..

```
R1PSAMU3LM0RS3
```


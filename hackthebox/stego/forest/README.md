# STEGO CHALLENGE: FOREST

## Challenge Description
Explore the forest and capture the flag!

```
forest.jpg
```

### FILTERS

```
https://29a.ch/photo-forensics/
```

Error analysis filters show some text in the left side.

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/forest/forest-29a.ch-photo.forensics-error.level.analysis.jpg" width=200px/>

Turning up the contrast allows us to see the text better..

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/forest/forest-phixr.com-exposure.jpg" width=200px/>

I can see the text `IsJuS1Af0r3sTbR0`, but that doesn't seem to be the flag.
What else am I missing?

### STEGHIDE

So what if this is the passphrase for `steghide`?

```
$ steghide extract -sf forest.jpg -p IsJuS1Af0r3sTbR0
wrote extracted data to "nothinghere.txt".
```

Well I'll be damned..

```
$ cat nothinghere.txt 
Gur sberfg vf n pbzcyrk rpbflfgrz pbafvfgvat znvayl bs gerrf gung ohssre gur rnegu naq fhccbeg n zlevnq bs yvsr sbezf. Gur gerrf uryc perngr n fcrpvny raivebazrag juvpu, va ghea, nssrpgf gur xvaqf bs navznyf naq cynagf gung pna rkvfg va gur sberfg. Gerrf ner na vzcbegnag pbzcbarag bs gur raivebazrag. Gurl pyrna gur nve, pbby vg ba ubg qnlf, pbafreir urng ng avtug, naq npg nf rkpryyrag fbhaq nofbeoref. UGO{NzNm1aTfXvyYmMOe0}
```

### SUBSTITUTION

Looking at the text, we can make a guess that `UGO{NzNm1aTfXvyYmMOe0}` is the
`HTB{xxxxx}` flag - so U=H, G=T, O=B. Feeding these clues into the online
cryptogram solver `https://quipquip.com` using `statistics` model yields the
following..

<img src="https://github.com/fortyfunbobby/security-projects/blob/master/hackthebox/stego/forest/crytogram-quipquip.com.jpg" width=200px/>

```
The forest is a complex ecosystem consisting mainly of trees that buffer the earth and support a myriad of life forms. The trees help create a special environment which, in turn, affects the kinds of animals and plants that can exist in the forest. Trees are an important component of the environment. They clean the air, cool it on hot days, conserve heat at night, and act as excellent sound absorbers. HTB{AmAz1nGsKilLzZBr0}
```

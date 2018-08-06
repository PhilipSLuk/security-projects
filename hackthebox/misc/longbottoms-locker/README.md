# MISC CHALLENGE: LONGBOTTOM'S LOCKER

## Challenge Description
Break into Longbottom's vault and steal his secrets.

```
index.html
```
<img src="index_html.jpg" width=250px/>

```
neville.gif
```
<img src="neville.gif" width=250px/>

```
socute.jpg
```
<img src="socute.jpg" width=250px/>

### INSPECTING OUR ARTIFACTS

We have a webpage which presents us with a login prompt. Entering random text
generates a pop-up box that informs us we have supplied a `Bad passphrase!`
implying that we have to determine the correct one.

<img src="index_html_bad_passphrase.jpg" width=250px/>

Examining our `index.html` we find the relevant piece of `javascript`..

```
<script>
    document.getElementById('neville-locker-form').addEventListener('submit', fu
nction(e) {
        e.preventDefault();

        var passphrase = document.getElementById('passwd').value,
            encryptedMsg = '4cce4470203e10b395ab1787a22553a5b2503d42a965da813676
d929cc16f76cU2FsdGVkX19FvUyhqWoQKHXNLBL64g8acK4UQoP6XZQ/n4MRL3rgQj8TJ/3r8Awtxte2
V9s+RLfQHJOHGwYtctqRa/H2BetmxjwGG+LYKUWC8Z6WBoYbecwtATCOuwewnp+VKBzsWLme+3BZyRgK
EA==',
            encryptedHMAC = encryptedMsg.substring(0, 64),
            encryptedHTML = encryptedMsg.substring(64),
            decryptedHMAC = CryptoJS.HmacSHA256(encryptedHTML, CryptoJS.SHA256(p
assphrase).toString()).toString();

        if (decryptedHMAC !== encryptedHMAC) {
            alert('Bad passphrase!');
            return;
        }

        var plainHTML = CryptoJS.AES.decrypt(encryptedHTML, passphrase).toString(CryptoJS.enc.Utf8);

        document.write(plainHTML);
        document.close();
    });
</script>
```

Looks like the password we enter into the page is used as the passphrase to
an AES decryption routine. So how do we figure out what the password is?

### BINWALK SOCUTE.JPG

String analysis on `socute.jpg` yields so anomolies at the end of the file..

```
$ strings socute.jpg | tail
db`f
h`bnb`
donotshareUX
3f@[i
"[PK
__MACOSX/UX
8f@[8f@[PK
__MACOSX/._donotshareUX
3f@[i
"[PK
```

The `PK` and presence of file names seems to suggest a zip file is hidden in the image?

```
$ binwalk socute.jpg 

DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
0             0x0             JPEG image data, JFIF standard 1.01
97465         0x17CB9         Zip archive data, at least v2.0 to extract, name: donotshare
99087         0x1830F         Zip archive data, at least v1.0 to extract, name: __MACOSX/
99142         0x18346         Zip archive data, at least v2.0 to extract, name: __MACOSX/._donotshare
99574         0x184F6         End of Zip archive
```

Let's take a look and see what we have..

```
$ unzip socute.jpg
Archive:  socute.jpg
warning [socute.jpg]:  97465 extra bytes at beginning or within zipfile
  (attempting to process anyway)
  inflating: donotshare              
   creating: __MACOSX/
  inflating: __MACOSX/._donotshare   
```

```
$ head donotshare 
(lp1
(lp2
(S' '
I163
tp3
aa(lp4
(S' '
I1
tp5
a(S'.'
$ tail donotshare 
I3
tp495
a(S' '
I1
tp496
aa(lp497
(S' '
I163
tp498
```

```
$ cat __MACOSX/._donotshare 
Mac OS X        	2??ATTR??<?<com.apple.quarantineq/0081;5b4065ff;Chrome;85F952B7-6DAB-46A2-8DCE-1AAA047401B0
$ file __MACOSX/._donotshare 
__MACOSX/._donotshare: AppleDouble encoded Macintosh file
```

Okay.. so now what?

### PICKLING

Searching around the interweb for some of the strings found in our `donotshare`
file (eg.  `aa(lp275`) seems to hint that it might be a Python `.pkl` or
`pickle` file (used for serializing and de-serializing Python object
structures). 


I wrote a little script to read in the pickle file and see if we can read the
data..

```
$ cat unpickle1.py 
import sys
import pickle

f = open(sys.argv[1], "r")
mydata = pickle.load(f)
f.close

print(mydata)
print(type(mydata))
```

```
$ python unpickle1.py donotshare 
<type 'list'>
[[(' ', 163)], [(' ', 1), ('.', 1), ('d', 1), ('8', 4), ('b', 1), ('.', 1), (' ', 12), ('d', 1), ('8', 3), (' ', 7), ('8', 3), (' ', 2), ('.', 1), ('d', 1), ('8', 4), ('b', 1), ('.', 1), (' ', 22), ('d', 1), ('8', 4), (' ', 2), ('8', 3), ('b', 1), (' ', 4), ('8', 3), (' ', 8), ('8', 7), ('b', 1), ('.', 1), (' ', 3), ('.', 1), ('d', 1), ('8', 4), ('b', 1), ('.', 1), (' ', 2), ('8', 9), (' ', 2), ('8', 9), (' ', 2), ('8', 3), (' ', 5), ('8', 3), (' ', 15)], [('d', 1), ('8', 2), ('P', 1), (' ', 2), ('Y', 1), ('8', 2), ('b', 1), (' ', 10), ('d', 1), ('8', 4), (' ', 7), ('8', 3), (' ', 1), ('d', 1), ('8', 2), ('P', 1), (' ', 2), ('Y', 1), ('8', 2), ('b', 1), (' ', 20), ('d', 1), ('8', 1), ('P', 1), ('8', 3), (' ', 2), ('8', 4), ('b', 1), (' ', 3), ('8', 3), (' ', 8), ('8', 3), (' ', 3), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('d', 1), ('8', 2), ('P', 1), (' ', 2), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('8', 3), (' ', 8), ('8', 3), (' ', 8), ('8', 3), (' ', 5), ('8', 3), (' ', 15)], [('8', 3), (' ', 4), ('8', 3), (' ', 12), ('8', 3), (' ', 7), ('8', 3), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 19), ('d', 1), ('8', 1), ('P', 1), (' ', 1), ('8', 3), (' ', 2), ('8', 5), ('b', 1), (' ', 2), ('8', 3), (' ', 8), ('8', 3), (' ', 4), ('8', 3), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 1), ('8', 3), (' ', 8), ('8', 3), (' ', 8), ('8', 3), (' ', 5), ('8', 3), (' ', 15)], [('8', 3), (' ', 8), ('8', 3), (' ', 2), ('8', 3), (' ', 3), ('8', 3), (' ', 3), ('.', 1), ('d', 1), ('8', 5), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 8), ('8', 3), (' ', 2), ('8', 3), (' ', 2), ('d', 1), ('8', 1), ('P', 1), (' ', 2), ('8', 3), (' ', 2), ('8', 3), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('8', 3), (' ', 8), ('8', 3), (' ', 3), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 1), ('8', 7), ('b', 1), ('.', 1), (' ', 2), ('8', 7), ('b', 1), ('.', 1), (' ', 2), ('8', 3), (' ', 5), ('8', 3), (' ', 1), ('8', 5), ('b', 1), ('.', 1), ('d', 1), ('8', 2), ('b', 1), ('.', 1), (' ', 2)], [('8', 3), (' ', 2), ('8', 5), (' ', 1), ('8', 3), (' ', 2), ('8', 3), (' ', 3), ('8', 3), (' ', 2), ('d', 1), ('8', 2), ('"', 1), (' ', 1), ('8', 3), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 8), ('8', 3), (' ', 2), ('8', 3), (' ', 1), ('d', 1), ('8', 2), (' ', 3), ('8', 3), (' ', 2), ('8', 3), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), ('8', 3), (' ', 8), ('8', 7), ('P', 1), ('"', 1), (' ', 2), ('8', 3), (' ', 4), ('8', 3), (' ', 6), ('"', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 6), ('"', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('8', 3), (' ', 5), ('8', 3), (' ', 1), ('8', 3), (' ', 1), ('"', 1), ('8', 3), (' ', 1), ('"', 1), ('8', 2), ('b', 1), (' ', 1)], [('8', 3), (' ', 4), ('8', 3), (' ', 1), ('8', 3), (' ', 2), ('8', 3), (' ', 3), ('8', 3), (' ', 2), ('8', 3), (' ', 2), ('8', 3), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 1), ('8', 6), (' ', 1), ('Y', 1), ('8', 2), (' ', 2), ('8', 2), ('P', 1), (' ', 1), ('8', 10), (' ', 1), ('8', 3), (' ', 2), ('Y', 1), ('8', 5), (' ', 1), ('8', 6), (' ', 1), ('8', 3), (' ', 1), ('T', 1), ('8', 2), ('b', 1), (' ', 3), ('8', 3), (' ', 4), ('8', 3), (' ', 8), ('8', 3), (' ', 8), ('8', 3), (' ', 1), ('8', 3), (' ', 5), ('8', 3), (' ', 1), ('8', 3), (' ', 2), ('8', 3), (' ', 2), ('8', 3), (' ', 1)], [('Y', 1), ('8', 2), ('b', 1), (' ', 2), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('8', 3), (' ', 3), ('8', 3), (' ', 2), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('8', 3), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 2), ('d', 1), ('8', 2), ('P', 1), (' ', 9), ('Y', 1), ('8', 1), ('b', 1), ('d', 1), ('8', 1), ('P', 1), (' ', 8), ('8', 3), (' ', 2), ('8', 3), (' ', 3), ('Y', 1), ('8', 4), (' ', 8), ('8', 3), (' ', 2), ('T', 1), ('8', 2), ('b', 1), (' ', 2), ('Y', 1), ('8', 2), ('b', 1), (' ', 2), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 2), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 2), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), ('.', 1), (' ', 1), ('.', 1), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('8', 3), (' ', 2), ('8', 3), (' ', 2), ('8', 3), (' ', 1)], [(' ', 1), ('"', 1), ('Y', 1), ('8', 4), ('P', 1), ('8', 2), (' ', 2), ('"', 1), ('Y', 1), ('8', 5), (' ', 1), ('8', 7), (' ', 1), ('"', 1), ('Y', 1), ('8', 5), (' ', 2), ('"', 1), ('Y', 1), ('8', 4), ('P', 1), ('"', 1), (' ', 11), ('Y', 1), ('8', 2), ('P', 1), (' ', 9), ('8', 3), (' ', 2), ('8', 3), (' ', 4), ('Y', 1), ('8', 3), (' ', 8), ('8', 3), (' ', 3), ('T', 1), ('8', 2), ('b', 1), (' ', 2), ('"', 1), ('Y', 1), ('8', 4), ('P', 1), ('"', 1), (' ', 3), ('"', 1), ('Y', 1), ('8', 4), ('P', 1), ('"', 1), (' ', 3), ('"', 1), ('Y', 1), ('8', 4), ('P', 1), ('"', 1), (' ', 3), ('"', 1), ('Y', 1), ('8', 5), ('P', 1), ('"', 1), (' ', 2), ('8', 3), (' ', 2), ('8', 3), (' ', 2), ('8', 3), (' ', 1)], [(' ', 163)]]
```

So we have some sort of list.. but what do we do with it?

### DATA ANALYSIS

Upon closer inspection, it appears we have a series of lists.. so let's
tweak our script to print out each list and see if we can make better sense
of it..

```
$ cat unpickle2.py 
import sys
import pickle

f = open(sys.argv[1], "r")
mydata = pickle.load(f)
f.close

for i in mydata:
  print i
  print '\n'
```

```
$ python unpickle2.py donotshare 
[(' ', 163)]

[(' ', 1), ('.', 1), ('d', 1), ('8', 4), ('b', 1), ('.', 1), (' ', 12), ('d', 1), ('8', 3), (' ', 7), ('8', 3), (' ', 2), ('.', 1), ('d', 1), ('8', 4), ('b', 1), ('.', 1), (' ', 22), ('d', 1), ('8', 4), (' ', 2), ('8', 3), ('b', 1), (' ', 4), ('8', 3), (' ', 8), ('8', 7), ('b', 1), ('.', 1), (' ', 3), ('.', 1), ('d', 1), ('8', 4), ('b', 1), ('.', 1), (' ', 2), ('8', 9), (' ', 2), ('8', 9), (' ', 2), ('8', 3), (' ', 5), ('8', 3), (' ', 15)]

[('d', 1), ('8', 2), ('P', 1), (' ', 2), ('Y', 1), ('8', 2), ('b', 1), (' ', 10), ('d', 1), ('8', 4), (' ', 7), ('8', 3), (' ', 1), ('d', 1), ('8', 2), ('P', 1), (' ', 2), ('Y', 1), ('8', 2), ('b', 1), (' ', 20), ('d', 1), ('8', 1), ('P', 1), ('8', 3), (' ', 2), ('8', 4), ('b', 1), (' ', 3), ('8', 3), (' ', 8), ('8', 3), (' ', 3), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('d', 1), ('8', 2), ('P', 1), (' ', 2), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('8', 3), (' ', 8), ('8', 3), (' ', 8), ('8', 3), (' ', 5), ('8', 3), (' ', 15)]

[('8', 3), (' ', 4), ('8', 3), (' ', 12), ('8', 3), (' ', 7), ('8', 3), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 19), ('d', 1), ('8', 1), ('P', 1), (' ', 1), ('8', 3), (' ', 2), ('8', 5), ('b', 1), (' ', 2), ('8', 3), (' ', 8), ('8', 3), (' ', 4), ('8', 3), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 1), ('8', 3), (' ', 8), ('8', 3), (' ', 8), ('8', 3), (' ', 5), ('8', 3), (' ', 15)]


[('8', 3), (' ', 8), ('8', 3), (' ', 2), ('8', 3), (' ', 3), ('8', 3), (' ', 3), ('.', 1), ('d', 1), ('8', 5), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 8), ('8', 3), (' ', 2), ('8', 3), (' ', 2), ('d', 1), ('8', 1), ('P', 1), (' ', 2), ('8', 3), (' ', 2), ('8', 3), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('8', 3), (' ', 8), ('8', 3), (' ', 3), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 1), ('8', 7), ('b', 1), ('.', 1), (' ', 2), ('8', 7), ('b', 1), ('.', 1), (' ', 2), ('8', 3), (' ', 5), ('8', 3), (' ', 1), ('8', 5), ('b', 1), ('.', 1), ('d', 1), ('8', 2), ('b', 1), ('.', 1), (' ', 2)]

[('8', 3), (' ', 2), ('8', 5), (' ', 1), ('8', 3), (' ', 2), ('8', 3), (' ', 3), ('8', 3), (' ', 2), ('d', 1), ('8', 2), ('"', 1), (' ', 1), ('8', 3), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 8), ('8', 3), (' ', 2), ('8', 3), (' ', 1), ('d', 1), ('8', 2), (' ', 3), ('8', 3), (' ', 2), ('8', 3), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), ('8', 3), (' ', 8), ('8', 7), ('P', 1), ('"', 1), (' ', 2), ('8', 3), (' ', 4), ('8', 3), (' ', 6), ('"', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 6), ('"', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('8', 3), (' ', 5), ('8', 3), (' ', 1), ('8', 3), (' ', 1), ('"', 1), ('8', 3), (' ', 1), ('"', 1), ('8', 2), ('b', 1), (' ', 1)]

[('8', 3), (' ', 4), ('8', 3), (' ', 1), ('8', 3), (' ', 2), ('8', 3), (' ', 3), ('8', 3), (' ', 2), ('8', 3), (' ', 2), ('8', 3), (' ', 1), ('8', 3), (' ', 4), ('8', 3), (' ', 1), ('8', 6), (' ', 1), ('Y', 1), ('8', 2), (' ', 2), ('8', 2), ('P', 1), (' ', 1), ('8', 10), (' ', 1), ('8', 3), (' ', 2), ('Y', 1), ('8', 5), (' ', 1), ('8', 6), (' ', 1), ('8', 3), (' ', 1), ('T', 1), ('8', 2), ('b', 1), (' ', 3), ('8', 3), (' ', 4), ('8', 3), (' ', 8), ('8', 3), (' ', 8), ('8', 3), (' ', 1), ('8', 3), (' ', 5), ('8', 3), (' ', 1), ('8', 3), (' ', 2), ('8', 3), (' ', 2), ('8', 3), (' ', 1)]

[('Y', 1), ('8', 2), ('b', 1), (' ', 2), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('8', 3), (' ', 3), ('8', 3), (' ', 2), ('Y', 1), ('8', 2), ('b', 1), (' ', 1), ('8', 3), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 2), ('d', 1), ('8', 2), ('P', 1), (' ', 9), ('Y', 1), ('8', 1), ('b', 1), ('d', 1), ('8', 1), ('P', 1), (' ', 8), ('8', 3), (' ', 2), ('8', 3), (' ', 3), ('Y', 1), ('8', 4), (' ', 8), ('8', 3), (' ', 2), ('T', 1), ('8', 2), ('b', 1), (' ', 2), ('Y', 1), ('8', 2), ('b', 1), (' ', 2), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 2), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), (' ', 2), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('Y', 1), ('8', 2), ('b', 1), ('.', 1), (' ', 1), ('.', 1), ('d', 1), ('8', 2), ('P', 1), (' ', 1), ('8', 3), (' ', 2), ('8', 3), (' ', 2), ('8', 3), (' ', 1)]

[(' ', 1), ('"', 1), ('Y', 1), ('8', 4), ('P', 1), ('8', 2), (' ', 2), ('"', 1), ('Y', 1), ('8', 5), (' ', 1), ('8', 7), (' ', 1), ('"', 1), ('Y', 1), ('8', 5), (' ', 2), ('"', 1), ('Y', 1), ('8', 4), ('P', 1), ('"', 1), (' ', 11), ('Y', 1), ('8', 2), ('P', 1), (' ', 9), ('8', 3), (' ', 2), ('8', 3), (' ', 4), ('Y', 1), ('8', 3), (' ', 8), ('8', 3), (' ', 3), ('T', 1), ('8', 2), ('b', 1), (' ', 2), ('"', 1), ('Y', 1), ('8', 4), ('P', 1), ('"', 1), (' ', 3), ('"', 1), ('Y', 1), ('8', 4), ('P', 1), ('"', 1), (' ', 3), ('"', 1), ('Y', 1), ('8', 4), ('P', 1), ('"', 1), (' ', 3), ('"', 1), ('Y', 1), ('8', 5), ('P', 1), ('"', 1), (' ', 2), ('8', 3), (' ', 2), ('8', 3), (' ', 2), ('8', 3), (' ', 1)]

[(' ', 163)]
```

Er.. still don't know what I'm looking at.

### RUN LENGTH ENCODING (RLE)

After further research, came across something called `run length encoding`..

```
Run-length encoding (RLE) is a very simple form of lossless data compression
in which runs of data (that is, sequences in which the same data value occurs
in many consecutive data elements) are stored as a single data value and
count, rather than as the original run.

https://en.wikipedia.org/wiki/Run-length_encoding
```

Looking at our data lists, this could fit so let's search for some code that
would help us decode this and enhance our script.

```
$ cat unpickle3.py 
# Run Length Encoding functions
# http://rosettacode.org/wiki/Run-length_encoding#Python

def encode(input_string):
    count = 1
    prev = ''
    lst = []
    for character in input_string:
        if character != prev:
            if prev:
                entry = (prev,count)
                lst.append(entry)
                #print lst
            count = 1
            prev = character
        else:
            count += 1
    else:
        try:
            entry = (character,count)
            lst.append(entry)
            return (lst, 0)
        except Exception as e:
            print("Exception encountered {e}".format(e=e)) 
            return (e, 1)
 
def decode(lst):
    q = ""
    for character, count in lst:
        q += character * count
    return q
 
### END RLE FUNCTIONS ###

import sys
import pickle

f = open(sys.argv[1], "r")
mydata = pickle.load(f)
f.close

for i in mydata:
  unpkl_data = decode(i)
  print unpkl_data
```

```
$ python unpickle3.py donotshare
                                                                                                                                                                   
 .d8888b.            d888       888  .d8888b.                      d8888  888b    888        8888888b.   .d8888b.  888888888  888888888  888     888               
d88P  Y88b          d8888       888 d88P  Y88b                    d8P888  8888b   888        888   Y88b d88P  Y88b 888        888        888     888               
888    888            888       888 888    888                   d8P 888  88888b  888        888    888 888    888 888        888        888     888               
888        888  888   888   .d88888 888    888        888  888  d8P  888  888Y88b 888        888   d88P 888    888 8888888b.  8888888b.  888     888 88888b.d88b.  
888  88888 888  888   888  d88" 888 888    888        888  888 d88   888  888 Y88b888        8888888P"  888    888      "Y88b      "Y88b 888     888 888 "888 "88b 
888    888 888  888   888  888  888 888    888 888888 Y88  88P 8888888888 888  Y88888 888888 888 T88b   888    888        888        888 888     888 888  888  888 
Y88b  d88P Y88b 888   888  Y88b 888 Y88b  d88P         Y8bd8P        888  888   Y8888        888  T88b  Y88b  d88P Y88b  d88P Y88b  d88P Y88b. .d88P 888  888  888 
 "Y8888P88  "Y88888 8888888 "Y88888  "Y8888P"           Y88P         888  888    Y888        888   T88b  "Y8888P"   "Y8888P"   "Y8888P"   "Y88888P"  888  888  888 
```

Neat! That worked and yielded us some text in the form of ASCII art.
Gu1d0-v4N-R055Um?

```
Guido van Rossum is a Dutch programmer best known as the author of the Python
programming language, for which he was the "Benevolent Dictator For Life"
(BDFL) until he stepped down from the position in July 2018.

https://en.wikipedia.org/wiki/Guido_van_Rossum
```

### BACK TO INDEX.HTML

Using `Gu1d0-v4N-R055Um` as the password to our `index.html` page yields the
our key..

<img src="index_html_success.jpg" width=250px/>

### APPENDIX

For fun, we could've simplified our unpickle script to as follows..

```
$ cat unpickle4.py 
import sys
import pickle

f = open(sys.argv[1], "r")
mydata = pickle.load(f)
f.close

for i in mydata:
  row=[]
  for elem in i:
    sym=elem[0]
    num=elem[1]
    row.append(sym * num)
  print ''.join(row)
```

```
$ python unpickle4.py donotshare 
                                                                                                                                                                   
 .d8888b.            d888       888  .d8888b.                      d8888  888b    888        8888888b.   .d8888b.  888888888  888888888  888     888               
d88P  Y88b          d8888       888 d88P  Y88b                    d8P888  8888b   888        888   Y88b d88P  Y88b 888        888        888     888               
888    888            888       888 888    888                   d8P 888  88888b  888        888    888 888    888 888        888        888     888               
888        888  888   888   .d88888 888    888        888  888  d8P  888  888Y88b 888        888   d88P 888    888 8888888b.  8888888b.  888     888 88888b.d88b.  
888  88888 888  888   888  d88" 888 888    888        888  888 d88   888  888 Y88b888        8888888P"  888    888      "Y88b      "Y88b 888     888 888 "888 "88b 
888    888 888  888   888  888  888 888    888 888888 Y88  88P 8888888888 888  Y88888 888888 888 T88b   888    888        888        888 888     888 888  888  888 
Y88b  d88P Y88b 888   888  Y88b 888 Y88b  d88P         Y8bd8P        888  888   Y8888        888  T88b  Y88b  d88P Y88b  d88P Y88b  d88P Y88b. .d88P 888  888  888 
 "Y8888P88  "Y88888 8888888 "Y88888  "Y8888P"           Y88P         888  888    Y888        888   T88b  "Y8888P"   "Y8888P"   "Y8888P"   "Y88888P"  888  888  888 
```

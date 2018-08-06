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

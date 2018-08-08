#*****************************************************************************
#* File:    unpickle1.py
#* Purpose: read in and print out contents of Python pickle file using
#*          Run Length Encoding to decode the data
#* Date:    August 6, 2018
#* Author:  fortyfunbobby
#*****************************************************************************
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

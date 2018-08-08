#*****************************************************************************
#* File:    unpickle2.py
#* Purpose: read in and print out contents of Python pickle file 
#* Date:    August 6, 2018
#* Author:  fortyfunbobby
#*****************************************************************************
import sys
import pickle

f = open(sys.argv[1], "r")
mydata = pickle.load(f)
f.close

for i in mydata:
  print i
  print '\n'

#*****************************************************************************
#* File:    unpickle1.py
#* Purpose: read in and print out contents of Python pickle file
#* Date:    August 6, 2018
#* Author:  fortyfunbobby
#*****************************************************************************
import sys
import pickle

f = open(sys.argv[1], "r")
mydata = pickle.load(f)
f.close

print(type(mydata))
print(mydata)

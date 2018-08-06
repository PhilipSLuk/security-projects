import sys
import pickle

f = open(sys.argv[1], "r")
mydata = pickle.load(f)
f.close

for i in mydata:
  print i
  print '\n'

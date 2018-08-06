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

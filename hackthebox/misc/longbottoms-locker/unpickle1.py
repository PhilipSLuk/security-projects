import sys
import pickle

f = open(sys.argv[1], "r")
mydata = pickle.load(f)
f.close

print(type(mydata))
print(mydata)

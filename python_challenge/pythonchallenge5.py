import re
import pickle

openfile = file('banner.p', 'r')
data = pickle.load(openfile)

for row in data:
    output = ''
    for entry in row:
        output += entry[0]*entry[1]
    print output

openfile.close()

    

import re
import urllib2
url = "http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing="
number = "49574"
count = 1
while True:
    file = urllib2.urlopen(url+number)
    text = file.read()
    print text
    
    numbers = re.findall(r'nothing is ([0-9]+)', text)

    if text.find('two') != -1:
        number = str(int(number)/2)
        print "result is " + number
        continue
    
    if len(numbers) == 0:
        break
    
    number = ''.join(numbers)
    print number
    file.close()



    

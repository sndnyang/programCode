import zipfile
import re

num = '90052'

zipobj = zipfile.ZipFile("channel.zip")
comments = ''
while True:
    text = zipobj.read(num + '.txt')
    comments += zipobj.getinfo(num + '.txt').comment

    nextNum = re.findall('Next nothing is ([0-9]+)', text)

    if len(nextNum) == 0:
        print text
        break;

    num = nextNum[0]
    
print comments
    

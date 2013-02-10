import re
import urllib2

file = urllib2.urlopen("http://www.pythonchallenge.com/pc/def/equality.html")
text = file.read()
letters = re.findall(r'[^A-Z][A-Z]{3}([a-z])[A-Z]{3}[^A-Z]', text)

print ''.join(letters)
file.close()

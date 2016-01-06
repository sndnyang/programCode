import re
import urllib2

page = urllib2.urlopen("http://www.pythonchallenge.com/pc/def/ocr.html")
text = page.read()
find_begin = text.find('-->') + len('-->')
text = text[find_begin:]
result = re.findall(r'[a-z]', text)
print ''.join(result)
page.close()

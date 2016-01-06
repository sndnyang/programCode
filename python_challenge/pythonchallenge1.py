import re
import urllib2

page = urllib2.urlopen("http://www.pythonchallenge.com/pc/def/map.html")
text = page.read()
page.close()

find_begin = text.find('g f')
find_end = text.find('spj.') + len('spj.')

text = text[find_begin:find_end]

import string
character = string.lowercase
map_char = character[2:]+character[:2]

table = string.maketrans(character, map_char)
print string.translate(text, table)

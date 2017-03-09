#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: three_points_circle 
# Created: 2014-09-07 18:29:40
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def checkio(data):

    #replace this for solution
    import re
    pos = re.findall('\d+[.0-9]*', data)
    print(pos)
    return ""

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio("(2,2),(6,2),(2,6)") == "(x-4)^2+(y-4)^2=2.83^2"
    assert checkio("(3,7),(6,9),(9,7)") == "(x-6)^2+(y-5.75)^2=3.25^2"


#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: ghost_detect.py 
# Created: 2014-08-30 22:11:21
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def recognize(number):
    """
    Is it a normal ship?
    """
    import re
    result = re.sub(r'0+', '0', bin(number)[2:])              
    zp = result.find('0')
    return zp * 3 + 2== len(result)  and result[-zp-1] == '0' 

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert recognize(21) == True, "First example"
    assert recognize(1587) == True, "Second example"
    assert recognize(3687) == False, "Thid example"
    assert recognize(233415) == False, "Thid example"

#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: number_factory 
# Created: 2014-09-06 23:09:26
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def checkio(n):
    #replace this for solution
    if n < 10: return n
    for i in range(9,1,-1):
        if not n%i:
            print i, n/i
            p = checkio(n/i)
            print p
            if not p: continue
            return int(str(p) + str(i)) 
    return 0

print checkio(20)
assert checkio(21) == 37, "2nd example"
assert checkio(17) == 0, "3rd example"
assert checkio(33) == 0, "4th example"
assert checkio(3125) == 55555, "5th example"
assert checkio(9973) == 0, "6th example"

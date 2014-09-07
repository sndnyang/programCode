#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: coin_golf 
# Created: 2014-09-06 23:37:39
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def r(c,x):
    if c[0]==x:return 0
    if len(c)<=1:return 1
    print c, x
    return min(r(c[1:],x),r(c[1:],x-c[0])) 

def golf(c):
    return min([x for x in range(1,100)if r(c,x)])

r=lambda c,x:0 if c[0]==x else 1 if len(c)<2 else min(r(c[1:],x),r(c[1:],x-c[0]))
golf=lambda c:min(x for x in range(1,100)if r(c,x))

c=[9, 2, 2, 1]
c=[1, 2, 3, 4, 5]
print golf(c)

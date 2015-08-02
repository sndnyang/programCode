#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: degreeofdirtiness 
# Created: 2015-08-02 11:16:58
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

T = input()

for i in range(T):
    eles = raw_input().split()
    N = int(eles[0])
    M = int(eles[1])

    dirty = (M-1) / N
    pos = (M-1) % N +1

    if N%2 and dirty % 2:
        N -= 1
        pos -= 1

    m = (pos+1) / 2
    if M % 2:
        print m, dirty
    else:
        print N-m+1, dirty


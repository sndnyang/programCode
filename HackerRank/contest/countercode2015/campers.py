#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: campers 
# Created: 2015-08-02 11:48:43
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

l = raw_input().split()
N = int(l[0])
K = int(l[1])

sniper = sorted([int(e) for e in raw_input().split()])

count = (sniper[0] - 1) / 2 + (N - sniper[-1]) / 2
print 'head tail ', count,
for i in range(1, len(sniper)):
    count += (sniper[i] - 1 -sniper[i-1] - 1) / 2

print count + K



#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: imba 
# Created: 2015-08-02 13:45:01
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

T = input()
for i in range(T):
    n = input()
    l = []
    for j in range(1, n+1):
        l.append(n+1-(j+1)/2 if j%2 else j / 2)
    print ' '.join(str(e) for e in l[::-1])

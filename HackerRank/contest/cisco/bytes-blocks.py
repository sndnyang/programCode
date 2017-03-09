#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: bytes-blocks 
# Created: 2015-04-12 09:27:56
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

from collections import defaultdict

if __name__ == '__main__':
    try:
        N = input()
        pairs = defaultdict(set)

        for i in range(N):
            block = raw_input()
            for e in pairs:
                if e+block == (e+block)[::-1] or (block+e == (block+e)[::-1]):
                    pairs[e].add(block)
        
    except EOFError:
        pass


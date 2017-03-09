#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: fizz_buzz 
# Created: 2015-02-07 13:53:03
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

import sys

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if not test: continue
    
    x, y, n = (int(e) for e in test.split())
    
    results = []
    for i in range(1, n+1):
        s = ''
        if i % x == 0: s += 'F'
        if i % y == 0: s += 'B'
        if s == '': s = str(i)
        results.append(s)

    print ' '.join(results)


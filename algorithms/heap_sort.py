#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: heap_sort 
# Created: 2014-10-17 22:23:20
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def heap_adjust(data):
    l = len(data) - 1
    while l > 0:
        up = l/2
        if data[up] > data[l]: break
        data[up], data[l] = data[l], data[up]
        l = up

if __name__ == "__main__":

    test = "99 95 58 89 71 38 35 26 79 59"

    data = [int(x) for x in test.split()]

    new = "70 93 27"

    for e in new.split():
        data.append(int(e))
        heap_adjust(data)
        #print ' '.join([str(e) for e in data])

    test = "97 90 84 76 89 56 14 34 49 66"

    data = [int(x) for x in test.split()]

    for i in range(3):
        data[0], data[-1] = data[-1], data[0]
        

        data.pop()


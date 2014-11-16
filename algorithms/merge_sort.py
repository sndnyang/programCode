#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: sort 
# Created: 2014-10-16 20:35:03
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

count = 0

def sort(a, l, h):
    if h <= l: return
    m = (l+h) / 2
    sort(a, l, m)
    sort(a, m+1, h)
    merge(a, l, m, h)
    
def bottom_up_sort(a, l):
    size = 1
    while size < l:
        for k in range(0, l, size*2):
            merge(a, k, k+size-1,min(k+2*size-1,l-1))

        size *= 2

def merge(ori, l, m, h):
    global count
    count += 1
    aux = ori[:]

    i, j = l, m+1
    for k in range(l, h+1):
        if i > m: 
            ori[k] = aux[j]
            j += 1
        elif j > h: 
            ori[k] = aux[i]
            i += 1
        elif aux[j] < aux[i]: 
            ori[k] = aux[j]
            j += 1
        else: 
            ori[k] = aux[i]
            i += 1

    print count, " ".join([str(x) for x in ori])
    
if __name__ == "__main__":

    test = "41 40 38 90 87 20 71 21 49 66"

    data = [int(x) for x in test.split()]

    bottom_up_sort(data, len(data))



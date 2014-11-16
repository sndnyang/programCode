#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: quick_sort 
# Created: 2014-10-16 21:04:38
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def selection(data, l, h):
    pass

def partition_for(data, l, h):
    selection(data, l, h)
    pass

def partition(data, l, h):
    selection(data, l, h)

    guard = data[l]

    i, j = l+1, h
    while i<j:

        i += 1
        while data[i] < guard:
            i += 1
            if i >= h:break

        j -= 1
        while data[j] > guard:
            j -= 1
            if l >= j:break

        if j <= i: break
        data[i], data[j] = data[j], data[i]

    data[l], data[i-1] = data[i-1], data[l]
    return i


def qsort(data, l, h):
    if l >= h: return

    k = partition(data, l, h)
    print ' '.join([str(x) for x in data])
    #qsort(data, l, k-1)
    #qsort(data, k+1, h)


if __name__ == "__main__":

    test = "B A A A B A A A B A A B "

    #data = [int(x) for x in test.split()]
    data = test.split()

    qsort(data, 0, len(data)-1)



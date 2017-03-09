#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: big-file-search 
# Created: 2015-04-12 08:54:20
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

from collections import defaultdict
def index_single(rindex, n, data):
    for i in data:
        rindex[i].add(n)

def reverse_index(N):
    rindex = defaultdict(set)
    for i in range(N):
        data = raw_input().split()
        index_single(rindex, i, data[1:])

    return rindex

def query_all(rindex, array):
    files = rindex[array[0]]
    for e in array[1:]:
        files = files.intersection(rindex[e])
    return files

def query_any(rindex, array):
    files = rindex[array[0]]
    for e in array[1:]:
        files = files.union(rindex[e])
    return files

def query_some(rindex, array):
    return set.difference(query_any(rindex, array),
                          query_all(rindex, array))

if __name__ == '__main__':

    N = input()
    rindex = reverse_index(N)

    Q = input()
    fmap = {'1':query_all, '2':query_any, '3':query_some}

    for i in range(Q):
        data = raw_input().split()
        T = data[0]
        K = int(data[1])
        print len(fmap[T](rindex, data[2:]))

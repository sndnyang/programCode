#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: find_friends 
# Created: 2014-09-06 21:28:59
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

from collections import defaultdict
def init(n):
    g = defaultdict(list)
    for pair in n:
        u, v = pair.split('-')
        g[u].append(v)
        g[v].append(u)
    return g

def is_connect(graph, l, u, v):
    l[u] = 1
    if v in graph[u]: return True
    return any(nv for nv in graph[u] if nv not in l and is_connect(graph, l, nv, v))

def check_connection(network, f, s):
    graph = init(network)

    color = {}
    return is_connect(graph, color, f, s)

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert check_connection(
        ("dr101-mr99", "mr99-out00", "dr101-out00", "scout1-scout2",
         "scout3-scout1", "scout1-scout4", "scout4-sscout", "sscout-super"),
        "scout2", "scout3") == True, "Scout Brotherhood"
    assert check_connection(
        ("dr101-mr99", "mr99-out00", "dr101-out00", "scout1-scout2",
         "scout3-scout1", "scout1-scout4", "scout4-sscout", "sscout-super"),
        "super", "scout2") == True, "Super Scout"
    assert check_connection(
        ("dr101-mr99", "mr99-out00", "dr101-out00", "scout1-scout2",
         "scout3-scout1", "scout1-scout4", "scout4-sscout", "sscout-super"),
        "dr101", "sscout") == False, "I don't know any scouts."

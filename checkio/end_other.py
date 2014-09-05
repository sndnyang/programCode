#!/usr/bin/env python3
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: end_other.py 
# Created: 2014-09-02 22:59:48
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def contain(p, wset):
    if len(wset) < 1: return False
    for x in wset:
        if x.endswith(p) or p.endswith(x): return True
    p = wset.pop()
    return contain(p, wset)
    
def checks(words_set):
    if len(words_set) <= 1: return False
    p = words_set.pop()
    return contain(p, words_set)

def checkio(words_set):
    w_set = sorted(words_set, key=lambda x:len(x))
    return any(w.endswith(e) for i, e in enumerate(w_set) for w in w_set[i+1:])


#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio({"hello", "lo", "he"}) == True, "helLO"
    assert checkio({"hello", "la", "hellow", "cow"}) == False, "hellow la cow"
    assert checkio({"walk", "duckwalk"}) == True, "duck to walk"
    assert checkio({"one"}) == False, "Only One"
    assert checkio({"helicopter", "li", "he"}) == False, "Only end"

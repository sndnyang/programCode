#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: min_max_built 
# Created: 2014-09-07 10:18:33
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def best(args, kwargs, comp):
    try: it = iter(*args)
    except TypeError: it = iter(args)
    key = kwargs.get("key", lambda x: x)
    m = key(next(it))
    for a in it: 
        m = m if comp(m, key(a)) else a
    return m
    
def min(*args, **kwargs):
    return best(args, kwargs, lambda x,y:x<y)

def max(*args, **kwargs):
    return best(args, kwargs, lambda x,y:x>y)


if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert max(2.2, 5.6, 5.9, key=int) == 5.6, "Two maximal items"
    assert min([[1, 2], [3, 4], [9, 0]], key=lambda x: x[1]) == [9, 0], "lambda key"
    assert max(3, 2) == 3, "Simple case max"
    assert min(3, 2) == 2, "Simple case min"
    assert min("hello") == "e", "From string"
    assert max([1, 2, 0, 3, 4]) == 4, "From a list"
    assert min(abs(i) for i in range(-10, 10)) == 0, "abs"


#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: golden_pyramid.py 
# Created: 2014-09-02 21:28:58
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def count_gold(pyramid):
    """
    Return max possible sum in a path from top to bottom
    """
    #replace this for solution
    layer = [0] * len(pyramid)
    for l in pyramid:
        new_layer = list(l)
        for j in range(len(l)):
            if j == 0: new_layer[j] += layer[0]
            elif j == len(l)-1: new_layer[j] += layer[-1]
            else:
                if layer[j] > layer[j-1]:
                    new_layer[j] += layer[j]
                else:
                    new_layer[j] += layer[j-1]

        layer = new_layer

    return max(layer)


if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert count_gold((
        (1,),
        (2, 3),
        (3, 3, 1),
        (3, 1, 5, 4),
        (3, 1, 3, 1, 3),
        (2, 2, 2, 2, 2, 2),
        (5, 6, 4, 5, 6, 4, 3)
    )) == 23, "First example"
    assert count_gold((
        (1,),
        (2, 1),
        (1, 2, 1),
        (1, 2, 1, 1),
        (1, 2, 1, 1, 1),
        (1, 2, 1, 1, 1, 1),
        (1, 2, 1, 1, 1, 1, 9)
    )) == 15, "Second example"
    assert count_gold((
        (9,),
        (2, 2),
        (3, 3, 3),
        (4, 4, 4, 4)
    )) == 18, "Third example"


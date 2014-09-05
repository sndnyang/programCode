#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: count_inversions.py 
# Created: 2014-09-05 20:52:50
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def count_inversion(seq):

    return sum(seq[j]<seq[i] for i in range(len(seq)-1) for j in range(i,len(seq)) )

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert count_inversion((5, 3, 2, 1, 0)) == 10, "Reversed"
    assert count_inversion((1, 2, 5, 3, 4, 7, 6)) == 3, "Example"
    assert count_inversion((0, 1, 2, 3)) == 0, "Sorted"
    assert count_inversion((99, -99)) == 1, "Two numbers"

#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: greedy 
# Created: 2015-03-07 11:10:01
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#   贪心算法实现
#  
#####################################################
import copy

def greedy_process(items, comp_func=None, callback=copy.copy, *argv):
    
    sorted_items = sorted(items, cmp=comp_func)

    return callback(sorted_items, *argv)


if __name__ == '__main__':
    i = [123,64,234,1562,6234,2652,4234,61346,236,234]
    print greedy_process(i)
    print greedy_process(i, lambda x,y:-cmp(x,y))

    test = [[8, 50], [74, 59], [31, 73], [45, 79], [24, 10], [41, 66], [93, 43], [88, 4], [28, 30], [41, 13]]

    print greedy_process(test, lambda x,y:x[0]+y[1]<y[0]+x[1])


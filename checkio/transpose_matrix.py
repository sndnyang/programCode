#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: transpose_matrix.py 
# Created: 2014-09-03 21:47:30
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def checkio(data):

    #replace this for solution
    new_data = []
    for i in range(len(data[1])):
        new_data.append([])

    print new_data
    for l in data:
        for i in range(len(l)):
            new_data[i].append(l[i])
            
    print new_data
    return new_data

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio([[1, 2, 3],
                    [4, 5, 6],
                    [7, 8, 9]]) == [[1, 4, 7],
                                    [2, 5, 8],
                                    [3, 6, 9]], "Square matrix"
    assert checkio([[1, 4, 3],
                    [8, 2, 6],
                    [7, 8, 3],
                    [4, 9, 6],
                    [7, 8, 1]]) == [[1, 8, 7, 4, 7],
                                    [4, 2, 8, 9, 8],
                                    [3, 6, 3, 6, 1]], "Rectangle matrix"

    assert checkio([[1,8]]) == ([[1],[8]])

#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: safe_coasts.py 
# Created: 2014-08-30 22:57:45
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def has_safe_neighbor(reg_map, i, j):
    rel_map = [(-1,-1), (0, -1), (1, -1), (-1, 0), (1, 0), (-1, 1), (0, 1), (1, 1)]
    for x, y in rel_map:
        if -1 < i+x < len(reg_map)  and -1 < j+y < len(reg_map[i]) and reg_map[i+x][j+y] == 'X':
            return True

    return False

def unsafe_neighbor(reg_map, i, j):
    rel_map = [(0, -1), (-1, 0), (1, 0), (0, 1)]
    for x, y in rel_map:

        if -1 < i+x < len(reg_map)  and -1 < j+y < len(reg_map[i]) and reg_map[i+x][j+y] != 'D' \
           and not has_safe_neighbor(reg_map, i+x, j+y):
            reg_map[i+x][j+y] = 'D'
            unsafe_neighbor(reg_map, i+x, j+y)


def finish_map(regional_map):

    unsafe_list = []
    list_map = []
    for i in range(len(regional_map)):
        list_map.append(list(regional_map[i]))
        for j in range(len(regional_map[i])):
            if regional_map[i][j] == 'D':
                unsafe_list.append((i, j))

    for i, j in unsafe_list:
        unsafe_neighbor(list_map, i, j)

    for i in range(len(list_map)):
        for j in range(len(list_map[i])):
            if list_map[i][j] == '.':
                list_map[i][j] = 'S'

    regional_map = []
    for i in range(len(list_map)):
        regional_map.append(''.join(list_map[i]))

    print regional_map
    return regional_map

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert list(finish_map(("D..XX.....",
                            "...X......",
                            ".......X..",
                            ".......X..",
                            "...X...X..",
                            "...XXXXX..",
                            "X.........",
                            "..X.......",
                            "..........",
                            "D...X....D"))) == ["DDSXXSDDDD",
                                                "DDSXSSSSSD",
                                                "DDSSSSSXSD",
                                                "DDSSSSSXSD",
                                                "DDSXSSSXSD",
                                                "SSSXXXXXSD",
                                                "XSSSSSSSSD",
                                                "SSXSDDDDDD",
                                                "DSSSSSDDDD",
                                                "DDDSXSDDDD"], "Example"
    assert list(finish_map(("........",
                            "........",
                            "X.X..X.X",
                            "........",
                            "...D....",
                            "........",
                            "X.X..X.X",
                            "........",
                            "........",))) == ["SSSSSSSS",
                                               "SSSSSSSS",
                                               "XSXSSXSX",
                                               "SSSSSSSS",
                                               "DDDDDDDD",
                                               "SSSSSSSS",
                                               'XSXSSXSX',
                                               "SSSSSSSS",
                                               "SSSSSSSS"], "Walls"
    assert isinstance(finish_map(("D..", "...", "...")), (list, tuple)), "List or tuple"


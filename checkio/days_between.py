#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: days_between.py 
# Created: 2014-09-05 22:21:43
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def days_diff(date1, date2):
    from datetime import date
    print date2[0], date2[1], date2[2]
    print (date(1982, 4, 22) - date(1982, 4, 19)).days
    return abs((date(date2[0], date2[1], date2[2]) - date(date1[0], date1[1], date1[2])).days)

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert days_diff((1982, 4, 19), (1982, 4, 22)) == 3
    assert days_diff((2014, 1, 1), (2014, 8, 27)) == 238
    assert days_diff((2014, 8, 27), (2014, 1, 1)) == 238

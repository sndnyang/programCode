#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: secure_password 
# Created: 2015-04-11 22:57:14
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

if __name__ == '__main__':

    T = input()
    for i in range(T):
        data = raw_input()
        data = data.split()
        m = int(data[0])
        M = int(data[1])
        count = sum(10**j for j in range(m, M+1))
        if count > 1000000:
            print 'YES'
        else:
            print 'NO'



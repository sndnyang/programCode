#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: remove-duplicates 
# Created: 2014-11-22 09:49:32
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        no_dup = []
        for e in A:
            print no_dup, e
            if not no_dup or e != no_dup[-1]:
                no_dup.append(e)
        print no_dup
                
        return len(no_dup)

test = Solution()

print test.removeDuplicates([1,1,2])

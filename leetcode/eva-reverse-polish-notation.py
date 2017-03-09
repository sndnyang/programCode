#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: eva-reverse-polish-notation 
# Created: 2014-11-22 10:00:01
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        stack = []

        for e in tokens:
            if e in '+-*/':
                l = stack.pop()
                f = stack.pop()
                r = eval(f + e + l)
                stack.append(str(r))
            else:
                stack.append(e)
            print stack
                
        print stack
        return int(stack[0])

test = Solution().evalRPN(['2', '1', '+'])
test = Solution().evalRPN(["4", "13", "5", "/", "+"] )

#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: prime_palindrome_golf 
# Created: 2014-09-05 23:36:53
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def golf(n):
    n+=1;
    while str(n)!=str(n)[::-1] or any(x for x in range(2,int(n**0.5)+1) if not n%x):n+=1
    return n

def golf2(n):
    n+=1;
    while str(n)!=str(n)[::-1] or any(x for x in range(2,int(n**0.5)+1) if not n%x):n+=1+n%2
    return n

prime=lambda n:not any(x for x in range(2,int(n**0.5)+1) if not n%x)

print prime(1041)
print prime(1042)
print prime(131)

print golf(1041)





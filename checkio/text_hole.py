#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: text_hole 
# Created: 2014-09-07 17:31:44
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

from re import match as m
golf3=lambda t,r=range,l=len:sum(1 for i in r(1,l(t)-1) for j in r(l(t[i])-2) if m('\S \S', t[i][j:j+3]) and m('\S{3}',t[i-1][j:j+3]) and m('\S{3}',t[i+1][j:j+3]))

golf=lambda t,r=range,l=len:sum(1 for i in r(1,l(t)-1)for j in r(l(t[i])-2)if t[i][j+1]==' ' and ''.join(t[i-1+p][j:j+3]for p in r(3)).count(' ')==1)


r=range
def golf2(t):
    for i in r(1,len(t)-1):
        for j in r(len(t[i])-2):
            if m('\S \S', t[i][j:j+3]) and m('\S{3}',t[i-1][j:j+3]) and m('\S{3}',t[i+1][j:j+3]):
                print i, j
                                                            
def golf(t):
    c = 0
    for i in r(1,len(t)-1):
        for j in r(len(t[i])-2):
            if (t[i][j+1]==' ') and ''.join(t[i-1+p][j:j+3]for p in r(3)).count(' ')==1:
                c += 1
                print i, j
    return c

assert golf(["How are you doing?",
      "I'm fine. OK.",
      "Lorem Ipsum?",
      "Of course!!!",
      "1234567890",
      "0        0",
      "1234567890",
      "Fine! good buy!"]) == 3
assert golf([
"Lorem ipsum dolor",
"sit amet,",
"consectetuer",
"adipiscing elit.",
"Aenean commodo",
"ligula eget dolor.",
"Aenean massa. Cum",
"sociis natoque",
"penatibus et magnis",
"dis parturient",
"montes, nascetur",
"ridiculus mus. Donec",
"quam felis,",
"ultricies nec,",
"pellentesque eu,",
"pretium quis, sem.",
"Nulla consequat",
"massa quis enim.",
"Donec pede justo,",
"fringilla vel,"]) == 11

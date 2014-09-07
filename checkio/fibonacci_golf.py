#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: fibonacci_golf 
# Created: 2014-09-07 00:47:45
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################
def fibgolf(t,n):
    p=t[1:3]
    l={'ib':[0,1],'ri':[0,1,1],'uc':[2,1],'ac':[0,1],'el':[0,1],'er':[3,0,2],'ad':[0,1,1]}[p]
    m={'ri':-3,'ac':-2,'el':-1,'er':-3,'ad':-3} 
    for i in range(n):
        x=l[m[p]] if p in m else 0
        l.append(l[-1]*(p not in ('er', 'ad')) + l[-2] +x)
    return l[n]

if __name__ == '__main__':
    assert fibgolf(u'fibonacci', 10) == 55
    assert fibgolf(u'tribonacci', 10) == 149
    assert fibgolf(u'lucas', 10) == 123
    assert fibgolf(u'jacobsthal', 10) == 341
    assert fibgolf(u'pell', 10) == 2378
    assert fibgolf(u'perrin', 10) == 17
    assert fibgolf(u'padovan', 10) == 9
 #      if t[0] in 'pjt':h+=l[-'pjt'.index(t[0])-1]
 #      if t[1:3] in ('er','ad'):h+= l[-3]-2*l[-1]

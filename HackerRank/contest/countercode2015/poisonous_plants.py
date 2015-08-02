#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: poisonous_plants 
# Created: 2015-08-02 12:08:03
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

def isSorted(plants):
    for i in range(1, len(plants)):
        if plants[i] > plants[i-1]:
            return False
    return True

def day_die(plants):
    alive = [plants[0]]
    day = 1
    flag = 0
    for i in range(1, len(plants)):
        if plants[i] <= plants[i-1]:
            if flag == 0:
                if plants[i] > alive[-1]:
                    flag = 1
                alive.append(plants[i])
            else:
                alive[-1] = plants[i]
                flag += 1
        else:
            flag = 0
        print plants[i], flag

        if flag > day:
            day = flag

    return alive, day


l = input()

plants = [int(e) for e in raw_input().split()]

mini = plants[:]
day = 0

while True:
    if isSorted(mini):
        break
    mini, aday = day_die(mini)
    print mini, aday
    day += aday

print day


#mini = [plants[0]]
#maxday = 1
#
#i = 0
#
#while i < len(plants):
#    if plants[i] <= mini[0]:
#        mini = [plants[i]]
#
#    if plants[i] > mini[-1]:
#        while i+1 < len(plants) and plants[i+1] >= plants[i]:
#            i += 1
#        mini.append(plants[i+1])
#
#    if len(mini) > maxday:
#        maxday = len(mini)
#    i += 1
#    print 'at ', i, mini
#    #print plants[i], 'will die at', day
#
#print maxday
#

#print mini

#for i in range(1, l):
#    if plants[i] <= plants[0]:
#        mini[i] = 0
#        plants[0] = plants[i]
#    if plants[i] >= plants[i-1]:
#        mini[i] = mini[i-1]
#    else:
#        mini[i] = mini[i-1] + 1
#
#print mini
#day = max(mini)
#i = 1
#



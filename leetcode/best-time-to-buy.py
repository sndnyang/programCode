#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: best-time-to-buy 
# Created: 2014-11-19 20:58:12
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        extrems = []
        
        for i in range(1, len(prices)-1):
            if prices[i] > prices[i-1] and prices[i] > prices[i+1]:
                extrems.append(prices[i])

        if prices[0] < extrems[0]:
            extrems = [prices[0]] + extrems
        if prices[-1] > extrems[-1]:
            extrems.append(prices[-1])

        


#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: speech_module.py 
# Created: 2014-08-17 18:37:03
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

FIRST_TEN = ["one", "two", "three", "four", "five", "six", "seven",
                          "eight", "nine"]
SECOND_TEN = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                            "sixteen", "seventeen", "eighteen", "nineteen"]
OTHER_TENS = ['', "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
                            "eighty", "ninety"]
HUNDRED = "hundred"

pos_map = {1:FIRST_TEN, 2:OTHER_TENS, 3:[x+' '+HUNDRED for x in FIRST_TEN]}

def checkio(number):

    #replace this for solution
    speech = ''
    numStr = str(number)
    numlen = len(numStr)

    for i in range(numlen):
        digit = int(numStr[i])
        dic = pos_map[numlen - i]
        print digit, dic

        if i != 0 and digit != 0: speech += ' '

        if i == numlen - 2 and digit == 1:
            speech += SECOND_TEN[number%10]
            break

        if digit == 0: continue
        speech += dic[digit-1] 

    print speech
    return speech

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio(4) == 'four', "1st example"
    assert checkio(133) == 'one hundred thirty three', "2nd example"
    assert checkio(12) == 'twelve', "3rd example"
    assert checkio(101) == 'one hundred one', "4th example"
    assert checkio(212) == 'two hundred twelve', "5th example"
    assert checkio(40) == 'forty', "6th example"
    assert not checkio(212).endswith(' '), "Don't forget strip whitespaces at the end of string"


#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: 89_roman_numerals.py 
# Created: 2014-08-17 14:54
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#    题意都没看懂…
#  
#####################################################

import sys

class RomanNum:
    def __init__(self):
        self.note = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        self.char = {1:'I', 5:'V', 10:'X', 50:'L', 100:'C', 500:'D', 1000:'M', 5000:'MMMMM'}
        
    def sum(self, string):
        i = len(string) - 1
        while string[i] not in self.note.keys(): i -= 1

        roman_sum = 0
        while i >= 0:
            item = string[i]
            value = self.note[item]
            if i > 0:
                former = self.note[string[i-1]] 
                if former < value:
                    value -= former
                    i -= 1
            roman_sum += value
            i -= 1
        return roman_sum

    def convert_single(self, num, mod):
        if mod >= 1000: return num * 'M'
        if num == 4 or num == 9: 
            return self.char[mod] + self.char[(num+1) * mod]
        else :
            big_5 = num / 5
            mod_5 = num % 5
            return big_5 * self.char[mod * 5] + mod_5 * self.char[mod]

    def convert(self, num):
        mod = 1
        form = ''
        while 0 < num:
            pos = num % 10
            
            form = self.convert_single(pos, mod) + form

            num /= 10
            mod *= 10

        return form

def roman(file_name):
    open_file = file(file_name)
    roman_engine = RomanNum()

    count = 0
    while True:
        line = open_file.readline()
        if not line: break
        num = roman_engine.sum(line)
        opt_format = roman_engine.convert(num)
        assert roman_engine.sum(opt_format) == num
        if  len(opt_format) >= len(line[:-1]):
            count += 1
        else:
            print opt_format, line[:-1G

    return count

if __name__ == "__main__":
    
    if len(sys.argv) == 1:
        file_name = '89_roman.txt'
    else:
        file_name = sys.argv[1]

    print roman(file_name)

    roman_engine = RomanNum()
    print roman_engine.sum('XLIX')
    print roman_engine.convert(1743)
    print roman_engine.convert(49)
    print roman_engine.convert(24)
    print roman_engine.convert(25)


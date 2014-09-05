#!/usr/bin/env python3
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: mokey_typing.py 
# Created: 2014-09-02 22:23:53
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################
def count_words(text, words):
    count = 0
    for word in text.lower().split():
        for w in words:
            if  word.find(w) > -1:
                count += 1
                break
    return count


if __name__ == '__main__':
    #These u"1sserts" using only for self-checking and not necessary for auto-testing
    assert count_words("How aresjfhdskfhskd you?", {"how", "are", "yo", "hello"}) == 3, "Example"
    assert count_words("Bananas, give me bananas!!!", {"banana", "bananas"}) == 2, "BANANAS!"
    assert count_words("Lorem ipsum dolor sit amet, consectetuer adipiscing elit.",
                       {"sum", "hamlet", "infinity", "anything"}) == 1, "Weird text"


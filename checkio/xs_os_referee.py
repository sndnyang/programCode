#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: xs_os_referee.py 
# Created: 2014-08-17  8:20:50
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#       checkio Xs and Os Referee
#  
#####################################################

def check_row(matrix):
    result = "D"
    for i in range(len(matrix)):
        header = matrix[i][0]
        if header == '.': continue

        lists = matrix[i]
        if lists.count(header) == 3: return header

    return result

def check_col(matrix):
    result = "D"
    for i in range(len(matrix)):
        header = matrix[0][i]
        if header == '.': continue

        lists = header

        for j in range(1, len(matrix)):
            lists += matrix[j][i]

        if lists.count(header) == 3: return header
        
    return result

def check_diag(matrix):

    if matrix[0][0] == matrix[1][1] and matrix[1][1] == matrix[2][2]:
        if matrix[0][0] != '.':
            return matrix[0][0]

    if matrix[2][0] == matrix[1][1] and matrix[1][1] == matrix[0][2]:
        if matrix[2][0] != '.':
            return matrix[2][0]

    return "D"

def checkio(game_result):

    result = "D"
    if result == "D":
        result = check_row(game_result)

    if result == "D":
        result = check_col(game_result)

    if result == "D":
        result = check_diag(game_result)

    return result

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio(["X.O","XO.","OXO"]) == "O", "Os wins"
    assert checkio(["O..","XOX","..O"]) == "O", "Os wins"
    assert checkio([
        u"X.O",
        u"XX.",
        u"XOO"]) == "X", "Xs wins"
    assert checkio([
        u"OO.",
        u"XOX",
        u"XOX"]) == "O", "Os wins"
    assert checkio([
        u"OOX",
        u"XXO",
        u"OXX"]) == "D", "Draw"
    assert checkio([
        u"O.X",
        u"XX.",
        u"XOO"]) == "X", "Xs wins again"

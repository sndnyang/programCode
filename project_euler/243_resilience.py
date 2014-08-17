#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: 243_resilience.py 
# Created: <T_CREATED_TIME>
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################
from CombineMath import PrimeGenerator
import math

primeGener = PrimeGenerator()

def factor(n):
    global primeGener

    res_num = []
    sqr = math.sqrt(n)
    primeGener.generateLarger(sqr)

    prime_list = primeGener.getCurList();

    for i in prime_list:
        if n % i == 0:
            res_num.append(i)
        if i > sqr: break
        i += 2

    return res_num

def resilient(n, res_num):
    tmp = n
    for x in res_num:
        tmp = tmp - tmp/x;

    return tmp

def brute_force():
    n = 1000000
    target = 15499.0 / 94744
    minimum = .2
    while True:
        factor_l = factor(n)
        res_num = resilient(n, factor_l)
        ratio = 1.0 * res_num / n 

        if ratio < minimum:
            print n, " get ", ratio, 
            print factor_l
            minimum = ratio

        if ratio < target:
            print "success!"
            break
        
        if n > 50000000: break

        n += 1

def product(num_list):
    pro = 1
    for n in num_list:
        pro *= n

    return pro

def process():
    
    global primeGener
    prime_list = primeGener.getCurList()
    last_prime = prime_list[-1]

    prod = product(prime_list)
    target = 15499.0 / 94744

    minimum = .2
    while True:
        res_num = resilient(prod, prime_list)
        ratio = 1.0 * res_num / (prod-1)


        if ratio < minimum:
            print prod, " get ", ratio, res_num
            print prime_list
            minimum = ratio

        if ratio < target:
            print "success!"
            break

        last_prime = primeGener.generateLarger(last_prime+1)
        prod *= last_prime
        print prime_list

    print prod

def main():
    global primeGener
    
    target = 15499.0 / 94744
    ratio = 1.0

    i = 1
    while ratio > target:
        ratio *= 1.0 - 1.0/primeGener.getNth(i)
        i += 1

    prime_list = primeGener.getCurList()
    prod = product(prime_list)

    for x in range(1, prime_list[-1]+1):
        multiprod = prod * x
        print multiprod
        res_num = resilient(multiprod, prime_list)
        ratio = 1.0 * res_num / (multiprod - 1)
        if ratio < target:
            print multiprod, res_num, " success get ", target
            break


if __name__ == '__main__':
    main()

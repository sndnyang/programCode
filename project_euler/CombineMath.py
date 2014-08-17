#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: PrimeGenerator.py 
# Created: 2014-08-17 11:33
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

import math

class PrimeGenerator:
    def __init__(self):
        self.prime_list = [2,3,5,7,11,13,17,19,23]
        self.cur_prime = 29

    def generate(self):

        n = self.cur_prime
        sqr_n = math.sqrt(n)
        
        while True:
            flag = True
            for x in self.prime_list:
                if n % x == 0:
                    flag = False
                    break
                if x > sqr_n:
                    break

            if flag == True:
                self.prime_list.append(n)
                break

            n += 2

        self.cur_prime = n+2

    def generateNList(self, n):
        if n < len(self.prime_list):
            return self.prime_list

        while len(self.prime_list) < n:
            self.generate()

        return self.prime_list

    def getNth(self, n):
        if n <= len(self.prime_list):
            return self.prime_list[n-1]

        self.generateNList(n)

        return self.prime_list[-1]

    def generateLarger(self, n):

        if n < self.prime_list[-1]: return self.prime_list[-1]

        while self.prime_list[-1] < n:
            self.generate()

        return self.prime_list[-1]

    def generateLess(self, n):

        self.generateLarger(n)

        return self.prime_list[-2]

    def getCurList(self):
        return self.prime_list

    def getLastPrime(self):
        return self.prime_list[-1]

    def factor(n):

        res_num = []
        sqrt = int(math.sqrt(n))
        primeGener.generateLarger(sqrt)

        prime_list = primeGener.getCurList();

        for i in prime_list:
            if n % i == 0:
                res_num.append(i)
            i += 2

        return res_num


if __name__ == '__main__':
    tester = PrimeGenerator()
   #for i in range(100):
   #    tester.generate()
   #print tester.getCurList()
    
    print tester.generateNList(51)

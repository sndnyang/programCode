/*
 * =====================================================================================
 *
 *       Filename:  single-number.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年11月18日 22时16分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

class Solution {
    public:
        int singleNumber(int A[], int n) {
            int x = 0;
            for (int i = 0; i < n; i++) {
                x = x^A[i];
            }
            return x;
        }
};


int main() 
{
    Solution test;
    int a[10] = {1,2,3,4,4,5,3,2,1};
    printf("%d\n", test.singleNumber(a, 9)); 

}

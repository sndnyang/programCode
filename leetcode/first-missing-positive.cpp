/*
 * =====================================================================================
 *
 *       Filename:  first-missing-positive.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年11月16日 09时54分37秒
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
        int firstMissingPositive(int A[], int n) {

            for (int i = 0; i < n; i++) {
                int tmp = A[i];
                while (tmp > 0 && tmp <= n && tmp != A[tmp-1]) {
                    int t = tmp;
                    tmp = A[tmp-1];
                    A[t-1] = t;
                }
            }

            for (int i = 0; i < n; i++) {
                printf("%d%s", A[i], (i==n-1)?"\n":" ");
            }

            for (int i = 0; i < n; i++) {
                if (i+1 != A[i]) return i+1;
            }
            return n+1;
        }

};

int main() {

    Solution test;

    int test_str[40] = {0};
    printf("%d\n", test.firstMissingPositive(test_str, 1));

    int test_str2[40] = {0, 1,2};
    printf("%d\n", test.firstMissingPositive(test_str2, 3));

    int test_str3[40] = {-1, 3, 4, 1};
    printf("%d\n", test.firstMissingPositive(test_str3, 4));

    int test_str4[40] = {-1,2,-3};
    printf("%d\n", test.firstMissingPositive(test_str4, 3));
}

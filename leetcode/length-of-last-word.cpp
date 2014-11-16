/*
 * =====================================================================================
 *
 *       Filename:  length-of-last-word.cpp
 *
 *    Description:  leetcode 
 *
 *        Version:  1.0
 *        Created:  2014年11月16日 08时51分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiulong.yancey.yang
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            int count = 0;
            for (int i = strlen(s)-1; i >= 0; i--) {
                if (s[i] == ' ' && count != 0)
                    break;
                else if(s[i] == ' ') 
                    continue;
                count++;
            }
            return count;
        }
};

int main() {

    Solution test;

    char test_str[40] = "yang xiulong";
    printf("%d\n", test.lengthOfLastWord(test_str));

    char test_str2[40] = "yang xiulong  ";
    printf("%d\n", test.lengthOfLastWord(test_str2));

    char test_str3[40] = "yang xiu long";
    printf("%d\n", test.lengthOfLastWord(test_str3));

    char test_str4[40] = "yang xiu.long";
    printf("%d\n", test.lengthOfLastWord(test_str4));
}

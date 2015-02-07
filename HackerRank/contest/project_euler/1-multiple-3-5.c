/*
 * =====================================================================================
 *
 *       Filename:  1-multiple-3-5.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年02月07日 14时59分03秒
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

unsigned int single_sum(int n, int k) {
    unsigned int i = n / k;
    return i * (1+i) * k / 2;
}

int main() {

    unsigned int n, k;
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%d", &k);
        printf("%d\n", single_sum(k-1, 3) + single_sum(k-1, 5) - single_sum(k-1, 15));
    }
    return 0;
}

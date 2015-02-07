/*
 * =====================================================================================
 *
 *       Filename:  63-int_powerful-digit-counts.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年02月07日 14时37分25秒
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
#include <string.h>
#include <math.h>

unsigned long int_pow(int x, int n) {
    unsigned long r = 1L;
    while (n-- > 0) r *= x;
    return r;
}

int main() {

    /*  Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n;
    int i = 0;
    scanf("%d", &n);

    unsigned long lower = int_pow(10, n-1), upper = int_pow(10, n);

    while (1) {
        unsigned long r = int_pow(i++, n);
        if (r >= lower && r < upper)
            printf("%ld\n", r); 
        if (r >= upper) break;
    }
    
    return 0;
}

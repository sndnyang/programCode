/*
 * =====================================================================================
 *
 *       Filename:  quick_sort.c
 *
 *    Description:  c语言的快速排序实现
 *
 *        Version:  1.0
 *        Created:  2014年10月17日 20时58分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  杨秀隆
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

void pyprint(int *data, int len)
{
    int i;
    for (i = 1; i <= len; i++)
        printf("%d%s", data[i-1], i==len?"\n":" ");
}

void selection(int *data, int l, int h)
{

}

void swap(int *data, int i, int j)
{
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

int partition(int *data, int l, int h)
{
    int i = l, j = h+1;

    while (1)
    {
        while (data[++i] < data[l])
            if (i >= h) break;

        while (data[--j] > data[l])
            if (l >= j) break;

        if (i >= j) break;

        swap(data, i, j);
    }

    swap(data, l, j);
    return j;

}

void quick_sort(int *data, int l, int h)
{
    selection(data, l, h);
    
    int k = partition(data, l, h);
    pyprint(data, h+1);
}

void my_qsort(int *data, int len)
{
    quick_sort(data, 0, len-1);
}

int main(int argc, char **argv)
{
    int i;
    int data[20];

    for (i = 1; i < argc; i++) 
        data[i-1] = atoi(argv[i]);

    my_qsort(data, argc-1);

}

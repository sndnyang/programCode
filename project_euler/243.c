#include <stdio.h>
#define MAXSIZE 1000024
int a[MAXSIZE];
int main()
{
    int i, j, k = 0;
    double resi = 15499.0 / 94744;
    int prime[100000];
    for (i = 2; i < MAXSIZE; i++)
    {
        if (a[i] == 0)prime[k++] = i;
        for (j = 0; j < k; j++)
        {
            int t = prime[j] * i;
            if (t > MAXSIZE || t < 0)break;
            a[t] = 1;
            if (i % prime[j] == 0)
        break;
        }
    }
    double level = 1.0;
    for (i = 1; ; i++)
    {
        level *= 1.0 * (prime[i] - 1) / prime[i];
        if (level < resi)
        {
            printf("%d\n", i);
            for (j = 0; j <= i; j++)
                printf("%d ", prime[j]);
            break;
        }
    }

    return 0;
}

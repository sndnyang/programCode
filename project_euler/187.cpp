#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k=0;
    int prime[10000]={0},prim[3000];
    for(i=2;i<100;i++)
        for(j=2*i;j<10000;j+=i)
            prime[j]=1;
    for(i=2;i<10000;i++)
       if(prime[i]==0)
       {
            printf("%4d ",i);
            prim[k++]=i;
       }
    printf("%d\n",k);
    printf("%d\n",k*k);
    system("pause");
    return 0;
}

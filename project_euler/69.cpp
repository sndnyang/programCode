#include<stdio.h>
#include<stdlib.h>
int pri[1000004]={0};
int main()
{
    int i,j,k=0;
    int prime[100000];    
    for(i=2;i<1000;i++)
       for(j=2*i;j<1000000;j+=i)
           pri[j]=1;
    for(i=2;i<1000000;i++)
       if(pri[i]==0)
       {
           prime[k]=i;
           k++;
       }
    printf("%d\n",k);
    int mul=1;
    for(i=0;mul<1000000;i++)
    {
        mul*=prime[i];
        printf("*%d =%d\n",prime[i],mul);
    }
    for(i=0;prime[i]<mul;i++);
    printf("%d\n",i);   
    system("pause");
    return 0;
}

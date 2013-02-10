#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,N,K,a[10024],sum=0,mu=1,b[10024];
    scanf("%d%d",&N,&K);
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)
        {
            goto loop;
        }                    
        mu*=a[i];
    }    
    for(i=0;i<N-K;i++)
    {
         b[i]=mu;
         for(j=0;j<=K;j++)
         {
              b[i]/=a[i+j];
         }         
         sum+=b[i];
         sum%=9973;
    }
    loop:printf("%d\n",sum);
    system("pause");
    return 0;
}
         

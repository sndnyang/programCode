#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int prime(int t)
{
    int i;
    for(i=2;i<=sqrt(t);i++)
         if(t%i==0)return 0;
    return 1;
}
int Con(int a,int b)
{
    int t,k;
    for(k=1;;k++)
    {
        t=k*k+a*k+b;
        if(t<0)t=-t;
        if(prime(t)==1)continue;
        else break;
    }
    return k;
}
int main()
{
    int i,j,k=0,t,ti,tj,prime[1024]={0};
    for(i=2;i<33;i++)
        for(j=2*i;j<1000;j+=i)
             if(prime[j]==0)prime[j]=1;
    for(i=3;i<1000;i+=2)
        if(prime[i]==0)        
             for(j=-1000;j<1001;j++)
             {
                  t=Con(j,i);
                  if(k<t)
                  {
                       k=t;ti=i;tj=j;
                  }
             }        
    printf("最多有%d个连续，a,b 分别是%d,%d 结果-> %d\n",k,ti,tj,ti*tj);   
    system("pause");
    return 0;
}
    

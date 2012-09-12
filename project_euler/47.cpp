#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[1000024]={0};
int Con4(int m,int n)
{
    int i;
    for(i=0;i<n;i++)
        if(a[m+i]!=n)
        return 0;
    return 1;
}   
int main()
{
    int i,j,prime[100000],k=0;
    for(i=2;i<1000;i++)
       for(j=2*i;j<1000000;j+=i)
           a[j]=1;
    for(i=2;i<1000000;i++)
       if(a[i]==0)
           prime[k++]=i;
       else a[i]=0;   
    for(i=0;i<k;i++)
        for(j=prime[i];j<1000000;j+=prime[i])
             a[j]++; 
    for(i=2;i<1000000;i++)
    {
        if(Con4(i,4)==1)        
        {
            printf("%d %d %d %d\n",i,i+1,i+2,i+3);
            break;
        }                
    }
    system("pause");
    return 0;
}

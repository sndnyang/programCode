#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[10004]={0};
int pri(int m)
{
    int i;
    for(i=3;i<sqrt(m);i+=2)
        if(m%i==0)
        {
            printf("%d mod %d==0\n",m,i);
        return 0;
        }
    return 1;
}
int main()
{
    int i,j,k=1,prime[10000]={0},n,t[1000],sum;
    for(i=2;i<100;i++)
        for(j=2*i;j<10000;j+=i)
            if(a[j]==0)a[j]=1;    
    for(j=3;j<10000;j++)
        if(a[j]==0)       
            prime[k++]=j;
    for(j=0;j<1000;j++)  
         t[j]=(j+1)*(j+1);        
    for(i=1;i<k;i++)
    {        
        for(j=0;prime[i]+2*t[j]<10000;j++)
        {
            sum=prime[i]+2*t[j];            
            a[sum]=2;          
        }        
    }
    for(i=9;i<10000;i+=2)
        if(a[i]!=2&&pri(i)==0)                    
            break;
    system("pause");
}

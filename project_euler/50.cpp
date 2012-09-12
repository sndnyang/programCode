#include<stdio.h>
#include<stdlib.h>
int a[1000024]={0};
long move;
int pos;
int max;
void Con(int p[],int sum,int x,int y)
{
     int j,k;
     long t=sum;
     for(j=y;j<x-1;j++)    
     {         
         if(t<1000000&&a[t]==0&&x-j>=max&&x-j>500)
         {            
              max=x-j;    
              move++;
              pos=t;               
         }
         t-=p[j];move++;
     }
}
int main()
{
    int i,j,k,prime[100000]={0};
    long sum;
    for(i=2;i<1000;i++)
        for(j=2*i;j<1000000;j+=i)
            if(a[j]==0)a[j]=1;
    k=1;move=0;
    for(j=2;j<1000000;j++)
        if(a[j]==0)       
            prime[k++]=j;
    j=0;        
    for(i=1;i<k;i++)
    {
        sum+=prime[i];  
        move++;        
        Con(prime,sum,i,j);
        while(sum>1000000)
        {     
              sum-=prime[j++];
              move++;
        }
    }          
    printf("%d %d %d\n",pos,max,move);    
    system("pause");
}

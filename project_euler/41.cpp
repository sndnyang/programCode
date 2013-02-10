#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int t;
int prime(int a[],int m)
{
    int i;
    t=0; 
    for(i=0;i<m;i++)     
         t=t*10+a[i];        
    for(i=2;i<=sqrt(t);i++)
         if(t%i==0)return 0;
    printf("sum==%d\n",t);
    return 1;
}
int Con(int p[],int a[],int deep,int m)
{
    int i,t;
    if(deep==m)
        if(prime(p,m)==1)
             return 1;
    for(i=0;i<m;i++)
        if(a[i]!=0)
        {             
             p[deep]=a[i];a[i]=0;
             t=Con(p,a,deep+1,m);             
             a[i]=i+1;
        }
    return t;
}           
int main()
{
    int i,j,p[10],n,a[9];        
    for(n=1;n<9;n++)
    { 
        for(i=0;i<9;i++)a[i]=i+1;       
        if(Con(p,a,0,n)==0)break;       
    }
    system("pause");
    return 0;
}
         

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int t[6]={1,2,3,5,7,9};
int Judge(int a[],int m)
{
    int i;
    long t=0;
    for(i=0;i<=m;i++)
    {
         t=t*10+a[i];
    }
    for(i=2;i<=sqrt(t);i++)
        if(t%i==0)return 0;
    return 1;         
}
void P(int a[],int m,int n)
{
     int i;
     if(n==m)
     {
        for(i=0;i<n;i++)
            printf("%d",a[i]); 
        printf("\n");
     }
     else
        for(i=0;i<6;i++)
        {
             a[m]=t[i];
             if(Judge(a,m)==1)
                 P(a,m+1,n);
        }
}
int main()
{
    int i,j,k,n,a[10];        
    for(i=2;i<5;i++)
    {
         a[0]=t[i];
         P(a,1,0);
    }
    system("pause");
    return 0;
}
    
    

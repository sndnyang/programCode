#include<stdio.h>
#include<stdlib.h>
int a[505][505];
void odd(int be,int r,int l,int b)
{
    int e,d,k,c;
    e=b/2;   
    d=0;   
    for(c=1;c<=b*b;c++)   
    {   
        a[d+r][e+l]=c+be;
        if(a[(d-1+b)%b+r][(e+1+b)%b+l]==0)   
        {   
            d=(d-1+b)%b;   
            e=(e+1+b)%b;   
        }   
        else  
        {   
            d=(d+1+b)%b;   
            e=e%b;   
        }   
    }
}
void oddeven(int n)
{
     int m=n/4,t,i,j;
     odd(0,0,0,n/2);
     odd(n*n/4,n/2,n/2,n/2);
     odd(n*n/2,0,n/2,n/2);
     odd(3*n*n/4,n/2,0,n/2);
     for(i=0;i<n/2;i++)
         for(j=0;j<m-1;j++)
         {
              t=a[i][n-j-1];
              a[i][n-j-1]=a[i+n/2][n-j-1];
              a[i+n/2][n-j-1]=t;
         }
     for(i=0;i<n/2;i++)
     {
         for(j=0;j<m;j++)
         {
              if(i==m&&j==m-1)j=m;
              t=a[i][j];
              a[i][j]=a[i+n/2][j];
              a[i+n/2][j]=t;
         }
     }
}
void even(int n)
{
     int i,j,k,t;
     for(i=0;i<n;i++)
         for(j=0;j<n;j++)
             a[i][j]=1+i*n+j;
     for(i=0;i<n/2;i++)
     {
         if(i%2==1)j=0;
         else j=1;
             for(;j<n/2;j+=2)
             {
                  k=n-j-1;
                  t=a[i][j];
                  a[i][j]=a[n-i-1][n-j-1];
                  a[n-i-1][n-j-1]=t;
                  t=a[i][k];
                  a[i][k]=a[n-i-1][n-k-1];
                  a[n-i-1][n-k-1]=t;
             }
     }
}
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    if(n%2==1)odd(0,0,0,n);
    else if(n%4==2)oddeven(n);
    else even(n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf(" %d",a[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}

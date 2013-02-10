#include <stdio.h>
#include <stdlib.h>
void print(int a[],int n)
{
     int i;
     for(i=0;i<n;i++)
         printf("%d ",a[i]);
     printf("\n");
}
void Perm(int a[],int m,int n)
{
     int t,j;
     if(m==n)
        print(a,n);
     else
        for(j=m;j<n;j++)
        {
            t=a[j];
            a[j]=a[m];
            a[m]=t;
            Perm(a,m+1,n);
            t=a[j];
            a[j]=a[m];
            a[m]=t;
        }
} 
                               
int main()
{
    int a[20],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        a[i]=i+1;
    Perm(a,0,n); 
    system("pause");
}

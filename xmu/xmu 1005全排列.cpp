#include <stdio.h>
#include <stdlib.h>
int a[9]={0};
void print(int n)
{
     int i;
     for(i=0;i<n;i++)
         printf("%d ",a[i]);
     printf("\n");
}
void Perm(int m,int n)
{
     int t,j,i;
     if(m==n)
        print(n);
     else
        for(i=1;i<=n;i++)
        {
            for(j=0;j<m;j++)
                if(a[j]==i)break;
            if(j==m)
            {          
                a[m]=i;
                Perm(m+1,n);
            }
        }
} 
                               
int main()
{
    int a[20],n,i;
    scanf("%d",&n);    
    Perm(0,n); 
    system("pause");
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,a[20][20],num=0,n,min,p,t[12]={0},q;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    i=0;q=n;
    while(q>1)
    {   
         min=100;          
         for(j=0;j<n;j++)
         {              
              if(a[i][j]!=0&&a[i][j]<min&&t[j]==0)
              {
                   min=a[i][j];
                   p=j;
              }
         }         
         t[i]=1;
         i=p;
         num+=min;
         q--;
    }
    num+=a[i][0];
    printf("%d\n",num);
    system("pause");
    return 0;
}
             
             

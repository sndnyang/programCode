#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,t,i;
    scanf("%d",&n);
     for(i=1;i<n;i++)
             printf("%3d ",i);
             printf("\n");
    for(i=1;i<n;i++)
    {
         
         if(n%i==0)printf("%3d ",i);
         else
         {
         for(t=i/2;t>=2;t--)
             if(n%t==0&&i%t==0)break;
         printf("%3d ",t);
          }
          }
             system("pause");
             return 0;
    }
             

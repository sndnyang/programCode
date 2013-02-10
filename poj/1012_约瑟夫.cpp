#include<stdio.h>
#include<stdlib.h>  
int main()
{
    int m,n,i,t,flag;     
    while(1)
    {
         scanf("%d",&n);
         if(n==0)break;     
         for(i=n+1;;i++)
         {
             t=0;
             m=0;
             for(t=2;t<=n;t++)
             {
                   m=(m+i)%t;
                   if(m<=n)
                   {
                        flag=0;
                        break;
                   }
             }
             if(flag==1)break;
         }
         printf("%d\n",i);
    }
    system("pause");
    return 0;
}

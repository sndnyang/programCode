#include <stdio.h>
#include<stdlib.h>
int main()
{
     int t[4],i,k,m[3];
     for(i=0;i<4;i++)
         scanf("%d",&t[i]);
     for(i=0;i<3;i++)
         m[i]=t[i+1]-t[i];
     if(m[0]==0)printf("no solution\n");
     else
     {
         if(m[1]/m[0]==1)printf("no solution\n");
         else printf("%d\n",t[0]-m[1]/m[0]);
     }
     system("pause");
     return 0;
} 

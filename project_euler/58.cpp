#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<windows.h>
int pri(int n)
{
    int i;
    for(i=2;i<sqrt(n);i++)
         if(n%i==0)return 1;
    return 0;
}
int  main()
{
     int i,n,m,j;
     int t=0,p=1;
     DWORD t1,t2;
     t1=GetTickCount();    
     for(i=3,j=2;;i+=2,j++)
     {
          m=(i-2)*(i-2);        
          n=m+i-1;          
          if(pri(n)==0)t++;          
          n+=i-1;
          if(pri(n)==0)t++;
          n+=i-1;          
          if(pri(n)==0)t++;          
          p+=4;                    
          if(t*1.0/p<0.10)
          {
               t2=GetTickCount();
               printf("%d and %d  %lf\n",i,j,t2-t1);
               break;
          }
     }
     printf("%d and %d\n",i,j);
     system("pause");
     return 0;
     }

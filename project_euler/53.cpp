#include<stdio.h>
#include<stdlib.h>
int m[50];
int C(int n,int r)
{
    int i,t,j,num=1;
    
    for(i=n;i>n-r;i--)
    {
          t=i;
          
          for(j=2;j<r+1;j++)
              if(m[j]==0&&t%j==0)
              {                   
                   m[j]=1;
                   t/=j;
              }
          num*=t;          
    }
    for(j=2;j<r+1;j++)
        if(m[j]==0)
        {
             m[j]=1;
             num/=j;
        }          
    return num;    
}
int main()
{
    int n,i,j,num=0,k;
    for(n=1;n<101;n++)
    {
         for(i=1;i<n/2+1;i++)
         {
              for(j=0;j<50;j++)
                  m[j]=0;             
              k=C(n,i);
              if(k>=1000000)
              { 
                   printf("begin at %d %d =%d",i,n,k);
                   break;
              }
         }
         if(k>=1000000)
         {   
             printf("  ╧╠  овак%d \n",n+1-2*i); 
             num+=n+1-2*i;
         }
    }
    printf("%d\n",num);
    system("pause");
    return 0;
}
             

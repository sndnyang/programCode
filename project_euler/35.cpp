#include<stdio.h>
#include<stdlib.h>
int a[1000024]={0};
int main()
{
    int i,j,num[13],t,k,m=13,b;
    int flag;
    for(i=2;i<1000;i++)
        for(j=2*i;j<1000000;j+=i)
            if(a[j]==0)a[j]=1;    
    for(i=111;i<1000000;i+=2)
    {
         if(a[i]==1)continue;        
         for(j=0;j<7;j++)num[j]=0;
         t=0;j=i;flag=0;
         while(j)
         {
              num[t]=j%10;
              if(j%2==0)
              {                    
                   flag=1;
                   break;
              }
              j/=10;
              t++;
         }                
         if(flag==1)
            continue;
         for(j=0;j<t;j++)
            num[t+j]=num[j];         
         flag=0;
         for(j=0;j<t;j++)
         {
              b=0;
              for(k=0;k<t;k++)
                  b=b*10+num[2*t-1-k-j];
              if(a[b]==1)
              {
                  flag=1;
                  break;
              }                          
         }
         if(flag==0)
         {         
             
             m++;      
         }
    } 
    printf("%d\n",m);
    system("pause");
    return 0;
}

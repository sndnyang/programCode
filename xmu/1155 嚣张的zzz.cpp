#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct 
{
     int po[3];
}Num;
int main()
{
    int n,i,j,p[3],low,high;
    long m;
    Num t[1890];    
    scanf("%d",&n);
    t[0].po[0]=1;
    t[0].po[1]=0;
    t[0].po[2]=0;
    t[0].po[3]=0;
    for(i=1;i<1900;i++)
    {
         for(j=0;j<3;j++)
             t[i].po[j]=t[i-1].po[j];
         m=(i+1)*(i+1);  j=0;
         while(m)
         {              
              t[i].po[j]+=m%10000;              
              m/=10000;              
              j++;
         }                  
         for(j=0;j<4;j++)
              if(t[i].po[j]>9999)
              {
                  t[i].po[j+1]+=t[i].po[j]/10000;
                  t[i].po[j]%=10000;
              } 
         if(t[i].po[2]>21&&t[i].po[1]>4749)
             break;         
    }
    while(n)
    {
            n--;
            for(j=0;j<3;j++)
            p[j]=0;
            low=0;high=i;
            scanf("%ld",m);
            j=0;
            while(m)
            {
                p[j]=m%10000;
                j++;
                m/=10000;
            }
            while(low!=high)
            {
                 if( big(p,  
                       
    }
    system("pause");
    return 0;
} 
            

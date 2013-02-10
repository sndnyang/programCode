#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int For (int p[],int m,int n)
{
    int i,t=m*(3*m-1)+n*(3*n-1),a,b;      
    for(i=sqrt(t/3);;i++)
        if((3*i*i-i)==t)
        {
             printf("%d is ",t);
             printf("at %d\n",i); 
             p[3]=i;
             return 1;
        }
        else if(i*(3*i-1)>t)break;
    
    return 0;
}
int Pn(int p[],int n)
{
    int i,t=n*(3*n-1),a,b,di;
    for(i=1;i<sqrt(t/3);i++)
    {
         di=t/i;
         if(di%3==2&&di*i==t&&i!=n)
         {
              di=(di+1)/3;a=(di+i)/2;b=(di-i)/2;
              if(a<n||b<n||(a>50000||b>50000))continue;   
              if(For(p,a,b)==1)
              {
                    p[0]=n;p[1]=b;p[2]=a;                    
                    return 1;                    
              }                           
         }
    }
}                                   
int main()
{
    int i,a[4]={0};
    for(i=1;i<10000;i++)
       if(Pn(a,i)==1)break;
    printf("\n");
    for(i=0;i<4;i++)
    {
        printf("%d = %d\n",a[i],a[i]*(3*a[i]-1));
    }
    system("pause");
}

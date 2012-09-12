#include<stdio.h>
#include<stdlib.h>
int max;
void Print(int a[],int m,int n,int x)
{
     int i,j,sum=0;    
     for(i=m-1;i>0;i--)
     {          
          j=a[i];          
          while(j)
          {
               sum+=j%10;
               j/=10;
          }
     }     
     j=a[0];
     while(j)
     {
          sum+=j%10;
          j/=10;
     }     
     if(sum>max)
     {
           for(i=m-1;i>-1;i--)
               printf("%d",a[i]);
           printf("\n");
           printf("i=%d,j=%d,sum=%d\n",x,n,sum);     
           max=sum;
     }  
} 
int Mul(int a[],int m,int n)
{
     int i,temp;
     for(i=0;i<30;i++)
         a[i]*=n;    
     for(i=0;i<m;i++)
     {
         temp=a[i]/10000;
         a[i]%=10000;
         a[i+1]=a[i+1]+temp;       
     }
     if(a[i]!=0)m++;
     return m;
}
int main()
{
    int i,j,k,a[1000],m;max=0;
    for(j=2;j<100;j++)
    {
         m=1;if(j%10==0)continue;
         for(i=0;i<1000;i++)a[i]=0;a[0]=j;
         for(i=1;i<100;i++)
         {
               m=Mul(a,m,j);
               Print(a,m,i,j);
         }
    }
    printf("\nmax=%d\n",max);
    system("pause");
    return 0;
}

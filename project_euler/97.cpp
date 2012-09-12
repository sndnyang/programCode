#include<stdio.h>
#include<stdlib.h>
void Print(int a[],int m,int n)
{
     int i;
     for(i=2;i>0;i--)
          printf("%d,",a[i]);
     printf("%d  %d\n",a[0],n);     
}          
int Mul(int a[],int m)
{
     int i,temp;
     for(i=0;i<4;i++)
         a[i]*=2;    
     for(i=0;i<m&&i<4;i++)
     {
         temp=a[i]/10000;
         a[i]%=10000;
         a[i+1]=a[i+1]+temp;       
     }
     if(a[i]!=0&&i<4)m++;
     return m;
}
void mul(int a[])
{
     int i,temp;
     for(i=0;i<4;i++)
         a[i]*=28433;    
     for(i=0;i<4;i++)
     {
         temp=a[i]/10000;
         a[i]%=10000;
         a[i+1]=a[i+1]+temp;       
     }  
}
int main()
{
    int i,j,k,a[10]={1},m=1,b[10]={2,16,128,1024},b1[10]={1,4,7,10,14,17,20},c[10]={5,24,107,510},d[10];
    for(i=0;a[2]<10;i++)
         m=Mul(a,m);   
    Print(a,m,i);    
    for(j=0;j<4;j++)
    {
         d[j]=c[j]-b1[j];
         printf("%d ",d[j]);
    }
    for(j=4;j<10;j++)
    {
         d[j]=d[j-1]*5;
         printf("%d ",d[j]);
    }
    printf("\n%d\n",7830457-d[9]-30);
    i=0;   
    do
    {
          m=Mul(a,m);
          i++;
    }while(i<17927);
    Print(a,m,i);         
    mul(a);
    Print(a,m,i);         
    system("pause");
    return 0;
}

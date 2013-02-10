#include<stdio.h>
#include<stdlib.h>
void print(int a[],int len)
{
    int i;
    for(i=len-1;i>=0;i--)
       printf("%d",a[i]);
    printf("\n");
}
int Eva(int a[],int b)
{
     int t=b,i=0;
     while(t)
     {
          a[i]=t%10;
          t/=10;
          i++;
     }
     return i;
}
int pal(int a[],int len)
{
    int i=0;
    for(i=0;i<len/2;i++)
       if(a[i]!=a[len-1-i])  
             return 0;    
    return 1;
}
int dou(int a[],int len)
{
    int i,temp=0;
    for(i=0;i<len/2;i++)
    {        
        a[i]=a[i]+a[len-1-i];
        a[len-1-i]=a[i];
    }
    if(len%2)a[len/2]*=2;    
    for(i=0;i<len;i++)
    {
        temp=a[i]/10;
        a[i]%=10;
        a[i+1]=a[i+1]+temp;       
    }
    if(a[i]!=0)    
        len++;        
    return len;
}    
int main()
{
    int i,j,a[30],ac,temp,count=0;
    for(i=1;i<=10000;i++)
    {
         for(j=0;j<30;j++)
             a[j]=0;
         ac=Eva(a,i);
         ac=dou(a,ac);         
         temp=1;
         while(temp<50)
         {
              if(pal(a,ac)==1)          
                   break;              
              else 
              {
                   ac=dou(a,ac);
                   temp++;
              }
         }
         if(temp>=50)
         {
              printf("%d\n",i);
              count++;
         }
    }
    printf("%d\n",count);
    system("pause");
    return 0;
}

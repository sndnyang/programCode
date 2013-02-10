#include<stdio.h>
#include<stdlib.h>
int ln;
int acc;
void print(int a[],int b[])
{
     int i;               
     if(b[ln-1]==0)
     {
           acc++;
           printf("   Yes");
     }
     printf("\n");
}     
void Add(int a[],int b[])
{
     int i,t;
     for(i=0;i<ln;i++)
     {
         t=b[i];
         b[i]=b[i]+a[i];
         a[i]=b[i]+t;
     }
      
     for(i=0;i<ln;i++)
     {
         if(a[i]>=10)
         {
             a[i+1]+=a[i]/10;
             a[i]%=10;
         }
         if(b[i]>=10)
         {
             b[i+1]+=b[i]/10;
             b[i]%=10;
         }
     }        
     if(a[ln]!=0)
        ln++;    
}
int main()
{
    int nu[10000]={3},de[10000]={2};
    int i,j;
    ln=1;acc=0;
    printf("1: 3/2\n");
    for(i=1;i<1000;i++)
    {
         Add(nu,de);                 
         printf("%d :",i+1);
         print(nu,de);
    }
    printf("%d\n",acc);
    system("pause");
    return 0;
}

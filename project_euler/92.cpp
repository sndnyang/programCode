#include<stdio.h>
#include<stdlib.h>
int Squ(int n)
{
    int k,i,t=n;    
    while(t!=1&&t!=89)
    {
         k=t;t=0;         
         while(k)
         {
               int temp=k%10;
               t+=temp*temp;
               k/=10;
         }                 
    }  
    return t;
}        
int main()
{
    int i,add=0;
    int temp[600]={0};
    for(i=2;i<=567;i++)
    {
         temp[i]=Squ(i);
         printf("%3d   %2d  ",i,temp[i]);
    }   
    for(i=2;i<10000000;i++)
    {
         int t=i,s=0;
         while(t)
         {
               int te=t%10;
               s+=te*te;
               t/=10;
         }         
         if(temp[s]==89)
               add++;
    }    
    printf("%d\n",add);      
    system("pause");
    return 0;
}
    

#include<stdio.h>
#include<stdlib.h>
long sum;
void Odd(int n)
{
     int i,j,k;
     if(n<5)
     {
         for(i=1;i<10;i+=2)
             for(j=2;j<10;j+=2)
                 if(i+j>9)                                      
                      sum+=10;                 
                 else
                 {
                     sum+=2;
                     Odd(n+1);
                 }
     }
}
int main()
{
    int i,j,k;
    sum=0;
    for(i=1;i<10;i+=2)
         for(j=2;j<10;j+=2)
              if(i+j<=9)sum+=2;
              else       
    Odd(0);
    printf("%ld\n",sum);
    system("pause");
    return 0;
}

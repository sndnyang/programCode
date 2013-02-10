#include<stdio.h>
#include<stdlib.h>   
int main()
{
    int i,j,a[4],t[10],result[10]={0},fi[2]={3,7},k=0,n;
    for(k=0;k<2;k++)
        for(i=0;i<10000;i+=10)
        {
             a[0]=i+fi[k];
             n=a[0]*a[0];
             if(n/100%10==8)          
                 for(j=0;j<5000;j++)
                 {
                     a[1]=a[0]*j*2+n/10000;
                     if(a[1]%10==7&&a[1]/100%10==6)
                     {                        
                         a[2]=2*a[0]+j*j+a[1]/10000;                        
                         a[3]=2*j+a[2]/10000;a[4]=1+a[3]/10000;
                         if(a[2]%10==5&&a[2]/100%10==4&&a[3]%10==3&&a[3]/100%10==2)
                         {
                             a[0]=n;
                             goto loop;                                  
                         }
                                                
                     }
                 }            
        }
    loop:printf("1%d%d ^2 =",j,i+fi[k]); 
    for(i=3;i>-1;i--)printf("%d ",a[i]%10000);                        
    system("pause");
    return 0;
}

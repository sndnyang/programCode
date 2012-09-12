#include<stdio.h>
#include<stdlib.h>
int nine[9];
int Can(int num)
{
    int t,i=0,r;    
    t=num;    
    while(t>0)
    {
         r=t%10;t/=10;
         if(r==0)return 0;
         if(nine[r-1]!=0)nine[r-1]--;
         else return 0;         
    }
    return 1;
}
void Mul(int k)
{
    int i,j,t,n;
    t=9;
    for(i=1;i<k;i++)t=t*10+9;
    printf("t==%d,k==%d\n",t,k);   
    for(i=t;i>t/9;i--)
    {
         for(j=0;j<9;j++)nine[j]=1;
         for(j=1;j<=9/k;j++)
             if(Can(i*j)==0)break;
         if(j>9/k){printf("%d\n",i);  break;}
    }
}
    
int main()
{
    int k,t;
    for(k=4;k>0;k--)Mul(k);        
    system("pause");
    return 0;
}        

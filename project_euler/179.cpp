#include<stdio.h>
#include<stdlib.h>
int prime[10000];
int same(int prim[],int x,int k)
{
    int i;
    for(i=0;i<k;i++)
    {
        
    }
    return 1;
}   
int main()
{
     int num=1;
     int i,j;
     for(i=0;i*i<10000000;i++)prime[i]=0;
     printf("%d\n",i);
     for(i=2;i<100;i++)
         for(j=i*2;j<5000;j+=i)
             prime[j]=1;
     int k=0;
     int prim[1000];
     for(i=2;i*i<10000000;i++)
         if(prime[i]==0)
            prim[k++]=i;
     printf("%d\n",k);     
     for(i=8;i<10;i++)
         if(same(prim,i,k)==1)
            num++;
     printf("%d\n",num);
     system("pause");
     return 0;
}

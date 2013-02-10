#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,k,pri[10024]={0},t[1250],s,sum;
    for(i=2;i<99;i++)
        for(j=i*2;j<10000;j+=i)
            if(pri[j]==0)pri[j]=1;
    j=0;
    for(i=2;i<10000;i++)
        if(pri[i]==0){t[j]=i;j++;}        
    while(1)
    {
        s=0;
        scanf("%d",&n);
        sum=0;        
        if(n==0)break;          
        for(i=0;t[i]!=0&&t[i]<=n;i++);        
        for(j=i;j>=0;j--)
        {
             sum=0;           
             for(k=j;k>=0;k--) 
             { 
                  sum+=t[k];
                  if(sum==n){s++;break;}
                  if(sum>n)break;
             }
        }
        printf("%d\n",s);     
    }         
    system("pause");
    return 0;
}

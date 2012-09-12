#include<stdio.h>
#include<stdlib.h>
int Judge(int x,int y,int z)
{
    int tim[10]={0},a[10]={0},t,n;
    t=x; 
    while(t>0)
    {
        tim[t%10]++;a[t%10]++;
        t/=10;
    }
    t=y;
    while(t>0)
    {
         tim[t%10]--;
         if(tim[t%10]<0)return 0;
         t/=10;
    }    
    t=z;
    while(t>0)
    {
         a[t%10]--;
         if(a[t%10]<0)return 0;
         t/=10;
    }
    return 1;
}        
int main()
{
    int i,j,prime[10024]={0},a[2000],k=0,t;
    for(i=2;i<100;i++)
        for(j=2*i;j<10000;j+=i)
            if(prime[j]==0)prime[j]=1;
    for(i=1001;i<10000;i++)
        if(prime[i]==0)
              a[k++]=i;   
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            t=2*a[j]-a[i];
            if(t>=10000)break;
            if(prime[2*a[j]-a[i]]==0&&Judge(t,a[i],a[j])==1)
            {
                printf("%d %d %d\n",a[i],a[j],2*a[j]-a[i]);
                 
            }
        }
    }
    system("pause");
    return 0;
}
             
        

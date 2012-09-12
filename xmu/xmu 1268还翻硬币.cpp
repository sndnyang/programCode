#include<stdio.h>
#include<stdlib.h>
int same(int coin[],int state[])
{
    for(int i=0;i<55;i++)
       if(coin[i]!=state[i])return 0;
    return 1;
}
int main()
{
    int i,j,k,n,m,t,temp,times;
    int coin[55]={0},num[55]={0};
    int state[55]={0};
    scanf("%d",&t);
    while(t)
    {
        t--;times=0;scanf("%d%d",&n,&m);
        for(i=1;i<n+1;i++)
             scanf("%d",&coin[i]);        
        for(i=1;i<m+1;i++)
        {
             scanf("%d",&temp);
             num[temp]++;
        }
        while(same(coin,state)!=1)
        {
            for(i=1;i<n+1;i++)
            {
                 if(coin[i]!=state[i])
                 {
                     times++;
                     if(num[i]==0)
                     {                         
                         times=-1;
                         break;
                     }
                     else 
                     {
                          for(j=i;j<=n;j+=i)
                             state[j]=(state[j]+1)%2;
                     }
                 }
            }
            if(times==-1)break;
        }
        printf("%d\n",times);
        for(i=0;i<55;i++)
        {
             coin[i]=0;state[i]=0;num[i]=0;
        }
    }
    system("pause");
    return 0;
}

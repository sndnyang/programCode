#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x,y,k,n,one,total,t,i;
    scanf("%d",&n);
    while(n)
    {
            n--;
            total=0;
            scanf("%d%d%d",&x,&y,&k);
            for(i=x;i<=y;i++)
            {
               one=0;
               t=i;
               while(t)
               {
                    if(t%2==1)one++;
                    if(one >k)break;
                    t/=2;
               }
               if(one==k)total++;
            }
             printf("%d\n",total);
    }
    system("pause");
}
         
    

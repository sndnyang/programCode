#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int i,k=1,N,t,m;
    scanf("%d",&N);    
    t=2;
    for(i=1;i<=N;i++)
    {k=1;
    if(i==1||i==2)k=i;
    else
    { t=2;
    while(i>t)
    {
            t*=t;
            k++;
    }
}
    printf("%d\n",k);
    }
   
    system("pause");
}
    
            

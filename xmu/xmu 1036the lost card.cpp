#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,k=0,p,t;
    scanf("%d",&n);
    for(i=0;i<2*n-1;i++)
    {
        scanf("%d",&p);
        t=p^k;        
        k=t;
    }
    printf("%d\n",t);
    system("pause");
    return 0;
}

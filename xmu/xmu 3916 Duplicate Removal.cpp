#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,k,p,a[28],m,t,j;
    while(scanf("%d",&n)&&n!=0)
    {
        m=1;
        for(i=1;i<=n;i++)
        {
             scanf("%d",&p);
             k=p^a[m-1];
             printf("%d %d\n",a[m-1],k);
             if(k!=0)a[m++]=p;
             printf("%d\n",m);
        }
        for(i=1;i<m;i++)
            printf("%d ",a[i]);
        printf("$\n");
    }
    system("pause");
    return 0;
}

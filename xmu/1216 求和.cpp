#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10240],b[10024];
    int i,n,j;long result=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    for(i=0;i<n;i++)
       scanf("%d",&b[i]);
    for(i=0;i<n-1;i++)
       for(j=i+1;j<n;j++)
       result+=(a[i]+a[j])*(b[i]+b[j]);
    printf("%ld\n",result);
    system("pause");
    return 0;
}
       

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,a[3];
    scanf("%d",&n);
    printf("Gnomes:\n");
    for(i=0;i<n;i++)
    {
         for(j=0;j<3;j++)scanf("%d",&a[j]);
         if((a[1]-a[0])*(a[2]-a[1])>0)
             printf("Ordered\n");
         else printf("Unordered\n");
    }
    system("pause");
    return 0;
}

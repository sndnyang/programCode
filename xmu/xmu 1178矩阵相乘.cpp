#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,x,y,k;
    int t[120][120],m[120][120],re[120][120]={0};
    scanf("%d%d%d",&n,&x,&y);
    for(i=0;i<n;i++)
       for(j=0;j<x;j++)
          scanf("%d",&t[i][j]);
    for(j=0;j<x;j++)
       for(i=0;i<y;i++)
       scanf("%d",&m[j][i]);
    for(i=0;i<n;i++)
       for(j=0;j<y;j++)
       {
            for(k=0;k<x;k++)
                re[i][j]+=t[i][k]*m[k][j];
       }
    for(i=0;i<n;i++)
    {
       for(j=0;j<y;j++)
         printf("%d ",re[i][j]);
         printf("\n");
    }
    system("pause");
    return 0;
}
               

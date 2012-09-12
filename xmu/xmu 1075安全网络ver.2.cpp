#include<stdio.h>
#include<stdlib.h>
int small,n;
int v[105];
void FindSmall(int a[][105],int x,int sum)
{
     int i;
     if(n-1==x&&sum<small)
     {
           small=sum;
     }
     else if(sum<small)
     {
          for(i=1;i<n;i++)
              if(v[i]==0)
              {
                   v[i]=1;
                   FindSmall(a,i,sum+a[x][i]);
                   v[i]=0;
              }          
     }
}
int main()
{
    int a[105][105],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        v[i]=0;
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    v[0]=1;
    small=a[0][n-1];
    for(i=1;i<n-1;i++)
    {
        v[i]=1;
        FindSmall(a,i,a[0][i]);
        v[i]=0;
    }
    printf("%d\n",small);
    system("pause");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITY 100001 
int a[102][102];
int D[102][102];
int P[102][102][102];
int n,m,max;
void Shortest_FLOYD()
{
     int i,j,k,u,v;
     for(i=0;i<n;i++)
         for(j=0;j<n;j++)
              D[i][j]=a[i][j];
     for(i=0;i<n;i++)
         for(j=0;j<n;j++)
             for(k=0;k<n;k++)
                 if(D[j][i]+D[i][k]<D[j][k])
                      D[j][k]=D[j][i]+D[i][k];
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)a[i][j]=INFINITY;
        }
    max=0;
    Shortest_FLOYD();
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(D[i][j]>max)max=D[i][j];

    if(max==INFINITY)printf("-1\n");
    else printf("%d\n",max-1);
    system("pause");
    return 0;
}


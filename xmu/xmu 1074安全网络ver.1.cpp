#include<stdio.h>
#include<stdlib.h>
int a[1024][1024];
struct
{
    int adjvex,cost;
}closedge[1024];
int s;
int mini(int n)
{
    int i,min=100000,k=1;
    for(i=2;i<=n;i++)
        if(closedge[i].cost<min&&closedge[i].cost!=0)
        {
             min=closedge[i].cost;
             k=i;
        }
    return k;
}
void MiniSpanTree_PRIM(int n,int k)
{
     int i,j,m;
     for(i=1;i<=n;i++)
         if(i!=k)
         {
             closedge[i].adjvex=k;
             closedge[i].cost=a[k][i];
         }
     closedge[k].cost=0;
     for(i=1;i<n;i++)
     {
          k=mini(n);
          s+=closedge[k].cost;
          closedge[k].cost=0;
          for(j=1;j<=n;j++)
              if(a[k][j]<closedge[j].cost)
              {
                   closedge[j].cost=a[k][j];
                   closedge[j].adjvex=k;
              }
     }
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    s=0;
    MiniSpanTree_PRIM(n,1);
    printf("%d\n",s);
    system("pause");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
char ma[1024][1024];
char vis[1024][1024];
int n,m,p;
void DFS(int x,int y)
{
     if(x>=0&&y>=0&&vis[x][y]==0&&ma[x][y]!='#'&&x<n&&y<m)
     {
         vis[x][y]=1;
         if(ma[x][y]=='*')p++;
         DFS(x-1,y);
         DFS(x+1,y);
         DFS(x,y-1);
         DFS(x,y+1);
     }
}
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
         for(i=0;i<n;i++)
              scanf("%s",ma[i]);
         p=0;
         for(i=0;i<n;i++)
             for(j=0;j<m;j++)vis[i][j]=0;
         for(i=0;i<n;i++)
             for(j=0;j<m;j++)
                 if(ma[i][j]=='X')
                     DFS(i,j);
                 printf("%d\n",p);
    }
    system("pause");
    return 0;
}

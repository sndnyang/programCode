#include<stdio.h>
#include<stdlib.h>
int edge(int matr[][202],int i,int x,int y,int n,int m)
{
    if(i==1)
    {
        if(matr[x+1][y]!=0)return 1;
        else if(x+1==n)return 1;
    }    
    if(i==0)
    {
        if(matr[x][y+1]!=0)return 1;
        else if(y+1==m)return 1;
    }
    if(i==3)
    {
        if(matr[x-1][y]!=0)return 1;
        else if(x-1==-1)return 1;
    }
    if(i==2)
    {
        if(matr[x][y-1]!=0)return 1;
        else if(y-1==-1)return 1;
    }
}
int main()
{
    int matr[202][202]={1};
    int n,m,i;
    int x=0,y=0,dir=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<n*m;i++)
    {
         if(edge(matr,dir,x,y,n,m)==1)
               dir=(dir+1)%4;
         printf("");
         if(dir==0)y++;
         if(dir==1)x++;
         if(dir==2)y--;
         if(dir==3)x--;
         matr[x][y]=i+1;         
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d ",matr[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}
    
              

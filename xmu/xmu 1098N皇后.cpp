#include<stdio.h>
#include<stdlib.h>
int n;
int judge(int mat[][25],int col,int row)
{
    for(int i=0;i<row;i++)
        if(mat[i][col]==1)
            return 0;
    for(int i=1;row>=i&&col+i<n;i++)
        if(mat[row-i][col+i]==1)
            return 0;
    for(int i=1;row>=i&&col-i>=0;i++)
        if(mat[row-i][col-i]==1)
              return 0;
    return 1;
}
int Back(int mat[][25],int row)
{
    if(row==n)
        return 1;
    for(int i=0;i<n;i++)
    {
         if(judge(mat,i,row)==0)
             continue;
         else
         {
             mat[row][i]=1;
             if(Back(mat,row+1)==1)return 1;
             else  mat[row][i]=0;
         }
    }
    return 0;
}
int main()
{
    int mat[25][25]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         mat[0][i]=1; 
         if(Back(mat,1)==0)
         {
             mat[0][i]=0;
             continue;
         }
         else break;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
           if(mat[i][j]==1)
              printf("%d %d\n",i+1,j+1);
    system("pause");
    return 0;
}

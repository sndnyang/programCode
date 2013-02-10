#include<stdio.h>
#include<stdlib.h>
int n,num;
int po[20][2];
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
void Back(int mat[][25],int row)
{
    if(row==n)
    {
         num++;
         if(num==1)
         {
             int k=0;
             for(int i=0;i<n;i++)
                 for(int j=0;j<n;j++)
                 if(mat[i][j]==1){
                     po[k][0]=i+1;
                     po[k][1]=j+1;
                     k++;
                 }
         }
    }
    else{
    for(int i=0;i<n;i++)
    {
         if(judge(mat,i,row)==0)
             continue;
         else
         {
             mat[row][i]=1;
             Back(mat,row+1);
             mat[row][i]=0;
         }
        }
    }
}
int main()
{
    int mat[25][25]={0};
    num=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         mat[0][i]=1; 
         Back(mat,1);
         mat[0][i]=0;         
    }
    printf("%d\n",num);
    for(int i=0;i<n;i++)
          printf("%d %d\n",po[i][0],po[i][1]);
    system("pause");
    return 0;
}

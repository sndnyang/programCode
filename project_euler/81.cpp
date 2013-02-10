#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int mat[81][81],min[81][81],i=0,j=0;
    int temp=0,m=0;
    char ch;
    FILE *fp;
    fp=fopen("matrix.txt","r");
    while( (ch=fgetc(fp))!=EOF)
    {
          m++;
          if(ch==',')
          {
              mat[i][j]=temp;
              j++;
              temp=0;
          }
          else if(ch=='\n')
          {
               mat[i][j]=temp;
               temp=0;
               i++;j=0;
          }
          else temp=temp*10+ch-'0';
    }
    min[0][0]=mat[0][0];
    for(i=1;i<80;i++)
        min[i][0]=mat[i][0]+min[i-1][0];
    for(i=1;i<80;i++)
        min[0][i]=mat[0][i]+min[0][i-1];
    for(i=1;i<80;i++)
        for(j=1;j<80;j++)
        {
             int a1=min[i][j-1];
             int a2=min[i-1][j];
             min[i][j]=(a1<a2?a1:a2)+mat[i][j];
        }
    printf("%d\n",min[79][79]);
    system("pause");
    return 0;
}
          

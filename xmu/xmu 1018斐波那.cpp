#include<stdio.h>
#include<stdlib.h>
int a[2][2]={1,1,1,0};
void Square(int b[][2],int m)
{
     int t[2][2],i,j,k;
     for(i=0;i<2;i++)
         for(j=0;j<2;j++)
         {
              t[i][j]=b[i][j];
              b[i][j]=0;
         }
     for(i=0;i<2;i++)
         for(j=0;j<2;j++)
             for(k=0;k<2;k++)
             {
                b[i][j]+=t[i][k]*t[k][j];
                b[i][j]%=m;
             }
}
void Mul(int b[][2],int m)
{
     int t[2][2],i,j,k;
     for(i=0;i<2;i++)
         for(j=0;j<2;j++)
         {
              t[i][j]=b[i][j];
              b[i][j]=0;
         }
     for(i=0;i<2;i++)
         for(j=0;j<2;j++)
             for(k=0;k<2;k++)
             {
                b[i][j]+=t[i][k]*a[k][j];
                b[i][j]%=m;
             }
}
void Print(int b[][2],int k)
{
     int i,j;
     for(i=0;i<2;i++)
     {
         for(j=0;j<2;j++)
             printf(" %5d",b[i][j]);
         printf("\n");
     }
     printf("%d \n",k);
}
int main()
{
    int i,j,k,c,n,m,p,l;
    int b[2][2]={1,1,1,0};
    int bi[33];
    scanf("%d",&c);
    for(l=0;l<c;l++)
    {
        scanf("%d%d",&n,&m);
        k=0;p=n;
        while(p)
        {
            bi[k++]=p%2;
            p/=2;
        }        
        for(i=0;i<2;i++)for(j=0;j<2;j++)
        b[i][j]=a[i][j];
        int p=1;
        for(i=k-2;i>=0;i--)
        {
            Square(b,m);
            if(bi[i]==1)
                Mul(b,m);         
        }
        printf("%d\n",b[0][1]);
    }
    system("pause");
    return 0;
}

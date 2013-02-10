#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,v[210];
    int m[210][210];
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=0;i<n;i++)m[i][i]=0;
    
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<=n-1;i++)
        {
            int j=i+l-1;
            for(int k=i;k<j;k++)
            {
                  if(k==i)
                       m[i][j]=m[i][k]+m[k+1][j]+v[i]*v[i+1]*v[j+1];
                  else
                  {
                       int temp=m[i][k]+m[k+1][j]+v[i]*v[k+1]*v[j+1];
                       if(temp<m[i][j])
                       {
                             m[i][j]=temp;
                       }
                  }
            }
        }
    }
    printf("%d",m[0][n-1]);
    system("pause");
    return 0;
}
                            

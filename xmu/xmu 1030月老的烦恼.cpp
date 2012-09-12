#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,m,i,j,ori,temp;
    char a[1024],b[1024];
    int c[1024];
    
    scanf("%d%d\n",&n,&m);
    scanf("%s%s",a,b);
    for(i=0;i<=m;i++)c[i]=0;
    
    for(i=1;i<=n;i++)
    {
         temp=c[0];
         c[0]=0;
         for(j=1;j<=m;j++)
         {
              ori=c[j];
              if(a[i-1]==b[j-1])
              {                 
                 c[j]=temp+1;
              }
              else 
              {
                 c[j]=c[j-1]>c[j]?c[j-1]:c[j];
              }
              temp=ori;
         }
    }
    printf("%d\n",c[m]);
    system("pause");
    return 0;
}

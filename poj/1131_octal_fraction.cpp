#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int main()
{
    int i,j,n,m,temp;    
    char t[100],p[100];
    while(scanf("%s",t)!=EOF)
    {
         char dest[100]={0};
         n=0;
         for(i=strlen(t)-1;i>1;i--)
         {
              m=t[i]-'0';
              for(j=0;j<n||m;j++)
              {
                   temp=m*10+(j<n?dest[j]-'0':0);
                   dest[j]=temp/8+'0';
                   m=temp%8;
              }
              n=j;
         }
         dest[j]='\0';
         printf("%s [8] = 0.%s [10]\n",t,dest);
    }
    system("pause");
    return 0;
}

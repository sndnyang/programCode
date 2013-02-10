#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,n,m,p1,p2;
    char a[100],b[200];
    while(scanf("%s%s",a,b)&&strcmp(a,"E")!=0)
    {
         n=strlen(a);
         p1=0;p2=0;
         for(i=0;i<n;i++)
         {
              if(a[i]=='R')
                  if(b[i]=='S')p1++;
                  else if(b[i]=='P')p2++;
              if(a[i]=='S')
                  if(b[i]=='R')p2++;
                  else if(b[i]=='P')p1++;
              if(a[i]=='P')
                  if(b[i]=='S')p2++;
                  else if(b[i]=='R')p1++;
         }
         printf("P1: %d\nP2: %d\n",p1,p2);
    }
    system("pause");
    return 0;
}
                  

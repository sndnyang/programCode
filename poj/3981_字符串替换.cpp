#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,k;
    char a[1024];
    while(scanf("%s",a)!=EOF)
    {                       
         for(i=0;i<strlen(a);i++)
         {
              if(a[i]=='y'&&a[i+1]=='o'&&a[i+2]=='u')
              {
                   printf("we");
                   i+=2;
              }
              else 
                  if(a[i]=='\n')printf(" ");
                  else printf("%c",a[i]);
         }
         printf(" ");
    }
    system("pause");
    return 0;
}

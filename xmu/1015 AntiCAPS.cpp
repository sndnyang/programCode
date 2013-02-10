#include<stdio.h>
#include<stdlib.h>
int main()
{
    char t[10240];
    char m;
    int top=0,i;
    while(scanf("%c",&m)!=EOF)
    {
          if(top==0)t[top]=m;
          else 
          {
               switch(t[top-1])
               {
                   case '!':
                   case '?':
                   case '.':t[top]=m;break;
                   default:t[top]=m-32;break;
               }
          }
    }
    for(i=0;i<top;i++)
       printf("%c",t[top]);
    getchar();
    system("pause");
}
   
   
         

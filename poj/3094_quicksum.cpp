#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n,i,sum;
    char t[300];
    while(1)
    {
          gets(t);
          if(strcmp(t,"#")==0)break;
          sum=0;
          for(i=0;i<strlen(t);i++)
          {
               if(t[i]==' ')continue;
               else sum+=(i+1)*(t[i]+1-'A');
          }
          printf("%d\n",sum);
    }
    system("pause");
    return 0;
}

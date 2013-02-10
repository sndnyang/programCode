#include<stdio.h>
#include<string.h>
typedef struct 
{
    char name[20];  
}team;
int main()
{
    char t[20];
    team a[10000];
    int n,i,j,top;
    scanf("%d",&n);
    top=1;
    for(i=0;i<n;i++)
    {
         scanf("%s",t);
         if(i==0)
                strcpy(a[0].name,t);                  
         else
         {
             for(j=0;j<top;j++)
                 if(strcmp(a[j].name,t)==0)break;
             if(j>=top)
             {
                       strcpy(a[top].name,t);
                       top++;
             }
         }
    }
    printf("%d\n",top);
}

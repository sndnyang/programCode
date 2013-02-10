#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int finish;
}Stack;
int main()
{  
    char t[5024];
    Stack q[2000];
    int n,i,j,m,l,p;
    scanf("%d",&n);  
    for(i=0;i<2000;i++)q[i].finish=0; 
    while(n)
    {
        n--;p=0;l=0;        
        scanf("%s",&t);
        for(i=0;i<strlen(t);i++)
        {
             switch(t[i])
             {
             case'a':m=0;l++;break;
             case'c':m=1;break;
             case'm':m=2;break;
             default:continue;
             }
             for(j=0;j<=l;j++)
             {
                 if(m==q[j].finish)
                 {
                     q[j].finish++;
                     if(q[j].finish==3)p++;
                     break;
                 }
             }
        }
        printf("%d\n",p);
        for(i=0;i<l;i++)q[i].finish=0; 
    }
    system("pause");
    return 0;
}
             
             
        

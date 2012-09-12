#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    int i,j,k=0,a[1205],num=0,t;
    char ch;
    fp=fopen("cipher1.txt","r");
    if(fp==NULL)
        printf("Sorry.This file can't be found\n");
    else
    {
        while((ch=getc(fp))!=EOF)
        {
             if(ch==',')
             {
                 a[k++]=num;
                 num=0;
             }
             else
                  num=num*10+ch-'0';
        }
    }
    printf("%d\n",k);
    for(i=10,j=40;i<30;i++)
    {
        k=i^j;
        printf("%d %d %d\n",i,j,k);
    }
    for(i='a';i<='z';i++)
    {
         for(j=0;j<10;j+=3)
         {
             t=a[j]^i;
             if(t>='a'&&t<='z'||(t<='Z'&&t>='A'))
             {
                  
                  continue;
             }
             else break;
         }
    }
    system("pause");
    return 0;
}

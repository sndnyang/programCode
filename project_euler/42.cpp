#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char ch;
    int i,t=0,word=0,add=0,num=0;
    int nth[2024]={0};
    for(i=1;i*(i+1)/2<2000;i++)
        nth[(i*i+i)/2]=1;    
    fp=fopen("words.txt","r");
    if(fp==NULL)
        printf("Sorry.This file can't be found\n");
    else
    {
        while((ch=getc(fp))!=EOF)
        {
             if(ch=='\"')
             {
                 t++;
                 if(t%2==0)
                 {                                         
                      
                      if(nth[add]==1&&add!=0)
                      {                                      
                           num++;
                      }
                      add=0;
                 }
             }
             else if(ch>='A'&&ch<='Z')
             {                 
                  add+=ch-'A'+1;
             }
        }
    }
    printf("%d\n",num);    
    system("pause");
    return 0;
}

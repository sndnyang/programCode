#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    char ch[10];int cou;
}ph;
ph di[8001];
void swap(int a,int b)
{
     int t;
     strcpy(di[a].ch,di[b].ch); 
     t=di[a].cou;
     di[a].cou=di[b].cou;
     di[b].cou=t;
}
int QSort(int low,int high)
{    
     int temp=di[low].cou;   
     char t[10];
     strcpy(di[0].ch,di[low].ch);
     strcpy(t,di[low].ch);
     while(low<high)
     {
           while(low<high&&strcmp(t,di[high].ch)<0)high--;
           swap(low,high);           
           while(low<high&&strcmp(t,di[low].ch)>0)low++;
           swap(high,low);
     }
     strcpy(di[low].ch,di[0].ch);
     di[low].cou=temp;
     return low;
}
void Sort(int low,int high)
{
     int final;
     if(low<high)
     {
         final=QSort(low,high);
         Sort(low,final-1);
         Sort(final+1,high);
     } 
}
int main()
{
    FILE *fp;
    char ch,name[20]={0};
    int i,t=0,add=0,m=0;long sum=0;
    fp=fopen("names.txt","r");
    if(fp==NULL)
        printf("Sorry.This file can't be found\n");
    else
    {
        while((ch=getc(fp))!=EOF)
        {
             if(ch=='\"')
             {
                 t++;
                 name[m]='\0';
                 if(t%2==0)
                 {  
                      di[t/2].cou=add;
                      strcpy(di[t/2].ch,name);       
                      add=0;m=0;
                 }
             }
             else if(ch>='A'&&ch<='Z')
             {
                  add+=ch-'A'+1;
                  name[m]=ch;
                  m++;
             }
        }
    }
    Sort(1,t/2);
    for(i=1;i<=t/2;i++)
    {
         sum+=di[i].cou*i;
    }
     
    printf("%ld\n",sum);   
    system("pause");
    return 0;
}

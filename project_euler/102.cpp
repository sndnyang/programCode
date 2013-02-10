#include<stdio.h>
#include<stdlib.h>
int inf(int a[])
{
    int i=0,t1,t2,t3;
    t1=a[0]*a[3]-a[2]*a[1];if(t1<0)i++;
    t2=a[2]*a[5]-a[3]*a[4];if(t2<0)i++;
    t3=a[1]*a[4]-a[0]*a[5];  if(t3<0)i++;   
    if(i%3==0)
    {
         
         return 1;
    }
    else return 0;
} 
int main()
{
    FILE *fp;
    char ch;
    int a[10],k=0,flag=1;
    int temp=0,i,num=0;
    fp=fopen("triangles.txt","r");
    while( (ch=fgetc(fp) )!=EOF)
    {
         
         if(ch==',')
         {
                a[k]=temp*flag;
                k++;
                flag=1;
                temp=0;
         }
         if(ch=='-')
                flag=-1;
         if(ch=='\n')
         {
                a[k]=temp*flag;
                flag=1;
                temp=0;
                k=0;                
                if(inf(a)==1)num++;                
              
                        
         }
         if(ch>='0'&&ch<='9')
              temp=temp*10+ch-'0';         
    }
    printf("%d\n",num);
    system("pause");
    return 0;
}
                

#include<stdio.h>
#include<stdlib.h>
int begin,end;
int equal(int a[],int b[],int x)
{
    int i,j,k;
    for(i=1;i<x;i++)
        if(b[i]==b[x]&&a[i]==a[x])
        {
             begin=i;
             end=x;
             break;
        }
    if(i!=x&&x>1)return 1;
    else return 0;
}
int main()
{
    int n,m,i,j,t,p=0;
    int a[50050];
    int b[50050];
    scanf("%d%d",&n,&m);
    t=0;
    if(n%m==0)
        printf("%d.0\n",n/m);
    else 
    {
       while(n%m!=0)
       {
          a[t]=n/m;
          b[t]=n%m;
          if(equal(a,b,t)==1)
               break;
          int r=n%m;
          n=r*10;
          t++;
        }
        a[t++]=n/m;       
        printf("%d.",a[0]);
        if(a[0]<100000)p=7;
        if(a[0]<10000)p=6;
        if(a[0]<1000)p=5;
        if(a[0]<100)p=4;
        if(a[0]<10)p=3;
        for(i=1;i<(end>0?end:t);i++)
        {
           if(i==begin)printf("(");printf("%d",a[i]);
           if(i==end-1)
           {
              printf(")");break;
           }
           p++;          
           if(p%76==0)printf("\n");
        }}
    system("pause");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
int bouncy(int x)
{
    int flag,t=x/10,g=x%10,s=t%10,y;
    if(g>s)flag=1;
    if(g<s)flag=0;
    if(g==s)flag=2;    
    while(t>=10)
    {
          t/=10;
          g=s;
          s=t%10;
          if(x==110)printf("%d %d %d\n",flag,g,s);
          if(g<s&&flag==1)return 1;
          if(g>s&&flag==0)return 1;          
    }
    return 0;
}
int main()
{
    int i,num=0;
    for(i=100;;i++)
    {         
          if(bouncy(i)==1)
                 num++;
                  
          if(num*1.0/i==0.99)break;
    }
    printf("%d\n",i);
    system("pause");
    return 0;
    
}

#include<stdio.h>
#include<stdlib.h>
int Max(int a,int b)
{
    int r=a%b,x;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int Ope(int a,int b,char x)
{
    switch(x)
    {
       case '+':return a+b;
       case '-':return a-b;
    }
}
int main()
{
    char in[10],re[10];
    int a1,a2,a,b,t;
    while(scanf("%s",in)!=EOF)
    {
          b=(in[6]-'0')*(in[2]-'0');
          a1=(in[0]-'0')*b/(in[2]-'0');
          a2=(in[4]-'0')*b/(in[6]-'0');
          a=Ope(a1,a2,in[3]);
          if(a==0)printf("0\n");
          else
          {
              t=Max(a,b);
              if(t>0)printf("%d/%d\n",a/t,b/t);
              else printf("%d/%d\n",-a/t,-b/t);
          }
    }
    system("pause");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char a[20];
    int t;
    scanf("%s",a);
    t=(a[0]-'0')*10+a[1]-'0';
    if(t==12)printf("PM %s",a);
    else if(t==0){a[0]='1';a[1]='2';printf("AM %s\n",a);}
    else if(t>12)
    {
         printf("PM ");
         t-=12;
         a[0]=t/10+'0';
         a[1]=t%10+'0';
         printf("%s\n",a);
    }
    else printf("AM %s\n",a);

    system("pause");
    return 0;
}

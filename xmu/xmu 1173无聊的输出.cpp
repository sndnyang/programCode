#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[12],q;
    int i,j,n,t,p;
    scanf("%s %d",a,&n);
    t=strlen(a);
    for(i=0;i<t/2;i++)
    {
         q=a[i];
         a[i]=a[t-i-1];
         a[t-i-1]=q;
    }
    printf("%c\n",a[0]);
    for(i=1;i<n;i++)
    {
        p=1;
        for(j=0;j<t;j++)
        {
             a[j]+=p;
             if(a[j]>'9')
             {
                 a[j]='0';
                 p=1;
             }
             else p=0;
        }
        if(p==1)
        {
             a[t]='1';
             a[++t]='\0';
        }   
        for(j=0;j<=i;j++)        
             printf("%c",a[t-j%t-1]);
        printf("\n");
    }
    system("pause");
    return 0;
}

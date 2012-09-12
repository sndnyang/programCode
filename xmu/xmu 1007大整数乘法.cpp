#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[1024],b[1024],c[2048],ch;
    int i,j,k,m,n,o,p,q,t,la,lb;
    scanf("%s%s",&a,&b);
    if(!strcmp(a,"0")||!strcmp(b,"0"))printf("0\n");
    else 
    { 
    la=strlen(a);lb=strlen(b);
    for(i=0;i<la/2;i++)
    {
         ch=a[i];
         a[i]=a[la-i-1];
         a[la-i-1]=ch;
    }
    for(i=0;i<lb/2;i++)
    {
         ch=b[i];
         b[i]=b[lb-i-1];
         b[lb-i-1]=ch;
    }
    p=0;
    for(i=0;i<la+lb-1;i++)
    {
         t=0;
         for(j=0;j<=i&&i-j<=i;j++)
             if(j<la&&i-j<lb)
                 t+=(a[j]-'0')*(b[i-j]-'0');
         q=t+p;         
         p=q/10;
         c[i]=q%10+'0';
    }
    c[i]='\0';
    if(p!=0)printf("%d",p);
    for(i=i-1;i>=0;i--)printf("%c",c[i]);
}
    system("pause");
    return 0;
}

#include<stdio.h>   
#include<string.h>
#include<stdlib.h>
int main()
{
    char t[10240],c;
    int k=0,flag=1;
    while((c=getchar())!=EOF)
    {
        int i;
        t[k]=c;
        if(t[k]>='A'&&t[k]<='Z')
            if(flag==0)
                 t[k]+=32;
            else flag=0;
        if(c=='.'||c=='!'||c=='?')flag=1;
        k++;
        if(c=='\n')
        {
               for(i=0;i<k;i++)
                    printf("%c",t[i]);
               k=0;
        }
    }
    system("pause");
    return 0;
}

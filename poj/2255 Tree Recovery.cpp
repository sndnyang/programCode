#include <stdio.h>
#include <string.h>
#include<stdlib.h>
char a[27],b[27];
int work(int zi,int zj,int hi,int hj)
{
    int i,j,k,fz,fh=hi;
    if(zi>zj)return 0; 
    printf("%c",b[hj]);//getchar();
    if(zi==zj) return 0;
    for (fz=zi;fz<=zj;fz++) if (a[fz]==b[hj])break;
    fh=hi+(fz-zi)-1;
    work(zi,fz-1,hi,fh);
    work(fz+1,zj,fh+1,hj-1);
}        
int main()
{
    scanf("%s%s",a,b);
    work(0,strlen(a)-1,0,strlen(b)-1);
    system("pause");   
    return 0;
}   

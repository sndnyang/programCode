#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[100004][11];
int comp(const void *a,const void *b)
{
    return strcmp((char *)a,(char*)b);
}
int main()
{
    int i,j,n,t=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",a[i]);
    qsort(a,n,sizeof(char)*11,comp);   
    for(i=1;i<n;i++)
        if(strcmp(a[i],a[i-1])!=0)t++;
    printf("%d\n",t);
    system("pause");
    return 0;
}

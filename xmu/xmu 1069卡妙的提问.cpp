#include<stdio.h>   
int main()      
{      
    int a,b,c,d;      
    scanf("%d%d%d%d",&a,&b,&c,&d);     
    if((d-b)*(b-a)!=(c-b)*(c-a)||(a-b)*(b-c)*(c-d)==0)printf("no solution\n");   
    else printf("%d\n",(b*b-a*c)/(2*b-c-a));      
    return 0;      
}

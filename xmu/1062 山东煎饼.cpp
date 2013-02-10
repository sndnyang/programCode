#include<stdio.h>
#include<stdlib.h>
int t[6]={500,100,50,10,5,1};
int money[6];
int N;
int Paper(int n,int m)
{
    if(n==0)return 0;
    else if(n<0)return -1000;
    if(m>=6)return -1000;
    
    if(n>=t[m])
        if(n/t[m]>=money[m])
             return money[m]+Paper(n-t[m]*money[m],m+1);
        else
             return n/t[m]+Paper(n%t[m],m+1);   
    else 
        return Paper(n,m+1);  
}
int main()
{
    int i,k;
    scanf("%d",&N);
    for(i=0;i<6;i++)
        scanf("%d",&money[i]); 
    k=Paper(1000-N*25,0);
    if(k>0)printf("%d\n",k);
    else printf("-1\n");
    system("pause");
    return 0;
}
    
    

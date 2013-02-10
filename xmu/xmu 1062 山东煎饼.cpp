#include<stdio.h>
#include<stdlib.h>
int t[6]={500,100,50,10,5,1};
int a[6];
int N;
int main()
{
    int i,k,p,m=0;
    scanf("%d",&N);
    for(i=0;i<6;i++)
        scanf("%d",&a[i]); 
    k=1000-N*25;
    for(i=0;i<6;i++)
        if(a[i]&&k)
        {
             p=a[i]<(k/t[i])? a[i]:(k/t[i]);
             m+=p;
             k=k-p*t[i];
        }
         if(k==0)printf("%d\n",m);
         else printf("-1\n");
 
    system("pause");
    return 0;
}

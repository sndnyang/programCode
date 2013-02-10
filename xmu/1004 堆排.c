#include <stdio.h>
#include <stdlib.h>
long c[1000024];
void Heapsort(long c[],int s,int m)
{
     long t=c[s];
     int j;
     for(j=2*s;j<=m;j*=2)
     {
         if(j<m&& c[j]<c[j+1])j++;
         if(t<c[j])
         {
             c[s]=c[j];
             s=j;
         }
         else break;
     }
     c[s]=t;
}
int main()
{
    int N,i;
    long t;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%ld",&c[i]);
    for(i=N/2;i>0;i--)
        Heapsort(c,i,N);
    for(i=N;i>=1;i--)
    {
        t=c[i];
        c[i]=c[1];
        c[1]=t;
        Heapsort(c,1,i-1);
    }
    for(i=1;i<=N;i++)
        printf("%ld ",c[i]);  
    system("pause");
}

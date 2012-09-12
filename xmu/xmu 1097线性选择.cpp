#include<stdio.h>
#include<stdlib.h>
int a[1000004];
void HeapAdjust(int a[],int s,int m)
{
     int t=a[s];
     int j;
     for(j=2*s;j<=m;j*=2)
     {
         if(j<m&& a[j]<a[j+1])j++;
         if(t<a[j])
         {
             a[s]=a[j];
             s=j;
         }
         else break;
     }
     a[s]=t;
}
void HeapSort(int a[],int N)
{
    int i,t;
    for(i=N/2;i>0;i--)
        HeapAdjust(a,i,N);
    for(i=N;i>=1;i--)
    {
        t=a[i];
        a[i]=a[1];
        a[1]=t;
        HeapAdjust(a,1,i-1);
    }
}
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    HeapSort(a,n);
    printf("%d",a[m]);
    system("pause");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
int a[2000005];
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
    int n,i,t=0;
    scanf("%d",&n);
    for(i=1;i<2*n-1;i++)
        scanf("%d",&a[i]);
    HeapSort(a,2*n-2);    
    for(i=1;i<2*n-1;i++)
    {
        if(a[i]!=a[i+1]&&a[i]!=a[i-1])
        {
              printf("%d ",a[i]);
              t++;
              if(t==2)break;
        }
    }
    if(t==0)printf("poor\n");
    system("pause");
    return 0;
}

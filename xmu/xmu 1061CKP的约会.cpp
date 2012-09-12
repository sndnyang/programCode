#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
     char name[20],b[10],e[10];
}cor;
int Partition(cor a[],int l,int r)
{
     char s[20],b1[10],e1[10];
     strcpy(s,a[l].name);
     strcpy(b1,a[l].b);
     strcpy(e1,a[l].e);
     int low=l,high=r;
     while(low<high)
     {
         while(strcmp(a[high].e,e1)>=0&&high>low)
             high--;
         strcpy(a[low].name,a[high].name);
         strcpy(a[low].b,a[high].b);
         strcpy(a[low].e,a[high].e);
         while(strcmp(a[low].e,e1)<=0&&low<high)low++;
         strcpy(a[high].name,a[low].name);
         strcpy(a[high].b,a[low].b);
         strcpy(a[high].e,a[low].e);
     }
     strcpy(a[low].name,s);
     strcpy(a[low].b,b1);
     strcpy(a[low].e,e1);   
     return low;
}     
void QuickSort(cor a[],int l,int r)
{
     if(l<r)
     {
            int q=Partition(a,l,r);            
            QuickSort(a,l,q-1);
            QuickSort(a,q+1,r);
     }
}
int main()
{
    int n,i,j=0;
    cor pe[1014];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s%s%s",pe[i].name,pe[i].b,pe[i].e);
    QuickSort(pe,0,n-1);
    int a[1024]={0},t=1;
    for(i=1;i<n;i++)
    {
        if(strcmp(pe[i].b,pe[j].e)>=0)
        {
             a[t++]=i;
             j=i;
        }
    }
    printf("%d\n",t);
    for(i=0;i<t;i++)
        printf("%s ",pe[a[i]].name);
    system("pause");
    return 0;
}

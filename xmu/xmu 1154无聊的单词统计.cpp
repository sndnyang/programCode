#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void HeapAdjust(char a[][22],int s,int m)
{
     char t[22];
     int j;
     strcpy(t,a[s]);
     for(j=2*s;j<=m;j*=2)
     {
         if(j<m&& strcmp(a[j],a[j+1])<0)j++;
         if(strcmp(t,a[j])<0)
         {
             strcpy(a[s],a[j]);
             s=j;
         }
         else break;
     }
     strcpy(a[s],t);
}
void HeapSort(char a[][22],int N)
{
    int i;
    char t[22];
    for(i=N/2;i>0;i--)
        HeapAdjust(a,i,N);
    for(i=N;i>=1;i--)
    {
        strcpy(t,a[i]);
        strcpy(a[i],a[1]);
        strcpy(a[1],t);
        HeapAdjust(a,1,i-1);
    }
}
int BSearch(char a[][22],int n,char key[])
{
    int low=1,high=n,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(strcmp(a[mid],key)==0)
            return mid+1;
        else if(strcmp(a[mid],key)>0)high=mid-1;
        else low=mid+1;
    }
    return -1;
}//bsearch
int main()
{
    int i=1,j,t=0,n=1,m=1;
    char a[505][22],b[505][22];
    while(scanf("%s",a[n])&&strcmp(a[n],"0")!=0)n++;
    n--;
    HeapSort(a,n);
    
    while(scanf("%s",b[m])&&strcmp(b[m],"0")!=0)m++;
    m--;
    HeapSort(b,m);
    for(i=1;i<=m;i++)
    {
         if(strcmp(b[i],b[i+1])!=0&&BSearch(a,n,b[i])!=-1)         
              t++;         
    }
    printf("%d\n",t);
    system("pause");
    return 0;
}

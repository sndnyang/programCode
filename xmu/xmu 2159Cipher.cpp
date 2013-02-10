#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void InsertSort(int a[],int len)
{
     int i,j;
     for(i=2;i<=len;i++)
     {
          if(a[i]<a[i-1])
          {
                a[0]=a[i];
                a[i]=a[i-1];
                for(j=i-2;a[0]<a[j];j--)
                     a[j+1]=a[j];
                a[j+1]=a[0];
          }
     }
}
int main()
{
    char a[120],b[120];
    int A[28]={0},B[28]={0};
    int a1,b1,i;
    scanf("%s%s",a,b);
    a1=strlen(a);
    b1=strlen(b);
    for(int i=0;i<a1;i++)
        A[a[i]-'A'+1]++;
    for(int i=0;i<b1;i++)
        B[b[i]-'A'+1]++;
    InsertSort(A,26);
    InsertSort(B,26);
    for(i=1;i<27;i++)
        if(A[i]!=B[i])
        {
             printf("NO\n");
             break;
        }
    if(i==27)printf("YES\n");
    system("pause");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
void Print(int a[],int len)
{
     int i;
     for(i=len-1;i>-1;i--)
        printf("%d ",a[i]);
     printf("%d\n",len);
}
int Com(int a[],int b[],int len)
{
    int i;
    for(i=len;i>-1;i--)
    {
        if(a[i]>b[i])return 1;
        if(a[i]<b[i])return -1;
    }
    if(i==-1)return 0;
}
int add(int a[],int b,int len)
{
    int i,temp;
    a[0]+=b;
    for(i=0;i<len;i++)
    {
        temp=a[i]/10000;
        a[i]%=10000;
        a[i+1]=a[i+1]+temp;       
    }
    if(a[i]!=0)len++;          
    return len;
}
int main()
{
    int i,j,n1=2,n2=2,l1=1,l2=1,l3=1,n=3;
    int t[10]={1},p[10]={1};
    printf("%d %d\n",t[0],p[0]);
    while(n)
    {
          while(1)
          {
                if(Com(t,p,l1)>0)
                {                                         
                     l2=add(p,3*n2-2,l2);
                     n2++;                       
                }
                else 
                if(Com(t,p,l2)<0)
                {                                         
                     l1=add(t,n1,l1);                     
                     n1++;                     
                }
                else if(Com(t,p,l1)==0)break;                
          }
          Print(t,l1);
          printf("%d %d \n",n1,n2);
          if(n1%2==0)n--;
          l2=add(p,3*n2-2,l2);n2++;               
          l1=add(t,n1,l1);n1++;               
    }
    system("pause");
    return 0;
}
          

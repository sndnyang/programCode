#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int init(char t[],int a[],int m)
{
    int i,j,k,temp;
    k=strlen(t)/4;
    for(i=0;i<strlen(t);i++)
    {         
         for(j=0;j<m;j++)
             a[j]=a[j]*10;
         a[0]+=t[i]-48;
         for(j=0;j<m;j++)
         {
              temp=a[j]/10000;
              a[j]%=10000;
              a[j+1]=a[j+1]+temp;       
         }
         if(a[j]!=0)m++;         
    }    
    return m;
}
int Prime(int a[],int n)
{
    int i,j,temp;    
    if(a[0]%2==0)return 0;   
    for(i=3;i<=sqrt(a[0]+a[1]*10000);i+=2)
    {         
         temp=0;         
         for(j=n-1;j>-1;j--)
             temp=(temp*10000+a[j])%i;                     
         if(temp==0)
         {
             printf("%d\n",i);
             return 0;
         }
         else continue;
    }
    return 1;
}  
int main()
{
    int a[10],i,j,k,n,m=1;
    char t[20];
    scanf("%d",&n);
    while(n)
    {
         n--;
         for(i=0;i<10;i++)
             a[i]=0;
         scanf("%s",t);
         m=init(t,a,m);                          
         if(strcmp(t,"2")==0||Prime(a,m)==1)printf("Yes\n");
         else printf("No\n");
    }
    system("pause");
    return 0;
}

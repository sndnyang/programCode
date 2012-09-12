#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int z;
int pri[6]={1,2,3,5,7,9};	
int trun(int a[],int m,int flag)
{
    int i,sum=0,p=100,t;
    for(i=0;i<m;i++)sum=sum*10+a[i];
	t=sum;	
    while(p/10<sum)
	{   
		for(i=3;i<=sqrt(t);i+=2)
			if(t%i==0)return 0;
		if(flag==1)break;
		t=sum%p;p*=10;
	}
	if(a[m-1]!=1&&a[m-1]!=9&&flag!=1)z+=sum;
    return 1;
}
void Con(int p[],int m)
{
     int i,n,flag=0;
     for(i=0;i<6;i++)
     {
         if(i==1)continue;
         p[m]=pri[i];
         if(trun(p,m+1,1)==1)
         {
              if(trun(p,m+1,2)==1)n++;
              Con(p,m+1);
         }                        
     }             
}
int main()
{
    int i,p[50],k=0;   
    for(i=1;i<5;i++)
    {
         p[k]=pri[i];Con(p,k+1);         
    }
	printf("%d\n",z);   
    system("pause");
    return 0;
}

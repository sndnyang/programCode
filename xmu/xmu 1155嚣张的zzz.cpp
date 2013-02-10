#include<stdio.h> 
#include<stdlib.h> 
int main()
{
	long n,m,fac[3000]={0},i,j,flag;
	for(i=1;;i++)
    {
          fac[i]=fac[i-1]+i*i;     
         
          if(fac[i]>2147483647||fac[i]<=0)break;
    }
	scanf("%d",&m);    
	int low,high,mid;
	while(m--)
	{
        low=1;high=i;flag=0;        
		scanf("%d",&n);
	    while(low<=high)
	    {
              mid=(low+high)/2;              
              if(fac[mid]==n)
              {
                    flag=1;
                    break;
              }
              else if(fac[mid]<n)low=mid+1;              
              else high=mid-1;
        }
        if(flag==1)printf("Yes\n");
	    else printf("No\n");
	}	
	system("pause");
	return 0;
}

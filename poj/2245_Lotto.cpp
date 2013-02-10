#include <stdio.h>
#include<stdlib.h>
int n;
void Write(int a[],int t[],int m,int p)
{
     int i;  
     if(p==6)
     {    
          for(i=0;i<6;i++)
              printf("%d ",a[i]);     
          printf("\n");
          return ;
     }       
     for(i=m;i<=m+n-6&&i<n;i++)
     {
         a[p]=t[i];
         Write(a,t,i+1,p+1);       
     }
}         
int main()
{
    int i;
    int t[15],a[6];
    while(1)
    {
         scanf("%d",&n);
         if(n==0)break;
         for(i=0;i<n;i++)
             scanf("%d",&t[i]);        
         Write(a,t,0,0);
         printf("\n");
    }
    system("pause");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,i,j,k,a[1001]={0},max=0,count;
    for(i=3;i<500;i++)
    {
         for(j=i;j<500;j++)
         {
              k=sqrt(i*i+j*j);
              if(i*i+j*j==k*k&&i+j+k<=1000)
              {                   
                   a[i+j+k]++;      
              }
         }        
    }
    for(i=1;i<=1000;i++)
    {    
        if(a[i]>max)
        {    max=a[i];
        count=i;
        printf("%d %d\n",max,count);
    }
}
printf("%d\n",count);
    system("pause");
    return 0;
}

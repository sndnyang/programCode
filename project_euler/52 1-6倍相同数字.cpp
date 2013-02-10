#include<stdio.h>
#include<stdlib.h>
int init(int x,int a[])
{
    int t=x;
    while(t)
    {
        a[t%10]++;
        t/=10;        
    }
}
int same(int x,int a[])
{
      int t=x,i;
      while(t)
      {
           a[t%10]--;
           t/=10;
      }
      for(i=0;i<10;i++)
          if(a[i])return 0;
      return 1;
}
int main()
{
    int i,j,k,flag=1,a[10]={0},b[10];   
    for(i=100000;i<166666;i++)
    {
        flag=1;
        for(j=0;j<10;j++)
            a[j]=0;
        init(i,a);        
        for(k=2;k<6;k++)
        {
            for(j=0;j<10;j++)
                b[j]=a[j];            
            if(same(k*i,b)==0)
            {
                 flag=0;
                 break;
            }                          
        }
        if(flag)
        {
            printf("%d\n",i);
            break;
        }
    }
    system("pause");
    return 0;
}
        
        
    

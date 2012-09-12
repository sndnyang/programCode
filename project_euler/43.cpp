#include<stdio.h>
#include<stdlib.h>
int prime[7]={2,3,5,7,11,13,17};
int sum[10];
void print(int p[],int a[])
{
     int i;
     for(i=0;i<10;i++)
     {
         if(a[i]==0)
         {
             printf("%d",i);  
             sum[0]+=i;
         }
     }
     for(i=1;i<=9;i++)
     {
         printf("%d",p[i]);
         sum[i]+=p[i];
     }
     printf("\n");
}
void For(int p[],int a[],int has)
{
     int i,j,k,t,b[10]; 
     for(j=0;j<=9;j++)
          b[j]=a[j]; 
     if(has==1)print(p,b);
     else 
         for(i=0;i<=9;i++)
         {
            
             if(b[i]==0)
             {
                 k=i*100+p[has]*10+p[has+1];                 
                 if(k%prime[has-2]==0)
                 {
                      p[has-1]=i;
                      b[i]=1;
                      For(p,b,has-1);
                      b[i]=0;                      
                 }
            }
        }
}
void Back(int p[],int a[],int has)
{
     int i,j,k,t,b[10];
     for(j=0;j<=9;j++)
         b[j]=a[j];   
     if(has==9)For(p,b,5);
     else 
        for(i=0;i<=9;i++)
        {            
            if(b[i]==0)
            {
                 k=p[has-1]*100+p[has]*10+i;                 
                 if(k%prime[has-2]==0)
                 {
                      p[has+1]=i;
                      b[i]=1;
                      Back(p,b,has+1);
                      b[i]=0;
                 }
            }
        }
}
void Five(int p[],int a[])
{
     int i,b[12],m,n;
     for(i=0;i<12;i++)b[i]=a[i];
     for(i=506;i<600;i+=11)
     {
         m=i/10%10;n=i%10;
         if(b[m]==0&&b[n]==0)
         {
              p[6]=m;p[7]=n;
              b[m]=1;b[n]=1;
              Back(p,b,7);
              b[m]=0;b[n]=0;
         }
     }
}              
int main()
{
    int p[10],a[20]={0},i;
    for(i=0;i<10;i++)sum[i]=0;
    p[5]=5;
    a[5]=1;
    Five(p,a);
    for(i=9;i>0;i--)
    {
        sum[i-1]+=sum[i]/10;
        sum[i]%=10;
    }
    for(i=0;i<10;i++)
         printf("%d",sum[i]);
    system("pause");
    return 0;
}
    
    

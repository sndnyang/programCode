#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long add;
int num;
void factor(long &add,int t,int m)
{
     int i;
     printf("add=%d ,n=%d\n",add,num);
     printf("t=%d m=%d  *=%d\n",t,m,t*m);
     
     for(i=2;i<=(int)sqrt(t);i++)
     {
         if(t%i==0)
         {
             if(t==i*i)
             {
                 add-=i*(num/t-1);
                 printf("- i=%d * n/t=%d =%d  ==%d\n",i,num/t,i*(num/t-1),add);    
             }
             else 
             {
                  printf("i=%d,need n/t=%d\n",i,num/t);
                  add-=i*(num/t-1);
                  printf("- %d ==%d\n",i*(num/t-1),add);
             }
                      
         } 
         factor(add,t/i,i);
     } 
     for(i=2;i<=(int )sqrt(m);i++)
     {
         if(m%i==0)
         {
             if(m==i*i)
             {
                 add-=i*(num/m-1);
                 printf("- %d * %d =%d  ==%d\n",i,num/m,i*(num/m-1),add);
             }
             else 
             {
                  printf("i=%d,need m/t=%d\n",i,m/t);
                  add-=i*(num/m-1);
                  printf("- %d   ==%d\n",i*(num/m-1),add);
             }
             
         }
         factor(add,m/i,i);
     }
}
int main()
{
    int n,i;
    long add;
    scanf("%ld",&add);
     printf("%ld\n",add);
    scanf("%d",&n);
    while(n)
    {
           n--;
           scanf("%d",&num);
           if(num==1)add=1;
           else add=2*num-1;              
           for(i=2;i<=(int)sqrt(num);i++)
           {
               if(num%i==0)
               {   
                    printf("in %d %d\n",num,i);
                    if(num!=i*i)
                    {   
                        printf("i=%d,num/i=%d ",i,num/i);                      
                        printf("%d + %d \n",add,(num/i-1)*(i-1)+(i-1)*(num/i-1));
                        add+=(num/i-1)*(i-1)+(i-1)*(num/i-1);
                    }
                    else 
                    {
                        printf("%d + %d \n",add,num/i*(i-1)-1);
                        add+=num/i*(i-1)-1;
                    }
                    factor(add,num/i,i);
               }
           }
           printf("%ld\n",add);
      }
      system("pause");
      return 0;
}
            

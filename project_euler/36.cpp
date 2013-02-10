#include<stdio.h>
#include<stdlib.h>
int p10[6],p2[22];
int ten(int x,int p[])
{
     int j,k=0,m=x;
     while(m)
     {
         p[k]=m%10;
         m/=10;
         k++;
     }
     return k;
}
int two(int x,int p[])
{
     int k=0,m=x;
     while(m)
     {
         p[k]=m%2;
         m/=2;
         k++;
     }
     return k;
}
int palin(int p[],int m)
{
    int i,j,flag=1;   
    for(i=0;i<m/2;i++)
        if(p[i]!=p[m-1-i])
        {
             flag=0;
             break;
        }    
    return flag;
}   
    
int main()
{
    int i,j,temp,count=0,flag;
    for(i=1;i<1000000;i+=2)
    {
           temp=ten(i,p10);                       
           flag=palin(p10,temp);
           if(flag==0)continue;                     
           temp=two(i,p2);                   
           flag=palin(p2,temp);               
           if(flag==0)continue;
           else 
           {                
                printf("%d ",i); 
                         
                count+=i;
           }           
    }
    printf("%d\n",count);
    system("pause");
    return 0;
}
           
           

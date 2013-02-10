#include<stdio.h>
#include<stdlib.h>
long t[1000024];
int K,N;
int Quick(long t[],int s,int m)
{
    int low=s,high=m,i;
    long pivot=t[s];    
    while(low<high)
    {
         while(high>low&&t[high]>pivot)
             high--;
         if(t[high]<pivot)
         { 
             t[low]=t[high];
             low++;
         }
         if(low==high)break;
         while(low<high&&t[low]<pivot)
             low++;
         if(t[low]>pivot)
         { 
             t[high]=t[low];
             high--;
         }
    }
    t[low]=pivot;    
    return (low);
}
void Sort(long t[],int s,int m)
{
     int k,i;
     k=Quick(t,s,m);
     if(k==K-1)
     {
         for(i=1;i<=N;i++)
             printf("%d ",t[i]); 
             printf("\n");     
         printf("%ld\n",t[k]);
     }
     else 
         if(k>K-1)Sort(t,s,k-1);
         else Sort(t,k+1,m);
}
int main()
{
    int i;
    scanf("%d %d",&N,&K);
    for(i=0;i<N;i++)
       scanf("%ld",&t[i]);   
    Sort(t,0,N-1);
    system("pause");
}
    

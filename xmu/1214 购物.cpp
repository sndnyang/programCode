#include<stdio.h>
#include<stdlib.h>
long a[100024];
void Heapsort(long c[],int s,int m)
{
     long t=c[s];
     int j;
     for(j=2*s;j<=m;j*=2)
     {
         if(j<m&& c[j]<c[j+1])j++;
         if(t<c[j])
         {
             c[s]=c[j];
             s=j;
         }
         else break;
     }
     c[s]=t;
}
int main()
{
    int N,M,i,j,t,k,total=0;
    long sum=0,num;
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++)
        scanf("%d",&a[i]);
    for(i=N/2;i>0;i--)
        Heapsort(a,i,N);
    for(i=N;i>=1;i--)
    {
        t=a[i];
        a[i]=a[1];
        a[1]=t;
        Heapsort(a,1,i-1);
    }
    
    sum=a[N]; 
    total=sum/M;   
    for(i=N-1;i>0;i--)
    {     
         num=0;    
         if(total<a[i])
         {
             sum+=a[i];
             printf("%d\n",sum);
             for(j=sum/M;j>total;j--)
             {
                  num=0;
                  for(k=N;k>=i;k--)
                  {
                      num+=a[k]/j;
                      printf("%d(%d/%d) +" ,a[k]/j,a[k],j);
                  }
                  printf("=%d\n",num);
                  if(num==M)
                  {
                      total=j;
                      break;                     
                  }
             }
         }
         else
         {
             if(num==M)t=1;
             else t=0;
             break;
         }
    }
    if(t==0)
    printf("%d\n",j);
    else printf("-1\n");
    system("pause");
}
         
   

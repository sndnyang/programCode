#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,m,i,j,a,b,t[210],deep;;
    scanf("%d",&n);
    while(n)
    {
            n--;
            for(i=0;i<201;i++)t[i]=0;
            scanf("%d",&m);
            for(i=0;i<m;i++)
            {     
                  deep=1;
                  scanf("%d%d",&a,&b);
                  if(i==0)
                  {
                       t[a]=1;t[b]=1;
                  }
                  else
                  {
                       t[a]=1;t[b]=1;                       
                       for(j=200;j>b;j--)
                            if(t[j]!=0)
                            {
                                 if(t[j]>=t[b])t[b]=t[j]+1;
                                 else if(t[j]==t[b]-1)t[b]--;
                            }
                       for(j=1;j<a;j++)
                            if(t[j]!=0)
                            {
                                 if(t[j]>=t[a])t[a]=t[j]+1;
                                 else if(t[j]==t[a]-1)t[a]--;
                            }                                              
                  }
                  if(t[a]>deep)deep=t[a];
                  if(t[b]>deep)deep=t[b];
                  t[b]=deep;t[a]=deep;                  
            }
            printf("%d\n",deep*10);        
   }
    system("pause");
    return 0;
}
    

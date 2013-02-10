#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,m,i,j,w[102],sum=0,wi[100400]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);        
        sum+=w[i];
    }
    wi[sum]=1;
    for(i=0;i<n;i++)
    { 
        for(j=1;j<sum;j++)
        {
            if(wi[j]!=0&&wi[j]!=i+1)
            {
                if(wi[j+w[i]]==0)
                     wi[j+w[i]]=i+1;
                if(j>w[i]&&wi[j-w[i]]==0)
                     wi[j-w[i]]=i+1;
            }
            if(w[i]>j&&wi[j]!=0&&wi[j]!=i+1&&wi[w[i]-j]==0)
                     wi[w[i]-j]=i+1;
        }
        wi[w[i]]=i+1;
    }
    m=0;
    for(j=1;j<=sum;j++)
        if(wi[j]!=0)
             m++;
    printf("%d\n",m);
    system("pause");
    return 0;
}

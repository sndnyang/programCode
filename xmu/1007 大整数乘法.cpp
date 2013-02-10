#include <stdio.h>
int main()
{
    char a[100],b[100],s[202];
    int n,i,j,g,t=0,k=1,temp;
    scanf("%d",&n);
    n--;
    scanf("%s%s",&a,&b);
    while(k<=2*n)
    {
         s[k]=0;
         temp=0;
         for(i=0;i<=n;i++)
         {
               for(j=0;j<=n;j++)
               {
                   if((i+j)==k-1)
                       temp+=(a[n-i]-48)*(b[n-j]-48);
               }
         }
         g=(temp+t)%10;
         t=(temp+t)/10;
         s[k]=g;
         k++;
    }
    temp=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            if((i+j)==k-1)
                temp+=(a[n-i]-48)*(b[n-j]-48);
    }
    temp+=t;
    printf("%d",temp);
    for(i=2*n;i>0;i--)
        printf("%d",s[i]);
    printf("\n");
    return 0;
}

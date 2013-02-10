#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,ti[1009][2],tr[1009][2],final[2],in1,in2,ou1,ou2,a1,b1,a2,b2;
    scanf("%d",&n);
    scanf("%d%d%d%d",&in1,&in2,&ou1,&ou2);
    for(j=0;j<2;j++)
       for(i=0;i<n;i++)
           scanf("%d",&ti[i][j]);
    for(j=0;j<2;j++)
       for(i=0;i<n-1;i++)
           scanf("%d",&tr[i][j]);
    final[0]=in1+ti[0][0];
    final[1]=in2+ti[0][1];    
    for(i=1;i<n;i++)
    {
         a1=final[0]+ti[i][0];b1=final[1]+ti[i][0]+tr[i-1][1];
         
         a2=final[1]+ti[i][1];b2=final[0]+ti[i][1]+tr[i-1][0];
         final[0]=a1<b1?a1:b1;final[1]=a2<b2?a2:b2;         
    }
    final[0]+=ou1;final[1]+=ou2;
    a1=final[0]<final[1]?final[0]:final[1];
    printf("%d\n",a1);
    system("pause");
    return 0;
}
    

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,A[2],B[2];
    int m;
    for(a=99;a>10;a--)
    {
        if(a%10==0)continue;
        for(b=a-1;b>9;b--)
        {             
             m=1000*b/a;
             A[0]=a%10;A[1]=a/10;
             B[0]=b%10;B[1]=b/10;
          
             if(A[0]==B[0])
                 if(1000*B[1]/A[1]==m)
                 {
                     printf("1:%d/%d,%d\n",a,b,m);
                 }
             if(A[1]==B[0])
             {
                 if(1000*B[1]/A[0]==m)
                 {
                     printf("2:%d/%d,%d\n",a,b,m);
                 }
             }
             if(A[0]==B[1])
                 if(1000*B[0]/A[1]==m)
                 {
                     printf("3:%d/%d,%d\n",a,b,m);
                 }
        }
    }
    system("pause");
    return 0;
}

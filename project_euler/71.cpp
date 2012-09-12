#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x,y;
    int num;
    double r,t;
    double inf,upp;
    double sc7=1.0*3/7;
    upp=1.0*3/7*1000000;
    inf=upp-1;
    t=int (sc7*1000000);
    printf("inf=%lf  upp=%lf  t=%lf\n",inf,upp,t);
    int i,j;
    printf("%lf\n",1.0*3/7);
    for(i=150000;i<150020;i++)
        for(j=i*2;j<i*3&&j<1000000;j++)
        {
             r=i*1.0/j;
             if(r!=sc7)continue;
             else if(r>sc7)
             {                 
                 r=i*1.0/j*1000000;
                 if(r>t)
                 {             
                       num=i;
                       printf("%lf  %d %d\n",i*1.0/j*1000000,i,j);
                       t=r;
                       break; 
                 }
             }
             else break;
        }
    loop:printf("%d\n",num);
    system("pause");
    return 0;
}

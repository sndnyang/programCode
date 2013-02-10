#include<stdio.h>
#include<stdlib.h>
#define pi 3.1415927
int main()
{
    int re,n=0;
    float d,time,av,di;
    while(1)
    {
         n++;
         scanf("%f%d%f",&d,&re,&time);
         if(re==0)break;
         di=pi*d*re/(12*5280);
         av=di/time*3600;
         printf("Trip #%d: %.2f %.2f\n",n,di,av);
    }
    system("pause");
    return 0;
}

         

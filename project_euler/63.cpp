#include<stdio.h>
#include<stdlib.h>
int Len(int x,int y)
{
    int num[100]={1},leng=1,i,j,temp;
    for(i=0;i<y;i++)
    {
         temp=0;
         for(j=0;j<leng;j++)
             num[j]*=x;        
         for(j=0;j<leng;j++)
         {              
              temp=num[j]/10;
              num[j+1]=num[j+1]+temp;
              num[j]%=10;
         }
         if(num[leng]!=0)leng++;
    }
    return leng/y;
}
int main()
{
    int i,j,total=1;
    for(i=2;i<10;i++)
        for(j=2;;j++)
        {
            if(Len(i,j)==0)
            {
                printf("%d can give %d \n",i,j-1);
                total+=j-1;
                break;
            }
        }
    printf("%d\n",total);
    system("pause");
    return 0;
}  

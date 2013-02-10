#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
     FILE *fp1,*fp2;
     char ch;
     int flag=0;
     int ae=0,maxa=519433;
     int be=0,b2,maxb=525807,b=0;
     double max=0,t;
     fp1=fopen("base_exp.txt","r");       
     while( (ch=fgetc(fp1))!=EOF)
     {
            if(ch==',')
            {     flag=1; b++;}                             
            else if(ch=='\n')
            {
                 flag=0;
                 t=be*log(ae);
                        
                 if(t>max)
                 {
                      max=t;
                      b2=b;
                 }
                 ae=0;be=0;                 
                 
            }
            else 
            {
                 if(flag==0)
                 {
                      ae=ae*10+ch-'0';
                 }
                 else 
                 {
                      be=be*10+ch-'0';
                 }
            }
     }     
     printf("%lf %d\n",max,b2);
     fclose(fp1);
     system("pause");
     return 0;
}

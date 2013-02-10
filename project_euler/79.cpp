#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isfirst(char a[][5],int flag[],int x,int y,int k)
{
    int i,j;
    printf("JUDGE %d\n",a[x][y]-'0');
    for(i=0;i<k;i++)
        for(j=0;j<3;j++)
             if(a[i][j]==a[x][y])
                  if(j!=0&&flag[a[i][j-1]-'0']==0)
                        return 0;                
    return 1;
}             
int main()
{
    int i,j=0,k=0,temp=0;
    int flag[10]={0};
    FILE *fp;
    char ch[5];
    char a[55][5];
    fp=fopen("keylog.txt","r");
    while( (fscanf(fp,"%s",ch))!=EOF)
    {      
         for(i=0;i<k;i++)
             if(strcmp(a[i],ch)==0)
                   j=1;
         if(j==1)
              j=0;                  
         else
         {             
             strcpy(a[k++],ch);             
         }
    } 
    char b[20],m=0,n;    
    for(j=0;j<10;j++)
    {
        for(n=0;n<3;n++)
        {
             for(i=0;i<k;i++)            
                 if(flag[a[i][n]-'0']==0&&isfirst(a,flag,i,n,k)==1)
                 {
                      b[m++]=a[i][n]-'0';
                      flag[a[i][n]-'0']=1;
                      temp=1;
                      printf("\n");
                      break;
                 }
             if(temp==1)
             {
                  temp=1;break;
             }
        }        
        if(temp==0)break;
        else temp=0;
    }
    printf("%d\n",m);
    for(i=0;i<m;i++)printf("%d",b[i]);
    system("pause");
    return 0;
}
         

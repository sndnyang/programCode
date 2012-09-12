#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print(char s[],int len)
{
     int i,add=1,flag=1,t=strlen(s);
     for(i=0;i<strlen(s);i++)
     {        
          add=flag;          
          if(s[i]>='0'&&s[i]<='9')
          {               
               if(s[i]=='9'&&add==1)flag=1;
               else flag=0;
               s[i]=(s[i]-'0'+add)%10+'0';              
          }
          else if(s[i]>='A'&&s[i]<='Z')
          {
               if(s[i]=='Z'&&add==1)flag=1;
               else flag=0;
               s[i]=(s[i]-'A'+add)%26+'A';                        
          }
          else if(s[i]>='a'&&s[i]<='z')
          {
               if(s[i]=='z'&&add==1)flag=1;
               else flag=0;
               s[i]=(s[i]-'a'+add)%26+'a';                         
          }                       
     }
     if(flag==1)
     {
          if(s[t-1]=='0')s[t]='1';
          else if(s[t-1]=='a')s[t]='a';
          else if(s[t-1]=='A')s[t]='A';          
          s[t+1]='\0';                           
     }     
     for(i=strlen(s)-1;i>=0;i--)
        printf("%c",s[i]);    
     printf("\n");
}
int main()
{
    int x,i,j,k,t,m,n;
    char s[112],temp;
    scanf("%s%d",s,&n);
    t=strlen(s);
    for(i=0;i<t/2;i++)
    {
         temp=s[i];
         s[i]=s[t-i-1];
         s[t-i-1]=temp;
    }
           
    for(i=0;i<n;i++)
    {
         print(s,t);         
    }
    system("pause");
    return 0;
}

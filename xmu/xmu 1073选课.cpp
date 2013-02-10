#include<stdio.h>
#include<stdlib.h>
typedef struct Edge
{
     int vex,dis;
     struct Edge *next;
}Edge;
typedef struct Vex
{
     int indegree;
     Edge *first;
}Vex;
Vex a[504];
int f[504];
char course[502][42];
void TopologicalSort(int n)
{
     int i,j,stack[504],m=1,count=0;
     Edge *p;
     for(i=1;i<=n;i++)
         if(!a[i].indegree)
             stack[m++]=i;
     m--;
     while(m)
     {
          i=stack[m--];
          f[count++]=i;
          for(p=a[i].first;p;p=p->next)
          {
               int k=p->vex;
               if(!(--a[k].indegree))
                    stack[++m]=k;
          }
     }
     if(count<n)printf("Impossible!\n");
     else for(i=0;i<n;i++)
     printf("%s ",course[f[i]]);
}
int main()
{
    int i,j,k,n,m;
    Edge *p,*q;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%s",course[i]);
    for(i=0;i<n;i++)
    {
         scanf("%d",&k);
         a[i+1].indegree=k;
         for(j=0;j<k;j++)
         {
             scanf("%d",&m);
             p=(Edge *)malloc(sizeof(Edge));
             p->vex=i+1;
             p->next=NULL;
             if(a[m].first==NULL)
             {
                  
                  a[m].first=p;
             }
             else
             {
                 q=a[m].first;
                 a[m].first=p;
                 p->next=q;
             }
         }
    }
    TopologicalSort(n);
    system("pause");
    return 0;
}

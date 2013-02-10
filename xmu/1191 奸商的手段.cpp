#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
        int price;
        struct node *front,*next;
}Good;
typedef struct tnode
{
        Good *head,*tail;
}TG;
int main()
{
    int i,n,m;
    char c[10];
    scanf("%d%d",&n,&m);
    TG a;
    Good *p,*q,*t;
    p=(Good *)malloc(sizeof(Good));
    p->price=0;
    a.head=p;a.tail=p;
    p->next=NULL;
    p->front=NULL;
    for(i=0;i<n;i++)
    {
        p=(Good *)malloc(sizeof(Good));
        scanf("%d",&p->price);
        p->next=NULL;
        p->front=NULL;
        q=a.head;
        t=q;
        while(q!=NULL&&q->price<p->price)
        {
              t=q;
              q=q->next;
        }
        t->next=p;
        p->next=q;        
    }
    a.tail=q;
    p=a.head;
    while(p!=NULL)
    {
         printf("%d \n",p->price);
         p=p->next;
    }
    printf("%d %d\n",a.head->next->price,a.tail->price);
    while(m)
    {
            m--;
            scanf("%s",c);
            printf("%s",c);
            if(strcmp(c,"RICH")==0)
            
    system("pause");
    return 0;
}
                

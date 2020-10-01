
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{ int info;  struct node *next;};

void create(struct node *);
void print(struct node *);
int main()
{

    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("unsuccessful Memory allocation....");
    }
    else
    {
        printf("\nsuccessful memory allocation...");
        create(p);
        print(p);
    }

    return 0;
}
void create(struct node *p)
{
    int t;   // it is used for input info
    printf("\nEnter info of current node:");
    scanf("%d",&t);
    if(t==0)
    {
        p->next=0;
        printf("\ndoes not having info about node....link destroyed to next node");
    }
    else
    {
        p->info=t;
        p->next=(struct node *)malloc(sizeof(struct node));
        create(p->next);
    }


}

void print(struct node *p)
{
    if(p->next==0)
    {
       printf("\nend...");
    }
    else
    {
    printf("\ninfo:%d---next=%u",p->info,p->next);
    print(p->next);
    }
}

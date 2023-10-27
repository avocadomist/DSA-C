#include <stdio.h>
#include <stdlib.h>
struct list create();
void insert_first();
void insert();
void delete();
void display();
struct list
{
    int data;
    struct list *next;
};
int main()
{
    int n;
    char c='y';
    struct list *start,*q;
    start=(struct list*)malloc(sizeof(struct list));
    while(c=='Y'||c=='y')
    {
        printf("The options are:\n1-Create a linked list\n2-Insert a node at a particular position\n");
        printf("3-Delete a node at a particular postion\n4-Display the linked list\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            *start=create();
            break;
            case 2:
            insert(start);
            break;
            case 3:
            delete(start);
            break;
            case 4:
            q=start;
            display(q);
            break;
            default:
            printf("Invalid choice.");
            break;
        }
        printf("\nWould you like to perform the operation again(Y/N): ");
        scanf(" %c",&c);
    }
    return 0;
}
struct list create()
{
    struct list *s,*start;
    char v;
    start=(struct list*)malloc(sizeof(struct list));
    printf("Enter data: ");
    scanf("%d",&start->data);
    start->next=NULL;
    s=start;
    printf("Would you like to add another node(Y/N): ");
    scanf(" %c",&v);
    while(v=='y'||v=='Y')
    {
        struct list *p=(struct list*)malloc(sizeof(struct list));
        printf("Enter data: ");
        scanf("%d",&p->data);
        p->next=NULL;
        s->next=p;
        s=s->next;
        printf("Would you like to add another node(Y/N): ");
        scanf(" %c",&v);
    }
    printf("The creation is done. \n");
    
    return *start;
}
void display(struct list *q)
{
    while(q->next)
    {
        printf("%d->",q->data);
        q=q->next;
    }
    printf("%d",q->data);
}
void insert_first(struct list *start)
{
    struct list *node;
    node= (struct list *) malloc (sizeof(struct list));
    if(node==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    node->next=start;
    printf("\nInput the new node value :");
    scanf( "%d", &node->data);
    start = node;
}
void delete(struct list *start)
{
    struct list *prev,*cur;
    int i=0,loc;
    cur=start;
    if(cur==NULL)
    {
        printf("Underflow");
        exit(0);
    }
    printf("Enter the location: ");
    scanf("%d",&loc);
    while(i<loc && cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
        i++;
    }
    prev->next=cur->next;
    free(cur);
}
void insert(struct list *start)
{
    struct list *node,*cur,*prev;
    int loc,i=0;
    cur=start;
    node= (struct list *) malloc (sizeof(struct list));
    if(node==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    printf("Enter position: ");
    scanf("%d",&loc);
    if(loc==0)
        insert_first(start);
    else
    {
        printf("\nInput the new node value :");
        scanf( "%d", &node->data);
        while(i<loc)
        {
            prev=cur;
            cur=cur->next;
            i++;
        }
        prev->next=node;
        node->next=cur;
    }
}

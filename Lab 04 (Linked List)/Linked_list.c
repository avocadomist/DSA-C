#include<stdio.h>
#include<stdlib.h>


int count=0;
struct node
{
    int data;
    struct node *link;
}*head=NULL;

void create()
{
    struct node *newnode,*current;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data in newnode: ");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        current=head;
        while(current->link!=NULL)
        {
            current=current->link;
        }
        current->link=newnode;
    }
    count++;
}

void insert_beg()
{
    struct node *newnode,*current;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d",&newnode->data);
    current=head;
    newnode->link=head;
    head=newnode;
    count++;
}

void insert_end()
{
    struct node *newnode,*current;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    current=head;

    while(current->link!=NULL)
        {
            current=current->link;
        }
    current->link=newnode;
    count++;

}

void insert()
{
    struct node *newnode,*current,*temp;
    int n;
    printf("\nEnter position at which you want to insert data: ");
    scanf("%d",&n);
    if(n==1)
    {
        insert_beg();
    }
    else if(n==count)
    {
        insert_end();
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        current=head;
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->link=NULL;
        for(int i=1;i<n;i++)
        {
            temp=current;
            current=current->link;
        }
        temp->link=newnode;
        newnode->link=current;
        count++;
    }
    
}

void delete_end()
{
    struct node *current,*temp;
    current=head;
    while(current->link!=NULL)
    {
        temp=current;
        current=current->link;
    }
    temp->link=NULL;
    free(current);
    current=NULL;
    count--;
}

void delete_beg()
{
    struct node *current;
    current=head;
    head=current->link;
    free(current);
    current=NULL;
    count--;
}

void delete()
{
    int n,i;
    struct node *current,*temp;
    printf("\nEnter the position of node to delete: ");
    scanf("%d",&n);
    if(n==1)
    {
        delete_beg();
    }
    else if(n==count)
    {
        delete_end();
    }
    else
    {
        current=head;
        for(i=1;i<n;i++)
        {
            temp=current;
            current=current->link;
        }
        temp->link=current->link;
        free(current);
        current=NULL;
        count--;
    }
}

void display()
{
    printf("\nDisplay:\n");
    struct node *current;
    current=head;
    while(current!=NULL)
    {
        printf("%d\t",current->data);
        current=current->link;
    }
}

int main()
{
    while(1)
    {
        int x;
        
        printf("\nAvailable options: \n1)Create nodes\n2)Insert a node\n3)Delete a node\n4)Display");
        printf("\n5)Exit the Program \nEnter your choice: ");
        scanf("%d",&x);
        if(x==1)
        {
            int n,i;
            printf("Enter number of nodes: ");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                create();
            }
        }
        else if(x==2)
            insert();
        else if(x==3)
            delete();
        else if(x==4)
            display();
        else if(x==5)
        {
            printf("\nProgram is ending....");
            break;
        }
        else
        {
            printf("\nInvalid choice!!Try Again\n");
            continue;
        }

    }
    return 0;
}
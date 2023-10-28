#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
}*head=NULL,*top=NULL;

void empty()
{
    printf("\nUnderflow\n");
}

void push()
{
    struct node *newnode,*current;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    
    current=head;
    top=newnode;
    
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

}

void pop()
{
    struct node *temp,*current;
    current=head;
    if (head==NULL)
    {
        empty();
    }
    else
    {
        while(current->link!=NULL)
        {
            temp=current;
            current=current->link;
        }
        if(top==head)
        {
            head=NULL;
        }
        else
        {
            free(top);
            top=NULL;
            top=temp;
            temp->link=NULL;
        }
    }
    
}

void display()
{
    printf("\nDisplay\n");
    struct node *current;
    current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->link;
    }
    printf("\n");
}

int main()
{
    int n=0;
    while(n!=4)
    {
        printf("\nAvailable stack operations:");
        printf("\n1)Push\n2)POP\n3)Display\n4)Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&n);
        
        switch(n)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting the program: ");
                break;
            default:
                printf("\nWrong choice try again");
                break;
        }
    }

    return 0;
}

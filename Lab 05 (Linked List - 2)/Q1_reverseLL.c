 #include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node *link; 
}*head=NULL;

void createList()
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
    
}

void reverseList()
{
    struct node *prev, *current, *next;
    prev=next=NULL;
    current = head;

    while(current!=NULL)
    {
        next = 	current->link;
        current->link = prev;
        prev = current; 
        current = next;
    }
	
	head = prev; // Make last node as head

}

void displayList()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    
    else
    {
        temp = head;
        while(temp!= NULL)
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->link;            
        }
    }
}

int main()
{
    int n;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
    	createList();
	}

    printf("\nData in the list \n");
    displayList();

    printf("\nReversing the list........\n");
    reverseList();

    printf("\nData in the list\n");
    displayList();

    return 0;
}
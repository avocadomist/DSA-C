#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
}*front=NULL, *rear=NULL;

void enqueue()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter data: ");
	scanf("%d", &newnode->data);
	
	newnode->link = NULL;
	
	if(rear==NULL)
	{
		rear=front=newnode;
	}
	
	else
	{
		rear->link=newnode;
		rear=newnode;
	}
}

void dequeue()
{
	struct node *temp;
	temp=front;
	
	if(front==NULL)
	{
        printf("queue is empty \n");
        front = rear = NULL;
    }
    else
    {    
        printf("deleted element is %d\n", front->data);
        front = front->link;
        free(temp);
    }
}

void display()
{
    struct node *temp;
 
    temp = front;

    if (front  ==  NULL)
    {
        printf(" queue empty \n");
    }
    
    else
    {
    	while (temp)
    	{
    		printf("%d  ", temp->data);
			temp = temp->link;
		}
        
	}
   
}


void main()
{
    int choice, value;
    
    do
    {
        printf("\nenter the choice \n");
        printf("1 : enqueue \n2 : dequeue \n3 : display \n4 : Exit\n");
        scanf("%d", &choice);
        
        switch (choice)    // menu driven program
        {
        case 1: 
            enqueue();
            break;
        case 2:    
            dequeue();
            break;
        case 3: 
            printf("\nQueue: \n");
            display();
            break;
        case 4: 
            printf("\nExit\n");
            break;
        default: 
            printf("wrong choice\n");
            break;
        }
    } while(choice!=4);
    
}

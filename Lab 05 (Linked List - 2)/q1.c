#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
}*head=NULL;
void create()
{
	struct node *current, *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
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
void reverse()
{
	struct node *current, *prev, *next;
    current=head->link;
    prev=head;
    while(current!=NULL)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;

    }
    head->link=NULL;
    head=prev;
}
void display()
{
	struct node *current;
	current=head;
	while(current!=NULL)
	{
		printf("%d ",current->data);
		current=current->link;
	}
}
int main()
{
	int n;
	printf("How many nodes? ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		create();
	}
	printf("\nThe list is: ");
	display();
	reverse();
	printf("\nThe reversed list is: ");
	display();
}
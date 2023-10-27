#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
}*head=NULL, *last=NULL;

void create()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	newnode->prev=last;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		last=head;
	}
	else{
		last->next=newnode;
		last=newnode;
	}
}

void swap(int k)
{
	struct node *current;
	int temp;
	current=head;
	for(int i=0;i<k;i++)
		current=current->next;
	temp=current->data;
	current->data=current->prev->data;
	current->prev->data=temp;
}

void display()
{
	struct node *current;
	current=head;
	while(current!=NULL)
	{
		printf("%d ",current->data);
		current=current->next;
	}
}
int main()
{
	int n,k;
	printf("How many nodes? ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		create();
	display();
	printf("\nEnter the position for swapping: ");
	scanf("%d",&k);
	swap(k);
	display();
}
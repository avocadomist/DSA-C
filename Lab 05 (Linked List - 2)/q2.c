//WAP to interchange Kth and K+1th node
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
void swap(int k)
{
	struct node *current, *prev=NULL;
	int temp;
	current=head;
	for(int i=0;i<k;i++)
	{
		prev=current;
		current=current->link;
	}
	temp=prev->data;
	prev->data=current->data;
	current->data=temp;
}
void display()
{
	struct node *current;
	current=head;
	while(current!=NULL)
	{
		printf("%d, ",current->data);
		current=current->link;
	}
}
int main()
{
	int n,k;
	printf("How many nodes? ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		create();
	}
	printf("\nThe list is: ");
	display();
	printf("\nEnter the postion for swapping:");
	scanf("%d",&k);
	swap(k);
	printf("\nThe swapped list is: ");
	display();
}
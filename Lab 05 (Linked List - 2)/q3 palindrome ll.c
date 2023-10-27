#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
}*head=NULL;
int count=0;
void create()
{
	struct node *newnode, *current;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	if (head==NULL)
	{
		head=newnode;
	}
	else{
		current=head;
		while(current->link!=NULL)
			current=current->link;
		current->link=newnode;
	}
	count++;
}

int palindrome()
{
	struct node *start, *end;
	int i=0,j;
	while(i!=count/2)
	{
		start=end=head;
		for(j=0;j<i;j++)
			start=start->link;
		for(j=0;j<count-(i+1);j++)
			end=end->link;
		if(start->data!=end->data)
			return 0;
		else
			i++;
	}
	return 1;
}

int main()
{
	int n;
	printf("Enter no. of nodes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		create();
	int result=palindrome();
	if(result==1)
		printf("It is palindrome.");
	else
		printf("Not a palindrome.");
	return 0;
}
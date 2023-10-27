#include<stdio.h>
#include<stdlib.h>
struct node{
	int r,c,data;
	struct node *link;
}*head=NULL;

void sparse(int row, int col, int val)
{
	struct node *newnode, *current;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->r=row;
	newnode->c=col;
	newnode->data=val;
	newnode->link=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else{
		current=head;
		while(current->link!=NULL)
			current=current->link;
		current->link=newnode;
	}
}

void display()
{
	struct node *current;
	current=head;
	printf("\nThe matrix is: \n");
	while(current!=NULL)
	{
		printf("\n%d\t%d\t%d",current->r,current->c,current->data);
		current=current->link;
	}
}
int main()
{
	int i,j,r,c,size=0,k=0;
	printf("Enter the no. of rows and columns:");
	scanf("%d %d",&r,&c);
	int a[r][c];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter element of index[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			if(a[i][j]!=0)
				size++;
	if(size>(r*c)/2)
	{
		printf("Not a sparse matrix");
		exit(0);
	}
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			if(a[i][j]!=0)
				sparse(i,j,a[i][j]);
				
	display();
}
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node *f = NULL;
struct node *r = NULL;

void enqueue() //Insert elements in Queue
{
	struct node* n;
	n = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter data: ");
	scanf("%d", &n->data);
	
	n->next = NULL;
	if((r==NULL)&&(f==NULL))
	{
		f = r = n;
		r->next = f;
	}
	else
	{
		r->next = n;
		r = n;
		n->next = f;
	}
} 

void dequeue() // Delete an element from Queue
{
	struct node* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else if(f == r){
		f = r = NULL;
		free(t);
	}
	else{
		f = f->next;
		r->next = f;
		free(t);
	}
	
	
}
void print()
{ // Print the elements of Queue
	struct node* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else{
		do{
			printf("\n%d",t->data);
			t = t->next;
		}while(t != f);
	}
}
int main()
{
	int opt;
	printf("Enter Your Choice:-");
	do{
		printf("\n\n1 Enqueue\n2 Display \n3 for Dequeue\n4 Exit");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				enqueue();
				break;
			case 2:
				print();
				break;
			case 3:
				 dequeue();
				break;
			case 4:
				printf("\nExit..\n")
				break;
			default:
				printf("\nIncorrect Choice");
			
		}
	}while(opt!=4);
return 0;
}
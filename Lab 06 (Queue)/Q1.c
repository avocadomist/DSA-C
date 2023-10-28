//Q.Create enque and deque operation for queue using dynamic array and linked list

#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,size=0;

void enque(int *arr)
{
    if(rear+1>=size)
    {
        int n;
        printf("\nThe queue is full, reallocating memory\n");
        printf("Enter number of elements you want to add: ");
        scanf("%d",&n);
        size+=n;
        arr=(int *)realloc(arr,size);
        enque(arr);
    }
    else
    {
        if(front==-1)
        {
            front++;
        }
        while(rear+1<size)
        {
            printf("\nEnter the data: ");
            scanf("%d",&arr[++rear]);
        }
        
    }

}

void dequeue(int *arr)
{
	front++;
    if((front==0 && rear==-1) || front>size)
    {
        printf("\nQueue is empty\n\n");
        front--;
    }
    else
    {
        printf("\nElement deleted is: %d",arr[front-1]);
    }
}

void display(int *a)
{
    printf("\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int *arr,c;
    printf("Enter number of elements in the queue: ");
    scanf("%d",&size);
    c=0;
    arr=(int *)malloc(size*sizeof(int));
    while(c!=4)
    {
        printf("\nAvailable options:\n1)Enqueue\n2)Dequeue\n3)Display\n4)Exit\nEnter your choice: ");
        scanf("%d",&c);

        switch (c)
        {
            case 1:
                enque(arr);
                break;
            case 2:
                dequeue(arr);
                break;
            case 3:
                display(arr);
                break;
            case 4:
                printf("Program is exiting....");
                break;
            default:
                printf("Invalid choice! Try Again.\n");
                break;
        }
    }

}
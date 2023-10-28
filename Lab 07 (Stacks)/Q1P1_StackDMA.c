#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define max 10

int *stk, top = -1;

void push()
{
	int val;
	
	if (top==(max-1))
	{
		printf("\nStack overflow\n");
	}
	
	else
	{
		printf("\nEnter data: ");
		scanf("%d", &val);
		
		stk[top++]=val;
	}
} 

void pop()
{
	if (top==-1)
	{
		printf("\nStack underflow\n");
	}
	
	else
	{
		printf("\nDeleted element is: %d\n", stk[--top]);
	}
}

void display()
{
	printf("\nStack: \n");
    for(int i=-1;i<top;i++)
	    printf("%d  ",stk[i]);
	printf("\n");
}

int main()
{
	int ch=0;
    
    stk=(int *)malloc(max*sizeof(int));
    
    while(ch!=4)
    {
        printf("\nAvailable options:");
        printf("\n1)Push\n2)Pop\n3)Display\n4)Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        
        switch(ch)
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
                printf("\nExit");
                break;
            default:
                printf("\nOption unavailable");
                break;
        }
    }

    return 0;
}







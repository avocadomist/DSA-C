#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,a,b,*arr,i,*ptr,sum=0;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	
    arr=(int*)calloc(n,sizeof(int));
	if(arr==NULL)
	{
		printf("Space not available.");
		exit(0);
	}
	else
	{
		printf("Enter the elements: ");
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
	}
	
    printf("Do you want more elements? 1- yes and 2- no: ");
	scanf("%d",&b);
	while(b==1)
	{
		printf("Enter by how much you want to increase: ");
		scanf("%d",&a);
		n=n+a;
		ptr=(int*)realloc(arr,n*sizeof(int));
		if(arr==NULL)
		{
			printf("Space not available.");
			exit(0);
		}
		arr=ptr;
		printf("Enter the new elements:\n");
		for(i=0;i<a;i++)
		{
			scanf("%d",&arr[n+i]);
			sum+=arr[n+i];
		}
		printf("Do you want more elements? Press 1 for yes and 0 for no ");
		scanf("%d",&b);
	}
	printf("The sum is %d", sum);
    free(arr);
    free(ptr);
    arr=NULL;
    ptr=NULL;
    return 0;
}
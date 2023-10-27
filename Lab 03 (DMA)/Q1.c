#include<stdio.h>
#include<stdlib.h>


int** calc(int n,int m,int **arr,int **arr1)
{
    int i,j;
    int **arr2=(int**)malloc(m*sizeof(int*));

    for(i=0;i<m;i++){
		arr2[i]=(int*)malloc(n*sizeof(int));

	}

    if(arr2==NULL){
        printf("\nNo space available");
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            arr2[i][j]=arr[i][j]+arr1[i][j];
        }
    }

    return arr2;
}

void main()
{
	int m,n,i,j,sum=0;
	printf("Enter rows and columns for the matrix: ");
	scanf("%d %d",&m,&n);
	int **arr=(int**)malloc(m*sizeof(int*));
    int **arr1=(int**)malloc(m*sizeof(int*));
    int **arr3=(int**)malloc(m*sizeof(int*));

    if(arr==NULL || arr1==NULL || arr3==NULL){
        printf("\nNo space available");
        exit(0);
    }


	printf("Enter the elements for matrix 1:\n");
	
    for(i=0;i<m;i++){
		arr[i]=(int*)malloc(n*sizeof(int));

	}

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    printf("Enter the elements for matrix 2:\n");

    for(i=0;i<m;i++){
		arr1[i]=(int*)malloc(n*sizeof(int));

	}

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    
    arr3=calc(n,m,arr,arr1);
    printf("\nThe addition of above two matrix is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",arr3[i][j]);
        }
        printf("\n");
    }

	free(arr);
    free(arr1);
    free(arr3);
    arr=NULL;
    arr1=NULL;
    arr3=NULL;
}
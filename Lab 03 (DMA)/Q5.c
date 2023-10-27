#include <stdio.h>
#include <stdlib.h>

int main(){
    int **arr,i,j,n,m;

    printf("Enter the no. of rows and column: ");
    scanf("%d %d",&n,&m);

    arr=(int**)malloc(n*sizeof(int));

    if(arr==NULL)
    {
        printf("\nNo space available");
        exit(0);
    }

    for (i=0;i<n;i++){
        arr[i]=(int*)malloc(m*sizeof(int));
    }

    printf("\nEnter the matrix elements:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    printf("\nThe matrix is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    free(arr);
    arr=NULL;
}
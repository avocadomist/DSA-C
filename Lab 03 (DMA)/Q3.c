#include <stdio.h>
#include <stdlib.h>



int main(){
    int *ptr,n,i,sum=0;
    printf("Enter the no. of elements in the array: ");
    scanf("%d",&n);

    ptr= (int*)malloc(n*sizeof(int));

    if(ptr==NULL){
        printf("No space available");
        exit(0);
    }

    printf("Enter the elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",ptr+i);
    }

    for(i=0;i<n;i++){
        sum+=*(ptr+i);
    }

    printf("Sum of the array is: %d",sum);
    free(ptr);   
    ptr=NULL;
}
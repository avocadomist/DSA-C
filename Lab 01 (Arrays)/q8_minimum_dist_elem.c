#include <stdio.h>

int main(){
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter elemnet %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    //printing unsorted array
    printf("\n\nPrinting unsorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    int x,y;
    printf("\n\nEnter a number:");
    scanf("%d",&x);
    printf("Enter another number:");
    scanf("%d",&y);

    int x_index,y_index,min=n,temp=arr[0];
    //min is initialized with the value n because the minimum distance can't be greater than the size of the array
    for(int i=0;i<n;i++){
        if(x==arr[i]){
            x_index=i;
            for(int j=0;j<n;j++){
                if(y==arr[j]){
                    y_index=j;
                
                    if ((y_index-x_index)<0){
                        temp=-(y_index-x_index);
                    }
                    else{
                        temp=y_index-x_index;  
                    }
                    if(min>temp){
                        min=temp;
                    }
                }
            }
        }
    }

    printf("The minimum distance between %d and %d is: %d\n",x,y,min);
}
#include <stdio.h>

int non_zero(int n,int arr[][n]);
int sum_diag(int n,int arr[][n]);
void min_diag(int n,int arr[][n]);
int diag_product(int n,int arr[][n]);


int main(){
    int n;
    printf("Enter number of rows and column: ");
    scanf("%d",&n);

    int a[n][n];
    for(int i=0;i<n;i++){
        printf("\n\nRow %d\n",i);
        for(int j=0;j<n;j++){
            printf("Enter element at index [%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("\n\nMatrix is:\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber of non zero elements are: %d\n",non_zero(n,a));
    printf("\nSum of elements above leading diagonal is: %d\n",sum_diag(n,a));
    min_diag(n,a);
    printf("\n\nProduct of diagonal elements is: %d",diag_product(n,a));

}

int non_zero(int n,int arr[][n]){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                sum+=1;
            }
        }
    }
    return sum;
}

int sum_diag(int n,int arr[][n]){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>i){
                sum+=arr[i][j];
            }
        }
    }
    return sum;
}

void min_diag(int n,int arr[][n]){
    printf("\nElements under the minor diagonal are: \n");
    for(int i=1;i<n;i++){
        for(int j=n-i;j<n;j++){
                printf("%d ",arr[i][j]);
        }
    }
}

int diag_product(int n,int arr[][n]){
    int product=1;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(i==j){
                product*=arr[i][j];
            }
        }
    }
    return product;
}
#include<stdio.h>

int  main()
{ 
    int i, j, r, c;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &r, &c);
    int  a[r][c],b[10][10];
    printf("Enter the elements:\n");
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            printf("a[%d][%d]: ",i,j);
            scanf("%d", &a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    printf("\nMatrix is: \n");
    for (i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            printf("%d | ",a[i][j]);

        }            
        printf("\n");
    }

    /*to lower*/
    for (i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            if(i<j)
            {
                a[i][j]=0;
            }
        }         
    }
    printf("\nLower triangular matrix: \n");
    for (i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            printf("%d | ",a[i][j]);
        }            
        printf("\n");
    }

    /*to upper*/
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            if(i>j)
            {
                b[i][j]=0;
            }
        }         
    }
    printf("\nUpper triangular matrix: \n");
    
    for (i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            printf("%d | ",b[i][j]);
        }            
        printf("\n");
    }

    /*from lower to upper*/
    printf("\nLower triangular matrix to upper triangular matrix: \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d | ",a[j][i]);
        }
        printf("\n");
    }
}




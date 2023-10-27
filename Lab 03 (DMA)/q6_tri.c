#include <stdio.h>
#include <math.h>
double dist(int *a, int *c, int *b, int *d)
{
    return sqrt(pow((*b - *a), 2) + pow((*d - *c), 2));
}

int main()
{
    int flag;
    int x1, y1, x2, y2, x3, y3;
    printf("\nEnter the first point: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the second point: ");
    scanf("%d%d", &x2, &y2);
    printf("Enter the third point: ");
    scanf("%d%d", &x3, &y3);
    double sa, sb, sc;
    sa = dist(&x1, &y1, &x2, &y2);
    sb = dist(&x2, &y2, &x3, &y3);
    sc = dist(&x3, &y3, &x1, &y1);

    if (((sa + sb) > sc) && ((sb + sc) > sa) && ((sa + sc) > sb))
    {
        printf("Triangle possible\n");
        flag = 1;
    }
    else
    {
        printf("Triangle can't be formed..\n");
        flag = 0;
    }
    if (flag == 1)
    {
        int x, y;
        double s;
        double a = dist(&x1, &y1, &x2, &y2);
        double b = dist(&x2, &y2, &x3, &y3);
        double c = dist(&x3, &y3, &x1, &y1);
        s = (a + b + c) / 2.0;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("The area of the triangle is: %.2f", area);
        printf("\nEnter point to check: ");
        scanf("%ld%ld", &x, &y);
        if ((dist(&x, &y, &x1, &y1) + dist(&x, &y, &x2, &y2) + dist(&x, &y, &x3, &y3)) <
            (a + b + c))
        {
            printf("(%d,%d) lies inside the triangle..\n", x, y);
        }
        else
        {
            printf("(%d,%d) does not lie inside the triangle..\n", x, y);
        }
    }
    return 0;
}
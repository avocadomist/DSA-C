#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swapsort(char **s, int n)
{
    char *temp = (char *)malloc(sizeof(char));
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(s[i], s[j]) > 0)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    char **s;
    s = (char **)malloc(sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        s[i] = (char *)malloc(sizeof(char));
    }
    printf("Enter the names: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
    }
    swapsort(s, n);
    printf("Names in alphabetical order..\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s\n", i + 1, s[i]);
    }
    return 0;
}
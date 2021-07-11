#include <stdio.h>
#define MAX_WIDTH 5
#define MAX_HEIGHT 5
void main()
{
    int r, c, a[MAX_WIDTH][MAX_HEIGHT], count = 0;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    if (r * c > MAX_WIDTH * MAX_HEIGHT)
    {
        printf("Overflow\nPlease enter a size of smaller dimensions");
        return 0;
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            printf("Enter value [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                count++;
        }
    if (count > (r * c) / 2)
        printf("Sparse matrix");
    else
        printf("Not a sparse matrix");
}
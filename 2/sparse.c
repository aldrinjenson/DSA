#include <stdio.h>
void main()
{
   int r, c, a[5][5], count = 0;
   printf("Enter number of rows and columns: ");
   scanf("%d %d", &r, &c);

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

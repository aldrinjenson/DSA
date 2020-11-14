#include <stdio.h>
void main()
{
   int r = 6, c = 5;

   int a[6][5] = {{1, 2, 3, 4, 5},
                  {6, 7, 8, 9, 10},
                  {11, 12, 13, 14, 15},
                  {16, 17, 18, 19, 20},
                  {21, 22, 23, 24, 25},
                  {26, 27, 28, 29, 30}};
   int ans[30];
   int s = r * c, k;
   int i, j;

   int iVal = 0, jVal = 0, count = 0;

   for (k = 0, i = 0, j = 0; k < s; k++)
   {
       ans[k] = a[i][j];
       if (i == count + 1 && j == count)
       {
           count++;
       }
       if (i == count)
       {
           iVal = 0;
           jVal = 1;
       }
       if (j == c - count - 1)
       {
           iVal = 1;
           jVal = 0;
       }
       if (i == r - count - 1)
       {
           iVal = 0;
           jVal = -1;
       }
       if (j == count && i != count)
       {
           iVal = -1;
           jVal = 0;
       }
       i += iVal;
       j += jVal;
   }

   for (int i = 0; i < s; i++)
       printf("%d ", ans[i]);
}

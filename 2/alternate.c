#include <stdio.h>

void main()
{
   int len = 11;
   int i, j, k;
   int a[11] = {-4, 8, -30, -6, 5, -9, 7, 1, -21, -11, 19};
   int ans[11];
   int positive[11], negative[11], positiveCount, negativeCount;

   for (positiveCount = 0, negativeCount = 0, k = 0; k < len; k++)
   {
       if (a[k] > 0)
       {
           positive[positiveCount] = a[k];
           positiveCount++;
       }
       else
       {
           negative[negativeCount] = a[k];
           negativeCount++;
       }
   }
   for (; positiveCount < len; positiveCount++)
       positive[positiveCount] = 0;
   for (; negativeCount < len; negativeCount++)
       negative[negativeCount] = 0;

   for (k = 0, i = 0, j = 0; k < len;)
   {
       if (positive[i])
       {
           ans[k] = positive[i];
           i++;
           k++;
       }
       if (negative[j])
       {
           ans[k] = negative[j];
           j++;
           k++;
       }
   }
   printf("\nAfter rearranging: ");
   for (i = 0; i < len; i++)
       printf("%d ", ans[i]);
}
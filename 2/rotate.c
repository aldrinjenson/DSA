#include <stdio.h>
void main()
{
   int a[20], size, n, i, temp;
   printf("Enter array size: ");
   scanf("%d", &size);
   for (i = 0; i < size; i++)
       scanf("%d", &a[i]);
   printf("Enter roating amount: ");
   scanf("%d", &n);

   printf("\nEntered array:  ");
   for (i = 0; i < size; i++)
       printf("%d ", a[i]);
   for (i = 0; i < size - n; i++)
   {
       temp = a[i];
       a[i] = a[i + n];
       a[i + n] = temp;
   }
   for (; i < size - 1; i++)
   {
       temp = a[i];
       a[i] = a[i + 1];
       a[i + 1] = temp;
   }

   printf("\nAfter rotating: ");
   for (i = 0; i < size; i++)
       printf("%d ", a[i]);
}

#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int *arr, int len)
{
  int i, j;
  for (i = 0; i < len - 1; i++)
  {
    for (j = 0; j < len - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
    }
  }
}

void main()
{
  int count, a[30];
  printf("How many numbers do you want to enter?(max 30): ");
  scanf("%d", &count);
  printf("Enter %d numbers:\n", count);

  for (int i = 0; i < count; i++)
    scanf(" %d", &a[i]);

  // int a[10] = {4, 3, -3, 434, -345, 0, 4356, -767, 65, 90};
  // int count = 10;

  bubbleSort(a, count);
  printf("After sorting\n");
  for (int i = 0; i < count; i++)
    printf("%d ", a[i]);
}
#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int *arr, int len)
{
  int i, j, min_index;
  for (i = 0; i < len - 1; i++)
  {
    min_index = i;
    for (j = i + 1; j < len; j++)
      if (arr[j] < arr[min_index])
        min_index = j;
    swap(&arr[i], &arr[min_index]);

    printf("After sorting\n");
    for (int i = 0; i < len; i++)
      printf("%d ", arr[i]);
  }
}

void main()
{
  int count, a[30];
  printf("How many numbers do you want to enter?max 30): ");
  scanf("%d", &count);
  printf("Enter %d numbers:\n", count);

  for (int i = 0; i < count; i++)
    scanf(" %d", &a[i]);
  selectionSort(a, count);
  printf("After sorting\n");
  for (int i = 0; i < count; i++)
    printf("%d ", a[i]);
}
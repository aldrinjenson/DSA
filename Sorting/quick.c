#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *arr, int l, int h)
{
  int pivot = arr[l];
  int down = l, up = h;
  while (down < up)
  {
    while (arr[down] <= pivot)
      down++;
    while (arr[up] > pivot)
      up--;
    if (down < up)
      swap(&arr[down], &arr[up]);
  }
  swap(&arr[l], &arr[up]);
  return up;
}

void quickSort(int *arr, int lb, int ub)
{
  if (lb >= ub)
    return;
  int j = partition(arr, lb, ub);
  quickSort(arr, lb, j - 1);
  quickSort(arr, j + 1, ub);
  return;
}

void main()
{
  int a[] = {46, 3, 656, 2, 6, 32, 8, 5};
  int count = sizeof(a) / sizeof(int);

  quickSort(a, 0, count - 1);

  printf("After sorting\n");
  for (int i = 0; i < count; i++)
    printf("%d ", a[i]);
  printf("\n");
}

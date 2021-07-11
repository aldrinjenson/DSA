#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertionSort(int *a, int len)
{
  int i, j;
  int temp;
  for (i = 1; i < len; i++)
  {
    temp = a[i];
    j = i - 1;
    while (temp < a[j] && j >= 0)
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = temp;
  }
}

void main()
{
  int a[] = {46, 3, 656, 2, 6, 8, 5};
  int count = sizeof(a) / sizeof(int);

  insertionSort(a, count);
  printf("After sorting\n");
  for (int i = 0; i < count; i++)
    printf("%d ", a[i]);
  printf("\n");
}
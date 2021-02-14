#include <stdio.h>
#define MAX 30

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void merge(int a[], int first, int mid, int last) //To combine the sorted sections
{
  int b[MAX];
  int j, lpt, upt, n;
  j = 0;
  lpt = first;
  upt = mid + 1;
  n = last - first + 1;
  while (lpt < mid + 1 && upt < last + 1)
  {
    if (a[lpt] < a[upt])
    {
      b[j] = a[lpt];
      lpt++;
      j++;
    }
    else
    {
      b[j] = a[upt];
      upt++;
      j++;
    }
  }

  while (lpt < mid + 1) //Insert the remaining elements of the sub-arrays
  {
    b[j] = a[lpt];
    lpt++;
    j++;
  }
  while (upt < last + 1)
  {
    b[j] = a[upt];
    upt++;
    j++;
  }

  lpt = first;
  for (j = 0; j < n; j++)
  {
    a[lpt] = b[j];
    lpt++;
  }
}

void mergeSort(int *arr, int first, int last)
{
  if (first == last)
    return;

  int mid = (first + last) / 2;
  mergeSort(arr, first, mid);
  mergeSort(arr, mid + 1, last);
  merge(arr, first, mid, last);
}

void main()
{

  int a[] = {46, 3, 656, 2, 6, 32, 8, 5};
  int count = sizeof(a) / sizeof(int);

  mergeSort(a, 0, count - 1);
  printf("After sorting\n");
  for (int i = 0; i < count; i++)
    printf("%d ", a[i]);
  printf("\n");
}
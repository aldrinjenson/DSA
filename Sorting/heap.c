#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int a[], int i, int j) //To check for the heap rule and arranging the array
{
  int temp;
  int k = i;
  int left = 2 * k + 1;  //Left son of i
  int right = 2 * k + 2; //Right son of i

  if (left < j && a[left] > a[k])
    k = left;
  if (right < j && a[right] > a[k])
    k = right;

  if (k != i)
  {
    temp = a[i];
    a[i] = a[k];
    a[k] = temp;
    heapify(a, k, j);
  }
}

void buildHeap(int arr[], int n) //To create the initial heap
{
  for (int i = n - 1; i >= 0; i--)
    heapify(arr, i, n);
}

void heapSort(int arr[], int n) //To sort the elements using Heap sort
{
  int temp;
  buildHeap(arr, n);
  for (int i = n - 1; i > 0; i--)
  {
    temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, 0, i);

    printf("\nAfter iteration: ");

    for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
  }
}

void main()
{
  // int count, a[30];
  // printf("How many numbers do you want to enter?(max 30): ");
  // scanf("%d", &count);
  // printf("Enter %d numbers:\n", count);

  // for (int i = 0; i < count; i++)
  //   scanf(" %d", &a[i]);

  // int a[10] = {4, 3, -3, 434, -345, 0, 4356, -767, 65, 90};

  int a[] = {46, 3, 656, 2, 6, 32, 8, 5};
  int count = sizeof(a) / sizeof(int);

  heapSort(a, count);
  printf("\nAfter sorting\n");
  for (int i = 0; i < count; i++)
    printf("%d ", a[i]);
  printf("\n");
}
#include <stdio.h>

int binarySearch(int a[], int el, int length)
{
  int start, end, middle;
  for (start = 0, end = length - 1; start <= end;)
  {
    middle = (start + end) / 2;
    if (a[middle] == el)
      return middle;
    else if (a[middle] < el)
      start = middle + 1;
    else
      end = middle - 1;
  }
  return -1;
}

void main()
{
  int x[] = {21, 34, 56, 67, 78, 89, 90, 432, 678, 5789};
  int size = sizeof(x) / sizeof(int);

  int term, length = 11;
  printf("Enter search term: ");
  scanf("%d", &term);
  int index = binarySearch(x, term, size);
  if (index != -1)
    printf("Found %d at position %d", term, index + 1);
  else
    printf("%d is not there in the entered array", term);
}
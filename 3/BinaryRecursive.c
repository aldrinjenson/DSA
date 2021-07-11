#include <stdio.h>

int binarySearch(int a[], int el, int l, int r)
{
    if (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == el)
            return m;
        else if (a[m] < el)
            return binarySearch(a, el, m + 1, r);
        else
            return binarySearch(a, el, l, m - 1);
    }
    return -1;
}

void main()
{
    int x[] = {21, 34, 56, 67, 78, 89, 90, 432, 678, 5789};
    int size = sizeof(x) / sizeof(int);

    int term;
    printf("Enter search term: ");
    scanf("%d", &term);
    int index = binarySearch(x, term, 0, size - 1);
    if (index != -1)
        printf("Found %d at position %d", term, index + 1);
    else
        printf("%d is not there in the entered array", term);
}
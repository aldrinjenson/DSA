#include <stdio.h>

int linearRecursive(int arr[], int el, int i, int end)
{
    if (i < end)
    {
        if (arr[i] == el)
            return i;
        else
            return linearRecursive(arr, el, i + 1, end);
    }
    return -1;
}

void main()
{
    int x[] = {9, 6, 4, 24, 56, 34, 23, 6, 7, 34, 23};
    int term, length = 11;
    printf("Enter search term: ");
    scanf("%d", &term);
    int index = linearRecursive(x, term, 0, length - 1);
    if (index != -1)
        printf("Found %d at position %d", term, index + 1);
    else
        printf("%d is not there in the entered array", term);
}
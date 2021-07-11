#include <stdio.h>

int linearSearch(int * arr, int el, int length)
{
    for (int i = 0; i < length; i++)
        if (arr[i] == el)
            return i + 1;
    return -1;
}

void main()
{
    int x[] = {9, 6, 4, 24, 56, 34, 23, 6, 7, 34, 23};
    int term, length = 11;
    printf("Enter search term: ");
    scanf("%d", &term);
    int index = linearSearch(x, term, 11);
    if (index != -1)
        printf("Found %d at position %d", term, index);
    else
        printf("%d is not there in the entered array", term);
}
#include <stdio.h>
void main()
{
    int len = 4, i, j, k;
    int a[4] = {14, 6, 5, 2};
    int b[4] = {10, 9, 5, 1};
    int sorted[10], max;

    for (i = 0, j = 0, k = 0; i < len && j < len; k++)
    {
        if (a[i] > b[j])
        {
            max = a[i];
            i++;
        }
        else
        {
            max = b[j];
            j++;
        }
        sorted[k] = max;
    }
    for (; i < len; i++, k++)
        sorted[k] = a[i];
    for (; j < len; k++, j++)
        sorted[k] = b[j];

    printf("After merging:\n");
    for (int i = 0; i < len * 2; i++)
        printf("%d ", sorted[i]);
}

#include <stdio.h>

void main()
{
    int n, i = 0;
    unsigned long int a = 1, b = 1, c;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("%lu %lu ", a, b);
    while (i < n - 2)
    {
        c = a + b;
        printf("%lu ", c);
        a = b;
        b = c;
        i ++;
    }
}
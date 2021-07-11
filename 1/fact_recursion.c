#include <stdio.h>

unsigned long int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}

void main()
{
    int n;
    // printf("Enter a number: ");
    // scanf("%d", &n);
    n = 65;
    printf("Factorial of %d = %lu\n", n, fact(n));
}
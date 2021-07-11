#include <stdio.h>

unsigned long int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

void main()
{
    int n = 5;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        printf("%lu ", fib(i));
} 
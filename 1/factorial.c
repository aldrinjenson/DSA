#include <stdio.h>
void main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    unsigned long int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    printf("Factorial of %d = %lu\n", n, fact);
}
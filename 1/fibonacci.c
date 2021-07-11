// #include <stdio.h>

// void main()
// {
//     int n, i = 0;
//     unsigned long int a = 1, b = 1, c;
//     printf("Enter n: ");
//     scanf("%d", &n);
//     printf("%lu %lu ", a, b);
//     while (i < n - 2)
//     {
//         c = a + b;
//         printf("%lu ", c);
//         a = b;
//         b = c;
//         i ++;
//     }
// }

#include <stdio.h>
// program to print the first n fibonacci numbers

int generateFib(int i)
{
    int a = 0, b = 1, c = 0;
    int count = 0;
    while (count < i)
    {
        c = a + b;
        a = b;
        b = c;
        count++;
    }
    return c;
}

int generateFibRecursive(int i)
{
    if (i == 0 || i == 1)
        return i;
    return generateFibRecursive(i - 1) + generateFibRecursive(i - 2);
}
void main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", generateFibRecursive(i));
        // printf("%d, ", generateFib(i));
    }
}
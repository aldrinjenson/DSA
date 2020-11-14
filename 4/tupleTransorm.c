// WAP in C to enter a matrix in normal(Conventional )form.Write a function to convert the matrix to tuple form and display it.Also find the transpose of the matrix represented in tuple form and display the transpose in tuple and normal form

#include <stdio.h>
#define maxCol 10
#define maxLength 100

struct tupleElement
{
    int row;
    int col;
    int el;
};

void convertToTuple(int a[][maxCol], struct tupleElement t[maxLength], int r, int c)
{
    int i, j, k = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                t[k].row = i;
                t[k].col = j;
                t[k].el = a[i][j];
                k++;
            }
        }
    }
}

void calculateTranspose(struct tupleElement t[], struct tupleElement transpose[], int nonZeroes)
{
    for (int i = 0; i < nonZeroes; i++)
    {
        transpose[i].row = t[i].col;
        transpose[i].col = t[i].row;
        transpose[i].el = t[i].el;
    }
}

void tupleInNormalForm(struct tupleElement t[maxLength], int r, int c, int nonZeroes)
{
    // workaround so that we don't need to store the full matrix form ever, thereby conserving on space, but not on time complexity
    int flag;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            flag = 0;
            for (int k = 0; k < nonZeroes; k++)
            {
                if (t[k].row == i && t[k].col == j)
                {
                    printf("%d ", t[k].el);
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                printf("%d ", 0);
        }
        printf("\n");
    }
}

void displayTupleForm(struct tupleElement t[], int nonZeroes)
{
    for (int i = 0; i < nonZeroes; i++)
        printf("{ %d, %d, %d }\n", t[i].row, t[i].col, t[i].el);
}

void displayMatrix(int a[][maxCol], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void main()
{
    int i, j, r, c, zeroes, a[10][maxCol], nonZeroes, transposeNormal[10][maxCol];
    struct tupleElement tuples[maxLength], transpose[maxLength];
    printf("Enter row and column sizes: ");
    scanf("%d %d", &r, &c);
    printf("Enter the number of zeroes: ");
    scanf("%d", &zeroes);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Enter a[%d][%d] ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    nonZeroes = r * c - zeroes;
    printf("\nThe entered matrix is:\n");
    displayMatrix(a, r, c);
    convertToTuple(a, tuples, r, c);
    printf("\nTuple form of the entered matrix is:\n");
    displayTupleForm(tuples, nonZeroes);
    calculateTranspose(tuples, transpose, nonZeroes);
    printf("\nTranspose in tuple form is:\n");
    displayTupleForm(transpose, nonZeroes);
    printf("\nTranspose in normal form is:\n");
    tupleInNormalForm(transpose, c, r, nonZeroes);
}
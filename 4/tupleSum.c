// Write a C program to enter two matrices in normal (conventional) form. Write a function to convert two matrices to tuple form and display it.  Find the sum of the two matrices in tuple form and display the sum in tuple form

#include <stdio.h>
#define maxCol 10
#define maxLength 100

typedef struct
{
    int row;
    int col;
    int el;
} tupleElement;

int i, j;

void convertToTuple(int a[][maxCol], tupleElement t[maxLength], int r, int c)
{
    int k = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            t[k].row = i;
            t[k].col = j;
            t[k].el = a[i][j];
            k++;
        }
    }
}

void calculateSum(tupleElement a[], tupleElement b[], tupleElement sum[], int length)
{
    for (i = 0; i < length; i++)
    {
        sum[i].row = a[i].row;
        sum[i].col = a[i].col;
        sum[i].el = a[i].el + b[i].el;
    }
}

void displayTupleForm(tupleElement t[], int length)
{
    for (i = 0; i < length; i++)
        printf("{ %d, %d, %d }\n", t[i].row, t[i].col, t[i].el);
}

void displayMatrix(int a[][maxCol], int r, int c)
{
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void inputValues(int matrix[][maxCol], int r, int c)
{
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Enter m[%d][%d] ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void main()
{
    int r, c, m1[10][maxCol], m2[10][maxCol];
    tupleElement tuple1[maxLength], tuple2[maxLength], sumTuple[maxLength];
    printf("Enter row and column sizes: ");
    scanf("%d %d", &r, &c);
    printf("\nEnter values for first matrix:\n");
    inputValues(m1, r, c);
    printf("\nEnter values for second matrix:\n");
    inputValues(m2, r, c);

    printf("\nMatrix 1:\n");
    displayMatrix(m1, r, c);
    printf("\nMatrix 2:\n");
    displayMatrix(m2, r, c);

    convertToTuple(m1, tuple1, r, c);
    convertToTuple(m2, tuple2, r, c);
    printf("\nTuple form of matrix 1:\n");
    displayTupleForm(tuple1, r * c);
    printf("\nTuple form of matrix 2:\n");
    displayTupleForm(tuple2, r * c);

    calculateSum(tuple1, tuple2, sumTuple, r * c);
    printf("\nSum of the matrices in tuple form is:\n");
    displayTupleForm(sumTuple, r * c);
}
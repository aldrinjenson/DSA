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

void convertToSparse(int a[][maxCol], tupleElement t[maxLength], int r, int c, int *len)
{
  int k = 0;
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
  *len = k;
}

void calculateSum(tupleElement a[], tupleElement b[], tupleElement sum[], int len1, int len2, int *len3)
{
  for (i = 0; i < len1; i++)
    sum[i] = a[i];

  int isInside;

  for (j = 0; j < len2; j++)
  {
    isInside = 0;
    for (int l = 0; l < len1; l++)
    {
      if (sum[l].row == b[j].row && sum[l].col == b[j].col)
      {
        isInside = 1;
        sum[l].el += b[j].el;
      }
    }
    if (!isInside)
    {
      sum[i] = b[j];
      i++;
    }
  }
  *len3 = i;

  // OR
  // sorted version
  // i = 1;
  // j = 1;
  // int k = 1;

  // while (i < a[0].el && j < b[0].el)
  // {
  //   if (a[i].row == b[j].row && a[i].col == b[j].col)
  //   {
  //     sum[k].row = a[i].row;
  //     sum[k].col = a[i].col;
  //     sum[k].el = a[i].el + b[j].el;
  //     k++;
  //     i++;
  //     j++;
  //   }
  //   else if (a[i].row == b[j].row && a[i].col != b[j].col)
  //   {
  //     if (a[i].col < b[i].col)
  //     {
  //       sum[k].row = a[i].row;
  //       sum[k].col = a[i].col;
  //       sum[k].el = a[i].el;
  //       k++;
  //       i++;
  //     }
  //     else
  //     {
  //       sum[k].row = b[j].row;
  //       sum[k].col = b[j].col;
  //       sum[k].el = b[j].el;
  //       k++;
  //       j++;
  //     }
  //   }
  //   else
  //   {

  //     if (a[i].row < b[i].row)
  //     {
  //       sum[k].row = a[i].row;
  //       sum[k].col = a[i].col;
  //       sum[k].el = a[i].el;
  //       k++;
  //       i++;
  //     }
  //     else
  //     {
  //       sum[k].row = b[j].row;
  //       sum[k].col = b[j].col;
  //       sum[k].el = b[j].el;
  //       k++;
  //       j++;
  //     }
  //   }
  // }

  // while (i <= a[0].el)
  // {
  //   sum[k].row = a[i].row;
  //   sum[k].col = a[i].col;
  //   sum[k].el = a[j].el;
  //   k++;
  //   i++;
  // }
  // while (j <= b[0].el)
  // {
  //   sum[k].row = b[j].row;
  //   sum[k].col = b[j].col;
  //   sum[k].el = b[j].el;
  //   k++;
  //   j++;
  // }
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
  int len1, len2, len3;
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

  convertToSparse(m1, tuple1, r, c, &len1);
  convertToSparse(m2, tuple2, r, c, &len2);
  printf("\nTuple form of matrix 1:\n");
  displayTupleForm(tuple1, len1);
  printf("\nTuple form of matrix 2:\n");
  displayTupleForm(tuple2, len2);

  calculateSum(tuple1, tuple2, sumTuple, len1, len2, &len3);
  printf("\nSum of the matrices in tuple form is:\n");
  displayTupleForm(sumTuple, len3);
}
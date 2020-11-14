#include <stdio.h>
#define maxCol 10
#define maxLength 100

typedef struct
{
  int row;
  int col;
  int val;
} tuple;

int i, j;

void getMatrix(int m[][maxCol], int r, int c)
{
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      scanf("%d", &m[i][j]);
}

void printMatrix(int m[][maxCol], int r, int c)
{
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c; j++)
      printf("%d ", m[i][j]);
    printf("\n");
  }
}

void convertMatrix(int m[][maxCol], tuple t[])
{
  int k = 0;
  for (i = 0; i < t[0].row; i++)
    for (j = 0; j < t[0].col; j++)
      if (m[i][j] != 0)
      {
        k++;
        t[k].row = i;
        t[k].col = j;
        t[k].val = m[i][j];
      }
  t[0].val = k;
}

void displayTuple(tuple t[])
{
  printf("%d  %d  %d\n", t[0].row, t[0].col, t[0].val);
  printf("row col val\n");
  for (i = 1; i <= t[0].val; i++)
    printf("%d  %d  %d\n", t[i].row, t[i].col, t[i].val);
}

void tupleToNormal(tuple t[], int m[][maxCol])
{
  int k = 1;
  for (i = 0; i < t[0].row; i++)
    for (j = 0; j < t[0].col; j++)
      m[i][j] = 0;
  for (i = 1; i <= t[0].val; i++)
    m[t[i].row][t[i].col] = t[i].val;
}

void multiplyTuple(tuple t1[], tuple t2[], tuple product[])
{
  tuple t3[maxLength]; // temporary tuple
  int temp, k = 0, flag;

  t3[0].row = t1[0].row;
  t3[0].col = t2[0].col;

  for (i = 1; i <= t1[0].val; i++)
  {
    for (j = 1; j <= t2[0].val; j++)
    {
      if (t1[i].col == t2[j].row)
      {
        k++;
        t3[k].row = t1[i].row;
        t3[k].col = t2[j].col;
        t3[k].val = t1[i].val * t2[j].val;
      }
    }
  }

  t3[0].val = k;

  // to see the intermediate form, uncomment the following
  // printf("\nIntermediate tuple\n");
  // displayTuple(t3);

  int r;

  for (i = 1; i <= k; i++)
  {
    r = t3[i].row;
    for (j = i + 1; t3[j].row <= r; j++)
    {
      if (t3[j].col == t3[i].col)
      {
        t3[i].val += t3[j].val;
        t3[j].row = -1; // flagging similar rows
      }
    }
  }

  int count = 0;

  // code to copy only the valid tuple rows to the product matrix
  for (i = 1; i <= k; i++)
  {
    if (t3[i].row != -1)
    {
      count++;
      product[count].row = t3[i].row;
      product[count].col = t3[i].col;
      product[count].val = t3[i].val;
    }
  }

  product[0].row = t1[0].row;
  product[0].col = t2[0].col;
  product[0].val = count;
}

void main()
{
  int r, c, m, n;
  tuple t1[maxLength], t2[maxLength], productTuple[maxLength];
  int productMatrix[maxCol][maxCol];
  // int m1[maxCol][maxCol], m2[maxCol][maxCol];
  // printf("Enter row and column size of matrix 1: ");
  // scanf("%d %d", &r, &c);
  // printf("Enter row and column size of matrix 2: ");
  // scanf("%d %d", &m, &n);

  // driver code to test algorithm
  r = 2, c = 3;
  m = 3, n = 4;

  int m1[][maxCol] = {
      {1, 0, 3},
      {4, 5, 0},
  };

  int m2[][maxCol] = {
      {1, 2, 0, 4},
      {5, 0, 7, 8},
      {0, 10, 0, 12},
  };

  if (c != m)
  {
    printf("Sorry the dimensions are not compatible for multiplying");
  }
  else
  {
    // printf("Enter values for matrix 1: ");
    // getMatrix(m1, r, c);
    // printf("Enter values for matrix 2: ");
    // getMatrix(m2, m, n);

    printf("\nMatrix 1\n");
    printMatrix(m1, r, c);
    printf("\nMatrix 2\n");
    printMatrix(m2, m, n);

    t1[0].row = r;
    t1[0].col = c;
    convertMatrix(m1, t1);
    t2[0].row = m;
    t2[0].col = n;
    convertMatrix(m2, t2);

    printf("After converting:\n");

    printf("\nMatrix 1\n");
    displayTuple(t1);
    printf("\nMatrix 2\n");
    displayTuple(t2);

    multiplyTuple(t1, t2, productTuple);
    printf("\nAfter multiplying:\n");
    displayTuple(productTuple);

    tupleToNormal(productTuple, productMatrix);
    printf("\nProduct in normal form:\n");
    printMatrix(productMatrix, productTuple[0].row, productTuple[0].col);

    int temp, k;
    int final[maxCol][maxCol];
    printf("\nProduct in matrix form:\n");
    for (i = 0; i < r; i++)
    {
      for (j = 0; j < n; j++)
      {
        temp = 0;
        for (k = 0; k < c; k++)
        {
          temp += m1[i][k] * m2[k][j];
        }
        final[i][j] = temp;
      }
    }

    printMatrix(final, r, n);
  }
}
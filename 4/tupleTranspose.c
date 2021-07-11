#include <stdio.h>
#define maxCol 10
#define maxLength 100

typedef struct
{
  int row;
  int col;
  int val;
} tuple;

int i, j, k;

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
  k = 0;
  for (i = 0; i < t[0].row; i++)
  {
    for (j = 0; j < t[0].col; j++)
      if (m[i][j] != 0)
      {
        k++;
        t[k].row = i;
        t[k].col = j;
        t[k].val = m[i][j];
      }
  }
  t[0].val = k;
}

void displayTuple(tuple t[])
{
  printf("row col val\n");
  for (i = 1; i <= t[0].val; i++)
    printf("%d  %d  %d\n", t[i].row, t[i].col, t[i].val);
}

void transposeTuple(tuple t1[], tuple t2[])
{
  for (i = 0; i <= t1[0].val; i++)
  {
    t2[i].row = t1[i].col;
    t2[i].col = t1[i].row;
    t2[i].val = t1[i].val;
  }
}

void tupleToNormal(tuple t[], int m[][maxCol])
{
  for (i = 0; i < t[0].row; i++)
    for (j = 0; j < t[0].col; j++)
      m[i][j] = 0;
  for (i = 1; i <= t[0].val; i++)
    m[t[i].row][t[i].col] = t[i].val;
}

void main()
{
  int r, c;
  tuple t1[maxLength], t2[maxLength];
  int transposeMatrix[maxCol][maxCol];
  int m1[maxCol][maxCol];
  printf("Enter row and column size of matrix 1: ");
  scanf("%d %d", &r, &c);

  printf("Enter values for matrix 1: ");
  getMatrix(m1, r, c);

  printf("\nMatrix 1\n");
  printMatrix(m1, r, c);

  t1[0].row = r;
  t1[0].col = c;
  convertMatrix(m1, t1);

  printf("After converting:\n");
  printf("\nMatrix 1\n");
  displayTuple(t1);

  transposeTuple(t1, t2);
  printf("\nAfter transposing:\n");
  displayTuple(t2);

  tupleToNormal(t2, transposeMatrix);
  printf("\nTranspose in normal form:\n");
  printMatrix(transposeMatrix, t2[0].row, t2[0].col);
}

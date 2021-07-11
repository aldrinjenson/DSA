#include <stdio.h>

int i, j, k;

typedef struct
{
  int row;
  int col;
  int value;
} triple;

void getMatrix(triple sparse[], int rowSize, int colSize, int *length)
{
  int temp;
  for (i = 0, k = 0; i < rowSize; i++)
  {
    for (j = 0; j < colSize; j++)
    {
      printf("Enter m[%d][%d]", i, j);
      scanf("%d", &temp);
      if (temp != 0)
      {
        sparse[k].row = i;
        sparse[k].col = j;
        sparse[k].value = temp;
        k++;
      }
    }
  }
  *length = k;
}

void printMatrix(triple sparse[], int rowSize, int colSize, int length)
{
  for (i = 0; i < length; i++)
    printf("{ %d %d %d }\n", sparse[i].row, sparse[i].col, sparse[i].value);
}

void addSparse(triple s1[], triple s2[], triple s3[], int len1, int len2, int len3)
{
  
}

void main()
{
  int m, n, r, c;
  int len1, len2, len3;
  triple sparse1[20], sparse2[20], sparse3[20];
  printf("Enter row and column size of matrix 1;");
  scanf("%d %d", &r, &c);
  // printf("Enter row and column size of matrix 2;");
  // scanf("%d %d", &m, &n);
  m = r;
  n = c;
  if (m != r || c != n)
  {
    printf("Dimensions of both the matrices have to be the same for adding");
    return;
  }
  else
  {
    printf("\nEnter values for matrix 1\n");
    getMatrix(sparse1, r, c, &len1);
    printf("\nEnter values for matrix 2\n");
    getMatrix(sparse2, m, n, &len2);

    printf("\nTuple form of sparse matrix 1\n");
    printMatrix(sparse1, r, c, len1);
    printf("\nTuple form of sparse matrix 2\n");
    printMatrix(sparse2, m, n, len2);

    addSparse(sparse1, sparse2, sparse3, len1, len2, len3);
    printf("\nAfter addition:\n");
    printMatrix(sparse3, m, n, len3);
  }
}
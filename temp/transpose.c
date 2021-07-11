/* Program to convert a matrix in its conventional form to the tuple form
                        find its transpose*/
#include <stdio.h>
#define Max 100
typedef struct
{ //To store the matrix in tuple form
  int row;
  int col;
  int val;
} tup;

void inputMat(int arr[][Max], int m, int n)
{ //To get the inputs from the user
  int i, j;
  printf("Enter the elements of the array:\n");
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
      scanf("%d", &arr[i][j]);
  }
}

void matConvert(int arr[][Max], tup t[])
{ //To convert the matrix in conventional form to tuple form
  int i, j, k, m, n;
  m = t[0].row;
  n = t[0].col;
  k = 0;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (arr[i][j] != 0)
      {
        t[k + 1].row = i;
        t[k + 1].col = j;
        t[k + 1].val = arr[i][j];
        k++;
      }
    }
  }
  t[0].val = k;
}

void transpose(tup t[])
{ //To find the transpose of the matrix in the tuple form
  int i, temp;
  for (i = 0; i <= t[0].val; i++)
  {
    temp = t[i].row;
    t[i].row = t[i].col;
    t[i].col = temp;
  }
}

void matDisp(int arr[][Max], int m, int n)
{ //To display the matrix in the conventional form
  int i, j;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d\t", arr[i][j]);
    }
    printf("\n");
  }
}

void tupConvert(tup t[], int arrt[][Max])
{ //To convert the matrix from the tuple form to the conventional form
  int i, j, k, m, n;
  m = t[0].row;
  n = t[0].col;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
      arrt[i][j] = 0;
  }
  for (k = 1; k <= t[0].val; k++)
  {
    i = t[k].row;
    j = t[k].col;
    arrt[i][j] = t[k].val;
  }
}

void tupDisp(tup t[])
{ //To display the matrix in tuple form
  int i;
  printf("Row\tCol\tVal\n");
  for (i = 0; i <= t[0].val; i++)
    printf("%d\t%d\t%d\n", t[i].row, t[i].col, t[i].val);
}

void main()
{
  int a[Max][Max], at[Max][Max];
  int r, c;
  printf("Enter the number of rows: ");
  scanf("%d", &r);
  printf("Enter the number of columns: ");
  scanf("%d", &c);
  inputMat(a, r, c);
  tup t1[Max];
  t1[0].row = r;
  t1[0].col = c;
  printf("\nThe given matrix in conventional form is:\n");
  matDisp(a, r, c);
  matConvert(a, t1);
  printf("\nThe given matrix in tuple form is:\n");
  tupDisp(t1);
  transpose(t1);
  printf("\nThe transpose of the matrix in tuple form is:\n");
  tupDisp(t1);
  tupConvert(t1, at);
  printf("\nThe transpose of the matrix in the conventional form is:\n");
  matDisp(at, c, r);
}
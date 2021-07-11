/* Program to convert two matrices into tuple form and find their sum */
#include<stdio.h>
#define Max 100
typedef struct{
	int row;
	int col;
	int val;
} tup;

void inputMat(int arr[][Max], int m, int n) {  //To get the inputs from the user
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	}
}

void matConvert(int arr[][Max], tup t[]) {  //To convert the matrix in conventional form to tuple form
	int i,j,k,m,n;
	m = t[0].row;
	n = t[0].col;
	k = 0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]!=0)
			{
				t[k+1].row = i;
				t[k+1].col = j;
				t[k+1].val = arr[i][j];
				k++;		
			}
		}
	}
	t[0].val = k;
}

void tupDisp(tup t[]) { //To display the matrix in tuple form
	int i;
	printf("Row\tCol\tVal\n");
	for(i=0;i<=t[0].val;i++)
		printf("%d\t%d\t%d\n",t[i].row,t[i].col,t[i].val);
}

void club(tup t[]){ //To club the values with same indices
	int m,n,i,j,k,x,y;
	m = t[0].row;
	n = t[0].col;
	int a[Max][Max];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			a[i][j] = 0;
	}
	k = 1;
	for(i=0;i<t[0].val;i++)
	{
		x = t[k].row;
		y = t[k].col;
		a[x][y] += t[k].val;
		k++;
	}
	tup fin[Max];
	matConvert(a, t);
}

void multiply(tup a[], tup b[], tup c[]) { //To fine product of the two matrices in tuple form
	int m,n,p,i,j,x;
	c[0].row = a[0].row;
	c[0].col = b[0].col;
	m = a[0].val;
	n = b[0].val;
	x = 1;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
				if(a[i].col == b[j].row)
				{
				c[x].val = a[i].val*b[j].val;
				c[x].row = a[i].row;
				c[x].col = b[j].col;
				x++;
				}
		}
	}
	c[0].val = x-1;
	club(c);
}


void main() {
	int a[Max][Max], b[Max][Max];
	int ra,ca,rb,cb;
	printf("Enter the number of rows of matrix A: ");
	scanf("%d",&ra);
	printf("Enter the number of columns of matrix A: ");
	scanf("%d",&ca);
	printf("Enter the number of rows of matrix B: ");
	scanf("%d",&rb);
	printf("Enter the number of columns of matrix B: ");
	scanf("%d",&cb);
	if(ca!=rb)
		printf("The two matrices cannot be multiplied due to size mismatch");
	else
	{	
		printf("Enter the elements of matrix A:\n");
		inputMat(a,ra,ca);
		printf("Enter the elements of matrix B:\n");
		inputMat(b,rb,cb);
		tup t1[Max],t2[Max],t3[Max];
		t1[0].row = ra;
		t1[0].col = ca;
		matConvert(a, t1);
		printf("\nThe matrix A in tuple form is:\n");
		tupDisp(t1);
		t2[0].row = rb;
		t2[0].col = cb;
		matConvert(b, t2);
		printf("\nThe matrix B in tuple form is:\n");
		tupDisp(t2);
		multiply(t1, t2, t3);
		printf("\nThe product of the two matrices in tuple form is:\n");
		tupDisp(t3);
	}
}
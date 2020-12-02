// write a program to perform polynomial addition of two polynomials in one variable using singly linked list
#include <stdlib.h>
#include <stdio.h>

struct node
{
  int coeff;
  int exp;
  struct node *link;
};

struct node *start = NULL;

void insert(int c, int e)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->coeff = c;
  newNode->exp = e;
  newNode->link = NULL;
  if (start == NULL)
  {
    start = newNode;
    return;
  }
  struct node *tempNode = start;
  while (tempNode->link)
    tempNode = tempNode->link;
  tempNode->link = newNode;
}

void main()
{
  int item, res, ch, el;
  int num, c, e;

  printf("\nPolynomial Addition:\n");
  printf("Enter number of terms");
  scanf("%d", &num);
  for (int i = 0; i < num; i++)
  {
    printf("Enter Coefficient of term %d", i + 1);
    scanf("%d", &c);
    printf("Enter exponent of term %d", i + 1);
    scanf("%d", &e);
    insert(c, e);
  }
}
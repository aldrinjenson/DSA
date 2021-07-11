#include <stdio.h>
#include <stdlib.h>

struct list
{
  float coef;
  int exp;
  struct list *link;
};

struct list *startA, *startB, *startC;

void insert(struct list **start, float c, int e) //To insert nodes of the polynomials A and B
{
  struct list *node, *temp;
  node = malloc(sizeof(struct list));
  node->coef = c;
  node->exp = e;
  node->link = NULL;
  temp = *start;
  while (temp->link != NULL)
    temp = temp->link;
  temp->link = node;
}

void attach(float c, int e, struct list **ptr)
{
  struct list *temp;
  temp = malloc(sizeof(struct list));
  temp->coef = c;
  temp->exp = e;
  (*ptr)->link = temp;
  *ptr = temp;
}

void combine()
{
  struct list *temp, *temp1, *prev;
  temp = startC;
  temp1 = startC->link;
  prev = temp;
  float c;
  while (temp->link != NULL)
  {
    temp1 = temp->link;
    prev = temp;
    while (temp1 != NULL)
    {
      if (temp->exp == temp1->exp)
      {
        temp->coef = temp->coef + temp1->coef;
        prev->link = temp1->link;
      }
      prev = temp1;
      temp1 = temp1->link;
    }
    temp = temp->link;
  }
}

void polymul(struct list *a, struct list *b, struct list **c) //To multiply the polynomials A and B
{
  float coefficient;
  int exponent;
  struct list *rear, *temp, *sb;
  rear = malloc(sizeof(struct list));
  *c = rear;
  sb = b;
  while (a != NULL)
  {
    b = sb;
    while (b != NULL)
    {
      coefficient = a->coef * b->coef;
      exponent = a->exp + b->exp;
      attach(coefficient, exponent, &rear);
      b = b->link;
    }
    a = a->link;
  }
  rear->link = NULL;

  temp = *c;
  *c = (*c)->link;
  free(temp);
  combine();
}

void display(struct list **start)
{
  struct list *node;
  node = *start;
  printf("%f * (x^%d) ", node->coef, node->exp);
  node = node->link;
  while (node != NULL)
  {
    if (node->coef > 0)
      printf("+ %f * (x^%d) ", node->coef, node->exp);
    else if (node->coef < 0)
      printf(" %f * (x^%d) ", node->coef, node->exp);
    node = node->link;
  }
  printf("\n");
}

int main()
{
  float c;
  int n1, n2, e;
  startA = NULL;
  startB = NULL;
  printf("Enter the number of terms of the First polynomial: ");
  scanf("%d", &n1);
  printf("Enter the coefficient of term 1 of A: ");
  scanf("%f", &c);
  printf("Enter the exponent of term 1 of A: ");
  scanf("%d", &e);
  struct list *newnode;
  newnode = malloc(sizeof(struct list));
  newnode->coef = c;
  newnode->exp = e;
  newnode->link = NULL;
  if (startA == NULL)
    startA = newnode;
  for (int i = 1; i < n1; i++)
  {
    printf("Enter the coefficient of term %d of A: ", (i + 1));
    scanf("%f", &c);
    printf("Enter the exponent of term %d of A: ", (i + 1));
    scanf("%d", &e);
    insert(&startA, c, e);
  }
  printf("The Polynimial A(x) is: ");
  display(&startA);

  printf("Enter the number of terms of the Second polynomial: ");
  scanf("%d", &n2);
  printf("Enter the coefficient of term 1 of B: ");
  scanf("%f", &c);
  printf("Enter the exponent of term 1 of B: ");
  scanf("%d", &e);
  newnode = malloc(sizeof(struct list));
  newnode->coef = c;
  newnode->exp = e;
  newnode->link = NULL;
  startB = newnode;
  for (int i = 1; i < n2; i++)
  {
    printf("Enter the coefficient of term %d of B: ", (i + 1));
    scanf("%f", &c);
    printf("Enter the exponent of term %d of B: ", (i + 1));
    scanf("%d", &e);
    insert(&startB, c, e);
  }
  printf("The Polynomial B(x) is: ");
  display(&startB);

  polymul(startA, startB, &startC);
  printf("The Product of the Polynomials is: ");
  display(&startC);
  return 0;
}
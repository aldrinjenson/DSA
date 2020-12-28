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

int compare(int a, int b) //To compare the exponents
{
  if (a < b)
    return -1;
  else if (a == b)
    return 0;
  else
    return 1;
}

void attach(float coefficient, int exponent, struct list **ptr)
{
  struct list *temp;
  temp = malloc(sizeof(struct list));
  temp->coef = coefficient;
  temp->exp = exponent;
  (*ptr)->link = temp;
  *ptr = temp;
}

void polyadd(struct list *a, struct list *b, struct list **c) //To add the polynomials in A and B and store the result in C
{
  float sum;
  struct list *rear, *temp;
  rear = malloc(sizeof(struct list));
  *c = rear;
  while (a != NULL && b != NULL)
  {
    switch (compare(a->exp, b->exp))
    {
    case -1: //a->exp < b->exp
      attach(b->coef, b->exp, &rear);
      b = b->link;
      break;
    case 0: //a->exp = b->exp
      sum = a->coef + b->coef;
      if (sum != 0)
        attach(sum, a->exp, &rear);
      a = a->link;
      b = b->link;
      break;
    case 1: //a->exp > b->exp
      attach(a->coef, a->exp, &rear);
      a = a->link;
      break;
    }
  }
  for (; a != NULL; a = a->link)
    attach(a->coef, a->exp, &rear);
  for (; b != NULL; b = b->link)
    attach(b->coef, b->exp, &rear);

  rear->link = NULL;

  temp = *c;
  *c = (*c)->link;
  free(temp);
}

void display(struct list **start)
{
  struct list *node;
  node = *start;
  while (node->link != NULL)
  {
    printf("%f * (x^%d) + ", node->coef, node->exp);
    node = node->link;
  }
  printf("%f * (x^%d)\n", node->coef, node->exp);
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

  polyadd(startA, startB, &startC);
  printf("The Sum of the Polynomials is: ");
  display(&startC);
  return 0;
}
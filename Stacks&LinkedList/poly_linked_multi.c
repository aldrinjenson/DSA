// write a program to perform polynomial addition of two temp->one variable using singly linked list
#include <stdlib.h>
#include <stdio.h>

struct node
{
  int coeff;
  int exp;
  struct node *link;
};

struct node *aStart = NULL;
struct node *bStart = NULL;
struct node *cStart = NULL;

void insert(int c, int e, struct node **start)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->coeff = c;
  newNode->exp = e;
  newNode->link = NULL;

  if (*start == NULL)
  {
    *start = newNode;
    return;
  }
  struct node *tempNode = *start;
  while (tempNode->link)
    tempNode = tempNode->link;
  tempNode->link = newNode;
}

void readInput(struct node **start) //address
{
  int num, c, e;
  printf("Enter number of terms: ");
  scanf("%d", &num);
  for (int i = 0; i < num; i++)
  {
    printf("Enter Coefficient of term %d: ", i + 1);
    scanf("%d", &c);
    printf("Enter exponent of term %d: ", i + 1);
    scanf("%d", &e);
    insert(c, e, start); //passing the same address which is recieved
  }
}

int compare(int x, int y)
{
  return (x < y) ? -1 : x > y;
}

void attach(struct node **ptr, int c, int e)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->coeff = c;
  newNode->exp = e;
  (*ptr)->link = newNode;
  *ptr = newNode;
}

void combine()
{
  struct node *t3 = cStart;
  struct node *temp = malloc(sizeof(struct node));
  struct node *prev = malloc(sizeof(struct node));

  for (; t3; t3 = t3->link)
  {
    for (temp = t3->link; temp; temp = temp->link)
    {
      if (t3->exp == temp->exp)
      {
        t3->coeff = t3->coeff + temp->coeff;
        temp->coeff = 0;
      }
      prev = temp;
    }
  }

}

void multiplyPolynomial(struct node *a, struct node *b, struct node **c)
{
  struct node *t1 = a;
  struct node *t2 = b;
  struct node *t3 = malloc(sizeof(struct node));
  *c = t3;

  while (t1)
  {
    t2 = b;
    while (t2)
    {
      attach(&t3, t1->coeff * t2->coeff, t1->exp + t2->exp);
      t2 = t2->link;
    }
    t1 = t1->link;
  }

  t3->link = NULL;
  struct node *temp = *c;
  *c = (*c)->link;
  free(temp);
  combine();
}

void display(struct node *start)
{
  struct node *temp = start;
  while (temp)
  {
    printf("%d", temp->coeff);
    if (temp->exp)
      printf("x^%d ", temp->exp);
    if (temp->link != NULL)
      printf(" + ");
    temp = temp->link;
  }
}

void main()
{
  int item, res, ch, el;
  printf("\nPolynomial Addition:\n");
  printf("Enter data for polynomial 1:\n");
  readInput(&aStart); //passing by reference
  printf("\nEnter data for polynomial 2:\n");
  readInput(&bStart);
  printf("Polynomial A is:\n");
  display(aStart);
  printf("\nPolynomial B is:\n");
  display(bStart); //passing by value

  multiplyPolynomial(aStart, bStart, &cStart);
  printf("\nAfter Multiplication:\n");
  display(cStart);
}
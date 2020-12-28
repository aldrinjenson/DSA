#include <stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  struct node *link;
};
struct node *start = NULL;

void fun1(struct node *s)
{
  printf("%d", s->data);
  printf("%d", s->link);
}

void main()
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = 5;
  newNode->link = NULL;
  start = newNode;
  fun1(start);
  fun1(newNode);
}
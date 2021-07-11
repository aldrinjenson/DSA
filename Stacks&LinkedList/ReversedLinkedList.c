#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

struct node *start = NULL;

void insert(int el)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = el;
  newNode->link = NULL;

  if (!start)
  {
    start = newNode;
    return;
  }
  struct node *tempNode = start;
  while (tempNode->link)
    tempNode = tempNode->link;
  tempNode->link = newNode;
}

void display()
{
  struct node *tempNode = start;
  while (tempNode)
  {
    printf("%d", tempNode->data);
    if (tempNode->link)
      printf(" -> ");
    tempNode = tempNode->link;
  }
  printf("\n");
}

void reverse()
{
  struct node *prev = NULL;
  struct node *curr = start;
  struct node *next = NULL;
  while (curr)
  {
    next = curr->link;
    curr->link = prev;
    prev = curr;
    curr = next;
  }

  curr->link = prev;
  start = curr;
}

void main()
{
  int num, el, i;
  printf("\n\t\tLinked list Reversal\n");
  printf("How many elements do you want to enter? ");
  scanf("%d", &num);

  for (i = 0; i < num; i++)
  {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &el);
    insert(el);
  }

  printf("\nThe entered linked list is:\n");
  display();
  reverse();
  printf("\nAfter reversing:\n");
  display();
}
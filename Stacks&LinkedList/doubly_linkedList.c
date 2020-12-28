// write a menu driven program to implement a doubly linked list and to perform the following:

// insert a node at the beginning of the list
// insert a node after a particular node in the list
// insert a node at the end of the list
// delete a node containing a particular item

#include <stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

struct node *start = NULL;

int isEmpty()
{
  return start == NULL;
}

void insertAtBeginning(int num)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = start;
  newNode->prev = NULL;
  start = newNode;
}

void insertAtEnd(int num)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = NULL;

  if (!start)
  {
    start = newNode;
    newNode->prev = NULL;
    return;
  }

  struct node *temp = start;
  while (temp->next)
    temp = temp->next;

  temp->next = newNode;
  newNode->prev = temp;
}

int insertAtPosition(int num, int el)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = NULL;

  struct node *temp = start;
  while (temp)
  {
    if (temp->data == el)
    {
      newNode->next = temp->next;
      temp->next = newNode;
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

int deleteParticularElement(int el)
{

  if (start->data == el)
  { // if the element to be deleted is the first element
    start = (start->next) ? start->next : NULL;
    start->next->prev = NULL;
    return 1;
  }

  struct node *temp = start;

  while (temp)
  {
    if (temp->next->data == el)
    {
      temp->next = temp->next->next;
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

void display()
{
  struct node *temp = start;
  while (temp)
  {
    printf("%d ", temp->data);
    if (temp->next)
      printf("-> ");
    temp = temp->next;
  }
}

void main()
{
  int item, res, ch, el;

  while (1)
  {
    printf("\n\nDoubly nexted List Operations:\n");
    printf("1.Insert node at the beginning\n2.Insert node after a particular node\n3.Insert node at the end\n4.Delete node containing a particular element\n5.Display\n6.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("Enter item: ");
      scanf("%d", &item);
      insertAtBeginning(item);
      printf("%d inserted at the beginning of the list\n", item);
      display();
      break;

    case 2:
      if (isEmpty())
      {
        printf("List empty. Aborting..");
        break;
      }
      printf("Enter item to be inserted: ");
      scanf("%d", &item);
      printf("Enter element after which item is to be inserted");
      scanf("%d", &el);
      res = insertAtPosition(item, el);
      if (!res)
      {
        printf("No such emlement exists");
        break;
      }
      printf("%d inserted\n", item);
      display();
      break;

    case 3:
      printf("Enter item: ");
      scanf("%d", &item);
      insertAtEnd(item);
      printf("%d Inserted at the end of the list\n", item);
      display();

      break;
    case 4:
      if (isEmpty())
      {
        printf("List empty. Aborting..");
        break;
      }
      printf("Enter element to be deleted: ");
      scanf("%d", &el);
      res = deleteParticularElement(el);
      if (!res)
      {
        printf("%d is not found in the list. Aborting", el);
        break;
      }
      printf("%d deleted from list\n", el);
      display();
      break;

    case 5:
      if (isEmpty())
      {
        printf("List Empty. Aborting");
        break;
      }
      display();
      break;
    case 6:
      goto exit_loop;
    default:
      printf("Invalid entry.\n");
      break;
    }
  }

exit_loop:
  printf("Exitting..");
}
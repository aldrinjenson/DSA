// write a menu driven program to implement a single linked list and to perform the following:

// insert a node at the beginning of the list
// insert a node after a particular node in the list
// insert a node at the end of the list
// delete a node containing a particular item

#include <stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  struct node *link;
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
  newNode->link = start;
  start = newNode;
}

void insertAtEnd(int num)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = num;
  newNode->link = NULL;

  if (!start)
  {
    start = newNode;
    return;
  }

  struct node *temp = start;
  while (temp->link)
    temp = temp->link;
  temp->link = newNode;
  newNode->link = start;
}

int insertAfterElement(int num, int el)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = num;
  newNode->link = NULL;

  struct node *temp = start;
  while (temp)
  {
    if (temp->data == el)
    {
      newNode->link = temp->link;
      temp->link = newNode;
      return 1;
    }
    temp = temp->link;
  }
  return 0;
}

int deleteAtPosition(int pos)
{
  if (start == NULL)
    return 0;

  // if (start->data == el)
  // { // if the element to be deleted is the first element
  //   start = (start->link) ? start->link : NULL;
  //   return 1;
  // }

  int count = 0;

  struct node *temp = start;
  for (int i = 1; i <= pos; i++)
  {
  }

  while (temp)
  {
    if (temp->link->data == el)
    {
      temp->link = temp->link->link;
      return 1;
    }
    temp = temp->link;
  }
  return 0;
}

void display()
{
  struct node *temp = start;

  if (!temp->link)
  {
    printf("%d", start->data);
    return;
  }

  while (temp->link != start)
  {
    printf("%d ", temp->data);
    printf("-> ");
    temp = temp->link;
  }
  printf("%d ---> %d", temp->data, start->data);
}

void main()
{
  int item, res, ch, el;

  while (1)
  {
    printf("\n\nLinked List Operations:\n");
    printf("1.Insert node at the beginning\n2.Insert node at the end\n3.Insert node after a particular element\n4.Delete node containing at a particular position\n5.Display\n6.Exit\n");
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
      printf("Enter item: ");
      scanf("%d", &item);
      insertAtEnd(item);
      printf("%d Inserted at the end of the list\n", item);
      display();

      break;

    case 3:
      if (isEmpty())
      {
        printf("List empty. Aborting..");
        break;
      }
      printf("Enter item to be inserted: ");
      scanf("%d", &item);
      printf("Enter element after which item is to be inserted: ");
      scanf("%d", &el);
      res = insertAfterElement(item, el);
      if (!res)
      {
        printf("%d is not found in the list. Aborting", el);
        break;
      }
      printf("%d inserted after %d\n", item, el);
      display();
      break;
    case 4:
      if (isEmpty())
      {
        printf("List empty. Aborting..");
        break;
      }
      int pos;
      printf("Enter position of the element to be deleted: ");
      scanf("%d", &pos);
      res = deleteAtPosition(pos);
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
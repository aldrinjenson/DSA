// Program to Implement circular Queue using arrays
#include <stdio.h>
#define MAXLENGTH 5

int Queue[MAXLENGTH];
int front = -1;
int rear = -1;

int insert(int num)
{
  if (rear == front - 1 || (front == 0 && rear == MAXLENGTH - 1))
    return 0;
  if (rear == -1)
  {
    front = 0;
    rear = 0;
  }
  else if (rear == MAXLENGTH - 1)
  {
    rear = 0;
  }
  else
    rear++;
  Queue[rear] = num;
  return 1;
}

int isEmpty()
{
  return front == -1;
}

int delete ()
{
  if (front == -1)
    return 0;

  int deletedeElem = Queue[front];

  if (front == rear)
  {
    front = 0;
    rear = 0;
  }
  front = (front + 1) % MAXLENGTH;
  // or
  // else if (front == MAXLENGTH - 1)
  //   front = 0;
  // else
  //   front++;
  return deletedeElem;
}

int showFrontElement()
{
  if (front == -1)
    return 0;
  return Queue[front];
}

void display()
{
  int i;
  if (rear < front)
  {
    for (i = front; i < MAXLENGTH; i++)
      printf("%d ", Queue[i]);
    for (i = 0; i <= rear; i++)
      printf("%d ", Queue[i]);
  }
  else
  {
    for (i = front; i <= rear; i++)
      printf("%d ", Queue[i]);
  }
}

void main()
{
  int item, res, ch;

  while (1)
  {
    printf("\n\nQueue operations:\n");
    printf("1.Insert\n2.Delete\n3.Show Front Element\n4.Display\n5.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("Enter item: ");
      scanf("%d", &item);
      res = insert(item);
      if (!res)
      {
        printf("Queue full. Aborting");
        break;
      }
      printf("Item Inserted");
      break;

    case 2:
      res = delete ();
      if (!res)
      {
        printf("Queue Empty. Aborting");
        break;
      }
      printf("Item deleted = %d", res);
      break;

    case 3:
      res = showFrontElement(item);
      if (!res)
      {
        printf("Stack Empty. Aborting");
        break;
      }
      printf("Item = %d", res);
      break;

    case 4:
      if (isEmpty())
      {
        printf("Queue Empty. Aborting");
        break;
      }
      display();
      break;
    case 5:
      goto exit_loop;
    default:
      printf("Invalid entry.\n");
      break;
    }
  }

exit_loop:
  printf("Exitting..");
}
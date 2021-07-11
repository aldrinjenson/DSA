// Program to Implement Queue using arrays
#include <stdio.h>
#define MAXLENGTH 30

int Queue[MAXLENGTH];
int front = -1;
int rear = -1;

int isEmpty()
{
  return (front == -1);
}

int insert(int n)
{
  if (rear == MAXLENGTH - 1)
  {
    return -1;
  }
  else if (rear == -1)
  {
    front = rear = 0;
  }
  else
  {
    rear++;
  }
  Queue[rear] = n;
}
int delete ()
{
  if (isEmpty())
  {
    return -1;
  }
  int item = Queue[front--];
  return item;
}
int showFrontElement()
{
  if (isEmpty())
  {
    return -1;
  }
  return Queue[front];
}
int display()
{
  for (int i = front; i <= rear; i++)
  {
    printf("%d, ", Queue[i]);
  }
}

// int insert(int n)
// {
//   if (rear == MAXLENGTH - 1)
//     return 0;
//   if (rear == -1)
//     front = rear = 0;
//   else
//     rear += 1;
//   Queue[rear] = n;
// }

// int delete ()
// {
//   if (front == -1)
//     return 0;
//   int item = Queue[front];
//   if (rear == front) // if only one item in queue
//   {
//     rear = -1;
//     front = -1;
//   }
//   else
//     front++;
//   return item;
// }

// int showFrontElement()
// {
//   if (front == -1)
//     return 0;
//   return Queue[front];
// }

// int isEmpty()
// {
//   return front == -1;
// }

// void display()
// {
//   if (front == -1)
//     return;
//   for (int i = front; i <= rear; i++)
//     printf("%d\n", Queue[i]);
// }

void main()
{
  int item, res, ch;
  char option = 1;

  do
  {
    printf("\nQueue operations:\n");
    printf("1.Insert\n2.Delete\n3.Show Front Element\n4.Display\n");
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
      res = showFrontElement();
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
    default:
      printf("Invalid entry.\n");
      break;
    }
    printf("\nDo you want to try again?(y/n): ");
    scanf(" %c", &option);
  } while (option == 'y');
}
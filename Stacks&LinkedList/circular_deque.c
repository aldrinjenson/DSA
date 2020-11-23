// Program to Implement deQueue using arrays
//  done and completed
#include <stdio.h>
#define MAXLENGTH 4

int Queue[MAXLENGTH];
int left = -1;
int right = -1;

int isFull()
{
  return (right == left - 1);
}

int insertLeft(int num)
{
  if (isFull())
    return 0;
  if (left == -1)
  {
    left = 0;
    right = 0;
  }
  else if (left == 0)
    left = MAXLENGTH - 1;
  else
    left--;
  Queue[left] = num;
}

int insertRight(int num)
{
  if (isFull())
    return 0;
  if (right == -1)
  {
    right = 0;
    left = 0;
  }
  else if (right == MAXLENGTH - 1)
    right = 0;
  else
    right++;
  Queue[right] = num;
}

int isEmpty()
{
  return left == -1 && right == -1;
}

int deleteLeft()
{
  if (isEmpty())
    return 0;
  int deletedElem = Queue[left];
  if (left == right)
  {
    left = -1;
    right = -1;
  }
  else if (left == MAXLENGTH - 1)
    left = 0;
  else
    left++;
  return deletedElem;
}

int deleteRight()
{
  if (isEmpty())
    return 0;
  int deletedElem = Queue[right];
  if (right == left)
  {
    right = -1;
    left = -1;
  }
  else if (right == 0)
    right = MAXLENGTH - 1;
  else
    right--;
  return deletedElem;
}

void display()
{
  int i;
  if (right < left)
  {
    for (i = left; i <= MAXLENGTH - 1; i++)
      printf("%d ", Queue[i]);
    for (i = 0; i <= right; i++)
      printf("%d ", Queue[i]);
  }
  else
  {
    for (i = left; i <= right; i++)
      printf("%d ", Queue[i]);
  }
}

void main()
{
  int item, res, ch;

  while (1)
  {
    printf("\n\nQueue operations:\n");
    printf("1.Insert from left\n2.Insert from right\n3.Delete from left\n4.Delete from right\n5.Display\n6.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("Enter item: ");
      scanf("%d", &item);
      res = insertLeft(item);
      if (!res)
      {
        printf("Queue full. Aborting");
        break;
      }
      printf("Item Inserted at left");
      break;

    case 2:
      printf("Enter item: ");
      scanf("%d", &item);
      res = insertRight(item);
      if (!res)
      {
        printf("Queue full. Aborting");
        break;
      }
      printf("Item Inserted at right");
      break;

    case 3:
      res = deleteLeft();
      if (!res)
      {
        printf("Queue Empty. Aborting");
        break;
      }
      printf("Item deleted from left = %d", res);
      break;
    case 4:
      res = deleteRight();
      if (!res)
      {
        printf("Queue Empty. Aborting");
        break;
      }
      printf("Item deleted from right = %d", res);
      break;

    case 5:
      if (isEmpty())
      {
        printf("Queue Empty. Aborting");
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
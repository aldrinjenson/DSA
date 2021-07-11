// Program to Implement deQueue using arrays
#include <stdio.h>
#define MAXLENGTH 6

int Queue[MAXLENGTH];
int left = -1;
int right = -1;

int leftStart = (MAXLENGTH / 2) - 1;
int rightStart = (MAXLENGTH / 2);

int insertLeft(int num)
{
  if (left == 0)
    return 0;
  if (left == -1)
    left = leftStart;
  else
    left--;
  Queue[left] = num;
  return 1;
}

int insertRight(int num)
{
  if (right == MAXLENGTH - 1)
    return 0;
  if (right == -1)
    right = rightStart;
  else
    right++;
  Queue[right] = num;
  return 1;
}

int isEmpty()
{
  return (left == -1 && right == -1);
}

int deleteLeft()
{
  if (left == -1)
    return 0;
  int deletedeElem = Queue[left];
  if (left == leftStart)
    left = -1;
  else
    left++;
  return deletedeElem;
}

int deleteRight()
{
  if (right == -1)
    return 0;
  int deletedeElem = Queue[right];
  if (right == rightStart)
    right = -1;
  else
    right--;
  return deletedeElem;
}

void display()
{
  int i;
  for (i = left; i <= leftStart; i++)
    printf("%d ", Queue[i]);
  for (i = rightStart; i <= right; i++)
    printf("%d ", Queue[i]);
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
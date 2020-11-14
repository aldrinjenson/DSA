// Program to Implement Stack using array

#include <stdio.h>
#define MAXLENGTH 30

int Stack[MAXLENGTH];
int top = -1;

int push(int n)
{
  if (top == MAXLENGTH - 1)
    return 0;
  top++;
  Stack[top] = n;
  return 1;
}

int pop()
{
  if (top == -1)
    return 0;
  int lastElem = Stack[top];
  top--;
  return lastElem;
}

int peek()
{
  if (top == -1)
    return 0;
  return Stack[top];
}

int isEmpty()
{
  return top == -1;
}

int display()
{
  if (top == -1)
    return 0;
  for (int i = top; i >= 0; i--)
    printf("%d\n", Stack[i]);
  return 1;
}

void main()
{
  int item, res, ch;
  char option;

  do
  {
    printf("\nStack operations:\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("Enter item: ");
      scanf("%d", &item);
      res = push(item);
      if (!res)
      {
        printf("Stack full. Aborting");
        break;
      }
      printf("Item pushed");
      break;

    case 2:
      res = pop();
      if (!res)
      {
        printf("Stack Empty. Aborting");
        break;
      }
      printf("Item popped = %d", res);
      break;

    case 3:
      res = peek();
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
        printf("Stack Empty. Aborting");
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
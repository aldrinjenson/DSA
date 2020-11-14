#include <stdio.h>
#define MAX_LENGTH 10

int arr[MAX_LENGTH];

char *Stack1 = "Stack1";
char *Stack2 = "Stack2";

int top1 = -1;
int top2 = MAX_LENGTH;

int push(char *Stack, int num)
{
  if (top1 + 1 == top2)
    return 0;
  if (Stack == Stack1)
  {
    top1++;
    arr[top1] = num;
  }
  else
  {
    top2--;
    arr[top2] = num;
  }
}

int isEmpty(char *Stack)
{
  return (Stack == Stack1) ? top1 == -1 : top2 == MAX_LENGTH;
}

int peek(char *Stack)
{
  if (isEmpty(Stack))
    return 0;
  return (Stack == Stack1) ? arr[top1] : arr[top2];
}

int pop(char *Stack)
{
  if (isEmpty(Stack))
    return 0;

  int res;

  if (Stack == Stack1)
  {
    res = arr[top1];
    top1--;
  }
  else
  {
    res = arr[top2];
    top2++;
  }
  return res;
}

int display(char *Stack)
{
  if (isEmpty(Stack))
    return 0;

  printf("\n%s\n", Stack);
  if (Stack == Stack1)
  {
    for (int i = top1; i >= 0; i--)
      printf("%d\n", arr[i]);
  }
  else
  {
    for (int i = top2; i <= MAX_LENGTH - 1; i++)
      printf("%d\n", arr[i]);
  }
  return 1;
}

void main()
{
  int item, res, ch, stackNum;
  do
  {
    printf("\n\nStack operations:\n");
    printf("Enter StackNumber to perform operation\n(1.Stack1 or 2.Stack2): ");
    scanf("%d", &stackNum);
    if (stackNum != 1 && stackNum != 2)
    {
      printf("Invalid entry\nTry Again\n");
      continue;
    }
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Quit\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    char *stk = (stackNum == 1) ? Stack1 : Stack2;

    switch (ch)
    {
    case 1:
      printf("Enter item: ");
      scanf("%d", &item);
      res = push(stk, item);
      if (!res)
      {
        printf("Stack full!! Aborting..");
        break;
      }
      printf("Item pushed");
      break;

    case 2:
      res = pop(stk);
      if (!res)
      {
        printf("Stack Empty!! Aborting..");
        break;
      }
      printf("Item popped = %d", res);
      break;

    case 3:
      res = peek(stk);
      if (!res)
      {
        printf("Stack Empty!! Aborting..");
        break;
      }
      printf("Item = %d", res);
      break;

    case 4:
      res = display(stk);
      if (!res)
        printf("Stack Empty!! Aborting..");
      break;
    case 5:
      printf("Quitting..\n");
      break;

    default:
      printf("Invalid entry.\n");
      break;
    }
  } while (ch != 5);
}
#include <stdio.h>
#include <ctype.h>
#define MAX_STACK_LENGTH 30
#define MAX_EXPRESSION_LENGTH 30

int Stack[MAX_STACK_LENGTH];
int top = -1;

void push(char ch)
{
  if (top != MAX_STACK_LENGTH - 1)
    Stack[++top] = ch;
}

char pop()
{
  if (top != -1)
    return Stack[top--];
}

char peek()
{
  return (top == -1) ? 0 : Stack[top];
}

void main()
{
  char postfix[MAX_EXPRESSION_LENGTH];
  char *ptr;
  printf("Enter the postfix expression: ");
  scanf(" %s", postfix);
  ptr = postfix;
  int n1, n2, n3, temp;

  while (*ptr != '\0')
  {
    if (isalnum(*ptr))
    {
      printf("Enter the value for %c: ", *ptr);
      scanf("%d", &temp);
      push(temp);
    }
    else
    {
      n1 = pop();
      n2 = pop();
      switch (*ptr)
      {
      case '+':
        n3 = n1 + n2;
        break;
      case '-':
        n3 = n2 - n1;
        break;
      case '*':
        n3 = n2 * n1;
        break;
      case '/':
        n3 = n2 / n1;
        break;
      }
      push(n3);
    }
    ptr++;
  }
  printf("Final answer after evaluation = %d\n", pop());
}

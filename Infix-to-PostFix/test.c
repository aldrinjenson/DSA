#include <stdio.h>
#include <ctype.h>
#include <string.h>
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

void display()
{
  if (top != -1)
  {
    for (int i = top; i >= 0; i--)
      printf("%d\n", Stack[i]);
  }
}

void main()
{
  // char infix[MAX_EXPRESSION_LENGTH] = "-+A*BC+DE";
  printf("Enter the infix expression: ");
  // scanf(" %s", infix);
  char infix[MAX_EXPRESSION_LENGTH] = "-+A/BCD";
  int n1, n2, n3, temp, i;

  for (i = 0; infix[i] != '\0'; i++)
    if (isalnum(infix[i]))
    {
      printf("Enter the value for %c: ", infix[i]);
      scanf("%d", &temp);
      push(temp);
    }

  // display();

  for (i = strlen(infix) - 1; i >= 0; i--)
  {
    if (!isalnum(infix[i]))
    {
      n1 = pop();
      n2 = pop();
      switch (infix[i])
      {
      case '+':
        n3 = n2 + n1;
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
      printf("%d", peek());
    }
  }
  printf("Final answer after evaluation = %d\n", pop());
  display();
}
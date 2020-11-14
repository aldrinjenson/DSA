#include <stdio.h>
#include <ctype.h>
#define MAXLENGTH 30

int Stack[MAXLENGTH];
int top = -1;

void push(char ch)
{
  if (top != MAXLENGTH - 1)
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

int priority(char x)
{
  switch (x)
  {
  case '(':
    return 0;
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  case '$':
    return 4;
  default:
    break;
  }
}

void main()
{
  char infix[20];
  printf("Enter infix expression: ");
  scanf(" %s", infix);
  // char *infix = "A+$B*C-D+E/F/(G+H)";
  char *iptr = infix;

  while (*iptr != '\0')
  {
    if (isalnum(*iptr))
      printf("%c", *iptr);
    else
    {
      if (*iptr == '(')
        push(*iptr);
      else if (*iptr == ')')
      {
        while (peek() != '(')
          printf("%c", pop());
        pop();
      }
      else
      {
        while (priority(*iptr) <= priority(peek()))
          printf("%c", pop());
        push(*iptr);
      }
    }
    iptr++;
  }
  while (top != -1)
    printf("%c", pop());
}
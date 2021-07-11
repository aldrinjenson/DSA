// write a program + algorithm to implement a priority queue using linked list. Assume square roots as thr priority. Add features to insert and delete nodes

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct node
{
  int data;
  float priority;
  struct node *next;
} Node;

Node *front = NULL;

void insert(int n)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->data = n;
  newNode->priority = sqrt(n);

  if (front == NULL || front->priority < newNode->priority)
  // if the newNode is of greater priority than the second node
  {
    newNode->next = front;
    front = newNode;
  }
  else
  {
    Node *temp = front;
    while (temp->next != NULL && temp->next->priority > newNode->priority)
    {
      // traverse till we find the correct spot based on the priority of the node after current
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void delete ()
{
  // since it is a priority queue, we delete from the front itself and not from the rear like other queues
  Node *temp = front;
  front = front->next;
  free(temp);
}

int peek()
{
  // for getting the front data
  return front->data;
}

void main()
{
  int count, temp;
  printf("How many numbers do you want to add to the queue?: ");
  scanf("%d", &count);
  printf("Enter %d numbers:\n", count);
  for (int i = 0; i < count; i++)
  {
    scanf("%d", &temp);
    if (temp < 0)
    {
      printf("It is not possible to calculate square root of negative number!");
      break;
    }
    insert(temp);
  }

  if (front == NULL)
  {
    printf("Queue empty");
  }
  else
  {
    printf("The priority queue is:\n");
    while (front != NULL)
    {
      printf("%d,", peek());
      delete ();
    }
  }
}
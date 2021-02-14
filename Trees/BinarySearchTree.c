// Write a C program to create a binary search tree and do the three different tree traversal methods

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} Node;

void addRecursively(Node **parent, Node *newNode)
{
  if (newNode->value < (*parent)->value)
  {
    if (!(*parent)->left)
      (*parent)->left = newNode;
    else
      addRecursively(&(*parent)->left, newNode);
  }
  else
  {
    if (!(*parent)->right)
      (*parent)->right = newNode;
    else
      addRecursively(&(*parent)->right, newNode);
  }
}

void traverseInOrder(Node *nd)
{
  if (nd == NULL)
    return;
  traverseInOrder(nd->left);
  printf("%d ", nd->value);
  traverseInOrder(nd->right);
}

void traversePreOrder(Node *nd)
{
  if (nd == NULL)
    return;
  printf("%d ", nd->value);
  traversePreOrder(nd->left);
  traversePreOrder(nd->right);
}

void traversePostOrder(Node *nd)
{
  if (nd == NULL)
    return;
  traversePostOrder(nd->left);
  traversePostOrder(nd->right);
  printf("%d ", nd->value);
}

void main()
{
  int n, temp;
  printf("How many numbers do you want to enter?: ");
  scanf("%d", &n);
  printf("Please enter %d numbers:\n", n);
  scanf("%d", &temp);
  Node *root = malloc(sizeof(struct node));
  root->left = NULL;
  root->right = NULL;
  root->value = temp;

  for (int i = 1; i < n; i++)
  {
    scanf("%d", &temp);
    Node *newNode = malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = temp;
    addRecursively(&root, newNode);
  }

  printf("\nTraversing in order: ");
  traverseInOrder(root);
  printf("\nTraversing in pre-order: ");
  traversePreOrder(root);
  printf("\nTraversing in post-order: ");
  traversePostOrder(root);
}
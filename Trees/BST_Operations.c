#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *root = NULL;

Node *createNode(int data)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *addNode(Node *node, int newData)
{
  if (!node)
    return createNode(newData);

  if (newData < node->data)
    node->left = addNode(node->left, newData);
  else if (newData > node->data)
    node->right = addNode(node->right, newData);

  return node;
}

void inorder(Node *node)
{
  if (!node)
    return;
  inorder(node->left);
  printf("%d ", node->data);
  inorder(node->right);
}

Node *getInorderSuccessor(Node *node)
{
  if (!(node->left))
    return node;
  else
    return getInorderSuccessor(node->left);
}

Node *deleteNode(Node *node, int data)
{
  if (!node)
    return NULL;

  if (data < node->data)
    node->left = deleteNode(node->left, data);
  else if (data > node->data)
    node->right = deleteNode(node->right, data);
  else
  {
    if (!node->left && !node->right)
    {
      node = NULL;
      printf("Leaf node");
    }
    else if (!node->right)
    {
      Node *temp = node;
      node = node->left;
      free(temp);
    }
    else if (!node->left)
    {
      Node *temp = node;
      node = node->right;
      free(temp);
    }
    else
    {
      Node *successor = getInorderSuccessor(node->right);
      node->data = successor->data;
      node->right = deleteNode(node->right, successor->data);
    }
  }
  return node;
}

void main()
{
  // int count, temp;
  printf("How many numbers do you want to enter?");
  // scanf("%d", &count);
  // printf("Enter %d numbers: ", count);
  // scanf("%d", &temp);

  // root = createNode(temp);

  // for (int i = 1; i < count; i++)
  // {
  //   scanf("%d", &temp);
  //   addNode(root, temp);
  // }
  root = createNode(11);
  addNode(root, 5);
  addNode(root, 32);
  addNode(root, 3);
  addNode(root, 34);
  addNode(root, 7);
  addNode(root, 6);
  addNode(root, 8);
  printf("\nThe inorder transversal is:\n");
  inorder(root);
  root = deleteNode(root, 11);
  printf("\nThe inorder transversal after deleting is:\n");
  inorder(root);
}
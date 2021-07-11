// Write a menu driven program in C to implement a binary search tree and to perform the following operations
// i) Insertion
// ii) Deletion
// iii) Searching

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

int search(Node *nd, int term)
{
  if (nd == NULL)
    return -1;

  if (term == nd->value)
    return nd->value;

  if (term < nd->value)
    search(nd->left, term);
  else
    search(nd->right, term);
}

Node *minValueNode(Node *current)
{
  while (current->left != NULL)
    current = current->left;
  return current;
}

Node *delete (Node *root, int val)
{
  if (root == NULL)
    return root;
  if (val < root->value)
    root->left = delete (root->left, val);
  else if (val > root->value)
    root->right = delete (root->right, val);
  else
  {
    if (root->left == NULL)
    {
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      free(root);
      return temp;
    }
    Node *temp = minValueNode(root->right);
    root->value = temp->value;
    root->right = delete (root->right, temp->value);
  }
  return root;
}

void main()
{
  int n, temp, term;
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

  while (1)
  {
    printf("\nEnter search term: ");
    scanf("%d", &term);
    int result = search(root, term);
    result != -1 ? printf("Found %d\n", result) : printf("Not Found in the tree\n");

    printf("\nEnter term to delete: ");
    scanf("%d", &term);
    Node *removedNode = delete (root, term);
    if (removedNode == NULL)
      printf("Element does not exist in the tree");
    else
      printf("%d deleted", term);

    printf("\nAfter deleting: ");
    traverseInOrder(root);
  }
}
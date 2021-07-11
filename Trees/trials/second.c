// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data)
{
  struct node *node = (struct node *)
      malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

void printPostorder(struct node *node)
{
  if (node == NULL)
    return;
  printPostorder(node->left);
  printPostorder(node->right);
  printf("%d ", node->data);
}

void printInorder(struct node *node)
{
  if (node == NULL)
    return;
  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}

void printPreorder(struct node *node)
{
  if (node == NULL)
    return;

  printf("%d ", node->data);
  printPreorder(node->left);
  printPreorder(node->right);
}

void addNode(struct node **loc, struct node *newnode)
{
  int data = newnode->data;
  if ((*loc)->data > data && (*loc)->left == NULL)
  {
    (*loc)->left = newnode;
    return;
  }
  else if ((*loc)->data < data && (*loc)->right == NULL)
  {
    (*loc)->right = newnode;
    return;
  }

  if ((*loc)->data > data)
    addNode(&((*loc)->left), newnode);
  else
    addNode(&((*loc)->right), newnode);
}

int main()
{
  int rootnode, n1, i, num;
  printf("Enter root node\n");
  scanf("%d", &rootnode);
  struct node *root = malloc(sizeof(struct node));

  root->data = rootnode;
  root->left = NULL;
  root->right = NULL;
  printf("Enter the number of  nodes to be added\n");
  scanf("%d", &n1);
  printf("Enter the nodes\n");
  for (i = 0; i < n1; i++)
  {
    scanf("%d", &num);
    struct node *newnode = newNode(num);
    addNode(&root, newnode);
  }

  printf("\nPreorder traversal of binary tree is \n");
  printPreorder(root);

  printf("\nInorder traversal of binary tree is \n");
  printInorder(root);

  printf("\nPostorder traversal of binary tree is \n");
  printPostorder(root);
  printf("\n");
}
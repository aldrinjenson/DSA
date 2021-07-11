#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

void insert(struct node **root, int newdata)
{

  struct node *current;
  struct node *parent;

  struct node *tempNode = (struct node *)malloc(sizeof(struct node));
  tempNode->data = newdata;
  tempNode->left = NULL;
  tempNode->right = NULL;

  if (*root == NULL)
  {
    *root = tempNode;
    return;
  }
  else
  {
    current = *root;
    parent = NULL;
    while (1)
    {
      parent = current;
      if (newdata < parent->data)
      {
        current = current->left;
        if (current == NULL)
        {
          parent->left = tempNode;
          return;
        }
      }
      else
      {
        current = current->right;
        if (current == NULL)
        {
          parent->right = tempNode;
          return;
        }
      }
    }
  }
}

void search(struct node *root, int num)
{
  if (root->data == num)
  {
    printf("Element found!\n");
    return;
  }
  if (num > root->data && root->right == NULL)
  {
    printf("Element not found\n");
    return;
  }
  if (num < root->data && root->left == NULL)
  {
    printf("Element not found\n");
    return;
  }
  if (num > root->data)
  {
    search(root->right, num);
  }
  else
  {
    search(root->left, num);
  }
}
struct node *FindMin(struct node *root)
{

  struct node *loc = root;
  while (loc->left != NULL)
  {
    loc->left;
  }
  return loc;
}
struct node *delete (struct node *root, int data)
{
  if (root == NULL)
    return root;
  else if (data < root->data)
    root->left = delete (root->left, data);
  else if (data > root->data)
    root->right = delete (root->right, data);
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
      root = NULL;
    }
    else if (root->left == NULL)
    {
      struct node *temp = root;
      root = root->right;
      free(temp);
    }
    else if (root->right == NULL)
    {
      struct node *temp = root;
      root = root->left;
      free(temp);
    }
    else
    {
      struct node *temp = FindMin(root->right);
      root->data = temp->data;
      root->right = delete (root->right, temp->data);
    }
  }
  return root;
}
void printPostorder(struct node *node)
{
  if (node == NULL)
    return;
  printPostorder(node->left);
  printPostorder(node->right);
  printf("%d ", node->data);
}

int main()
{
  struct node *root = NULL;

  int ch, num, n;
  while (ch != 4)
  {
    printf("1-insert 2-delete 3-display 4-exit\n");
    scanf("%d", &ch);
    if (ch == 1)
    {
      printf("Enter number of elements to be added: ");
      scanf("%d", &n);

      printf("Enter numbers to be inserted:\n");
      while (n > 0)
      {
        scanf("%d", &num);
        insert(&root, num);
        n--;
      }
    }

    else if (ch == 2)
    {
      printf("Enter number to be deleted: ");
      scanf("%d", &num);
      root = delete (root, num);
    }
    else if (ch == 3)
    {
      printf("PostOrderTraversal\n");
      printPostorder(root);
      printf("\n");
    }
    else if (ch == 4)
      continue;
    else
      printf("invalid choice\n");
  }

  return 0;
}
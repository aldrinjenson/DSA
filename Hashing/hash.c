#include <stdlib.h>
#include <stdio.h>
#define size 13

typedef struct
{
  int key;
  int isFilled;
} item;

item hashtable[size];

int hash(int n)
{
  return n % size;
}

void storeItem(int n)
{
  item *newItem = malloc(sizeof(item));
  newItem->key = n;

  int pos = hash(n);
  for (int i = pos; i < size; i++)
  {
    if (!hashtable[i].isFilled)
    {
      newItem->isFilled = 1;
      hashtable[i] = *newItem;
      return;
    }
  }
  for (int i = 0; i < pos; i++)
  {
    if (!hashtable[i].isFilled)
    {
      newItem->isFilled = 1;
      hashtable[i] = *newItem;
      return;
    }
  }
  printf("Hashtable full");
  return;
}

void display()
{
  printf("Index | Key\n");
  for (int i = 0; i < size; i++)
  {
    if (hashtable[i].isFilled)
      printf("  %d      %d\n", i, hashtable[i].key);
    else
      printf("  %d      NULL\n", i);
  }
}

void search()
{
  int n;
  printf("\nEnter search key");
  scanf("%d", &n);
  int p = hash(n);
  for (int i = p; i < size; i++)
  {
    if (hashtable[i].isFilled && hashtable[i].key == n)
    {
      printf("Index = %d", i);
      return;
    }
  }
  for (int i = 0; i < p; i++)
  {
    if (hashtable[i].isFilled && hashtable[i].key == n)
    {
      printf("Index = %d", i);
      return;
    }
  }
  printf("%d does not exist in the hashtable", n);
}

void main()
{
  int count, num;
  printf("Enter the number of keys to enter");
  scanf("%d", &count);
  for (int i = 0; i < count; i++)
  {
    scanf("%d", &num);
    storeItem(num);
  }

  display();
  while (2)
  {
    search();
  }
}
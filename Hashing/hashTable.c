// write a c program to insert a set of keys into a hash table of size m = 13 using the division method and the collision resolution technique as linear probing

// Implementing a hashmap in C!!
#include <stdlib.h>
#include <stdio.h>
#define size 13

typedef struct
{
  int key;
  int value;
  int isFilled;
} item;

item hashTable[size];

int hash(int n)
{
  return n % size;
}

void addItem(int key, int value)
{
  int i;
  item *newItem = malloc(sizeof(item));
  newItem->key = key;
  newItem->value = value;

  int pos = hash(key);
  for (i = pos; i < size; i++)
  {
    if (!hashTable[i].isFilled || hashTable[i].key == key)
    {
      newItem->isFilled = 1;
      hashTable[i] = *newItem;
      return;
    }
  }
  for (i = 0; i < pos; i++)
  {
    if (!hashTable[i].isFilled || hashTable[i].key == key)
    {
      newItem->isFilled = 1;
      hashTable[i] = *newItem;
      return;
    }
  }
  printf("Hash Table full");
  return;
}

int getItem(int key)
{
  int hCode = hash(key);
  return (hashTable[hCode].value);
}

void display()
{
  printf("Hash table:\n");
  printf("Index| Key | Value:\n");
  for (int i = 0; i < size; i++)
    printf("%d,     %d,     %d\n", i, hashTable[i].key, hashTable[i].value);
}

void search()
{
  int k;
  printf("Enter key to search: ");
  scanf("%d", &k);
  int val = getItem(k);
  printf("Corresponding value stored with %d is %d\n", k, val);
}

void main()
{
  int i;
  int count, key, value;

  printf("Enter number of key-value pairs to be saved: ");
  scanf("%d", &count);
  for (i = 0; i < count; i++)
  {
    printf("Item %d - ", i + 1);
    printf("Enter key: ");
    scanf("%d", &key);
    printf("Enter value: ");
    scanf("%d", &value);
    addItem(key, value);
  }
  display();
  printf("\n");
  while (1)
  {
    search();
  }
}
// Given a natural language text, store each words in a hash table of size m=26 using the mod function. Find the number of key comparisons for a successful search, if the collision resolution technique used is 1) linear probing 2) Quadratic probing

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define size 26

typedef struct
{
  int key;
  char *word;
  int isFilled;
} item;

item hashtable[size];

int getAscii(char *word)
{
  int sum = 0;
  for (int i = 0; i < strlen(word); i++)
    sum += word[i] - '0';
  return sum;
}

int linearProbe(int p, char *word)
{
  int i;
  for (i = p; i < size; i = (i + 1) % size)
  {
    if (!hashtable[i].isFilled)
      return i;
  }
  return -1;
}

int quadraticProbe(int p, char *word)
{
  if (!hashtable[p].isFilled)
    return p;

  for (int i = 0; i < size; i = (p + (i * i)) % size)
  {
    if (!hashtable[i].isFilled)
      return i;
  }
  return -1;
}

int hash(char *word)
{
  int n = getAscii(word);
  int pos = n % size;
}

void storeItem(int index, char *word, int method)
{
  item *newItem = malloc(sizeof(item));
  newItem->word = word;
  newItem->key = index;

  int p = hash(word);
  int pos = method == 1 ? linearProbe(p, word) : quadraticProbe(p, word);

  if (pos == -1)
  {
    printf("Hash table full!");
    return;
  }

  newItem->isFilled = 1;
  hashtable[pos] = *newItem;
}

void display()
{
  for (int i = 0; i < size; i++)
    if (hashtable[i].isFilled)
      printf("%d %s\n", i, hashtable[i].word);
    else
      printf("%d NULL\n", i);
}

int search(char *query, int method)
{
  int count;
  int p = hash(query);
  if (method == 1) //search using linear-probing
  {
    for (int i = p, count = 0; count < size; i = (i + 1) % size, count++)
    {
      if (hashtable[i].isFilled && strcmp(hashtable[i].word, query) == 0)
        return i;
    }
    return -1;
  }
  else // search using quadratic-probing
  {
    for (int i = 0, count = 0; count < size; i = (p + (i * i)) % size, count++)
    {
      if (hashtable[i].isFilled && strcmp(hashtable[i].word, query) == 0)
        return i;
    }
    return -1;
  }
}

void main()
{
  char words[11][11];
  char query[10];
  int count, method, pos;

  printf("Enter number of items to be added: ");
  scanf("%d", &count);
  printf("1.Linear Probing\n2.Quadratic Probing");
  printf("\nChoose probing technique(1 or 2): ");
  scanf("%d", &method);

  if (method != 1 && method != 2)
  {
    printf("Error! Only enter values 1 or 2");
  }
  else
  {
    printf("Enter %d words\n", count);
    for (int i = 0; i < count; i++)
    {
      scanf(" %s", words[i]);
      storeItem(i, words[i], method);
    }
    display();
    while (1)
    {
      printf("\nEnter a word to search and find the index: ");
      scanf("%s", query);
      pos = search(query, method);
      if (pos == -1)
        printf("\n%s does not exist in the hashtable %d", query, pos);
      else
        printf("\n%s is found at position %d", query, pos);
    }
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>


typedef struct node
{
  string phrase;
  struct node* next;
} node;

#define LIST_SIZE = 2

bool unload(node * list);
void visualizer(node *list);

int main(void)
{
  node* list = NULL;

  for (int i = 0; i < LIST_SIZE; i++)
  {

  }
  string phrase = get_string("Enter a phrase: ");
  node *n = malloc(sizeof(node));
  if (n == NULL)
  {
    return 1;
  }

  n->phrase = phrase;
  n->next = NULL;
  n->next = list;

  visualizer(list);
  return 0;
}
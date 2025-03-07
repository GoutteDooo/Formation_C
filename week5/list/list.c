#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
  int number;
  struct node* next;
} node;

int main(void)
{
  node* list = NULL;
  int count = get_int("Number: ");
  for (int i = 0; i < count; i++)
  {
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
      return 1;
    }
    n->number = i + 1;
    n->next = list;
    
    list = n;
  }

  //Time passes
  node *ptr = list;

  while (ptr != NULL)
  {
    printf("%i\n", ptr->number);
    ptr = ptr->next;
  }

  return 0;
}
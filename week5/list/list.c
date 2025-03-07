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
    n->next = NULL;

    //if list is empty
    if (list == NULL)
    {
      list = n;
    }
    //if list has numbers already
    else
    {
      for (node* ptr = list; ptr != NULL; ptr = ptr->next)
      {
        if (ptr->next == NULL)
        {
          ptr->next = n;
          break;
        }
      }
    }
  }

  //Time passes
  for (node *ptr = list; ptr != NULL; ptr = ptr->next)
  {
    printf("%i\n", ptr->number);
  }

  return 0;
}
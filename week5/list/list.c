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
  for (int i = 0; i < 10; i++)
  {
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
      //TODO: free any memory already malloc'd
      return 1;
    }
    n->number = get_int("Number: ");
    n->next = NULL;

    //if list is empty
    if (list == NULL)
    {
      list = n;
    }
    //if list has numbers already
    else if (n->number < list->number)
    {
      n->next = list;
      list = n;
    }
    else
    {
      for (node* ptr = list; ptr != NULL; ptr = ptr->next)
      {
        if (ptr->next == NULL)
        {
          //Append node
          ptr->next = n;
          break;
        }

        //If in middle of list
        if (n->number <  ptr->next->number)
        {
          n->next = ptr->next;
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

  //Time passes

  node* ptr = list;

  while(ptr != NULL)
  {
    node* next = ptr->next;
    free(ptr);
    ptr = next;
  }

  return 0;
}
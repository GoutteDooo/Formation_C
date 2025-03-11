#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct dllnode
{
  char* phrase;
  int id;
  struct dllnode* before;
  struct dllnode* next;
} dllnode;
#define NODES_NUMBER 3

int main(void)
{
  dllnode* list = malloc(sizeof(dllnode));
  string phrase = get_string("Enter a phrase: ");
  list->phrase = phrase;
  list->id = 0;
  list->before = NULL;
  list->next = NULL;
  for (int i = 0; i < NODES_NUMBER; i++)
  {
    
    string phrase = get_string("Enter a phrase: ");

  }

  return 0;
}
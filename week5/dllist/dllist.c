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

dllnode* create_node(dllnode* list);


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
    list->next = create_node(list);
    string phrase = get_string("Enter a phrase: ");

  }

  return 0;
}

dllnode* create_node(dllnode* list)
{
  dllnode* new_node = malloc(sizeof(dllnode));
  list->next = new_node;
  string s = get_string("Enter a phrase: ");
  new_node->phrase = s;
  new_node->before = list;
  new_node->next = NULL;
  return new_node;
}
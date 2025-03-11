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
void print_list(dllnode* list);
void free_list(dllnode* list);


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
    list->next->id = i + 1;
    list = list->next;
  }
  print_list(list);
  free_list(list);
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


void print_list(dllnode* list)
{
  for(dllnode* ptr = list; ptr != NULL; ptr = ptr->before)
  {
    printf("address: %p\n",ptr);
    printf("id: %i\n",ptr->id);
    printf("phrase: %s\n",ptr->phrase);
    printf("before: %p\n",ptr->before);
    printf("next: %p\n",ptr->next);
  }
}


void free_list(dllnode* list)
{
  dllnode* ptr = list;
  int direction = 0; //direction 0 -> right, 1 -> left
  while (ptr != NULL)
  {
    if (direction == 0)
    {
      if (list == NULL) {
        direction = 1;
        continue;
      }
      ptr = list;
      list = list->next;
    }
    //if we reached the bottom right, we go left and free all memories
    if (direction == 1)
    {
      list = ptr;
      ptr = ptr->before;
      free(list);
      if (ptr == NULL)
      {
        //We freed all nodes
        break;
      }
    }
  }
}
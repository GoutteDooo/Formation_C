#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct slnode
{
  char* phrase;
  struct slnode* next;
} slnode;

slnode* create(slnode* list, char* phrase);
void print_list(slnode* list);

int main(void)
{
  slnode* list = malloc(sizeof(slnode));
  if (list == NULL) return 1;
  list->phrase = "Hello!";
  list->next = NULL;
  for (int i = 0; i < 3; i++)
  {
    string s = get_string("Enter a phrase: ");
    slnode* node = create(list, s);
    list = node;
  }
  print_list(list);

  return 0;
}

slnode* create(slnode* list, char* phrase)
{
  slnode* new_node = malloc(sizeof(slnode));
  if (new_node == NULL) return NULL;
  new_node->phrase = phrase;
  new_node->next = list;
  return new_node;
}

void print_list(slnode* list)
{
  for(slnode* ptr = list; ptr != NULL; ptr = ptr->next)
  {
    printf("address: %p\n",ptr);
    printf("phrase: %s\n",ptr->phrase);
    printf("next: %p\n",ptr->next);
  }
}
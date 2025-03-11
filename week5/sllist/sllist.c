#include <stdio.h>
#include <stdlib.h>

typedef struct slnode
{
  char* phrase;
  struct slnode* next;
} slnode;

slnode* create(slnode* list, char* phrase);

int main(void)
{
  slnode* list = malloc(sizeof(slnode));
  if (list == NULL) return 1;
  list->phrase = "Hello!";
  list->next = NULL;
  slnode* node = create(list, "saloute");
  printf("phrase: %s, next: %p\n", list->phrase, list->next);

  return 0;
}

slnode* create(slnode* list, char* phrase)
{
  slnode* new_node = malloc(sizeof(slnode));
  if (new_node == NULL) return NULL;
  new_node->phrase = phrase;
  new_node->next = list;
  list = new_node;
  return new_node;
}
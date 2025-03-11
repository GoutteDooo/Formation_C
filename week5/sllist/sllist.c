#include <stdio.h>
#include <stdlib.h>

typedef struct slnode
{
  char* phrase;
  struct slnode* next;
} slnode;

int main(void)
{
  slnode* list = malloc(sizeof(slnode));
  if (list == NULL) return 1;
  list->phrase = "Hello!";
  list->next = NULL;
  printf("phrase: %s, next: %p\n", list->phrase, list->next);

  return 0;
}
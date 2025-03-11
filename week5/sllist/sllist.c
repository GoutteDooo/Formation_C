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
  list->phrase = "Hello!";
  list->next = NULL;

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct dllnode
{
  char* phrase;
  int id;
  struct dllnode* next;
  struct dllnode* before;
} dllnode;

int main(void)
{
  dllnode* list = malloc(sizeof(dllnode));
  
  return 0;
}
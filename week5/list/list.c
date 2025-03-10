#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>


typedef struct node
{
  string phrase;
  struct node* next;
} node;

#define LIST_SIZE 2

bool unload(node* list);
void visualizer(node* list);

int main(void)
{
  node* list = NULL;

  for (int i = 0; i < LIST_SIZE; i++)
  {
    string phrase = get_string("Enter a phrase: ");
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
      return 1;
    }
    
    n->phrase = phrase;
    n->next = list;
		list = n;
    
    visualizer(list);
  }

  if (!unload(list))
  {
    printf("Error freeing the list.\n");
    return 1;
  }

  printf("Freed the list.\n");
	return 0;
}

bool unload(node* list)
{
	//TODO: Free all allocated nodes
	return false;
}

void visualizer(node* list)
{
	printf("+-- List Visualizer --+\n");
	printf("Location %x\n", list);
	printf("Phrase: %s\n", list->phrase);
	printf("Next: %x\n",list->next);
	printf("+---------------------+\n");
}
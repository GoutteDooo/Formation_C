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
	if (list->next == NULL)
	{
		free(list);
		return true;
	}
	for (node* ptr = list->next; ptr != NULL; ptr = ptr->next)
	{
		if (ptr == NULL)
		{
			free(list);
			return true;
		}
		free(list);
		list = ptr;
	}
	return false;
}

void visualizer(node* list)
{
	printf("+-- List Visualizer --+\n");
	printf("Location %p\n", list);
	printf("Phrase: %s\n", list->phrase);
	printf("Next: %p\n",list->next);
	printf("+---------------------+\n");
}
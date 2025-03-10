#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct node
{
  string phrase;
  struct node* next;
} node;

node* table[26];

int hash(string phrase);
bool unload(node* list);
void visualizer(node* list);

int main(void)
{
  // Add items
  for (int i = 0; i < 3; i++)
  {
    string phrase = get_string("Enter a new phrase: ");

    //Find phrase bucket
    int bucket = hash(phrase);
    printf("%s hashes to %i\n", phrase, bucket);
  }

  return 0;
}

//TODO: return the correct bucket for a given phrase
int hash(string phrase)
{
  //returns 0 to 25 depending on the first char of phrase
  return tolower(phrase[0]) - 'a';
}
// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return (toupper(word[0]) - 'A') % 26;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dico = fopen(dictionary, "r");
    if (dico == NULL)
    {
        printf("Could not open dictionary!\n");
        return false;
    }

    //Définir tout les nexts de la hashtable à NULL par défaut
    for (int i = 0; i < N ; i++)
    {
        // table[i] = malloc(sizeof(node));
        table[i]->next = NULL;
        printf("table[%i]: %p\n",i,&table[i]);
    }

    char* scanned_word = malloc(LENGTH);
    int test = 0;
    while (fscanf(dico, "%s", scanned_word) != EOF)
    {
        break;
        /*
        printf("scanned word: %s\n",scanned_word);
        test++;
        if (test > 10000000) break;
        */
        
        node* new_word = malloc(sizeof(node));
        if (new_word == NULL)
        {
            printf("Error when loading. No more memory available.\n");
            return false;
        }
        strcpy(new_word->word, scanned_word);
        // before : head -> last_word -> other_word
        int hindex = hash(new_word->word);
        printf("table->next: %p\n", table[hindex]->next);
        continue;
        new_word->next = table[hindex]->next;
        //here : head -> last_word <- new_word
        //                     |
        //                     V
        //                 other_word
        table[hindex]->next = new_word;
        // and : head -> new_word -> last_word -> other_word
    }
    free(scanned_word);
    
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}

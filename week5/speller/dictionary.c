// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

//Globals
const unsigned int N = 26;
unsigned int number_words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word to find which bucket to it is stored
    unsigned int h = hash(word);
    // Go find the word through the selected bucket
    for (node* checker = table[h]; checker != NULL; checker = checker->next)
    {
        char* lowercase_word = strtolower(word);
        if (strcasecmp(lowercase_word, checker->word) == 0) return true;
    }
    // we traverse all the nodes and didn't find the word
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hash sum of ASCII values of the length of a word
    unsigned int ascii_sum = 0;
    char* lowercase_word = strtolower(word);
    for (int i = 0, n = strlen(word); i < n; i ++)
    {
        ascii_sum += lowercase_word[i];
    }
    return ascii_sum % N;
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

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char scanned_word[LENGTH];
    while (fscanf(dico,"%s", scanned_word) != EOF)
    {

        if(scanned_word[0] == '\0')
        {
            printf("No word to insert into node.\n");
            continue;
        }

        node* new_word = malloc(sizeof(node));
        new_word->next = NULL;
        if (new_word == NULL)
        {
            printf("Error when loading. No more memory available.\n");
            return false;
        }
        number_words++;
        
        // insert scanned word into new node
        strcpy(new_word->word, scanned_word);

        // hash word to find which bucket we'll store the new node
        int hindex = hash(new_word->word);

        // if table[i] is empty, define head -> new_word
        if (table[hindex] == NULL) {
            table[hindex] = new_word;
        }
        else
        {
            // before : head -> last_word -> other_word
            new_word->next = table[hindex];
            //here : head -> last_word <- new_word
            //                     |
            //                     V
            //                 other_word
            table[hindex] = new_word;
            // and : head -> new_word -> last_word -> other_word
        }
    }
    fclose(dico);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    /*
    unsigned int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL) break;
        // checker chaque bucket
        for (node* checker = table[i]; checker != NULL; checker = checker->next, count++);
    }
    */
    return number_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //explorer chaque bucket, et free tout les nodes
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            for(node* checker = table[i]->next; checker != NULL; checker = checker->next)
            {
                free(table[i]);
                table[i] = checker;
                if (checker->next == NULL)
                {
                    free(checker);
                    break;
                }
            }
        }
    }
    // All buckets is empty
    return true;
}


/* -- Helpers --*/
/* Convert a full string to lowercase */
char* strtolower(const char* word)
{
    char* copy = strcpy(copy, word);
    for (int i = 0, n = strlen(copy); i < n ; i++)
    {
        copy[i] = tolower(copy[i]);
    }
    return copy;
}
// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Number of Words 
unsigned dictionary_size = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Cursor set to first item
    int hash_value = hash(word); // Hash Word
    node *n = table[hash_value]; // Access Linked List in Hash Table

    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0) // if word is found/matched
        {
            return true;
        }
        n = n->next; // to traverse linked lists.
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned long hash = 5381;
    int c;

    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *dictionary_ptr = fopen(dictionary, "r");

    if (dictionary_ptr == NULL)
    {
        // Memory card cannot be read
        printf("Cannot be opened for reading\n");
        return 1;
    }

    // Initialise Word Array
    char word[LENGTH + 1];

    // Read strings from file one at a time
    while (fscanf(dictionary_ptr, "%s", word) != EOF)
    {
        // Create a new node for each word; Allocate Memory
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy word to node
        strcpy(n->word, word);

        // Hash Value of Word
        unsigned int hash_value = hash(word); // Hash word

        n->next = table[hash_value]; // New pointer est.
        table[hash_value] = n; // Head connected to new pointer
        dictionary_size++;
    }
    fclose (dictionary_ptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (dictionary_size > 0)
    {
        return dictionary_size;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *n = table[i]; // n set as a bucket location
        
        // Go over hash table, and free all the nodes in the linked lists.
        while (n != NULL)
        {
            node *temp = n;
            n = n->next;
            free(temp);
        }

        if (i == N - 1 && n == NULL )
        {
            return true;
        }
    }
    return false;
}
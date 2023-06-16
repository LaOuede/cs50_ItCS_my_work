// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h> //fopen ; fscanf
#include <stdlib.h> //malloc
#include <string.h> //strcpy
#include <strings.h> //strcasecmp

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Hashes word to a number
unsigned int hash_function(const char *word)
{
    /*
        What to do?
        Input : word, w/ alphabetical characters and (possible) apostrophes
        Output : numerical index between 0 and N - 1, inclusive
            N is define at the top of the file
            Larger N means more buckets
            If the function ends up with a value greater than N,
                it's possible to get the value % N to get a value in the appropriate renge
        Deterministic
        Examples : First letter, First two letter, Math using all the letters, ...
    */
    int len = strlen(word);
    int total = 0;

    for (int i = 0; word[i]; i++)
    {
        total += word[i];
    }
    total += len;
    return (total);
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    /*
        What to do?
        - Return true if the word is in the dictionary, false otherwise
        - Case insensitive
        1) Hash word to obtain a hash value
        2) Access linked list at that index in the hash table
        3) Traverse linked list, looking for the word (strcasecmp)
    */
    int hash = 0;
    int len = strlen(word);
    char *copy = NULL;
    node *ptr = NULL;

    // Make a copy of the word
    copy = calloc(len + 1, sizeof(char));
    for (int i = 0; i < len; i++)
    {
        copy[i] = tolower(word[i]);
    }
    // Hash the word to find his bucket
    hash = hash_function(copy);
    // Try to find the word by going through the linked list
    for (ptr = table[hash]; ptr; ptr = ptr->next)
    {
        // If the word from the text is the same as the word from the dictionnary, return true
        if (strcasecmp(copy, ptr->word) == 0)
        {
            free(copy);
            return true;
        }
    }
    // Free the copy
    free(copy);
    // If words are differents
    return false;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    /*
        What to do ?
        1) open dictionnary file
            fopen()
            check is return value is NULL
        2) read strings from dictionnary one line at a time
            fscanf(file, "%s", word)
            will return EOF once it reaches end of file
        3) create a new node for each word
            use malloc : node *n = malloc(sizeof(node))
            check if return is NULL
            copy the word into node : strcpy(n->word, word of dictionnary)
        4) hash word to obtain hash value
            use the hash function
            hash() takes a string and return an index
        5) insert node to hash table at that location
            recall that hash table is an array of linked lists
            be sure to set pointers in the correct order!
            add on top
    */
    node *n;
    FILE *pointer;
    int  hash_value = 0;
    char word[LENGTH + 1];

    // Open dictionary file and create a file "pointer" returned by fopen
    pointer = fopen(dictionary, "r");
    if (pointer == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }
    // Extract one word at a time from dictionary
    while (fscanf(pointer, "%s", word) != EOF)
    {
        // Create a new node
        n = malloc(sizeof(node));
        if (!n)
        {
            printf("Node memory allocation failed\n");
            return false;
        }
        // Copy the word from dictionary to node
        strcpy(n->word, word);
        // Calculate the hash value for the node
        hash_value = hash_function(n->word);
        // Initialize next to NULL
        n->next = NULL;
        // Insert node in the hash table at the hash value place
        if (table[hash_value] == NULL)
        {
            table[hash_value] = n;
        }
        else
        {
            n->next = table[hash_value];
            table[hash_value] = n;
        }
    }
    // Close dictionary
    fclose(pointer);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int size = 0;
    node *current_node = NULL;

    for (int i = 0; i < N; i++)
    {
        current_node = table[i];
        while (current_node != NULL)
        {
            size++;
            current_node = current_node->next;
        }
    }
    return (size);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int size = 0;
    node *ptr = NULL;
    node *current_node = NULL;

    for (int i = 0; i < N; i++)
    {
        current_node = table[i];
        while (current_node != NULL)
        {
            ptr = current_node->next;
            free(current_node);
            current_node = ptr;
        }
    }
    return true;
}

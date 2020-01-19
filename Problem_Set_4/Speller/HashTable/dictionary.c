// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

//LinkedList prototypes
bool freeNode(node *currentNode);
bool searchInList(node *head, const char *word);

//HashTables prototypes
void addElementToBucket(const char *word);

// A variable to count the number of words from the dictionary
unsigned int sizeOfDict = 0;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        addElementToBucket(word);
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return sizeOfDict;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    return searchInList(hashtable[hash(word)], word);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    bool val = true;
    for (int i = 0; i < N; i++)
    {
        if (hashtable[i])
        {
            val = val && freeNode(hashtable[i]);
        }
    }
    return val;
}


/*Hashtables functions */

//Add a new element to a bucket
void addElementToBucket(const char *word)
{
    unsigned int hashcode = hash(word);
    node *newNode = malloc(sizeof(node));
    if (!newNode)
    {
        ;
    }
    else
    {
        strcpy(newNode->word, word);
        newNode->next = hashtable[hashcode];
        hashtable[hashcode] = newNode;
    }
    sizeOfDict++;
}

// A recursive function to free every node of a list starting with the head
bool freeNode(node *currentNode)
{
    bool val = true;
    if (currentNode->next == NULL)
    {
        free(currentNode);
        return val;
    }
    else
    {
        val = val && freeNode(currentNode->next);
        free(currentNode);
        return val;
    }
    return false;
}

// A function to verify if a word is in a list or not
bool searchInList(node *head, const char *word)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

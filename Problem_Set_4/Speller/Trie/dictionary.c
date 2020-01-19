// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;

//Trie prototypes
int nextPath(const char *word);
void addElementToTrie(const char *word, node *trieBranch);
bool searchInTrie(const char *word, node *trieBranch);
void freeNode(node *temp);

// Represents a trie
node *root = NULL;

//Keep dictionary length
unsigned int dicoLength = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }
    root->is_word = false;
    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
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

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        addElementToTrie(word, root);
        dicoLength++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dicoLength;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    if (!root)
    {
        return false;
    }
    return searchInTrie(word, root);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (!root)
    {
        return false;
    }
    freeNode(root);
    return true;
}

/*Trie functions*/

//This function return the right index for the value
int nextPath(const char *word)
{
    if (isalpha(word[0]))
    {
        return (tolower(word[0]) - 'a');
    }
    return 26;
}

//Add a new element to a trie
void addElementToTrie(const char *word, node *trieBranch)
{
    int length = strlen(word);
    node *temp = trieBranch;
    for (int i = 0; i < length; i++)
    {
        int nP = nextPath((word + i));
        if (!temp->children[nP] && (i != length - 1))
        {
            node *anotherNode = malloc(sizeof(node));
            anotherNode->is_word = false;
            for (int j = 0; j < N; j++)
            {
                anotherNode->children[j] = NULL;
            }
            temp->children[nP] = anotherNode;
            temp = temp->children[nP];
        }
        else if (!temp->children[nP] && (i == length - 1))
        {
            node *anotherNode = malloc(sizeof(node));
            anotherNode->is_word = true;
            for (int j = 0; j < N; j++)
            {
                anotherNode->children[j] = NULL;
            }
            temp->children[nP] = anotherNode;
        }
        else if (temp->children[nP] && (i != length - 1))
        {
            temp = temp->children[nP];
        }
        else if (temp->children[nP] && (i == length - 1))
        {
            temp->children[nP]->is_word = true;
        }
    }
}

bool searchInTrie(const char *word, node *trieBranch)
{
    bool rep = true;
    int length = strlen(word);
    node *temp = trieBranch;

    for (int i = 0; i < length; i++)
    {
        int nP = nextPath((word + i));
        if (!temp->children[nP])
        {
            rep = false;
            break;
        }
        else
        {
            if (i == length - 1)
            {
                rep = temp->children[nP]->is_word;
            }
            else
            {
                temp = temp->children[nP];
            }
        }
    }

    return rep;
}

void freeNode(node *temp)
{
    for (int i = 0; i < N; i++)
    {
        if (temp->children[i])
        {
            freeNode(temp->children[i]);
        }
    }
    free(temp);
}


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

// Define DICTIONARY variable
#define DICTIONARY "/usr/share/dict/words"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
#define N 10000

// Hash function declaration
unsigned int hash(const char *word);

// Words in the dictionary
unsigned int dictionaryWords = 0;

// Hash table
node *table[N];

// Function prototype for strcasecmp
int strcasecmp(const char *s1, const char *s2);

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Convert word to lowercase
    char lowercase_word[LENGTH + 1];
    for (int i = 0; word[i] != '\0'; i++)
    {
        lowercase_word[i] = tolower(word[i]);
    }
    lowercase_word[strlen(word)] = '\0';

    unsigned int index = hash(lowercase_word); // Use lowercase word for hashing
    node *cursor = table[index];

    while (cursor != NULL)
    {
        // Compare lowercase word with lowercase dictionary word
        if (strcasecmp(cursor->word, lowercase_word) == 0)
        {
            return true; // Word found
        }
        cursor = cursor->next;
    }

    return false; // Word not found
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }

    // Read words from file and insert into hash table
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        // Copy word into node
        strcpy(new_node->word, word);

        // Hash word to obtain index
        unsigned int index = hash(word);

        // Insert node into hash table
        new_node->next = table[index];
        table[index] = new_node;

        // Increment word count
        dictionaryWords++;
    }

    // Close dictionary file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dictionaryWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}

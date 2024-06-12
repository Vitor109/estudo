#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct for a person
typedef struct person
{
    struct person *parents[2]; // Two parents
    char alleles[2];           // Two alleles for blood type
} person;

// Global constants
const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

// Function prototypes
person *create_family(int generations);
void create_parents(person *child, int generations);
void assign_alleles(person *child);
void free_family(person *p);
void print_family(person *p, int generation);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);

    return 0;
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // Allocate memory for new person
    person *new_person = malloc(sizeof(person));

    // Check if we reached the end of generations
    if (generations > 1)
    {
        // Recursively create parents
        create_parents(new_person, generations);

        // Assign alleles based on parents
        assign_alleles(new_person);
    }
    else
    {
        // Set parent pointers to NULL for the youngest generation
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;

        // Randomly assign alleles for the youngest generation
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    return new_person;
}

// Create parents for a person
void create_parents(person *child, int generations)
{
    // Recursively create parents
    child->parents[0] = create_family(generations - 1);
    child->parents[1] = create_family(generations - 1);
}

// Assign alleles to a person based on its parents
void assign_alleles(person *child)
{
    // Randomly assign child alleles based on parents
    child->alleles[0] = child->parents[0]->alleles[rand() % 2];
    child->alleles[1] = child->parents[1]->alleles[rand() % 2];
}

// Free memory allocated for a family
void free_family(person *p)
{
    if (p != NULL)
    {
        // Free parents
        free_family(p->parents[0]);
        free_family(p->parents[1]);

        // Free child
        free(p);
    }
}

// Print each family member and their alleles
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);

    // Print parents
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}

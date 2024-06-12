#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(const char *word);

int main(void)
{
    // Get input words from both players
    char word1[100];
    char word2[100];

    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = '\0'; // Remover o caractere de nova linha

    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = '\0'; // Remover o caractere de nova linha

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(const char *word)
{
    int score = 0;

    // Iterate over each character in the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Convert the character to uppercase
        char uppercase_char = toupper(word[i]);

        // Check if the character is a letter
        if (isalpha(uppercase_char))
        {
            // Calculate the index of the character in the POINTS array
            int index = uppercase_char - 'A';

            // Add the corresponding points to the total score
            score += POINTS[index];
        }
    }

    return score;
}

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Protótipos de funções
int count_letters(const char *text);
int count_words(const char *text);
int count_sentences(const char *text);
int calculate_index(int letters, int words, int sentences);

int main(void)
{
    // Obter entrada do usuário
    char text[1000];
    printf("Text: ");

    if (fgets(text, sizeof(text), stdin) == NULL)
    {
        printf("Error reading input.\n");
        return 1;
    }

    // Remover caractere de nova linha da entrada
    text[strcspn(text, "\n")] = '\0';

    // Verificar se a entrada não está vazia
    if (strlen(text) == 0)
    {
        printf("No text entered.\n");
        return 1;
    }

    // Contar letras, palavras e sentenças
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Verificar se há palavras suficientes para calcular o índice
    if (words < 1)
    {
        printf("Not enough words to calculate the index.\n");
        return 1;
    }

    // Calcular o índice
    int index = calculate_index(letters, words, sentences);

    // Imprimir o resultado
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}

// Contar letras em uma string
int count_letters(const char *text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Contar palavras em uma string
int count_words(const char *text)
{
    int count = 1; // Iniciar com 1 para considerar a primeira palavra
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Contar sentenças em uma string
int count_sentences(const char *text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// Calcular o índice Coleman-Liau
int calculate_index(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    return lround(0.0588 * L - 0.296 * S - 15.8);
}

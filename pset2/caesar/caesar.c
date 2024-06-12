#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Verifica se o número de argumentos é válido
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Verifica se a chave é um número inteiro positivo
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Converte a chave para um inteiro
    int key = atoi(argv[1]);

    // Verifica se a chave está no intervalo válido
    if (key < 0)
    {
        printf("Key must be a non-negative integer.\n");
        return 1;
    }

    // Solicita o texto ao usuário
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // Cifra o texto
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Verifica se o caractere é uma letra maiúscula
        if (isupper(plaintext[i]))
        {
            // Aplica a cifra de César preservando a capitalização
            printf("%c", 'A' + (plaintext[i] - 'A' + key) % 26);
        }
        // Verifica se o caractere é uma letra minúscula
        else if (islower(plaintext[i]))
        {
            // Aplica a cifra de César preservando a capitalização
            printf("%c", 'a' + (plaintext[i] - 'a' + key) % 26);
        }
        // Se não for uma letra, imprime o caractere sem modificação
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}

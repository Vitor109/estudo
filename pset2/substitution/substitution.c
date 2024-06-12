#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_valid_key(const char *key)
{
    // Verifica se a chave é válida (26 caracteres alfabéticos únicos)
    if (strlen(key) != 26)
    {
        return 0;
    }

    int freq[26] = {0}; // Frequência de cada letra na chave

    for (int i = 0; i < 26; i++)
    {
        char c = key[i];

        if (!isalpha(c))
        {
            return 0; // A chave contém um caractere não alfabético
        }

        int index = tolower(c) - 'a';

        if (freq[index] > 0)
        {
            return 0; // A chave contém uma letra mais de uma vez
        }

        freq[index]++;
    }

    return 1; // A chave é válida
}

char encrypt_char(char plain_char, const char *key)
{
    // Criptografa um caractere usando a cifra de substituição
    if (isalpha(plain_char))
    {
        char base = isupper(plain_char) ? 'A' : 'a';
        int index = tolower(plain_char) - 'a';
        char encrypted_char = isupper(plain_char) ? toupper(key[index]) : key[index];
        return isupper(plain_char) ? toupper(key[index]) : tolower(key[index]);
    }
    else
    {
        return plain_char; // Mantém caracteres não alfabéticos inalterados
    }
}

int main(int argc, char *argv[])
{
    // Verifica o número correto de argumentos
    if (argc != 2)
    {
        printf("Erro: Forneça exatamente uma chave como argumento.\n");
        return 1;
    }

    // Verifica se a chave é válida
    if (!is_valid_key(argv[1]))
    {
        printf("Erro: A chave é inválida.\n");
        return 1;
    }

    char *key = argv[1];

    // Solicita ao usuário uma string de texto simples
    printf("plaintext: ");
    char plain_text[500];
    fgets(plain_text, sizeof(plain_text), stdin);

    // Criptografa e imprime o texto cifrado
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        char encrypted_char = encrypt_char(plain_text[i], key);
        printf("%c", encrypted_char);
    }

    // Imprime uma nova linha
    printf("\n");

    // Retorna com sucesso
    return 0;
}

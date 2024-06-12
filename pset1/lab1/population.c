#include <cs50.h>
#include <stdio.h>

int main()
{
    // Solicitar ao usuário um tamanho inicial da população
    int populacao_inicial;
    do
    {
        populacao_inicial = get_int("Digite o tamanho inicial da população (mínimo 9): ");
    }
    while (populacao_inicial < 9); // Verifica se a população inicial é pelo menos 9

    // Solicitar ao usuário o tamanho final da população
    int tamanho_final;
    do
    {
        tamanho_final = get_int("Digite o tamanho final desejado da população (deve ser maior ou igual ao tamanho inicial): ");
    }
    while (tamanho_final < populacao_inicial); // Verifica se o tamanho final é maior ou igual ao inicial

    // Calcular o número de anos necessários para atingir o tamanho final
    int anos = 0;
    int populacao = populacao_inicial;
    while (populacao < tamanho_final)
    {
        // Calcular o número de nascimentos e mortes
        int nascimentos = populacao / 3;
        int mortes = populacao / 4;
        // Atualizar a população
        populacao += nascimentos - mortes;
        // Atualizar o número de anos
        anos++;
    }

    // Imprimir o número de anos necessários
    printf("Years: %d\n", anos);

    return 0;
}

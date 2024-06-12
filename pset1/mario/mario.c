#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main()
{
    int tamanho = 0;
    do
    {
        printf("Tamanho: ");
        scanf("%d", &tamanho);
    }
    while (tamanho < 1 || tamanho > 8);
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (i + j < tamanho - 1)

                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
    return 0;
}

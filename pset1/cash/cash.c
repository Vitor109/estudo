#include <math.h>
#include <stdio.h>

int main(void)
{
    float troco;
    int centavos, indice, quantidade = 0;
    int moedas[] = {25, 10, 5, 1};

    do
    {
        printf("Troco Devido: ");
        scanf("%f", &troco);
    }
    while (troco <= 0);

    // Arredonda para o inteiro mais próximo
    centavos = round(troco * 100);

    for (indice = 0; indice < 4; indice++)
    {
        quantidade += centavos / moedas[indice];
        centavos %= moedas[indice];
    }

    printf("%i\n", quantidade);

    return 0;
}

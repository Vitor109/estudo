#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Verifica se o programa foi executado com o argumento correto
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Abre o arquivo de imagem forense
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Variáveis para o nome do arquivo de saída e para o arquivo de saída
    char filename[8];
    FILE *img = NULL;

    // Variável para armazenar o número de JPEGs recuperados
    int count = 0;

    // Variável para armazenar os bytes lidos do arquivo
    BYTE buffer[512];

    // Loop para ler o arquivo de entrada
    while (fread(buffer, sizeof(BYTE), 512, file))
    {
        // Verifica se o bloco lido é o início de um novo JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Se já tiver um arquivo aberto, fecha-o
            if (img != NULL)
            {
                fclose(img);
            }

            // Cria o nome do próximo arquivo JPEG
            sprintf(filename, "%03i.jpg", count);

            // Abre o novo arquivo JPEG
            img = fopen(filename, "w");

            // Escreve o bloco atual no arquivo JPEG
            fwrite(buffer, sizeof(BYTE), 512, img);

            // Incrementa o contador de JPEGs
            count++;
        }
        else if (img != NULL)
        {
            // Se já tiver um arquivo aberto, continua escrevendo nele
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
    }

    // Fecha o arquivo de imagem forense
    fclose(file);

    // Fecha o último arquivo JPEG, se estiver aberto
    if (img != NULL)
    {
        fclose(img);
    }

    // Retorna 0 para indicar sucesso
    return 0;
}

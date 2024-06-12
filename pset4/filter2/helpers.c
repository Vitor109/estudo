#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Calcula a média dos valores de RGB e define cada canal para a média
            int gray = round((float) (image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3);
            image[h][w].rgbtRed = gray;
            image[h][w].rgbtGreen = gray;
            image[h][w].rgbtBlue = gray;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Calcula os novos valores RGB usando a fórmula de sepia
            int sepiaRed = round(0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.189 * image[h][w].rgbtBlue);
            int sepiaGreen = round(0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue);
            int sepiaBlue = round(0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue);

            // Define os novos valores RGB após a aplicação do filtro de sepia
            image[h][w].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[h][w].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[h][w].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            // Troca os pixels da esquerda com os pixels da direita
            RGBTRIPLE temp = image[h][w];
            image[h][w] = image[h][width - 1 - w];
            image[h][width - 1 - w] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Cria uma cópia temporária da imagem para manter os valores originais
    RGBTRIPLE temp[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            temp[h][w] = image[h][w];
        }
    }

    // Aplica o filtro de blur
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int count = 0;
            int red = 0, green = 0, blue = 0;

            // Percorre a vizinhança de cada pixel
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int new_i = h + di;
                    int new_j = w + dj;

                    // Verifica se o pixel está dentro dos limites da imagem
                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
                    {
                        count++;
                        red += temp[new_i][new_j].rgbtRed;
                        green += temp[new_i][new_j].rgbtGreen;
                        blue += temp[new_i][new_j].rgbtBlue;
                    }
                }
            }

            // Calcula a média dos valores de RGB para o pixel
            image[h][w].rgbtRed = round((float) red / count);
            image[h][w].rgbtGreen = round((float) green / count);
            image[h][w].rgbtBlue = round((float) blue / count);
        }
    }
}

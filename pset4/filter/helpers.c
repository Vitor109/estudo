#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int average = round((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3.0);
            image[h][w].rgbtBlue = average;
            image[h][w].rgbtGreen = average;
            image[h][w].rgbtRed = average;
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
            RGBTRIPLE temp = image[h][w];
            image[h][w] = image[h][width - 1 - w];
            image[h][width - 1 - w] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            temp[h][w] = image[h][w];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float sum_red = 0;
            float sum_blue = 0;
            float sum_green = 0;
            int counter = 0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int new_h = h + i;
                    int new_w = w + j;

                    if (new_h >= 0 && new_h < height && new_w >= 0 && new_w < width)
                    {
                        sum_red += temp[new_h][new_w].rgbtRed;
                        sum_blue += temp[new_h][new_w].rgbtBlue;
                        sum_green += temp[new_h][new_w].rgbtGreen;
                        counter++;
                    }
                }
            }

            image[h][w].rgbtRed = round(sum_red / counter);
            image[h][w].rgbtBlue = round(sum_blue / counter);
            image[h][w].rgbtGreen = round(sum_green / counter);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE temp[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int gx_red = 0, gx_green = 0, gx_blue = 0;
            int gy_red = 0, gy_green = 0, gy_blue = 0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int new_h = h + i;
                    int new_w = w + j;

                    if (new_h >= 0 && new_h < height && new_w >= 0 && new_w < width)
                    {
                        gx_red += image[new_h][new_w].rgbtRed * gx[i + 1][j + 1];
                        gx_green += image[new_h][new_w].rgbtGreen * gx[i + 1][j + 1];
                        gx_blue += image[new_h][new_w].rgbtBlue * gx[i + 1][j + 1];

                        gy_red += image[new_h][new_w].rgbtRed * gy[i + 1][j + 1];
                        gy_green += image[new_h][new_w].rgbtGreen * gy[i + 1][j + 1];
                        gy_blue += image[new_h][new_w].rgbtBlue * gy[i + 1][j + 1];
                    }
                }
            }

            int red = round(sqrt(gx_red * gx_red + gy_red * gy_red));
            int green = round(sqrt(gx_green * gx_green + gy_green * gy_green));
            int blue = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));

            temp[h][w].rgbtRed = (red > 255) ? 255 : red;
            temp[h][w].rgbtGreen = (green > 255) ? 255 : green;
            temp[h][w].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = temp[h][w];
        }
    }
}

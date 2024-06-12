#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        // Prompt the user for the height
        height = get_int("Height: ");
    }
    // Check if the input is within the range [1, 8]
    while (height < 1 || height > 8);

    // Loop through each row
    for (int i = 0; i < height; i++)
    {
        // Print spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // Print left pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        // Print gap
        printf("  ");
        // Print right pyramid
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        // Move to the next line
        printf("\n");
    }
    return 0;
}

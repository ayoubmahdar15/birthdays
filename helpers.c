#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // Loop for Columns
    {
        for (int j = 0; j < width; j++) // Loop for Rows
        {
            // Exact values for each color
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            // Average Values to Produce Grayscale Effect
            int grayscale_average = round((red + blue + green) / (float)3.0);

            // Set values of each color to average
            grayscale_average = image[i][j].rgbtGreen = image[i][j].rgbtBlue = image[i][j].rgbtRed;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // Loop for Columns
    {
        for (int j = 0; j < width; j++) // Loop for Rows
        {
            // Exact values for each color
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            // Sepia Formulas While Ensuring Values Are Within 0-255 Range
            int sepiaRed = round((.393 * red) + (.769 * green) + (.189 * blue));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            else
            {
                sepiaRed = image[i][j].rgbtRed;
            }

            int sepiaBlue = round((.349 * red) + (.686 * green) + (.168 * blue));

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            else
            {
                sepiaBlue = image[i][j].rgbtBlue;
            }

            int sepiaGreen = round((.272 * red) + (.534 * green) + (.131 * blue));

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            else
            {
                sepiaGreen = image[i][j].rgbtGreen;
            }
        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // Loop for Columns
    {
        for (int j = 0; j < width / 2; j++) // Loop for Rows (Swap Up Until Half of Width)
        {
            RGBTRIPLE temp = image[i][j]; // Store it in tmp.
            image[i][j] = image[i][width - (1 + j)]; // Flip values
            image[i][width - (1 + j)] = temp;

            break;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // Loop for Columns
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;

        }
    }
}


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
            int grayscale_average = round(((float)red + (float)blue + (float)green) / 3.0);

            // Set values of each color to average
            grayscale_average = image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // Loop for Columns
    {
        for (int j = 0; j < width; j++) // Loop for Rows
        {
            // Exact values for each color
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;

            // Sepia Formulas While Ensuring Values Are Within 0-255 Range
            int sepiaGreen = round((0.349 * red) + (0.686 * green) + (0.168 * blue));

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                 image[i][j].rgbtGreen = sepiaGreen;
            }

            int sepiaBlue = round((0.272 * red) + (0.534 * green) + (0.131 * blue));

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

            int sepiaRed = round((0.393 * red) + (0.769 * green) + (0.189 * blue));

            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
        }
    }
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // Loop for Columns
    {
        for (int j = 0; j < width / 2; j++) // Loop for Rows (Swap Up Until Half of Width)
        {
            RGBTRIPLE temp = image[i][j]; // Store it in tmp.
            image[i][j] = image[i][width - 1 - j]; // Flip values
            image[i][width - 1 - j] = temp;

            break;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
	float average_red;
	float average_green;
	float average_blue;

    for (int i = 0; i < height; i++) // i = row
    {
        for (int j = 0; j < width; j++) // j = column
        {
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++) // i = row
    {
        for (int j = 0; j < width; j++) // j = column
        {
            // Top Right Corner
            if (i == 0 && j == (width - 1))
            {
                average_green = (float) (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen) / 4.0;
                average_blue = (float) (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue) / 4.0;
                average_red = (float) (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed) / 4.0;

                average_green = round(average_green);
                average_red = round(average_red);
                average_blue = round(average_blue);

                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                image[i][j].rgbtBlue = average_blue;
            }
            // Top Left Corner
            else if (i == 0 && j == 0)
            {
                average_green = (float) (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 4.0;
                average_blue = (float) (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 4.0;
                average_red = (float) (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 4.0;

                average_green = round(average_green);
                average_red = round(average_red);
                average_blue = round(average_blue);

                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                image[i][j].rgbtBlue = average_blue;
            }

            // Bottom Right Corner
            else if (i == (height - 1) && j == (width - 1))
            {
                average_green = (float) (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen) / 4.0;
                average_blue = (float) (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue) / 4.0;
                average_red = (float) (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed) / 4.0;

                average_green = round(average_green);
                average_red = round(average_red);
                average_blue = round(average_blue);

                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                image[i][j].rgbtBlue = average_blue;
            }

            // Bottom Left Corner
            else if (i == (height - 1) && j == 0)
            {
                average_green = (float) (image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen) / 4.0;
                average_blue = (float) (image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue) / 4.0;
                average_red = (float) (image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j+1].rgbtRed) / 4.0;

                average_green = round(average_green);
                average_red = round(average_red);
                average_blue = round(average_blue);

                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                image[i][j].rgbtBlue = average_blue;
            }

            // Left Side Edges
            else if (j == 0 && (i != 0 && i < height - 1))
            {
                average_green = (float) (image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6.0;
                average_blue = (float) (image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6.0;
                average_red = (float) (image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 6.0;

                average_green = round(average_green);
                average_red = round(average_red);
                average_blue = round(average_blue);

                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                image[i][j].rgbtBlue = average_blue;
            }

            // Right Side Edges
            else if (j == (width - 1) && (i > 0 && i < height - 1))
            {
                average_green = (float) (image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen) / 6.0;
                average_blue = (float) (image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue) / 6.0;
                average_red = (float) (image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed) / 6.0;

                average_green = round(average_green);
                average_red = round(average_red);
                average_blue = round(average_blue);

                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                image[i][j].rgbtBlue = average_blue;
            }

            // Top Side Edges
            else if (i == 0 && (j > 0 && j < width - 1))
            {
                average_green = (float) (image[i][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen) / 6.0;
                average_blue = (float) (image[i][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue) / 6.0;
                average_red = (float) (image[i][j].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed) / 6.0;

                average_green = round(average_green);
                average_red = round(average_red);
                average_blue = round(average_blue);

                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                image[i][j].rgbtBlue = average_blue;
            }

            // Bottom Side Edges
            else if (i == height - 1 && (j > 0 && j < width - 1))
            {
                average_green = (float) (image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen) / 6.0;
                average_blue = (float) (image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue) / 6.0;
                average_red = (float) (image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed) / 6.0;

                average_green = round(average_green);
                average_red = round(average_red);
                average_blue = round(average_blue);

                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                image[i][j].rgbtBlue = average_blue;
            }

            // Center Pieces / Rest
            else
            {
                average_green = (float) (image[i][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen) / 9.0;
                average_blue = (float) (image[i][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen) / 9.0;
                average_red = (float) (image[i][j].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen) / 9.0;

                average_green = round(average_green);
                average_red = round(average_red);
                average_blue = round(average_blue);

                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                image[i][j].rgbtBlue = average_blue;
            }
        }
    }
return;
}



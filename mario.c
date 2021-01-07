#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int height;
    int spaces; 
    int hashes;

    do
    {
        height = get_int("Height (Positive number between 1-8): \n");
    }
    while (height < 1 || height > 8);

    //draw the half pyramid
    for (spaces = 0; spaces < height; spaces++)
    {
        for (hashes = 1; hashes < height; hashes++ )    
        {
            printf("#");
        }
        printf("\n");
    }

}
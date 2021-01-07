#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int height;

    do
    {
        //user input for height 
        height = get_int("Height (Positive number between 1-8): \n");
    }
    while (height < 1 || height > 8);

    
    for (int row = 0; row < height ; row++)
    {
        for (int column = 0; column < height ; column++ )    
        {
            if (row + column >= height - 1) 
                printf("#");
            else 
                printf(" ");
        }
        printf("\n");
    }

}
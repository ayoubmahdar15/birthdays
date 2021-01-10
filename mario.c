#include <stdio.h>
#include <cs50.h>

int main(void)

{
    //Prompt for Input
    int height;
        do
        {
             height = get_int("Enter height: ");
        }
       while (height < 1 || height > 8);

    printf("%i\n", height);

    // Rows 
    for (int i = 0; i < height ; i++)   
    {
            // Columns producing "# or  "
           for (int m = 0; m < (8 - (i + 1)); m++)
                printf(" ");
           
           for (int c = 0; c < i + 1; c++)
                printf("#");
       
       printf("\n");
    }
   
}



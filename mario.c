#include <cs50.h>
#include <stdio.h> 

int main(void);
{   
    int height; 
    do
    {
        height = get_int("Positve Number for Height: \n");
    }
    while (height < 1 or height > 8);
        height = int(input("Height: "))
    
    printf("%i\n", height);
}
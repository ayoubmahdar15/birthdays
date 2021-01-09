#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int start_size;    
    // TODO: Prompt for start size
    do
    {
        start_size = get_int("Enter starting population size: \n");
    }
    while (start_size < 9);
    
    int end_size;
    // TODO: Prompt for end size
    do
    {
        end_size = get_int("Enter ending population size: \n");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    
    do
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years++;
    }
    while (end_size < start_size);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
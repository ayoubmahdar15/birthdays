#include <cs50.h>
#include <stdio.h> 

int main(void)
{
    // Asking for name input
    string name = get_string("What is your name?\n");
    // Response with name input
    printf("hello, %s\n", name);
}
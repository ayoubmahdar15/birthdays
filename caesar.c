#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //k is command-line argument (non-neg integer)
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        string plain_statement = get_string("plaintext: \n");
        
        printf("ciphertext: \n");
        for (int i = 0, n = strlen(plain_statement); i < n; i++)
            {
                char c = plain_statement[i];
                if (isalpha(c)) 
                {
                    if (isupper(c)) 
                    {
                        printf("%c", ((c - 'A' + key) % 26) + 'A');
                    }
                    else (islower(c)); 
                    {
                        printf("%c", ((c - 'a' + key) % 26) + 'a');
                    } //Shift character by key
                }
                else
                {
                    printf("%c", c);
                }
            }
        printf("\n");
        return 0;
    }
    else
        {
            printf("Error\n");
            return 1;
        }

        //None or too many C-LA = print("Error") and return value of 1
        //if not decimal digit = print("Usage: .caesar key")

    //K can be any positive int (even greater than 26)

    // Must output get_string (plaintext)
    // Must output produced ciphertext
        // None alpha characters should not be affected.

    // End of program, exit by returning zero from main.
}



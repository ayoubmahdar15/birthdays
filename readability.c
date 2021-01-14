#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{   //Get Input from User: String of Text
string text = get_string("Text: ");

int i;
int count_letters = 0;
int count_words = 1;
int count_sentences = 0;
    
    for (i=0; i < strlen(text); i++)
    {
        char c = text[i];
        if (isalpha (c))
        {
            count_letters++;
        }
        if (isspace (c))
        {
            count_words++;
        }
        if (c == '.' || c == '!' || c == '?')
        {
            count_sentences++;
        }
    }

    float L = (count_letters / (float) count_words) * 100;
    float S = (count_sentences / (float) count_words) * 100;
    float index = ((0.0588 * L) - (0.296 * S) - 15.8);
    int estimated_grade = round(index);

    if (estimated_grade >= 1 && estimated_grade < 16)
    {
        printf("Grade %i\n", estimated_grade);
    }
    else if (estimated_grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Before Grade 1\n");
    }
}

    //Get Output: Grade "X"

    //If Output >=16, produce "Grade 16+"

    // If Output < 1, produce "Before Grade 1"
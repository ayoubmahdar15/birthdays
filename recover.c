#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    // open memory card
    FILE *input_card = fopen(argv[1], "r"); 
    // Memory card cannot be read 
    if (input_card == NULL)
    {
        printf("Cannot be read\n"); 
        return 1;
    }
    
    unsigned char buffer[512]; // Buffer for Array
    int count_images = 0; // Counting # of Images Recovered
    char filename[8];
    FILE *output_images = NULL;// File Pointer for Output
    
    // Read Memory Card
    while (fread(buffer, 512, 1, input_card) != 0)
    {
        // Start of New JPEG
        if (buffer[0] == 0xff && buffer [1] == 0xd8 && buffer [2] == 0xff && (buffer [3] & 0xf0) == 0xe0) 
        {
            // write jpeg into file name (000.jpg, 001.jpg...)  
            sprintf(filename, "%03i.jpg", count_images);
            // open filename   
            output_images = fopen(filename, "w");
            // keep track of images found 
            count_images++; 
        }
        // Writing into New File 
        if (output_images != NULL)
        {
            fwrite(&buffer, 512, 1, output_images);                            
        }
    }
    // Close Files 
    fclose(input_card); 
    fclose(output_images); 
    
    return 0; 
}
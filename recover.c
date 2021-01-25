#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Incorrect usage\n");
        return 1; 
    }
    
    FILE *memory_card = fopen(argv[1], "r"); 
    if (memory_card == NULL)
    {
        printf("Cannot be opened for reading\n");
        return 1; 
    }
    
    unsigned char buffer [512];
    int image_count = 0; 
    FILE *output_images = NULL; 
    char filename [8];
    
    while (fread(&buffer, 512, 1, memory_card))
    {
        if ((buffer[0] == 0xff && buffer [1] == 0xd8 && buffer [2] == 0xff && (buffer [3] & 0xf0) == 0xe0))
        {
            // write jpeg into file name (000.jpg, 001.jpg...)
            sprintf(filename, "%03i.jpg", image_count);
            // open filename
            output_images = fopen(filename, "w");
            // keep track of images found
            image_count++;
        }
        
        if (output_images != 0)
        {
            fwrite(&buffer, 512, 1, output_images);
        }
    }
    
    fclose(output_images); 
    fclose(memory_card); 
    
    return 0;
}
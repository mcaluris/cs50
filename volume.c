// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t BYTE;

typedef int16_t WAVE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE *buffer = malloc(sizeof(BYTE) * 44);
    
    fread(buffer, sizeof(BYTE), HEADER_SIZE, input);

    fwrite(buffer, sizeof(BYTE), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    WAVE *block = malloc(sizeof(WAVE));
    
    while(fread(block, sizeof(WAVE), 2, input))
    {
        for(int i = 0;  i < 2; i++)
    {
        block[i] = block[i] * factor;
    }
    
        fwrite(block, sizeof(WAVE), 2, output); 
    }
    
    

    // Close files
    free(block);
    free(buffer);
    fclose(input);
    fclose(output);
    
}

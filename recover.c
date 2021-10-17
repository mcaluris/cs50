#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

typedef uint8_t BYTE;

bool is_jpeg (BYTE *buffer);

FILE *file_out = NULL;

int main(int argc, char *argv[])
{
     //Check for correct usage
     if(argc != 2)
     {
         printf("Usage: ./recover <file name>\n");
         return 1;
     }
     
     //Open file 
     FILE *input = fopen(argv[1], "r");
     if(!input)
     {
         printf("Could not open %s.\n", argv[1]);
         return 1;
     }
    //filename must hold 3 digits plus .jpeg and null charactor
    char *filename = malloc(sizeof(BYTE) * 8);
    //
    BYTE *buffer = malloc(sizeof(BYTE) * 512);
    
    //
    bool jpeg_found = false;
    
    //filecount for filenames
    int filecount = 0;
    
    //create file pointer 
    FILE *output = NULL;
    
    while(fread(buffer, sizeof(buffer), 1, input))
    {
        if(is_jpeg(buffer))
        {
            //create filename defined by filecount #
            sprintf(filename, "%03i.jpg", filecount);
            
            if(jpeg_found == true)
            {
                //first jpeg in buffer. close file
                fclose(output);
            }
            else
            {
                //set to true
                jpeg_found = true;
            }
            //open file and write block
            output = fopen(filename, "w");
            fwrite(buffer, sizeof(buffer), 1, output);
            
            filecount++;
        }
        //path if no new header is found && jpeg_found = true ---> continue writing blocks
        else
        {
            if(jpeg_found == true)
            {
                //write current block 
                fwrite(buffer, sizeof(buffer), 1, output);
            }
        }
        //continue checking card until EOF 
    }
    
    free(buffer);
    free(filename);
    fclose(output);
    fclose(input);
     
    return 0;
     
}


//confirm data is jpeg 
bool is_jpeg (BYTE *buffer)
{
    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}

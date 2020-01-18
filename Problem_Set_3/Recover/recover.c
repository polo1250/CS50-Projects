#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

//Defining a data type with one byte memory size
typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    // remember filename
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // variable state to detect when we reach end of the file, variable newone to determine if we reached jpeg files or not,
    // counter i that increment to be used in a new filename
    int state = 1, newone = 0, i = 0;

    // bloc, a pointer to an address that can hold 512 bytes, a filename pointer for each new filename to be created, and a
    // file pointer initialized to be used for each new jpeg file that will be created
    BYTE *bloc = malloc(512);
    char *filename = malloc(strlen("000.jpg") * sizeof(char));
    FILE *outptr = NULL;

    do
    {
        //check if we reached the end of file or not
        if (fread(bloc, 1, 512, inptr) != 512)
        {
            state = 0;
        }
        else
        {
            //check if it's the beginning of a new jpeg file and act accordingly wether it's the first one or not
            if (bloc[0] == 0xff && bloc[1] == 0xd8 && bloc[2] == 0xff && (bloc[3] & 0xf0) == 0xe0)
            {
                if (newone == 0)
                {
                    newone = 1;
                    sprintf(filename, "%03i.jpg", i);
                    FILE *newptr = fopen(filename, "w");
                    outptr = newptr;
                    fwrite(bloc, 512, 1, outptr);
                }
                else
                {
                    fclose(outptr);
                    sprintf(filename, "%03i.jpg", ++i);
                    FILE *newptr = fopen(filename, "w");
                    outptr = newptr;
                    fwrite(bloc, 512, 1, outptr);
                }
            }
            else
            {
                if (newone == 0)
                {
                    ;
                }
                else
                {
                    fwrite(bloc, 512, 1, outptr);
                }
            }
        }
        if (state == 0)
        {
            fclose(outptr);
        }
    }
    while (state == 1);

    // free all dynamic allocated variables
    free(bloc);
    free(filename);
    fclose(inptr);

    return 0;
}

// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

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
    /* 
    //TEST
    char c;
    printf("input content: \n");
    while ((c = fgetc(input)) != EOF)
    {
        printf("%c",c);
    }
    printf("\n");
    */
    // TODO: Copy header from input file to output file
    int8_t* buffer = malloc(HEADER_SIZE);
    fread(buffer, sizeof(int8_t), HEADER_SIZE, input);
    fwrite(buffer, sizeof(int8_t), HEADER_SIZE, output);
    free(buffer);

    float factor = atof(argv[3]);
    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer16;
    while (fread(&buffer16, sizeof(int16_t), 1, input))
    {
        buffer16 *= factor;
        printf("%u,",buffer16);
        fwrite(&buffer16, sizeof(int16_t), 1, output);
    }
    printf("\n");
    // Close files
    fclose(input);
    fclose(output);
}

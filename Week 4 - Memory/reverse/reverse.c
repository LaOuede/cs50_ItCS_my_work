#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    FILE *file;
    FILE *wav;
    WAVHEADER buf;
    int size = 0;

    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav");
        return (1);
    }

    // Open input file for reading
    // TODO #2
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Unable to open %s\n", argv[1]);
        return (1);
    }

    // Read header
    // TODO #3
    fread(&buf, sizeof(WAVHEADER), 1, file);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(buf) == 0)
    {
        printf("%s\n is not a WAV file", argv[2]);
        fclose(file);
        return (1);
    }

    // Open output file for writing
    // TODO #5
    wav = fopen(argv[2], "w");
    if (wav == NULL)
    {
        printf("Unable to open %s\n", argv[2]);
        fclose(file);
        return (1);
    }

    // Write header to file
    // TODO #6
    fwrite(&buf, sizeof(WAVHEADER), 1, wav);

    // Use get_block_size to calculate size of block
    // TODO #7
    size = get_block_size(buf);

    // Write reversed audio to file
    // TODO #8
    BYTE block[size];

    if (fseek(file, size, SEEK_END))
    {
        fclose(file);
        fclose(wav);
        return (1);
    }
    while (ftell(file) - size > sizeof(buf))
    {
        if (fseek(file, -2 * size, SEEK_CUR))
        {
            fclose(file);
            fclose(wav);
            return (1);
        }
        fread(block, size, 1, file);
        fwrite(block, size, 1, wav);
    }
    fclose(file);
    fclose(wav);
    return (0);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    // Ensure WAV format
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return (1);
    }
    return (0);
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    // Calculate size of block
    WORD bytesPerSample;

    bytesPerSample = (header.bitsPerSample / 8) * header.numChannels;
    return (bytesPerSample);
}
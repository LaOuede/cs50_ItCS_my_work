#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;

/*
    TOD0 :
    1) Open memory card
        FILE *f = fopen(filename, "r");
    2) Look for beginning of a JPEG
        Each JPEG starts with a distinct header :
            First 3 bytes = 0xff 0xd8 0xff
            Last byte = 0xe...
        JPEGs are stored back-to-back in memory card
        Each block is 512 bytes
        fread(data, size, number, inptr);
            data = pointer to where to store data you're reading
            size = size of each element to read
            number = number of element to read
            inptr = File * to read from
        Is a JPEG?
            buffer[0] == 0xff
            buffer[1] == 0xd8
            buffer[2] == 0xff
            (buffer[3] & 0xf0) == 0xe0
    3) Open a new JPEG file
        Making a new JPEG :
            Filenames : ###.jpg starting at 000.jpg
            sprintf(filename, "%03i.jpg", 2);
            FILE *img = fopen(filename, "w");
    4) Write 512 bytes until a new JPEG is found
        fwrite(data, size, number, outptr);
            data = pointer to bytes that will be written to file
            size = size of each element to write
            number = number of elements to write
            outptr = FILE * to write to
        fread returns the number of items of size "size" were read
    5) Pseudocode :
        Open memory card
        Repeat until end of card
            Read 512 bytes into a buffer
            If start of new JPEG
                If first JPEG
                    ...
                Else
                    ...
            Else
                If already found JPEG
                    ...
        Close any remaining files
*/

int main(int argc, char *argv[])
{
    int i = 0;
    int read = 512;
    BYTE buf[512];
    FILE *file;
    FILE *img;
    char *name = NULL;

    // Check for usage error
    if (argc != 2)
    {
        puts("Usage: ./recover IMAGE");
        return (1);
    }
    // Open memory card
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Unable to open %s\n", argv[1]);
        return (1);
    }
    // Repeat read until the end of file
    // Read 512 bytes into a buffer
    while (read == fread(buf, sizeof(BYTE), 512, file))
    {
        // Look for beginning of a JPEG
        if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xf0) == 0xe0)
        {
            // If it's the first image
            if (i == 0)
            {
                // Allocate memory for img name
                name = calloc(8, sizeof(char));
                // Generate file name
                sprintf(name, "%03i.jpg", i);
                // Open the file to write in
                img = fopen(name, "w");
                fwrite(&buf, sizeof(BYTE), 512, img);
                // Free allocated memory
                free(name);
                // Incremente i in order to pass from 000.jpg to 001.jpg
                i++;
            }
            // If it's not the first .jpg, close the file and open a new one
            // i is an index to write image file name
            else
            {
                fclose(img);
                name = calloc(8, sizeof(char));
                sprintf(name, "%03i.jpg", i);
                img = fopen(name, "w");
                fwrite(&buf, sizeof(BYTE), 512, img);
                free(name);
                i++;
            }
        }
        // If already found JPEG (aks beginning already found), continue to write in the .jpg file
        else if (i > 0)
        {
            fwrite(&buf, sizeof(BYTE), 512, img);
        }
    }
    // Close any remaining opened files
    fclose(img);
    fclose(file);
    return (0);
}
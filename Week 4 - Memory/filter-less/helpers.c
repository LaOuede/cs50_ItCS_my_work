#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float Blue;
    float Red;
    float Green;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            Blue = ((image[y][x].rgbtBlue + image[y][x].rgbtRed + image[y][x].rgbtGreen) / 3.0);
            Green = ((image[y][x].rgbtBlue + image[y][x].rgbtRed + image[y][x].rgbtGreen) / 3.0);
            Red = ((image[y][x].rgbtBlue + image[y][x].rgbtRed + image[y][x].rgbtGreen) / 3.0);
            Blue = round(Blue);
            Green = round(Green);
            Red = round(Red);
            image[y][x].rgbtBlue = Blue;
            image[y][x].rgbtGreen = Green;
            image[y][x].rgbtRed = Red;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float Blue;
    float Red;
    float Green;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            Blue = (image[y][x].rgbtBlue * .131 + image[y][x].rgbtRed * .272 + image[y][x].rgbtGreen * .534);
            if (Blue > 255)
            {
                Blue = 255;
            }
            Green = (image[y][x].rgbtBlue * .168 + image[y][x].rgbtRed * .349 + image[y][x].rgbtGreen * .686);
            if (Green > 255)
            {
                Green = 255;
            }
            Red = (image[y][x].rgbtBlue * .189 + image[y][x].rgbtRed * .393 + image[y][x].rgbtGreen * .769);
            if (Red > 255)
            {
                Red = 255;
            }
            Blue = round(Blue);
            Green = round(Green);
            Red = round(Red);
            image[y][x].rgbtBlue = Blue;
            image[y][x].rgbtGreen = Green;
            image[y][x].rgbtRed = Red;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    float tempBlue;
    float tempRed;
    float tempGreen;

    for (int y = 0; y < height; y++)
    {
        int counter = width - 1;
        for (int x = 0; x < width / 2; x++)
        {
            tempBlue = image[y][x].rgbtBlue;
            image[y][x].rgbtBlue = image[y][counter].rgbtBlue;
            image[y][counter].rgbtBlue = tempBlue;
            tempGreen = image[y][x].rgbtGreen;
            image[y][x].rgbtGreen = image[y][counter].rgbtGreen;
            image[y][counter].rgbtGreen = tempGreen;
            tempRed = image[y][x].rgbtRed;
            image[y][x].rgbtRed = image[y][counter].rgbtRed;
            image[y][counter].rgbtRed = tempRed;
            counter--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    float Blue;
    float Red;
    float Green;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            temp[y][x].rgbtBlue = image[y][x].rgbtBlue;
            temp[y][x].rgbtGreen = image[y][x].rgbtGreen;
            temp[y][x].rgbtRed = image[y][x].rgbtRed;
        }
    }
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            //edges
            if (x == 0 && y > 0 && y < height - 1)
            {
                Blue = (float)(temp[y - 1][x].rgbtBlue + temp[y - 1][x + 1].rgbtBlue + temp[y][x].rgbtBlue
                               + temp[y][x + 1].rgbtBlue + temp[y + 1][x].rgbtBlue + temp[y + 1][x + 1].rgbtBlue) / 6;
                Green = (float)(temp[y - 1][x].rgbtGreen + temp[y - 1][x + 1].rgbtGreen + temp[y][x].rgbtGreen
                                + temp[y][x + 1].rgbtGreen + temp[y + 1][x].rgbtGreen + temp[y + 1][x + 1].rgbtGreen) / 6;
                Red = (float)(temp[y - 1][x].rgbtRed + temp[y - 1][x + 1].rgbtRed + temp[y][x].rgbtRed
                              + temp[y][x + 1].rgbtRed + temp[y + 1][x].rgbtRed + temp[y + 1][x + 1].rgbtRed) / 6;
            }
            else if (y == 0 && x > 0 && x < width - 1)
            {
                Blue = (float)(temp[y][x - 1].rgbtBlue + temp[y][x].rgbtBlue + temp[y][x + 1].rgbtBlue
                               + temp[y + 1][x - 1].rgbtBlue + temp[y + 1][x].rgbtBlue + temp[y + 1][x + 1].rgbtBlue) / 6;
                Green = (float)(temp[y][x - 1].rgbtGreen + temp[y][x].rgbtGreen + temp[y][x + 1].rgbtGreen
                                + temp[y + 1][x - 1].rgbtGreen + temp[y + 1][x].rgbtGreen + temp[y + 1][x + 1].rgbtGreen) / 6;
                Red = (float)(temp[y][x - 1].rgbtRed + temp[y][x].rgbtRed + temp[y][x + 1].rgbtRed
                              + temp[y + 1][x - 1].rgbtRed + temp[y + 1][x].rgbtRed + temp[y + 1][x + 1].rgbtRed) / 6;
            }
            else if (x == width - 1 && y > 0 && y < height - 1)
            {
                Blue = (float)(temp[y - 1][x - 1].rgbtBlue + temp[y - 1][x].rgbtBlue
                               + temp[y][x - 1].rgbtBlue + temp[y][x].rgbtBlue
                               + temp[y + 1][x - 1].rgbtBlue + temp[y + 1][x].rgbtBlue) / 6;
                Green = (float)(temp[y - 1][x - 1].rgbtGreen + temp[y - 1][x].rgbtGreen
                                + temp[y][x - 1].rgbtGreen + temp[y][x].rgbtGreen
                                + temp[y + 1][x - 1].rgbtGreen + temp[y + 1][x].rgbtGreen) / 6;
                Red = (float)(temp[y - 1][x - 1].rgbtRed + temp[y - 1][x].rgbtRed
                              + temp[y][x - 1].rgbtRed + temp[y][x].rgbtRed
                              + temp[y + 1][x - 1].rgbtRed + temp[y + 1][x].rgbtRed) / 6;
            }
            else if (y == height - 1 && x > 0 && x < width - 1)
            {
                Blue = (float)(temp[y - 1][x - 1].rgbtBlue + temp[y - 1][x].rgbtBlue + temp[y - 1][x + 1].rgbtBlue
                               + temp[y][x - 1].rgbtBlue + temp[y][x].rgbtBlue + temp[y][x + 1].rgbtBlue) / 6;
                Green = (float)(temp[y - 1][x - 1].rgbtGreen + temp[y - 1][x].rgbtGreen + temp[y - 1][x + 1].rgbtGreen
                                + temp[y][x - 1].rgbtGreen + temp[y][x].rgbtGreen + temp[y][x + 1].rgbtGreen) / 6;
                Red = (float)(temp[y - 1][x - 1].rgbtRed + temp[y - 1][x].rgbtRed + temp[y - 1][x + 1].rgbtRed
                              + temp[y][x - 1].rgbtRed + temp[y][x].rgbtRed + temp[y][x + 1].rgbtRed) / 6;
            }
            //Corners
            else if (x == 0 && y == 0)
            {
                Blue = (float)(temp[y][x].rgbtBlue + temp[y][x + 1].rgbtBlue + temp[y + 1][x].rgbtBlue + temp[y + 1][x + 1].rgbtBlue) / 4;
                Green = (float)(temp[y][x].rgbtGreen + temp[y][x + 1].rgbtGreen + temp[y + 1][x].rgbtGreen + temp[y + 1][x + 1].rgbtGreen) / 4;
                Red = (float)(temp[y][x].rgbtRed + temp[y][x + 1].rgbtRed + temp[y + 1][x].rgbtRed + temp[y + 1][x + 1].rgbtRed) / 4;
            }
            else if (x == 0 && y == height - 1)
            {
                Blue = (float)(temp[y - 1][x].rgbtBlue + temp[y - 1][x + 1].rgbtBlue + temp[y][x].rgbtBlue + temp[y][x + 1].rgbtBlue) / 4;
                Green = (float)(temp[y - 1][x].rgbtGreen + temp[y - 1][x + 1].rgbtGreen + temp[y][x].rgbtGreen + temp[y][x + 1].rgbtGreen) / 4;
                Red = (float)(temp[y - 1][x].rgbtRed + temp[y - 1][x + 1].rgbtRed + temp[y][x].rgbtRed + temp[y][x + 1].rgbtRed) / 4;
            }
            else if (x == width - 1 && y == 0)
            {
                Blue = (float)(temp[y][x - 1].rgbtBlue + temp[y][x].rgbtBlue + temp[y + 1][x - 1].rgbtBlue + temp[y + 1][x].rgbtBlue) / 4;
                Green = (float)(temp[y][x - 1].rgbtGreen + temp[y][x].rgbtGreen + temp[y + 1][x - 1].rgbtGreen + temp[y + 1][x].rgbtGreen) / 4;
                Red = (float)(temp[y][x - 1].rgbtRed + temp[y][x].rgbtRed + temp[y + 1][x - 1].rgbtRed + temp[y + 1][x].rgbtRed) / 4;
            }
            else if (x == width - 1 && y == height - 1)
            {
                Blue = (float)(temp[y - 1][x - 1].rgbtBlue + temp[y - 1][x].rgbtBlue + temp[y][x - 1].rgbtBlue + temp[y][x].rgbtBlue) / 4;
                Green = (float)(temp[y - 1][x - 1].rgbtGreen + temp[y - 1][x].rgbtGreen + temp[y][x - 1].rgbtGreen + temp[y][x].rgbtGreen) / 4;
                Red = (float)(temp[y - 1][x - 1].rgbtRed + temp[y - 1][x].rgbtRed + temp[y][x - 1].rgbtRed + temp[y][x].rgbtRed) / 4;
            }
            //center
            else if (x > 0 && x < width - 1 && y > 0 && y < height - 1)
            {
                Blue = (float)(temp[y - 1][x - 1].rgbtBlue + temp[y - 1][x].rgbtBlue + temp[y - 1][x + 1].rgbtBlue
                               + temp[y][x - 1].rgbtBlue + temp[y][x].rgbtBlue + temp[y][x + 1].rgbtBlue
                               + temp[y + 1][x - 1].rgbtBlue + temp[y + 1][x].rgbtBlue + temp[y + 1][x + 1].rgbtBlue) / 9;
                Green = (float)(temp[y - 1][x - 1].rgbtGreen + temp[y - 1][x].rgbtGreen + temp[y - 1][x + 1].rgbtGreen
                                + temp[y][x - 1].rgbtGreen + temp[y][x].rgbtGreen + temp[y][x + 1].rgbtGreen
                                + temp[y + 1][x - 1].rgbtGreen + temp[y + 1][x].rgbtGreen + temp[y + 1][x + 1].rgbtGreen) / 9;
                Red = (float)(temp[y - 1][x - 1].rgbtRed + temp[y - 1][x].rgbtRed + temp[y - 1][x + 1].rgbtRed
                              + temp[y][x - 1].rgbtRed + temp[y][x].rgbtRed + temp[y][x + 1].rgbtRed
                              + temp[y + 1][x - 1].rgbtRed + temp[y + 1][x].rgbtRed + temp[y + 1][x + 1].rgbtRed) / 9;
            }
            Blue = round(Blue);
            Green = round(Green);
            Red = round(Red);
            image[y][x].rgbtBlue = Blue;
            image[y][x].rgbtGreen = Green;
            image[y][x].rgbtRed = Red;
        }
    }
    return;
}

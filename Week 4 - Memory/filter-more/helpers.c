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


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    float Blue;
    float Red;
    float Green;
    float Gx_Blue;
    float Gx_Red;
    float Gx_Green;
    float Gy_Blue;
    float Gy_Red;
    float Gy_Green;

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
                Gx_Blue = (float)((-1) * 0 + 0 * (temp[y - 1][x].rgbtBlue) + 1 * (temp[y - 1][x + 1].rgbtBlue)
                                  + (-2) * 0 + 0 * (temp[y][x].rgbtBlue) + 2 * (temp[y][x + 1].rgbtBlue)
                                  + (-1) * 0 + 0 * (temp[y + 1][x].rgbtBlue) + 1 * (temp[y + 1][x + 1].rgbtBlue));
                Gx_Green = (float)((-1) *  0 + 0 * (temp[y - 1][x].rgbtGreen) + 1 * (temp[y - 1][x + 1].rgbtGreen)
                                   + (-2) *  0 + 0 * (temp[y][x].rgbtGreen) + 2 * (temp[y][x + 1].rgbtGreen)
                                   + (-1) *  0 + 0 * (temp[y + 1][x].rgbtGreen) + 1 * (temp[y + 1][x + 1].rgbtGreen));
                Gx_Red = (float)((-1) *  0 + 0 * (temp[y - 1][x].rgbtRed) + 1 * (temp[y - 1][x + 1].rgbtRed)
                                 + (-2) *  0 + 0 * (temp[y][x].rgbtRed) + 2 * (temp[y][x + 1].rgbtRed)
                                 + (-1) *  0 + 0 * (temp[y + 1][x].rgbtRed) + 1 * (temp[y + 1][x + 1].rgbtRed));
                Gy_Blue = (float)((-1) *  0 + (-2) * (temp[y - 1][x].rgbtBlue) + (-1) * (temp[y - 1][x + 1].rgbtBlue)
                                  + 0 *  0 + 0 * (temp[y][x].rgbtBlue) + 0 * (temp[y][x + 1].rgbtBlue)
                                  + 1 *  0 + 2 * (temp[y + 1][x].rgbtBlue) + 1 * (temp[y + 1][x + 1].rgbtBlue));
                Gy_Green = (float)((-1) *  0 + (-2) * (temp[y - 1][x].rgbtGreen) + (-1) * (temp[y - 1][x + 1].rgbtGreen)
                                   + 0 *  0 + 0 * (temp[y][x].rgbtGreen) + 0 * (temp[y][x + 1].rgbtGreen)
                                   + 1 *  0 + 2 * (temp[y + 1][x].rgbtGreen) + 1 * (temp[y + 1][x + 1].rgbtGreen));
                Gy_Red = (float)((-1) *  0 + (-2) * (temp[y - 1][x].rgbtRed) + (-1) * (temp[y - 1][x + 1].rgbtRed)
                                 + 0 *  0 + 0 * (temp[y][x].rgbtRed) + 0 * (temp[y][x + 1].rgbtRed)
                                 + 1 *  0 + 2 * (temp[y + 1][x].rgbtRed) + 1 * (temp[y + 1][x + 1].rgbtRed));
                Blue = sqrt(pow(Gx_Blue, 2) + pow(Gy_Blue, 2));
                Green = sqrt(pow(Gx_Green, 2) + pow(Gy_Green, 2));
                Red = sqrt(pow(Gx_Red, 2) + pow(Gy_Red, 2));
            }
            else if (y == 0 && x > 0 && x < width - 1)
            {
                Gx_Blue = (float)((-1) * 0 + 0 * 0 + 1 * 0
                                  + (-2) * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 2 * (temp[y][x + 1].rgbtGreen)
                                  + (-1) * (temp[y + 1][x - 1].rgbtGreen) + 0 * (temp[y + 1][x].rgbtGreen) + 1 * (temp[y + 1][x + 1].rgbtGreen));
                Gx_Green = (float)((-1) * 0 + 0 * 0 + 1 * 0
                                   + (-2) * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 2 * (temp[y][x + 1].rgbtGreen)
                                   + (-1) * (temp[y + 1][x - 1].rgbtGreen) + 0 * (temp[y + 1][x].rgbtGreen) + 1 * (temp[y + 1][x + 1].rgbtGreen));
                Gx_Red = (float)((-1) * 0 + 0 * 0 + 1 * 0
                                 + (-2) * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 2 * (temp[y][x + 1].rgbtRed)
                                 + (-1) * (temp[y + 1][x - 1].rgbtRed) + 0 * (temp[y + 1][x].rgbtRed) + 1 * (temp[y + 1][x + 1].rgbtRed));
                Gy_Blue = (float)((-1) * 0 + (-2) * 0 + (-1) * 0
                                  + 0 * (temp[y][x - 1].rgbtBlue) + 0 * (temp[y][x].rgbtBlue) + 0 * (temp[y][x + 1].rgbtBlue)
                                  + 1 * (temp[y + 1][x - 1].rgbtBlue) + 2 * (temp[y + 1][x].rgbtBlue) + 1 * (temp[y + 1][x + 1].rgbtBlue));
                Gy_Green = (float)((-1) * 0 + (-2) * 0 + (-1) * 0
                                   + 0 * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 0 * (temp[y][x + 1].rgbtGreen)
                                   + 1 * (temp[y + 1][x - 1].rgbtGreen) + 2 * (temp[y + 1][x].rgbtGreen) + 1 * (temp[y + 1][x + 1].rgbtGreen));
                Gy_Red = (float)((-1) * 0 + (-2) * 0 + (-1) * 0
                                 + 0 * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 0 * (temp[y][x + 1].rgbtRed)
                                 + 1 * (temp[y + 1][x - 1].rgbtRed) + 2 * (temp[y + 1][x].rgbtRed) + 1 * (temp[y + 1][x + 1].rgbtRed));
                Blue = sqrt(pow(Gx_Blue, 2) + pow(Gy_Blue, 2));
                Green = sqrt(pow(Gx_Green, 2) + pow(Gy_Green, 2));
                Red = sqrt(pow(Gx_Red, 2) + pow(Gy_Red, 2));
            }
            else if (x == width - 1 && y > 0 && y < height - 1)
            {
                Gx_Blue = (float)((-1) * (temp[y - 1][x - 1].rgbtBlue) + 0 * (temp[y - 1][x].rgbtBlue) + 1 * 0
                                  + (-2) * (temp[y][x - 1].rgbtBlue) + 0 * (temp[y][x].rgbtBlue) + 2 * 0
                                  + (-1) * (temp[y + 1][x - 1].rgbtBlue) + 0 * (temp[y + 1][x].rgbtBlue) + 1 * 0);
                Gx_Green = (float)((-1) * (temp[y - 1][x - 1].rgbtGreen) + 0 * (temp[y - 1][x].rgbtGreen) + 1 * 0
                                   + (-2) * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 2 * 0
                                   + (-1) * (temp[y + 1][x - 1].rgbtGreen) + 0 * (temp[y + 1][x].rgbtGreen) + 1 * 0);
                Gx_Red = (float)((-1) * (temp[y - 1][x - 1].rgbtRed) + 0 * (temp[y - 1][x].rgbtRed) + 1 * 0
                                 + (-2) * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 2 * 0
                                 + (-1) * (temp[y + 1][x - 1].rgbtRed) + 0 * (temp[y + 1][x].rgbtRed) + 1 * 0);
                Gy_Blue = (float)((-1) * (temp[y - 1][x - 1].rgbtBlue) + (-2) * (temp[y - 1][x].rgbtBlue) + (-1) * 0
                                  + 0 * (temp[y][x - 1].rgbtBlue) + 0 * (temp[y][x].rgbtBlue) + 0 * 0
                                  + 1 * (temp[y + 1][x - 1].rgbtBlue) + 2 * (temp[y + 1][x].rgbtBlue) + 1 * 0);
                Gy_Green = (float)((-1) * (temp[y - 1][x - 1].rgbtGreen) + (-2) * (temp[y - 1][x].rgbtGreen) + (-1) * 0
                                   + 0 * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 0 * 0
                                   + 1 * (temp[y + 1][x - 1].rgbtGreen) + 2 * (temp[y + 1][x].rgbtGreen) + 1 * 0);
                Gy_Red = (float)((-1) * (temp[y - 1][x - 1].rgbtRed) + (-2) * (temp[y - 1][x].rgbtRed) + (-1) * 0
                                 + 0 * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 0 * 0
                                 + 1 * (temp[y + 1][x - 1].rgbtRed) + 2 * (temp[y + 1][x].rgbtRed) + 1 * 0);
                Blue = sqrt(pow(Gx_Blue, 2) + pow(Gy_Blue, 2));
                Green = sqrt(pow(Gx_Green, 2) + pow(Gy_Green, 2));
                Red = sqrt(pow(Gx_Red, 2) + pow(Gy_Red, 2));
            }
            else if (y == height - 1 && x > 0 && x < width - 1)
            {
                Gx_Blue = (float)((-1) * (temp[y - 1][x - 1].rgbtBlue) + 0 * (temp[y - 1][x].rgbtBlue) + 1 * (temp[y - 1][x + 1].rgbtBlue)
                                  + (-2) * (temp[y][x - 1].rgbtBlue) + 0 * (temp[y][x].rgbtBlue) + 2 * (temp[y][x + 1].rgbtBlue)
                                  + (-1) * 0 + 0 * 0 + 1 * 0);
                Gx_Green = (float)((-1) * (temp[y - 1][x - 1].rgbtGreen) + 0 * (temp[y - 1][x].rgbtGreen) + 1 * (temp[y - 1][x + 1].rgbtGreen)
                                   + (-2) * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 2 * (temp[y][x + 1].rgbtGreen)
                                   + (-1) * 0 + 0 * 0 + 1 * 0);
                Gx_Red = (float)((-1) * (temp[y - 1][x - 1].rgbtRed) + 0 * (temp[y - 1][x].rgbtRed) + 1 * (temp[y - 1][x + 1].rgbtRed)
                                 + (-2) * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 2 * (temp[y][x + 1].rgbtRed)
                                 + (-1) * 0 + 0 * 0 + 1 * 0);
                Gy_Blue = (float)((-1) * (temp[y - 1][x - 1].rgbtBlue) + (-2) * (temp[y - 1][x].rgbtBlue) + (-1) * (temp[y - 1][x + 1].rgbtBlue)
                                  + 0 * (temp[y][x - 1].rgbtBlue) + 0 * (temp[y][x].rgbtBlue) + 0 * (temp[y][x + 1].rgbtBlue)
                                  + 1 * 0 + 2 * 0 + 1 * 0);
                Gy_Green = (float)((-1) * (temp[y - 1][x - 1].rgbtGreen) + (-2) * (temp[y - 1][x].rgbtGreen) + (-1) * (temp[y - 1][x + 1].rgbtGreen)
                                   + 0 * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 0 * (temp[y][x + 1].rgbtGreen)
                                   + 1 * 0 + 2 * 0 + 1 * 0);
                Gy_Red = (float)((-1) * (temp[y - 1][x - 1].rgbtRed) + (-2) * (temp[y - 1][x].rgbtRed) + (-1) * (temp[y - 1][x + 1].rgbtRed)
                                 + 0 * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 0 * (temp[y][x + 1].rgbtRed)
                                 + 1 * 0 + 2 * 0 + 1 * 0);
                Blue = sqrt(pow(Gx_Blue, 2) + pow(Gy_Blue, 2));
                Green = sqrt(pow(Gx_Green, 2) + pow(Gy_Green, 2));
                Red = sqrt(pow(Gx_Red, 2) + pow(Gy_Red, 2));
            }
            //Corners
            else if (x == 0 && y == 0)
            {
                Gx_Blue = (float)((-1) * 0 + 0 * 0 + 1 * 0
                                  + (-2) * 0 + 0 * (temp[y][x].rgbtBlue) + 2 * (temp[y][x + 1].rgbtBlue)
                                  + (-1) * 0 + 0 * (temp[y + 1][x].rgbtBlue) + 1 * (temp[y + 1][x + 1].rgbtBlue));
                Gx_Green = (float)((-1) * 0 + 0 * 0 + 1 * 0
                                   + (-2) * 0 + 0 * (temp[y][x].rgbtGreen) + 2 * (temp[y][x + 1].rgbtGreen)
                                   + (-1) * 0 + 0 * (temp[y + 1][x].rgbtGreen) + 1 * (temp[y + 1][x + 1].rgbtGreen));
                Gx_Red = (float)((-1) * 0 + 0 * 0 + 1 * 0
                                 + (-2) * 0 + 0 * (temp[y][x].rgbtRed) + 2 * (temp[y][x + 1].rgbtRed)
                                 + (-1) * 0 + 0 * (temp[y + 1][x].rgbtRed) + 1 * (temp[y + 1][x + 1].rgbtRed));
                Gy_Blue = (float)((-1) * 0 + (-2) * 0 + (-1) * 0
                                  + 0 * 0 + 0 * (temp[y][x].rgbtBlue) + 0 * (temp[y][x + 1].rgbtBlue)
                                  + 1 * 0 + 2 * (temp[y + 1][x].rgbtBlue) + 1 * (temp[y + 1][x + 1].rgbtBlue));
                Gy_Green = (float)((-1) * 0 + (-2) * 0 + (-1) * 0
                                   + 0 * 0 + 0 * (temp[y][x].rgbtGreen) + 0 * (temp[y][x + 1].rgbtGreen)
                                   + 1 * 0 + 2 * (temp[y + 1][x].rgbtGreen) + 1 * (temp[y + 1][x + 1].rgbtGreen));
                Gy_Red = (float)((-1) * 0 + (-2) * 0 + (-1) * 0
                                 + 0 * 0 + 0 * (temp[y][x].rgbtRed) + 0 * (temp[y][x + 1].rgbtRed)
                                 + 1 * 0 + 2 * (temp[y + 1][x].rgbtRed) + 1 * (temp[y + 1][x + 1].rgbtRed));
                Blue = sqrt(pow(Gx_Blue, 2) + pow(Gy_Blue, 2));
                Green = sqrt(pow(Gx_Green, 2) + pow(Gy_Green, 2));
                Red = sqrt(pow(Gx_Red, 2) + pow(Gy_Red, 2));
            }
            else if (x == 0 && y == height - 1)
            {
                Gx_Blue = (float)((-1) * 0 + 0 * (temp[y - 1][x].rgbtBlue) + 1 * (temp[y - 1][x + 1].rgbtBlue)
                                  + (-2) * 0 + 0 * (temp[y][x].rgbtBlue) + 2 * (temp[y][x + 1].rgbtBlue)
                                  + (-1) * 0 + 0 * 0 + 1 * 0);
                Gx_Green = (float)((-1) * 0 + 0 * (temp[y - 1][x].rgbtGreen) + 1 * (temp[y - 1][x + 1].rgbtGreen)
                                   + (-2) * 0 + 0 * (temp[y][x].rgbtGreen) + 2 * (temp[y][x + 1].rgbtGreen)
                                   + (-1) * 0 + 0 * 0 + 1 * 0);
                Gx_Red = (float)((-1) * 0 + 0 * (temp[y - 1][x].rgbtRed) + 1 * (temp[y - 1][x + 1].rgbtRed)
                                 + (-2) * 0 + 0 * (temp[y][x].rgbtRed) + 2 * (temp[y][x + 1].rgbtRed)
                                 + (-1) * 0 + 0 * 0 + 1 * 0);
                Gy_Blue = (float)((-1) * 0 + (-2) * (temp[y - 1][x].rgbtBlue) + (-1) * (temp[y - 1][x + 1].rgbtBlue)
                                  + 0 * 0 + 0 * (temp[y][x].rgbtBlue) + 0 * (temp[y][x + 1].rgbtBlue)
                                  + 1 * 0 + 2 * 0 + 1 * 0);
                Gy_Green = (float)((-1) * 0 + (-2) * (temp[y - 1][x].rgbtGreen) + (-1) * (temp[y - 1][x + 1].rgbtGreen)
                                   + 0 * 0 + 0 * (temp[y][x].rgbtGreen) + 0 * (temp[y][x + 1].rgbtGreen)
                                   + 1 * 0 + 2 * 0 + 1 * 0);
                Gy_Red = (float)((-1) * 0 + (-2) * (temp[y - 1][x].rgbtRed) + (-1) * (temp[y - 1][x + 1].rgbtRed)
                                 + 0 * 0 + 0 * (temp[y][x].rgbtRed) + 0 * (temp[y][x + 1].rgbtRed)
                                 + 1 * 0 + 2 * 0 + 1 * 0);
                Blue = sqrt(pow(Gx_Blue, 2) + pow(Gy_Blue, 2));
                Green = sqrt(pow(Gx_Green, 2) + pow(Gy_Green, 2));
                Red = sqrt(pow(Gx_Red, 2) + pow(Gy_Red, 2));
            }
            else if (x == width - 1 && y == 0)
            {
                Gx_Blue = (float)((-1) * 0 + 0 * 0 + 1 * 0
                                  + (-2) * (temp[y][x - 1].rgbtBlue) + 0 * (temp[y][x].rgbtBlue) + 2 * 0
                                  + (-1) * (temp[y + 1][x - 1].rgbtBlue) + 0 * (temp[y + 1][x].rgbtBlue) + 1 * 0);
                Gx_Green = (float)((-1) * 0 + 0 * 0 + 1 * 0
                                   + (-2) * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 2 * 0
                                   + (-1) * (temp[y + 1][x - 1].rgbtGreen) + 0 * (temp[y + 1][x].rgbtGreen) + 1 * 0);
                Gx_Red = (float)((-1) * 0 + 0 * 0 + 1 * 0
                                 + (-2) * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 2 * 0
                                 + (-1) * (temp[y + 1][x - 1].rgbtRed) + 0 * (temp[y + 1][x].rgbtRed) + 1 * 0);
                Gy_Blue = (float)((-1) * 0 + (-2) * 0 + (-1) * 0
                                  + 0 * (temp[y][x - 1].rgbtBlue) + 0 * (temp[y][x].rgbtBlue) + 0 * 0
                                  + 1 * (temp[y + 1][x - 1].rgbtBlue) + 2 * (temp[y + 1][x].rgbtBlue) + 1 * 0);
                Gy_Green = (float)((-1) * 0 + (-2) * 0 + (-1) * 0
                                   + 0 * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 0 * 0
                                   + 1 * (temp[y + 1][x - 1].rgbtGreen) + 2 * (temp[y + 1][x].rgbtGreen) + 1 * 0);
                Gy_Red = (float)((-1) * 0 + (-2) * 0 + (-1) * 0
                                 + 0 * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 0 * 0
                                 + 1 * (temp[y + 1][x - 1].rgbtRed) + 2 * (temp[y + 1][x].rgbtRed) + 1 * 0);
                Blue = sqrt(pow(Gx_Blue, 2) + pow(Gy_Blue, 2));
                Green = sqrt(pow(Gx_Green, 2) + pow(Gy_Green, 2));
                Red = sqrt(pow(Gx_Red, 2) + pow(Gy_Red, 2));
            }
            else if (x == width - 1 && y == height - 1)
            {
                Gx_Blue = (float)((-1) * (temp[y - 1][x - 1].rgbtBlue) + 0 * (temp[y - 1][x].rgbtBlue) + 1 * 0
                                  + (-2) * (temp[y][x - 1].rgbtBlue) + 0 * (temp[y][x].rgbtBlue) + 2 * 0
                                  + (-1) * 0 + 0 * 0 + 1 * 0);
                Gx_Green = (float)((-1) * (temp[y - 1][x - 1].rgbtGreen) + 0 * (temp[y - 1][x].rgbtGreen) + 1 * 0
                                   + (-2) * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 2 * 0
                                   + (-1) * 0 + 0 * 0 + 1 * 0);
                Gx_Red = (float)((-1) * (temp[y - 1][x - 1].rgbtRed) + 0 * (temp[y - 1][x].rgbtRed) + 1 * 0
                                 + (-2) * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 2 * 0
                                 + (-1) * 0 + 0 * 0 + 1 * 0);
                Gy_Blue = (float)((-1) * (temp[y - 1][x - 1].rgbtBlue) + (-2) * (temp[y - 1][x].rgbtBlue) + (-1) * 0
                                  + 0 * (temp[y][x - 1].rgbtBlue) + 0 * (temp[y][x].rgbtBlue) + 0 * 0
                                  + 1 * 0 + 2 * 0 + 1 * 0);
                Gy_Green = (float)((-1) * (temp[y - 1][x - 1].rgbtGreen) + (-2) * (temp[y - 1][x].rgbtGreen) + (-1) * 0
                                   + 0 * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 0 * 0
                                   + 1 * 0 + 2 * 0 + 1 * 0);
                Gy_Red = (float)((-1) * (temp[y - 1][x - 1].rgbtRed) + (-2) * (temp[y - 1][x].rgbtRed) + (-1) * 0
                                 + 0 * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 0 * 0
                                 + 1 * 0 + 2 * 0 + 1 * 0);
                Blue = sqrt(pow(Gx_Blue, 2) + pow(Gy_Blue, 2));
                Green = sqrt(pow(Gx_Green, 2) + pow(Gy_Green, 2));
                Red = sqrt(pow(Gx_Red, 2) + pow(Gy_Red, 2));
            }
            //center
            if (x > 0 && x < width - 1 && y > 0 && y < height - 1)
            {
                Gx_Blue = (float)((-1) * (temp[y - 1][x - 1].rgbtBlue) + 0 * (temp[y - 1][x].rgbtBlue) + 1 * (temp[y - 1][x + 1].rgbtBlue)
                                  + (-2) * (temp[y][x - 1].rgbtBlue) + 0 * (temp[y][x].rgbtBlue) + 2 * (temp[y][x + 1].rgbtBlue)
                                  + (-1) * (temp[y + 1][x - 1].rgbtBlue) + 0 * (temp[y + 1][x].rgbtBlue) + 1 * (temp[y + 1][x + 1].rgbtBlue));
                Gx_Green = (float)((-1) * (temp[y - 1][x - 1].rgbtGreen) + 0 * (temp[y - 1][x].rgbtGreen) + 1 * (temp[y - 1][x + 1].rgbtGreen)
                                   + (-2) * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 2 * (temp[y][x + 1].rgbtGreen)
                                   + (-1) * (temp[y + 1][x - 1].rgbtGreen) + 0 * (temp[y + 1][x].rgbtGreen) + 1 * (temp[y + 1][x + 1].rgbtGreen));
                Gx_Red = (float)((-1) * (temp[y - 1][x - 1].rgbtRed) + 0 * (temp[y - 1][x].rgbtRed) + 1 * (temp[y - 1][x + 1].rgbtRed)
                                 + (-2) * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 2 * (temp[y][x + 1].rgbtRed)
                                 + (-1) * (temp[y + 1][x - 1].rgbtRed) + 0 * (temp[y + 1][x].rgbtRed) + 1 * (temp[y + 1][x + 1].rgbtRed));
                Gy_Blue = (float)((-1) * (temp[y - 1][x - 1].rgbtBlue) + (-2) * (temp[y - 1][x].rgbtBlue) + (-1) * (temp[y - 1][x + 1].rgbtBlue)
                                  + 0 * (temp[y][x - 1].rgbtBlue) + 0 * (temp[y][x].rgbtBlue) + 0 * (temp[y][x + 1].rgbtBlue)
                                  + 1 * (temp[y + 1][x - 1].rgbtBlue) + 2 * (temp[y + 1][x].rgbtBlue) + 1 * (temp[y + 1][x + 1].rgbtBlue));
                Gy_Green = (float)((-1) * (temp[y - 1][x - 1].rgbtGreen) + (-2) * (temp[y - 1][x].rgbtGreen) + (-1) * (temp[y - 1][x + 1].rgbtGreen)
                                   + 0 * (temp[y][x - 1].rgbtGreen) + 0 * (temp[y][x].rgbtGreen) + 0 * (temp[y][x + 1].rgbtGreen)
                                   + 1 * (temp[y + 1][x - 1].rgbtGreen) + 2 * (temp[y + 1][x].rgbtGreen) + 1 * (temp[y + 1][x + 1].rgbtGreen));
                Gy_Red = (float)((-1) * (temp[y - 1][x - 1].rgbtRed) + (-2) * (temp[y - 1][x].rgbtRed) + (-1) * (temp[y - 1][x + 1].rgbtRed)
                                 + 0 * (temp[y][x - 1].rgbtRed) + 0 * (temp[y][x].rgbtRed) + 0 * (temp[y][x + 1].rgbtRed)
                                 + 1 * (temp[y + 1][x - 1].rgbtRed) + 2 * (temp[y + 1][x].rgbtRed) + 1 * (temp[y + 1][x + 1].rgbtRed));
                Blue = sqrt(pow(Gx_Blue, 2) + pow(Gy_Blue, 2));
                Green = sqrt(pow(Gx_Green, 2) + pow(Gy_Green, 2));
                Red = sqrt(pow(Gx_Red, 2) + pow(Gy_Red, 2));
            }
            Blue = round(Blue);
            Green = round(Green);
            Red = round(Red);
            if (Blue > 255)
            {
                Blue = 255;
            }
            if (Red > 255)
            {
                Red = 255;
            }
            if (Green > 255)
            {
                Green = 255;
            }
            image[y][x].rgbtBlue = Blue;
            image[y][x].rgbtGreen = Green;
            image[y][x].rgbtRed = Red;
        }
    }
    return;
}


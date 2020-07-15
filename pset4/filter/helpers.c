#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE color = image[i][j];

            int media = round((color.rgbtBlue + color.rgbtGreen + color.rgbtRed) / 3.000);

            image[i][j].rgbtRed = media;
            image[i][j].rgbtGreen = media;
            image[i][j].rgbtBlue = media;
        }
    }
}

int max_value(int pxl)
{
    if(pxl > 255)
    {

       pxl = 255;

    }

    return pxl;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE color = image[i][j];

                image[i][j].rgbtRed =  max_value(round(0.393 * color.rgbtRed + 0.769 * color.rgbtGreen + 0.189 * color.rgbtBlue));
                image[i][j].rgbtGreen =  max_value(round(0.349 * color.rgbtRed + 0.686 * color.rgbtGreen + 0.168 * color.rgbtBlue));
                image[i][j].rgbtBlue =  max_value(round(0.272 * color.rgbtRed + 0.534 * color.rgbtGreen + 0.131 * color.rgbtBlue));

        }
    }
}

void swp(RGBTRIPLE * color1, RGBTRIPLE * color2)
{
    RGBTRIPLE tmp = *color1;
    *color1 = *color2;
    *color2 = tmp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
   for (int i = 0; i < height; i++)
   {
       for (int j = 0; j < width / 2; j++)
       {
            swp(&image[i][j], &image[i][width - 1 - j]);
       }


   }
}

bool is_valid_pixel(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

RGBTRIPLE get_blurred_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width] )
{
    int redValue, greenValue, blueValue; redValue = greenValue = blueValue = 0;
    int numberOfValidPixels = 0;

    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int new_i = i + di;
            int new_j = j + dj;
            if (is_valid_pixel(new_i, new_j , height, width))
            {
                numberOfValidPixels++;
                redValue += image[new_i][new_j].rgbtRed;
                blueValue += image[new_i][new_j].rgbtBlue;
                greenValue += image[new_i][new_j].rgbtGreen;
            }
        }
    }

    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round ((float) redValue / numberOfValidPixels);
    blurred_pixel.rgbtGreen = round ((float) greenValue / numberOfValidPixels);
    blurred_pixel.rgbtBlue = round ((float) blueValue / numberOfValidPixels);

    return blurred_pixel;


}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
        {
            for ( int j = 0; j < width; j++)
            {
                new_image[i][j] = get_blurred_pixel(i, j, height, width, image);
            }
        }

    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                image[i][j] = new_image[i][j];
            }
        }

}

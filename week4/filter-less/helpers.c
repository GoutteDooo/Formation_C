#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Parcourir tout les pixels de l'image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Pour chaque pixel, faire la moyenne des trois couleurs
            double red = image[i][j].rgbtRed;
            double green = image[i][j].rgbtGreen;
            double blue = image[i][j].rgbtBlue;
            double avg = (red + green + blue) / 3;
            // printf("avg= %f\n",avg);
            //Puis, ajouter cette moyenne dans chacune des couleurs pour donner un niveau de gris
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Parcourir tout les pixels de l'image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Pour chaque pixel
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;
            int rs = (0.393 * red) + (0.769 * green) + (0.189 * blue);
            int gs = (0.349 * red) + (0.686 * green) + (0.168 * blue);
            int bs = (0.272 * red) + (0.534 * green) + (0.131 * blue);
            // printf("avg= %f\n",avg);
            //Puis, ajouter cette moyenne dans chacune des couleurs pour donner un niveau de gris
            image[i][j].rgbtRed = rs > 255 ? 255 : rs;
            image[i][j].rgbtGreen = gs > 255 ? 255 : gs;
            image[i][j].rgbtBlue = bs > 255 ? 255 : bs;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Pour chaque pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, reverse_j = width - 1; j < width; j++,reverse_j--)
        {
            //switch, pixel par pixel, sur la colonne opposée
            if (j >= reverse_j)
            {
                break;
            }
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][reverse_j];
            image[i][reverse_j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    printf("blur...\n");
    
    return;
}

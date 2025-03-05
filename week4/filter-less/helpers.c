#include "helpers.h"
#include <stdio.h>
#include <math.h>

RGBTRIPLE avg_boxes(int x, int y, int h, int w, RGBTRIPLE image[h][w]);


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Parcourir tout les pixels de l'image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Pour chaque pixel, faire la moyenne des trois couleurs
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;
            float avg = (red + green + blue) / 3;
            // printf("avg= %f\n",avg);
            //Puis, ajouter cette moyenne dans chacune des couleurs pour donner un niveau de gris
            image[i][j].rgbtRed = round(avg);
            image[i][j].rgbtGreen = round(avg);
            image[i][j].rgbtBlue = round(avg);
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
            float rs = (0.393 * red) + (0.769 * green) + (0.189 * blue);
            float gs = (0.349 * red) + (0.686 * green) + (0.168 * blue);
            float bs = (0.272 * red) + (0.534 * green) + (0.131 * blue);
            // printf("avg= %f\n",avg);
            //Puis, ajouter cette moyenne dans chacune des couleurs pour donner un niveau de gris
            image[i][j].rgbtRed = rs > 255 ? 255 : round(rs);
            image[i][j].rgbtGreen = gs > 255 ? 255 : round(gs);
            image[i][j].rgbtBlue = bs > 255 ? 255 : round(bs);
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
    // printf("blur...\n");
    //Create a copy of image
    RGBTRIPLE copy[height][width];
    //Pour chaque pixel
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            //Modifier le pixel
            copy[x][y] = avg_boxes(x, y, height, width, image);
        }
    }
    //On assigne l'image à la copie
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            //Modifier le pixel
            image[x][y] = copy[x][y];
        }
    }
    return;
}

/**
    Sélectionne tout les pixels existants autour du pixel sélectionné par défaut
    et renvoie la moyenne de la sélection
*/
RGBTRIPLE avg_boxes(int x, int y, int h, int w, RGBTRIPLE image[h][w])
{
    //Sélectionne le box 3*3 autour, incluant le pixel sélectionné par défaut
    int x_area[2] = {-1, 1};
    int y_area[2] = {-1, 1};
    //Interdire sélection avant x = 0, y = 0 et x = width - 1 et  y = width - 1
    if (x - 1 < 0) x_area[0] = 0;
    if (y - 1 < 0) y_area[0] = 0;
    if (x + 1 == h) x_area[1] = 0;
    if (y + 1 == w) y_area[1] = 0;
    //Inclu tout les pixels
    RGBTRIPLE avg;
    avg.rgbtRed = 0;
    avg.rgbtGreen = 0;
    avg.rgbtBlue = 0;
    int red = 0;
    int green = 0;
    int blue = 0;
    int count = 0;
    for (int i = x_area[0]; i <= x_area[1] ; i++)
    {
        for (int j = y_area[0]; j <= y_area[1]; j++)
        {
            red += image[x + i][y + j].rgbtRed;
            green += image[x + i][y + j].rgbtGreen;
            blue += image[x + i][y + j].rgbtBlue;
            count++;
        }
    }
    //avg contient actuellement la somme des pixels sélectionné
    // printf("px before div (rgb): %x %x %x\n", avg.rgbtRed,avg.rgbtGreen,avg.rgbtBlue); 
    float fred = (red / count) > 255 ? 255 : (red / count);
    float fgreen = (green / count) > 255 ? 255 : (green / count);
    float fblue = (blue / count) > 255 ? 255 : (blue / count);
    avg.rgbtRed = round(fred);
    avg.rgbtGreen = round(fgreen);
    avg.rgbtBlue = round(fblue);
    // printf("px after div (rgb): %x %x %x\n", avg.rgbtRed,avg.rgbtGreen,avg.rgbtBlue);
    //Calculer la moyenne et la retourner
    return avg;
}
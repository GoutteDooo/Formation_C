#include "helpers.h"
#include <stdio.h>

int avg_boxes(RGBTRIPLE pixel[int x][int y], int h, int w);


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
    //Create a copy of image
    RGBTRIPLE copy[height][width];
    //Pour chaque pixel
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            //Modifier le pixel
            copy[x][y] = avg_boxes(image[x][y], height, width);
        }
    }
    return;
}

/**
/* Sélectionne tout les pixels existants autour du pixel sélectionné par défaut
/* et renvoie la moyenne de la sélection
*/
int avg_boxes(RGBTRIPLE pixel[int x][int y], int h, int w)
{
    //Sélectionne le box 3*3 autour, incluant le pixel sélectionné par défaut
    int x_area[2] = {-1, 1};
    int y _area[2] = {-1, 1};
    //Interdire sélection avant x = 0, y = 0 et x = width - 1 et  y = width - 1
    if (x - 1 < 0) x_area[0] = 0;
    if (y - 1 < 0) y_area[0] = 0;
    if (x + 1 == w) x_area[1] = 0;
    if (y + 1 == h) y_area[1] = 0;
    //Inclu tout les pixels
    int avg = 0;
    int count = 0
    for (int i = x_area[0]; i <= x_area[1] ; i++)
    {
        for (int j = y_area[0]; j <= y_area[1]; j++)
        {
            avg += pixel[x + i][x + j];
            count++;
        }
    }
    //avg contient actuellement la somme des pixels sélectionné
    //Calculer la moyenne et la retourner
    return (avg / count);
}
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef __int8_t BYTE;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./recover FILE\n");
    return 1;
  }
  char *infile = argv[1];
  FILE* card = fopen(infile, "r");
  if (card == NULL)
  {
      printf("Could not open %s.\n", infile);
      return 1;
  }
  //Rechercher par paquets de 512 B (stockés dans un buffer)
  uint8_t search[512];
  int count = 0;
  int8_t has_printed = 0;
  //Une fois le fichier ouvert, le parcourir et trouver une signature JPEG (ffd8ffe?) -> 4 first B of block of 512 B
  while (has_printed || fread(search, 512, 1, card))
  {
    has_printed = 0;
    //Une fois une signature trouvée, créer un fichier avec pour nom "###.jpg" (démarrer a 000.jpg et incrémenter à chaque trouvaille)
    if (search[0] == 0xff && search[1] == 0xd8 && search[2] == 0xff && (search[3] & 0xF0) == 0xE0)
    {
      //Signature JPEG trouvée
      count++;
      printf("Jpeg found : %i\n", count);

      //On crée le nouveau fichier JPEG
      char* name = malloc(30);
      sprintf(name, "recovered_dir/%i.jpg", count);
      FILE* newJPG = fopen(name, "w");

      //Ecrire dans le nouveau fichier jusqu'à trouver une nouvelle signature JPEG
      do
      {
        fwrite(search, 512,1,newJPG);
        fread(search, 512, 1, card);
        if (feof(card)) break;
      } while (!(search[0] == 0xff && search[1] == 0xd8 && search[2] == 0xff && (search[3] & 0xF0) == 0xE0));
      //sortie de la boucle : Nouvelle signature JPEG trouvée
      has_printed = 1;
      free(name);
      fclose(newJPG);
    }
    if (feof(card)) break;
  }
  //Remplir le nouveau fichier jusqu'à trouver une prochaine signature JPEG ou arriver à la fin de la lecture
  /* TEST LECTURE
  __int16_t b;
  while ((b = fgetc(card)) != EOF)
  {
    if (b == 0xff) {
      printf("%x",b);
    }
  }
  */
  printf("\n");
  fclose(card);
}
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
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
  BYTE search[512];
  //Une fois le fichier ouvert, le parcourir et trouver une signature JPEG (ffd8ffe?) -> 4 first B of block of 512 B
  while (fread(search, 512, 1, card))
  {
    
  }
  //Une fois une signature trouvée, créer un fichier avec pour nom "###.jpg" (démarrer a 000.jpg et incrémenter à chaque trouvaille)
  //Remplir le nouveau fichier jusqu'à trouver une prochaine signature JPEG ou arriver à la fin de la lecture
  __int16_t b;
  while ((b = fgetc(card)) != EOF)
  {
    if (b == 0xff) {
      printf("%x",b);
    }
  }
  printf("\n");
  fclose(card);
}
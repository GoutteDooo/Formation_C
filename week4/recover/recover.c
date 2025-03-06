#include <stdint.h>
#include <stdio.h>
typedef __int8_t BYTE;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./recover FILE\n");
    return 1;
  }
  char *infile = argv[1];
  FILE* inptr = fopen(infile, "r");
  if (inptr == NULL)
  {
      printf("Could not open %s.\n", infile);
      return 1;
  }
  //Une fois le fichier ouvert, le parcourir et trouver une signature JPEG
  //Une fois une signature trouvée, créer un fichier avec pour nom "###.jpg" (démarrer a 000.jpg et incrémenter à chaque trouvaille)
  //
  BYTE b;
  while ((b = fgetc(inptr)) != EOF)
  {
    printf("%x",b);
  }
  printf("\n");
  fclose(inptr);
}
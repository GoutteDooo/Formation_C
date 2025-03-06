#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("error");
    return 1;
  }
  char *infile = argv[1];
  FILE* inptr = fopen(infile, "r");
  if (inptr == NULL)
  {
      printf("Could not open %s.\n", infile);
      return 4;
  }
  fprintf(card,"r");
  int v = 2;
  printf("ok %i\n", v);
  fclose(card);
}
#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("error\n");
    return 1;
  }
  char *infile = argv[1];
  FILE* inptr = fopen(infile, "r");
  if (inptr == NULL)
  {
      printf("Could not open %s.\n", infile);
      return 1;
  }
  fprintf(inptr,"r");
  fclose(inptr);
}
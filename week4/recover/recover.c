#include <stdio.h>
typedef __int8_t BYTE;

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
  BYTE b;
  while ((b = fgetc(inptr)) != EOF)
  {
    printf("%c",b);
  }
  printf("\n");
  fclose(inptr);
}
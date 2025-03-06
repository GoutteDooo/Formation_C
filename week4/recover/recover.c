#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("error");
    return 1;
  }
  FILE* card = fopen("card.raw", "r");
  fprintf(card,"r");
  int v = 2;
  printf("ok %i\n", v);
  fclose(card);
}
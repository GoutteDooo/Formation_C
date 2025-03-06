#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE* card = fopen("card.raw", "r");
  fprintf(card,"r");
  int v = 2;
  printf("ok %i\n", v);
  fclose(card);
}
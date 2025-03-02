#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


int main(int argc, char* argv[])
{
  if (argc != 2) return 1;
  FILE* input = fopen(argv[1], "r");

  uint8_t b[4];//size of byte : unsigned int (8B)

  while(fread(&b, sizeof(b), 4, input))
  {
    printf("reading...");
  }
  printf("\n");
  fclose(input);
  return 0;
}
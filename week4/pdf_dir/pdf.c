#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


int main(int argc, char* argv[])
{
  if (argc != 2) return 1;
  FILE* input = fopen(argv[1], "r");

  uint8_t buffer[4];//size of byte : unsigned int (8B)

  uint8_t signature[] = {0x25, 0X50, 0x44, 0x46};

  fread(buffer, sizeof(uint8_t), 4, input);

  if (strcmp(buffer, signature) == 0)
  {
    printf("Success!\n");
    return 0;
  }
  printf("%s, %s\n", buffer, signature);
  printf("Nope.\n");

  fclose(input);
  return 0;
}
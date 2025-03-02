#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
  if (argc != 2) return 1;
  FILE *input = fopen("hi.txt", "rb");
  BYTE b;
  while(fread(&b, sizeof(b), 4, input))
  {

  }
  printf("%s\n",s);
  fclose(input);
  return 0;
}
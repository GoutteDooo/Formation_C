#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;//unsigned 8 bits int

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("error\n");
    return 2;
  }
  FILE *src = fopen(argv[1], "rb");//read in binary
  FILE *dst = fopen(argv[2], "wb");
  if (src == NULL || dst == NULL)
  {
    return 1;
  }
  BYTE b;

  while(fread(&b, sizeof(b), 1, src) != 0)
  {
    fwrite(&b, sizeof(b), 1, dst);
  }

  fclose(dst);
  fclose(src);

  return 0;
}
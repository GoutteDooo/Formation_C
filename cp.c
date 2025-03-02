#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
  FILE *src = fopen(argv[1], "r");
  FILE *dst = fopen(argv[2], "w");
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
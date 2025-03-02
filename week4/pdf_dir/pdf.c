#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  if (argc != 2) return 1;
  FILE* input = fopen("hi.txt");
  BYTE b;
  fread(&b, 1, 4, input);
  return 0;
}
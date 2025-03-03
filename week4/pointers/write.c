#include <stdio.h>

int main(int argc, char* argv[])
{
  FILE* output = fopen(argv[1],"w");
  char c = 'A';
  fwrite(&c, sizeof(char), 1, output);
  printf("Success!\n");
  return 0;
}
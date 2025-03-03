#include <stdio.h>

int main(int argc, char* argv[])
{
  if (argc != 3) return 1;
  FILE* input = fopen(argv[1],"r");
  FILE* output = fopen(argv[2],"w");
  char ch;
  while ((ch = fgetc(input)) != EOF)
  {
    fputc(ch, output);
  }
  fclose(input);
  fclose(output);
  printf("Success.\n");
  return 0;
}
#include <stdio.h>

int main(int argc, char* argv[])
{
  if (argc != 2) return 1;
  FILE* input = fopen(argv[1],"r");
  FILE* output = fopen(argv[2],"w");
  char ch;
  while ((ch = fgetc(argv[1])) != EOF)
  {
    fputc(ch, argv[2]);
  }
  return 0;
}
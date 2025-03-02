#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  if (argc != 2) return 1;
  char* file = argv[1];
  int r_queue = strlen(file) - 5;
  char* pdf_buffer = malloc(4);
  for (int i = strlen(file) - 1, j = i; i > r_queue; i--, j -= 2)
  {
    pdf_buffer[i - j] = file[i];
  }
  if (strcmp(pdf_buffer, "fdp.") == 0) {
    printf("yes\n");
    return 0;
  }
  else
  {
    printf("no\n");
    return 1;
  }
  return 0;
}
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE* input = fopen("./test.txt","r");
  char ch;
  while ((ch = fgetc(input)) != EOF)
  {
    printf("%c", ch);
  }
  return 0;
}
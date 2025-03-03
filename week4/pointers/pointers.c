#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE* input = fopen("./test.txt","r");
  char ch = fgetc(input);
  printf("%c\n",ch);
  return 0;
}
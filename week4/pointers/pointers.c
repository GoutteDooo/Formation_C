#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE* input = fopen("./test.txt","r");
  char ch = fgetc(input);
  for (int i = 0; i < 5; i++)
  {
    printf("%c\n",ch);
    ch = fgetc(input);
  }
  return 0;
}
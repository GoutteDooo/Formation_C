#include <cs50.h>
#include <stdio.h>

int main(void)
{
  
  return 0;
}

void recursive(int c)
{
  if (c == 0)
  {
    return 0;
  }
  recursive(c - 1);
  for (int i = 0; i < c; i++)
  {
    printf("#");
  }
  printf("\n");
}
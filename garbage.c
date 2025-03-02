#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
  int *x;
  // int *y;

  x = malloc(sizeof(int));

  *x = 42;

  printf("x = %i\n",*x);
  return 0;
}
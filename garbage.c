#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  int *x;
  // int *y;

  x = malloc(sizeof(int));

  *x = 42;

  printf("x = %li\n",x);
  return 0;
}
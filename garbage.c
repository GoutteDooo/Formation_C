#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int scores[1024];
  for (int i = 0; i < 1024; i++)
  {
    printf("%I\n", scores[i]);
  }
  return 0;
}
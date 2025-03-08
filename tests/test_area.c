#include <stdio.h>
float guess_blue(int blueStart, int redStart, int bluePulled, int redPulled);

int main(int argc, char* argv[])
{
  if (argc != 2) return 1;
  float f = guess_blue(10,10,0,0);
  printf("%f\n",f);
  return 0;
}

float guess_blue(int blueStart, int redStart, int bluePulled, int redPulled)
{
  int total_marbles_left = blueStart + redStart - bluePulled - redPulled;
  int blue_left = blueStart - bluePulled;
  return ((float)blue_left / total_marbles_left);
}
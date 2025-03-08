#include <stdio.h>
float guess_blue(int blueStart, int redStart, int bluePulled, int redPulled);

int main(void)
{
  guess_blue(10,10,0,0);
  return 0;
}

float guess_blue(int blueStart, int redStart, int bluePulled, int redPulled)
{
  int marbles_left = blueStart + redStart - bluePulled - redPulled;
  
  return 0.0;
}
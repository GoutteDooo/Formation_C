#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float guess_blue(int blueStart, int redStart, int bluePulled, int redPulled);

int main(void)
{
  
  return 0;
}

bool pythagorean_triple(const unsigned sides[3])
{
  for (int i = 0; i < 3; i++)
  {
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
      //on ne veut pas vérifier le même indice
      if (i == j) break;
      sum += sides[j]*sides[j];
    }
    if (sum == sides[i]*sides[i])
    {
      return true;
    }
  }
  return false;
}

int main_guess_blue(int argc, char* argv[])
{
  if (argc != 5) return 1;
  float f = guess_blue(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
  printf("%f\n",f);
  return 0;
}

float guess_blue(int blueStart, int redStart, int bluePulled, int redPulled)
{
  int total_marbles_left = blueStart + redStart - bluePulled - redPulled;
  int blue_left = blueStart - bluePulled;
  return ((float)blue_left / total_marbles_left);
}

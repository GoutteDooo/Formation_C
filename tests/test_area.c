#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
float guess_blue(int blueStart, int redStart, int bluePulled, int redPulled);
bool pythagorean_triple(const unsigned sides[3]);
int diffsum(const int *arr, size_t n);
int comp(const void* a, const void* b) ;

int main(void)
{
  const int arr[3] = {10,2,1};
  int s = diffsum(arr,3);
  printf("%i\n",s);
  return 0;
}


int diffsum(const int *arr, size_t n)
{
  // Sort the array
  qsort(arr, n, sizeof(int), comp);
  int sum = 0;
  printf("array: %i\n", arr);
  // Then, take each pair and add it to sum
  for (int i = 0; i < n - 1; i++) 
  {
    int p1 = i + 1;
    int p2 = i;
    sum += p2 - p1;
    printf("i: %i\n actual sum: %i\n",i,sum);
  }
  return sum;
}

// Custom comparator
int comp(const void* a, const void* b) 
{
    // If a is smaller, positive value will be returned
    return (*(int*)a - *(int*)b);
}

int main_pythagorean_triple(void)
{
  const unsigned int a[3] = {5,3,4};
  bool b = pythagorean_triple(a);
  printf("%b\n",b);
  return 0;
}

bool pythagorean_triple(const unsigned sides[3])
{
  for (int i = 0; i < 3; i++)
  {
    int sum = 0;
    int calc = sides[i] * sides[i];
    for (int j = 0; j < 3; j++)
    {
      //on ne veut pas vérifier le même indice
      if (i == j) continue;
      sum += sides[j]*sides[j];
    }

    printf("sum = %i & sides[i] = %i\n",sum, calc);
    if (sum == calc)
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

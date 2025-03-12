#include <stdio.h>

unsigned int hash(char* str);

#define HASH_MAX 25

int main(int argc, char* argv[])
{
  int x = hash(argv[1]);
  printf("x = %i\n", x);
  return 0;
}

unsigned int hash(char* str)
{
  int sum = 0;
  for (int j = 0; str[j] != '\0'; j++)
  {
    sum += str[j];
  }
  return sum % HASH_MAX;
}
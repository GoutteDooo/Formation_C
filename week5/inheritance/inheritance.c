#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct person
{
  struct person* parents[2];
  char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person* create_family(int generations);
void print_family(person* p, int generation);
void free_family(person* p);
char random_allele();

int main(void)
{
  // Seed rng
  srand(time(0));

  // Create a new family with three generations
  person* p = create_family(GENERATIONS);

  // Print family tree of blood types
  print_family(p,0);

  // Free mem
  free_family(p);
  return 0;
}
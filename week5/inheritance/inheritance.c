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

person* create_family(int generations)
{
  // TODO: Allocate memory for new person


  // If there are still generations left to create
  if (generations > 1)
  {
    // Create two parents for current person by recursively calling
    person* parent0 = create_family(generations - 1);
    person* parent1 = create_family(generations - 1);

    // TODO: Set parent pointers for current person

    // TODO: Randomly assign cyrrent person's alleles 
  }
}
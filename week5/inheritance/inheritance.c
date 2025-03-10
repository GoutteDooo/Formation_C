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
  person* new_person = malloc(sizeof(person));
  if (new_person == NULL) return NULL;

  // If there are still generations left to create
  if (generations > 1)
  {
    // Create two parents for current person by recursively calling
    person* parent0 = create_family(generations - 1);
    person* parent1 = create_family(generations - 1);

    // TODO: Set parent pointers for current person
    new_person->parents[0] = parent0;
    new_person->parents[1] = parent1;

    // TODO: Randomly assign current person's alleles based on the alleles of their parents
    new_person->alleles[0] = parent0->alleles[rand() % 2];
    new_person->alleles[1] = parent1->alleles[rand() % 2];;
  }

  //If there are no gens left to create
  else 
  {
    // TODO: Set parent pointers to NULL
    new_person->parents[0] = NULL;
    new_person->parents[1] = NULL;

    // TODO: Randomly assign alleles

  }

  //TODO: Return newly created person
  return NULL;
}

void free_family(person *p)
{
  return;
}
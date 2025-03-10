#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
  struct person* parents[2];
  char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person* create_family(int generations)
{
  
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  FILE *file = fopen("phonebook.csv", "a");//w = write, a = append
  char *name = get_string("Name: ");
  char *number = get_string("Number: ");

  fprintf(file, "%s: %s\n", name, number);

  fclose(file);

  return 0;
}
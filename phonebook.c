#include <stdio.h>
#include <string.h>

int main(void)
{
  FILE *file = fopen("phonebook.csv", "w");//w = write
  char *name = get_string("Name: ");
  char *number = get_string("Number: ");

  fprintf(file, "%s,%s\n", name, number);

  fclose(file);
  
  return 0;
}
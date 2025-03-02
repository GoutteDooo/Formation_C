#include <cs50.h>
#include <stdio.h>
void swap(int *a, int *b);

int main(void)
{
  int a = 12;
  int b = 33;
  swap(&a,&b);

  printf("a: %i\n",a);
  printf("b: %i\n",b);
  return 0;
}

void swap(int *a, int *b)
{
  int tmp = *a;
  printf("tmp: %i\n",tmp);
  printf("a before: %i\n",*a);
  *a = *b;
  printf("a after: %i\n",*a);
  printf("b before: %i\n",*b);
  *b = tmp;
  printf("b after: %i\n",*b);

}
#include <cs50.h>
#include <stdio.h>
void pdecrement(int *x);
int vdecrement(int x);

int main(void)
{
  int k = 52;
  int* pk = &k;
  int* pn = NULL;
  printf("k before dec: %i\n", k);
  pdecrement(pk);
  printf("k after pdec: %i\n", k);
  k = vdecrement(k);
  printf("k after vdec: %i\n", k);
  printf("pn: %i\n", *pn);
  return 0;
}

void pdecrement(int *x)
{
  (*x)--;
}

int vdecrement(int x)
{
  return --x;
}
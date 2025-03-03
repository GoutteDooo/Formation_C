#include <cs50.h>
#include <stdio.h>
void recursive(int c);//for testing
int fact(int n);

/**
  fact(1)
  fact(2)
  fact(3)
  fact(4)
  fact(5)
  printf()
  main()
*/
int main(void)
{
  printf("n= %i\n",fact(4));
  return 0;
}

void recursive(int c)
{
  if (c == 0)
  {
    return;
  }
  recursive(c - 1);
  //Here, the function stops, and put another recursive on top of the stack
  //Then, the other recursives functions who hasn't c == 0 will follows the same rhythm.
  //And, when c reaches 0
  //The stack will pop off one by one recursives function with c from 0 to the default one.
  /**
  Example :
  recursive(3)
  Stack when c reaches 0:
  recursive(0) <-- step 1 : return !
  recursive(1) <-- step 2 : #
  recursive(2) <-- step 3 : ##
  recursive(3) <-- step 4 : ###
   */
  for (int i = 0; i < c; i++)
  {
    printf("#");
  }
  printf("\n");
}


int fact(int n)
{
  printf("f= %i\n",n);
  if (n == 1)
  {
    return 1;
  }
  else
  {
    return n * fact(n - 1);
  }
}
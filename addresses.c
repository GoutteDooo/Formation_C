#include <cs50.h>
#include <stdio.h>
//test
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("error\n");
        return 1;
    }
    int i = get_int("i: ");
    int j = get_int("j: ");
    printf("it: %i\n",i);
    printf("j: %i\n",j);
    printf("%s\n",argv[1]);
    return 0;
}
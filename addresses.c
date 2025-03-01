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
    int i = get_string("i: ");
    int j = get_string("j: ");
    if (strcmp(i,j) == 0)
    {
        printf("same\n");
    }
    else
    {
        printf("diff\n");
    }
    return 0;
}
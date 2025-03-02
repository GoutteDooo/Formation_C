#include <cs50.h>
#include <stdio.h>
#include <string.h>
//test
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("error\n");
        return 1;
    }
    if (strcmp(argv[1],argv[2]) == 0)
    {
        printf("same\n");
    }
    else
    {
        printf("diff\n");
    }
    printf("locs : %p, %p\n",argv[1], argv[2]);
    return 0;
}
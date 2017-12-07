#include <stdio.h>

int main(int argc, char **argv)
{
    
    for (int i = 0; i < argc; ++i)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");
    
    if (argc < 2)
    {
        printf("Usage: test shack tack\n");
    }
}

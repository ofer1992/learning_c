#include <stdio.h>

/* mess around with spaces of various kind */

int main()
{
    int nb, nt, nl; /* number of blanks, tabs, newlines */
    int c;
    
    nb = 0;
    nt = 0;
    nl = 0;
    
    while((c = getchar()) != EOF)
    {
        if (c == '\\')
            printf("\\\\");
        else if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else
            putchar(c);
    }
    printf("blanks:%d, tabs:%d, newlines:%d\n", nb, nt, nl);
}

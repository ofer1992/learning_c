#include <stdio.h>
#include <ctype.h>

#define NOT_NUMBER 0

int getint(int *p);

int main()
{
    int n;
    if (getint(&n) == NOT_NUMBER)
    {
        printf("Not a number\n");
    }
    else
    {
        printf("The number is %d\n", n);
    }
    printf("%c\n", getchar());
}

/*
    converts stream of characters to int.
    returns EOF for end of file, 0 if next input isn't a number and
    1 for success.
*/
int getint(int *p)
{
    int c = getchar();
    
    if (c == EOF)
    {
        ungetc(c, stdin);
        return EOF;
    }
    
    if (!isdigit(c))
    {
        ungetc(c, stdin);
        return NOT_NUMBER;
    }
    
    *p = 0;
    
    while (isdigit(c))
    {
        *p *= 10;
        *p += c - '0';
        c = getchar();
    }
    //TODO: Handle case where c is EOF
    ungetc(c, stdin);
    
    return 1;
}

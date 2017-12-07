#include <stdio.h>

#define IN 1;
#define OUT 0;

/*
    Receives a c program and prints it without "/*" comments.
*/
int main()
{
    int c, peek;
    int comment; /* flag for being inside a comment */
    int string; /* flag for being inside a string */
    
    string = comment = OUT;
    
    while ((c = getchar()) != EOF)
    {
        if (string) /* inside a string */
        {
            putchar(c);
            if (c == '"')
            {
                string = OUT;
            }
        }
        else if (comment) /* inside a comment */
        {
            if (c == '*' && (c = getchar()) == '/')
            {
                comment = OUT;
            }
        }
        else /* outside a comment and a string */
        {
            if (c == '"')
            {
                string = IN;
                putchar(c);
            }
            else if (c == '/')
            {
                peek = getchar();
                if (peek == '*') 
                {
                    comment = IN;
                }
                else 
                {
                    putchar(c);
                    if (peek == EOF)
                    {
                        return 0;
                    }
                    else if (peek == '"')
                    {
                        string = IN;
                    }
                    putchar(peek);
                }
            }
            else
            {
                putchar(c);
            }
        }
    }
    
    return 0;
}

#include <stdio.h>

#define CODE 0
#define COMMENT 1
#define STRING 2

int string(int);
int comment(int, int);
int code(int, int);

/*
    Receives a c program and prints it without "/*" comments.
*/
int main()
{
    int c, peek;
    int state; /* type cursor is in */
    
    state = CODE;
    c = getchar();
    
    while (c != EOF)
    {
        peek = getchar();
        if (state == CODE)
        {
            state = code(c, peek);
            if (state == COMMENT)
                c = getchar();
            else
                c = peek;
        }
        else if (state == COMMENT)
        {
            state = comment(c, peek);
            if (state == CODE)
                c = getchar();
            else
                c = peek;
        }
        else if (state == STRING)
        {
            state = string(c);
            c = peek;
        }
    }
}

/*
    logic for when in a string
*/
int string(int c)
{
    putchar(c);
    if (c == '"')
        return CODE;
    return STRING;
}

/*
    logic for when in a comment.
    if returns CODE skip a characters.
*/
int comment(int c, int peek) 
{
    if (c == '*' && peek == '/')
        return CODE;
    return COMMENT;
}

/* 
    logic for when in a code.
    if returns COMMENT skip a character.
*/
int code(int c, int peek)
{
    if (c == '/' && peek == '*')
        return COMMENT;
    putchar(c);
    if (c == '"')
        return STRING;
    return CODE; 
}

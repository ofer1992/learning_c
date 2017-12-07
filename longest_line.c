#include <stdio.h>

#define STARTLEN 127

int get_line(char s[], int len);
void copy(char from[],char to[]);

/*
    Finds longest line in input and prints it.
*/
int main()
{
    int max; /* maximum length encountered */
    int len; /* current line length */
    char line[STARTLEN]; /* current input line */
    char longest[STARTLEN]; /* longest line saved here */
    
    max = 0;
    
    while((len = get_line(line, STARTLEN)) != 0)
    {
        if (len > max)
        {
            max = len;
            copy(line, longest);
        }
    }
    
    if (max > 0)
    {
        printf("%s", longest);
    }

    return 0;
}

/*  
    Reads next line from input, saves it to "line" and returns length.
    0 is EOF
*/
int get_line(char s[], int len) // TODO: "reset" array?
{
    int i, c;
    
    for (i = 0; i < len && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    
    s[i] = '\0';

    return i;
}

/*
    Copies "from" into "to", assuming "to" is big enough.
*/
void copy(char from[], char to[])
{
    for (int i = 0; (to[i] = from[i]) != '\0'; i++)
        ;
}

#include <stdio.h>


/*
    receives string and returns true iff without repeatable characters;
*/
int noRepeat(char *s, int l, int r)
{
    int letters[256] = {0};
    
    for (;  l <= r; l++)
    {
        if (letters[s[l]] == 1)
        {
            return 0;
        }
        letters[s[l]] = 1;
    }
    
    return 1;
}

/*
    looks for identical letter in string and returns it's index
    if none returns -1
*/
int indexOfIdenticalLetter(char *s, int l, int r, char c)
{
    for (; l <= r; l++)
    {
        if (s[l] == c)
        {
            return l;
        }
    }
    
    return -1;
}

int lengthOfLongestSubstringV1(char* s)
{
    int max, l, r;
    
    max = 0;
    l = 0;
    
    while(s[l+max] != '\0')
    {
        if (noRepeat(s, l ,l+max))
        {
            max += 1;
            printf("%c\n", s[l+max]);
        }
        else
        {
            l++;
        }
    }
    
    return max;
}

int lengthOfLongestSubstring(char* s)
{
    int max, l, r;
    
    max = 0;
    l = 0;
    
    while(s[l+max+1] != '\0')
    {
        int ind = indexOfIdenticalLetter(s, l, l+max, s[l+max+1]);
        if (ind == -1)
        {
            max += 1;
        }
        else
        {
            l = ind + 1;
        }
    }
    
    return max + 1;
}

int
main (int argc, char *argv[])
{
    printf("%d\n", lengthOfLongestSubstring("ggububgvfk"));
    return 0;
}

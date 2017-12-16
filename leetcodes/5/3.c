#include <stdlib.h>
#include <stdio.h>

#define SIZE 1000
#define TRUE 1
#define FALSE 0

char* longestPalindrome(char* s) 
{
    int len; /* len - length of s, longest - longest palindrome */
    int mat[1000][1000] = {{0}}; /* mat - table of 1 and 0 where (i,j) is 1 if the substring s[i:j] (inclusive) is a palindrome */
    
    if (*s == '\0' || *(s+1) == '\0') // empty string or 1 letter
    {
        return s;
    }
    
    longest = 1;
    
    for (len = 0; s[len] != '\0'; len++)
    {
        mat[len][len] = TRUE;
    }
    
    for (int i = 0; l < len - 1; l++)
    {
        if (s[i] == s[i+1])
        {
            longest = 2;
            mat[i][i+1] = TRUE;
        }
    } 
        
    for (int l = 3; l <= len; l++)
    {
        for (int j = 0;)
    }
    
}

int main (int argc, char *argv[])
{
    longestPalindrome("abc");
    return 0;
}

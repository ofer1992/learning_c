#include <stdio.h>

#define MAX_LENGTH  15

/* receives input and prints histogram of length of words */

int main()
{
    int word_len[MAX_LENGTH] = {0};
    int char_counter, num_of_rows, c; /* counts length of word, counts amount of rows needed for histogram */
    
    char_counter = num_of_rows = 0;
    
    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (char_counter > 0)
            {
                ++word_len[char_counter];
                if (word_len[char_counter] > num_of_rows)
                {
                    num_of_rows = word_len[char_counter];
                }
            }
            char_counter = 0;
        }
        else
        {
            ++char_counter;
        }
    }
    
    printf("%d\n", num_of_rows);
    
    for (int i = num_of_rows; i > 0; --i)
    {
        for (int j = 1; j <= MAX_LENGTH; ++j)
        {
            if (word_len[j] >= i)
            {
                printf(" - ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    for (int i = 1; i <= MAX_LENGTH; ++i)
    {
        printf(" %d ", i);
    }
    printf("\n");
    
}

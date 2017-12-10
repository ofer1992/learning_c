/**
 * The code file for the countSubStr function.
 */


#ifndef COUNT_SUB_STR_H
#define COUNT_SUB_STR_H

#include <stdio.h>
#include <stdlib.h>

/**
 * the MyString struct
 * */
struct MyString
{
    char *s;
    int len;
    
};

typedef struct MyString * MyStringP;

/*
    copies "from" to "to"
    assumes "to" has enough space allocated
*/
void copy(char *to, char *from)
{
    for(; *(to++) = *(from++);)
        ;
}

/**
 * allocates a new String containing the str1 char*
 * @param str1 a char*
 * @return a new MyString * struct contaning str1
 */
MyStringP createStringFromChars(const char* str1)
{
    if (str1 == NULL)
    {
        return NULL;
    }
    MyStringP str = (MyStringP) malloc(sizeof(struct MyString));
    for (str->len = 0; str1[str->len] != '\0'; str->len++)
        ;
        
    str->s = (char *) malloc(str->len + 1);
    copy(str->s, (char *) str1);
    
    return str;
}

/**
 * allocates a new String which is a copy of str1
 * @param str1 a String
 * @return a copy of str1
 */
MyStringP createStringFromString(const MyStringP str1)
{
    if (str1 == NULL)
    {
        return NULL;
    }
    MyStringP str = (MyStringP) malloc(sizeof(struct MyString));
    str->len = str1->len;
    str->s = (char *) malloc(str->len + 1);
    copy(str->s, str1->s);
    
    return str;
}

/**
 * frees the allocated memory given to the struct
 * @param str1 the string to free
 */
void freeString(MyStringP str1)
{
    if (str1 == NULL)
    {
        return;
    }
    free(str1->s);
    free(str1);
}

/**
 * returns the lenght of the given String
 * @param str1 - the string
 * @return lenght of str1
 */
unsigned int lengthString(const MyStringP str1)
{
    if (str1 == NULL)
    {
        return -1;
    }
    return str1->len;
}

/**
 * returns the value of the given String
 * @param str1 - the string
 * @return the content of str1
 */
const char* cString(const MyStringP str1)
{
    if (str1 == NULL)
    {
        return NULL;
    }
    
    return (const char *) str1->s;
}

/**
 * compares the 2 Strings by this logic:
 * compares the 2 strings by the first unmatched char.
 *
 * @param str1 the first string to compare
 * @param str2 the second string to compare
 * @return
 * 1 if the ASCII value of first unmatched character is greater in str1 then str2.
 * 0 if both strings are identical (equal)
 * -1 if the ASCII value of first unmatched character is less in str1 then str2.
 */
int cmpString(const MyStringP str1,const MyStringP str2)
{
    char *first;
    char *second;
    
    if (str1 == NULL || str2 == NULL)
    {
        return -2;
    }
    
    first = (char *) str1->s;
    second = (char *) str2->s;
    
    for(; *first == *second; first++, second++)
    {
        if (*first == '\0')
        {
            return 0;
        }
    }
            
    return (*first > *second) ? 1 : -1;
}

/**
 * concatenate the 2 Strings in to one String
 * @param str1 the first string in the result, the method will change the value of str1
 * @param str2 the second string in the result
 * @return the result of the concatenate
 */
MyStringP concatString(MyStringP str1,const MyStringP str2)
{
    if (str1 == NULL || str2 == NULL)
    {
        return NULL;
    }
    
    str1->s = realloc(str1->s, str1->len + str2->len + 1);
    copy(str1->s + str1->len, str2->s);
    str1->len = str1->len + str2->len + 1;
    
    return str1;
}

/**
 * deletes a certain char from the String
 * @param str1 the string, changes his value according to the result
 * @param letter the letter to delete from the String
 * @return the result.
 */
MyStringP deleteCharString(MyStringP str1,const char letter)
{
    char *p1, *p2;
    p1 = p2 = str1->s;
    
    for(; p2 <= (str1->s + str1->len); p1++, p2++)
    {
        while (*p2 == letter) //whdat if letter='\0'
        {
            ++p2;
            str1->len--;
        }
        *p1 = *p2;
    }
    
    return str1;
}

int main()
{
    MyStringP str = createStringFromChars("subpas");
    printf("%s\n", str->s);
    MyStringP str1 = createStringFromChars("supa");
    printf("%s\n", str1->s);
    concatString(str1, str);
    printf("%s\n", str1->s);
    deleteCharString(str1, 'a');
    printf("%s\n", str1->s);
}

#endif

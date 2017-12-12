#include <stdio.h>
#include "stack.h"

int main (int argc, char *argv[])
{
    Stack *st;
    st = createStack(10);
    for (int i = 0; i < 10; i += 1)
    {
        push(st, i);
    }
    for (int i = 0; i < 10; i += 1)
    {
        printf("%d\n", pop(st));
    }
    
    freeStack(st);
    return 0;
}



#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"

struct Stack
{
    int stack[];
    int head;
};

/*
    initalize a new stack.
*/
Stack * createStack(int size)
{
    Stack st;
    st.stack = (int[]) malloc(size * sizeof(int)); //TODO: free
    st.head = 0;
    return &st;
}

/*
    free stack.
*/
void freeStack(Stack *st)
{
    free(st->stack);
    free(st);
}
/*
    push an integer into the stack.
*/
void push(Stack *st, int val)
{
    assert(st.head <= STACK_SIZE);
    st->stack[st->head++] = val;
}

/*
    pop an integer into the stack.
*/
int pop(Stack *st)
{
    assert(st->head > 0);
    return st->stack[--st->head];
}

int main ()
{
    Stack *st;
    st = createStack(16);
    for (int i = 0; i < 10; i += 1)
    {
        push(st, i);
    }
    for (int i = 0; i < 10; i += 1)
    {
        printf("%d\n", pop(st));
    }
    
    return 0;
}

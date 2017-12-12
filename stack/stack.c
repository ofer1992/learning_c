#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"

struct Stack
{
    int *stack;
    int head;
    int size;
};

/*
    initalize a new stack.
*/
Stack * createStack(int size)
{
    Stack *st;
    
    st = (Stack *) malloc(sizeof(Stack));
    st->stack = (int*) malloc(size * sizeof(int)); //TODO: free
    st->head = 0;
    st->size = size;
    
    return st;
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
    assert(st->head <= st->size);
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


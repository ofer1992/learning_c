#ifndef STACK
#define STACK

typedef struct Stack Stack;

/*
    initalize a new stack.
*/
Stack * createStack(int size);

/*
    free stack.
*/
void freeStack(Stack *st);
/*
    push an integer into the stack.
*/
void push(Stack *st, int val);

/*
    pop an integer into the stack.
*/
int pop(Stack *st);

#endif

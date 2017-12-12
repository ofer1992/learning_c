#include <stdio.h>
#include <ctype.h>
#include "stack.h"

int main (int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("usage: ./prog n1 n2 n3 ...\n\
        n_i is an operator or operand, expected order\n\
        is reverse polish notation\n");
        return -1;
    }
    
    Stack *st = createStack(argc - 1);
    
    for(int i = 1; i < argc; i++)
    {
        if (isdigit(*argv[i]))
        {
            printf("%c\n", *argv[i]);
            push(st, *argv[i] - '0');
        }
        else
        {
            printf("%c\n", *argv[i]);
            int op1, op2;
            op2 = pop(st);
            op1 = pop(st);
            switch (*argv[i])
            {
                case '+':
                    push(st, op1 + op2);
                    break;
                case '-':
                    push(st, op1 - op2);
                    break;
                case '*':
                    push(st, op1 * op2);
                    break;
                case '/':
                    push(st, op1 / op2);
                    break;
                default:
                    printf("ERROR\n");
                    return 0;
            }
        }
    }
    printf("%d\n", pop(st));
    return 0;
}


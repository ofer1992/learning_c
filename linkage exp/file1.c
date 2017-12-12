#include <stdio.h>
#include "file1.h"

extern int a = 0;
int b = 1;
static int c = 2;

void printFile1()
{
    int d = 3;
    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
}

#include <stdio.h>
#include "file1.h"

extern int a;
int b;
extern int c;
c = 7;

main()
{
    int d = 0;
    printFile1();
    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    a = 1;
    b = 0;
    printFile1();
    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    {
        extern int b;
        int a = 5;
        b = 5;
        int c = 5;
        printFile1();
        printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    }
    
}

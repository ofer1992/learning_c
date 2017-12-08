#include <stdio.h>

typedef struct S
{
    int a;
    int b;
    int arr[2];
} S;

main()
{
    S s1, s2;
    s1.a = 1;
    s1.b = 2;
    //s1.arr[0] = s1.arr[1] = 0;
    s2 = s1;
    s1.arr[0] = (s1.arr[1] = 4) - 1;
    printf("s1.arr = {%d, %d}\n", s1.arr[0], s1.arr[1]);
    printf("s2.arr = {%d, %d}\n", s2.arr[0], s2.arr[1]);
    
}

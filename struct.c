#include <stdio.h>
#include <stdlib.h>

typedef struct Complex
{
    double _real, _imag;
} Complex;

Complex *newComplex(double r, double i)
{
    Complex *s = malloc(sizeof(Complex));
    s->_real = r;
    s->_imag = i;
    return s;
}

main()
{
    Complex *p1;
    Complex *p2;
    p1 = newComplex(1.0, 2.0);
    p2 = newComplex(3.0, 4.0);
    printf("c1 r=%lf i=%lf\n", (*p1)._real, (*p1)._imag);
    printf("c2 r=%lf i=%lf\n", p2->_real, p2->_imag);
    
    free(p1);
    free(p2);
}

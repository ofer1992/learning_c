#include <stdio.h>

#define LOWER 0      /* lower limit of conversion */
#define UPPER 300    /* upper limit */
#define STEP  20     /* step size */
/* comments brah */

int main()
{
    float fahr;
    
    for(fahr = LOWER; fahr <= UPPER; fahr += 20)
    {
        printf("%3.0f\t%6.1f\n", fahr, (5.0/9.0) * (fahr-32));
    }
    return 1;
}

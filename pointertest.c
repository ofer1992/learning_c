#include <stdio.h>

main()
{
    char amessage[] = "now is the time";
    char *pmessage = "now is the time";
    amessage[0] = 'l';
    //*pmessage = 'l';
    printf("%s\n", amessage);
    pmessage = amessage;
    *pmessage = 'n';
    printf("%s\n", amessage);
    printf("%s\n", pmessage);
}

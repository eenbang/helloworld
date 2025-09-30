#include <stdio.h>
#include "1.h"
#define SIZE 1000
int main()
{
    int n,array[SIZE],getint(int *),s;

    for (n = 0; n < SIZE && (s = getint(&array[n])) != EOF;n++)
        ;
    printf("%i",s);
}

#include <stdio.h>
#include "1.h"
#define SIZE 1000
int main()
{
    int n,array[SIZE],getint(int *);

    for (n = 0; n < SIZE &&  getint(&array[n]) != EOF;n++)
        printf("%i",array[n]);
}


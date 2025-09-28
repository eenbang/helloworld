#include <stdio.h>
#include <stdlib.h>

int getline(char s[],int lim);

int main()
{
    char line[1000];
    int len;
    len = getline(line,1000);
    printf("%i",len);
}



int getline(char s[],int lim)
{

    int c,i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

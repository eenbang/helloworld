#include <stdio.h>
#define MAXLINE 1000
char pattern[] =  "ould";
int getline(char line[],int max);
int strindex(char source[],char searchfor[]);
main()
{
    char line[MAXLINE];
    int found = 0;
    while (getline (line,MAXLINE) >0)
    {
        if (strindex(line,pattern) >= 0)
        {
            printf("%s",line);
            found++;
        }

    }
    printf("%i",found);
    return found;

}

//���б��浽s�У������ظ��еĳ���
int getline (char s[],int lim)
{
    int i; int c ;
    for (i = 0;i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (s[i] == '\n')
    {
        s[i++] = c;

    }
    s[i] = '\0';
    return i;

}
//���ң�t��s�е�λ��
int strindex (char s[],char t[])
{
    int i,j,k;
    for (i = 0; s[i] != '\0';i++)
    {
        for (j = i,k = 0; t[k] != '\0' && s[j] == t[k]; j++,k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;

    }
    return -1;
}



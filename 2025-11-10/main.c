#include <stdio.h>

void DrawWall(char digit,int height,int width)
{
    int i,j;
    for(i = 1; i <= height; i++)
    {
        for(j = 1; j <= width; j++)
        {
            printf("%c",digit);
        }
        printf("\n");
    }
}
void DrawFrame(char digit,int height,int width)
{
    int i,j;
    for(i = 1; i <= height; i++)
    {
        for(j = 1; j <= width; j++)
        {
            if(i == 1 || i == height) printf("%c",digit);
            else if(j == 1 || j == width) printf("%c",digit);
            else printf(" ");

        }
        printf("\n");
    }
}
void DrawTriangle(char digit,int height,int width)
{
    int i,j;
    int n = height;
    if(n < width) n = width;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i ; j++)
        {
            printf("%c",digit);
        }
        printf("\n");
    }
}
int main()
{
    while(1)
    {
        int height = -1, width = -1;
        char digit;
        int kind;
        printf("get:\n");
        while(scanf("%d",&kind) != 1 || (kind != 1 && kind != 2 && kind != 3))
        {
            if(kind == -1) return 0;
            printf("wrong111\n");
            while(getchar() != '\n');
        }
        getchar();
        scanf("%c",&digit);
        while(getchar() != '\n');
        while(scanf("%d",&height) != 1 || height < 1 || height > 3000)
        {
            printf("Wrong\n");
            while(getchar() != '\n');
        }
        while(scanf("%d",&width) != 1 || width < 1 || width > 3000)
        {
            printf("Wrong\n");
            while(getchar() != '\n');
        }
        switch(kind)
        {
        case 1 :
            DrawWall(digit,height,width);
            break;
        case 3 :
            DrawTriangle(digit,height,width);
            break;
        case 2 :
            DrawFrame(digit,height,width);
            break;

        }
    }
}

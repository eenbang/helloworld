#include <stdio.h>
long long Jc(int n)
{
    int s = 1;
    for(;n > 1;n--)
    {
        s = s * n;
    }
    return s;
}
int main()
{
    int num;
    printf("请输入阶乘\n");
    while(1)
    {
        if(scanf("%d",&num) != 1)
        {
            printf("非法输入\n");
            while(getchar() != '\n');
            continue;
        }
        if (num >= 1 && num <=20)
            printf("%d的阶乘是%lld\n",num,Jc(num));
        else if (num == -1)
            break;
        else
            printf("非法输入\n");
    }
}


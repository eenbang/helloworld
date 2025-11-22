#include <stdio.h>
#include <stdlib.h>

int main()
{
    double n = -2;

    printf("请输入需要计算斐波那契数列的正整数[0,90]之间，输入-1时程序退出。\n");
    while(1){
        while(scanf("%lf",&n) != 1 || n < 0 || n >90){
            if (n == -1) return 0;
            printf("非法输入，需要[0,90]闭区间的正整数，输入-1时程序退出。\n");
            while(getchar() != '\n');
        }
        int cout = n;
        while(n != 1){
            n = n * (n - 1);
            n--;
        }
        printf("第%d个斐波那契数值是%.0lf\n",cout,n);
    }
}

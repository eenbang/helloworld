#include <stdio.h>

double isunit(char c);
double max(double m[]);
double min(double m[]);
double sum(double m[]);
double ave(double m[]);

int main()
{
    int n = 1;
    char unit;
    int i = 0;
    double m[1000];

    // 初始化数组结束标记
    m[0] = -1;

    while(1){
        printf("欢迎来到货物质量单位统一换算系统。1千克=1000克，1镑=16盎司，1镑=454克。\n");
        printf("请输入货物的质量数(正整数)。\n");

        while(scanf(" %d",&n)!=1 || n<1 || n>1000){
            printf("非法输入，需要[1,1000]闭区间的正整数。\n");
            while(getchar()!='\n');
        }

        printf("请输入货物的质量单位（g,G-克，k,K-千克，o,O-盎司，p,P-镑）,输入x程序退出。\n");

        scanf(" %c",&unit);

        // 处理退出逻辑
        if (unit == 'x' || unit == 'X'){
            if(m[0] == -1) {
                printf("没有输入任何货物数据，程序退出。\n");
                return 0;
            } else {
                printf("最重的货物的质量是%.0lf克\n", max(m));
                printf("最轻的货物的质量是%.0lf克\n", min(m));
                printf("货物的全部质量是%.0lf克\n", sum(m));
                printf("货物的平均质量是%.0lf克\n", ave(m));
                return 0;
            }
        }

        // 验证单位输入
        while(isunit(unit) == 0){
            printf("非法输入，需要(g,G-克,k,K-千克,o,O-盎司,p,P-镑) ,输入x程序退出。\n");
            scanf(" %c",&unit);

            // 再次检查退出
            if (unit == 'x' || unit == 'X'){
                if(m[0] == -1) {
                    printf("没有输入任何货物数据，程序退出。\n");
                    return 0;
                } else {
                    printf("最重的货物的质量是%.0lf克\n", max(m));
                    printf("最轻的货物的质量是%.0lf克\n", min(m));
                    printf("货物的全部质量是%.0lf克\n", sum(m));
                    printf("货物的平均质量是%.0lf克\n", ave(m));
                    return 0;
                }
            }
        }

        // 存储数据
        m[i] = isunit(unit) * n;
        printf("第%d个货物的质量是%.0lf克\n", i+1, m[i]);

        // 更新结束标记位置
        m[i+1] = -1;
        i++;

        // 检查数组是否已满
        if(i >= 999){
            printf("已达到最大货物数量限制。\n");
            break;
        }
    }

    return 0;
}

double isunit(char c)
{
    if(c == 'g' || c == 'G') return 1;
    else if(c == 'k' || c == 'K') return 1000;
    else if(c == 'o' || c == 'O') return 454.0/16.0;  // 使用浮点数除法
    else if(c == 'p' || c == 'P') return 454;
    else return 0;
}

double max(double m[])
{
    if(m[0] == -1) return 0;  // 空数组处理

    double max_val = m[0];
    int i = 1;

    while(m[i] != -1){
        if (max_val < m[i]){
            max_val = m[i];
        }
        i++;  // 确保每次循环都递增
    }
    return max_val;
}

double min(double m[])
{
    if(m[0] == -1) return 0;  // 空数组处理

    double min_val = m[0];
    int i = 1;

    while(m[i] != -1){
        if (min_val > m[i]){
            min_val = m[i];
        }
        i++;  // 确保每次循环都递增
    }
    return min_val;
}




double sum(double m[])
{
    if(m[0] == -1) return 0;  // 空数组处理

    double total = 0;
    int i = 0;

    while(m[i] != -1){
        total += m[i];
        i++;
    }
    return total;
}

double ave(double m[])
{
    if(m[0] == -1) return 0;  // 空数组处理

    double total = 0;
    int count = 0;
    int i = 0;

    while(m[i] != -1){
        total += m[i];
        count++;
        i++;
    }

    return total / count;
}

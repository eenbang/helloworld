#include <stdio.h>
#include <math.h>
double isunit(char c);
double max(double m[]);
double min(double m[]);
double sum(double m[]);
double ave(double m[]);


int main()
{
    int n = 1; char unit;
    int i = 0; double m[1000];
    m[0] = -1;
    while(1){
        printf("欢迎来到货物质量单位统一换算系统。1千克=1000克，1镑=16盎司，1镑=454克。\n");
        printf("请输入货物的质量数(正整数)。\n");
        while(scanf(" %d",&n)!=1 || n<1 || n>10000){
            printf("非法输入，需要[0,1000]闭区间的正整数。\n");
            while(getchar()!='\n');
        }
        printf("请输入货物的质量单位（g,G-克，k,K-千克，o,O-盎司，p,P-镑）,输入x程序退出。\n");
        scanf(" %c",&unit);
        while(isunit(unit) == 0){


            /*对输入x时进行处理*/
            if (unit=='x' || unit=='X' ){
                m[i] = -1;//对数组末端进行标记
                if(m[0] == -1) return 0;//如果什么都没有，直接退出
                else{
                    printf("最重的货物的质量是%.0lf克\n",max(m));
                    printf("最轻的货物的质量是%.0lf克\n",min(m));
                    printf("货物的全部质量是%.0lf克\n",sum(m));
                    printf("货物的平均质量是%.0lf克\n",ave(m));
                    return 0;
                }
            }
             else{
                 printf("非法输入，需要(g,G-克,k,K-千克,o,O-盎司,p,P-镑) ,输入x程序退出。\n");
                 scanf(" %c",&unit);
             }


        }
        i++;
        m[i-1] = round(isunit(unit) * n);//将第i次的质量以g的形式记录在数组i-1中
        printf("第%d个货物的质量是%.0lf克\n",i,m[i-1]);


    }

}

double isunit(char c)
{


    if(c == 'g' || c == 'G') return 1;
    else if(c == 'k' || c == 'K') return 1000;
    else if(c == 'o' || c == 'O') return 454.0/16.0;
    else if(c == 'p' || c == 'P') return 454;
    else return 0;
}

double max(double m[])
{
    int i = 1;
    double maxi = m[0];
    while(m[i] != -1){
        if (maxi < m[i]){
            maxi = m[i];

        }
        i++;
    }
    return maxi;
}
double min(double m[])
{
    double mini = m[0];
    int i = 1;
    while(m[i] != -1){
        if (mini > m[i]){
            mini = m[i];

        }
        i++;
    }
    return mini;
}
double sum(double m[])
{
    double suma = m[0];
    int i = 1;
    while(m[i] != -1){
        suma += m[i];
        i++;
    }
    return suma;
}
double ave(double m[])
{
    double suma = m[0];
    int i = 1;
    while(m[i] != -1){
        suma += m[i];
        i++;
    }
    return round(suma/i);
}

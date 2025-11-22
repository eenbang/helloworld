#include <stdio.h>
#include <stdbool.h>
bool LeapYear(int year)
{
    if(year % 4 == 0 && year % 100 != 0) return true;
    else if(year % 400 == 0) return true;
    else return false;
}

int main()
{
    int i,year;
    int birthDay = 0;
    int lollipopGet = 0,lollipopGive = 0;
    //先判断是否为合法输入,并进行处理
    while(1)
    {
        while(scanf("%d",&year) != 1 ||  year < 2000 || year > 3000)
        {
           if(year == 999) return 0;
           printf("wrong\n");
           while(getchar() != '\n');
        }
        for(i = 2000; i <= year; i++)
        {
            if(LeapYear(i))
            {
                birthDay++;
                lollipopGet += 700;
            }
            lollipopGive += 140;
        }
        printf("%d\n",birthDay);
        printf("%d\n",lollipopGive);
        printf("%d\n",lollipopGet);
    }

}




#include <stdio.h>

// 判断是否是闰年
int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算某年某月某日是这一年的第几天
int dayOfYear(int year, int month, int day)
{
    // 每个月的天数
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 如果是闰年，二月有29天
    if (isLeapYear(year))
    {
        monthDays[1] = 29;
    }

    // 计算日期在一年中的第几天
    int totalDays = day;
    for (int i = 0; i < month - 1; i++)
    {
        totalDays += monthDays[i];
    }

    return totalDays;
}

int main()
{
    int year, month, day;
    printf("请输入年、月、日：\n");
    scanf("%d %d %d", &year, &month, &day);
    int result = dayOfYear(year, month, day);
    printf("这是这一年的第%d天\n", result);
    return 0;
}

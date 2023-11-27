#include <stdio.h>

int main()
{
    int a;                // 定义一个整数变量a
    int n;                // 定义一个整数变量n
    int temp = 0;         // 定义一个整数变量temp，并初始化为0
    int sum = 0;          // 定义一个整数变量sum，并初始化为0
    printf("请输入数字"); // 提示用户输入数字
    scanf("%d", &a);      // 读取用户输入的数字并赋值给变量a
    printf("请输入n");    // 提示用户输入n
    scanf("%d", &n);      // 读取用户输入的n并赋值给变量n

    if (a == 0 || n == 0)
    {                      // 如果a或n等于0
        printf("%d\n", 0); // 打印0
    }
    else
    { // 否则
        for (int i = 0; i < n; i++)
        {                             // 对于0到n-1的每一个i
            temp = temp * 10 + a;     // 计算temp*10 + a的值并赋值给temp
            sum += temp;              // 将temp的值累加到sum上
        }
    }

    printf("%d\n", sum); // 打印sum的值

    return 0; // 返回0，表示程序正常结束
}

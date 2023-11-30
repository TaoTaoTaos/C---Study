#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*程序的主要步骤如下：

1.用户输入四个1-13的数，这四个数存储在数组a[]中。
2.通过三层嵌套循环，遍历所有可能的运算符组合。
运算符存储在数组ope[]中，包括加、减、乘、除四种运算符。
3.对于每种运算符组合，程序计算五种不同的表达式的值。
这五种表达式分别是
((A_B)C)D、
(A(B_C))D、
A((B_C)D)、
A(B(C_D))、
(A_B)_(C_D)
其中，A、B、C、D是用户输入的四个数，_代表运算符。

如果某个表达式的值等于24，程序就打印出这个表达式。

穷举很简单，关键就是理清三层循环*/

int a[4];                           // 数组a[]用于存放用户输入的四个操作数
char ope[4] = {'+', '-', '*', '/'}; // 数组ope[]用于存放四类运算符

// num()函数用于让用户输入四个1-13的数，并存储在数组a[]中。
void num()
{
    int i;

    for (i = 0; i < 4; i++)
    {
        printf("请输入第%d个数（1-13）：", i + 1);
        scanf("%d", &a[i]);
        while (a[i] < 1 || a[i] > 13)
        {
            printf("输入错误，请输入一个1-13的数：");
            scanf("%d", &a[i]);
        }
    }
    for (i = 0; i < 4; i++)
    {
        printf("第%d张牌：%d\n", i + 1, a[i]);
    }
}

// cal()函数接收两个整数和一个运算符作为参数，根据运算符对两个整数进行相应的运算，并返回结果。
int cal(int x, int y, char ope)
{
    int z;
    if (ope == '+')
        z = x + y;
    else if (ope == '-')
        z = x - y;
    else if (ope == '*')
        z = x * y;
    else if (ope == '/')
        z = x / y;

    return z;
}

// express_1()函数接收四个整数和三个运算符作为参数，计算表达式((A_B)_C)_D的值，并返回结果。
int express_1(int i, int j, int k, int t, char ope1, char ope2, char ope3)
{
    int x1, x2, x3;
    x1 = cal(i, j, ope1);
    x2 = cal(x1, k, ope2);
    x3 = cal(x2, t, ope3);

    return x3;
}

// express_2()函数接收四个整数和三个运算符作为参数，计算表达式(A_(B_C))_D的值，并返回结果。
int express_2(int i, int j, int k, int t, char ope1, char ope2, char ope3)
{
    int x1, x2, x3;
    x1 = cal(j, k, ope2);
    x2 = cal(i, x1, ope1);
    x3 = cal(x2, t, ope3);

    return x3;
}

// express_3()函数接收四个整数和三个运算符作为参数，计算表达式A_((B_C)_D)的值，并返回结果。
int express_3(int i, int j, int k, int t, char ope1, char ope2, char ope3)
{
    int x1, x2, x3;
    x1 = cal(j, k, ope2);
    x2 = cal(x1, t, ope3);
    x3 = cal(i, x2, ope1);

    return x3;
}

// express_4()函数接收四个整数和三个运算符作为参数，计算表达式A_(B_(C_D))的值，并返回结果。
int express_4(int i, int j, int k, int t, char ope1, char ope2, char ope3)
{
    int x1, x2, x3;
    x1 = cal(k, t, ope3);
    x2 = cal(j, x1, ope2);
    x3 = cal(i, x2, ope1);

    return x3;
}

// express_5()函数接收四个整数和三个运算符作为参数，计算表达式(A_B)_(C_D)的值，并返回结果。
int express_5(int i, int j, int k, int t, char ope1, char ope2, char ope3)
{
    int x1, x2, x3;
    x1 = cal(i, j, ope1);
    x2 = cal(k, t, ope3);
    x3 = cal(x1, x2, ope2);

    return x3;
}

void game1() // 输入数字，系统自己解答
{
    num(); // 获取输入的数字

    int i, j, k, t;
    i = a[0];
    j = a[1];
    k = a[2];
    t = a[3];

    int x, y, z;
    char p, q, r;

    int flag = 0; // 添加一个标志变量，初始值为0

    for (x = 0; x < 4; x++) // 三层循环遍历所有可能的情况，遇到==24的情况就打印出这个表达式，并将标志变量设置为1
    {
        p = ope[x];
        for (y = 0; y < 4; y++)
        {
            q = ope[y];
            for (z = 0; z < 4; z++)
            {
                r = ope[z];
                if (express_1(i, j, k, t, p, q, r) == 24)
                {
                    printf("((%d %c %d) %c %d) %c %d = 24\n", i, p, j, q, k, r, t);
                    flag = 1; // 如果找到了满足条件的表达式，就把标志变量设为1
                }
                if (express_2(i, j, k, t, p, q, r) == 24)
                {
                    printf("(%d %c (%d %c %d)) %c %d = 24\n", i, p, j, q, k, r, t);
                    flag = 1;
                }
                if (express_3(i, j, k, t, p, q, r) == 24)
                {
                    printf("%d %c ((%d %c %d) %c %d) = 24\n", i, p, j, q, k, r, t);
                    flag = 1;
                }
                if (express_4(i, j, k, t, p, q, r) == 24)
                {
                    printf("%d %c (%d %c (%d %c %d)) = 24\n", i, p, j, q, k, r, t);
                    flag = 1;
                }
                if (express_5(i, j, k, t, p, q, r) == 24)
                {
                    printf("(%d %c %d) %c (%d %c %d) = 24\n", i, p, j, q, k, r, t);
                    flag = 1;
                }
            }
        }
    }

    if (flag == 0) // 如果所有的循环结束后，标志变量仍然为0，就输出"没有值等于24"
    {
        printf("这四张牌组合不了24\n");
    }

    if (flag == 1)
    { // 如果标志变量为1
        printf("\n");
        printf("所有能够出现24点的表达式有这些：\n");
    }
}
void game2()
{
    srand(time(NULL)); // 用当前时间作为随机数种子
    int a[4];
    for (int i = 0; i < 4; i++)
    {
        a[i] = rand() % 13 + 1; // 生成1到13的随机数
    }

    int i, j, k, t;
    i = a[0];
    j = a[1];
    k = a[2];
    t = a[3];

    printf("电脑生成的四个数字是：%d, %d, %d, %d\n", i, j, k, t);
    printf("请尝试解答，如果无法解答，输入'1'来查看答案。\n");
     char user_input[100];
    scanf("%s", user_input);

if(strcmp(user_input, "1") == 0) 


    {

    int x, y, z;
    char p, q, r;

    int flag = 0; // 添加一个标志变量，初始值为0

    for (x = 0; x < 4; x++) // 三层循环遍历所有可能的情况，遇到==24的情况就打印出这个表达式，并将标志变量设置为1
    {
        p = ope[x];
        for (y = 0; y < 4; y++)
        {
            q = ope[y];
            for (z = 0; z < 4; z++)
            {
                r = ope[z];
                if (express_1(i, j, k, t, p, q, r) == 24)
                {
                    printf("((%d %c %d) %c %d) %c %d = 24\n", i, p, j, q, k, r, t);
                    flag = 1; // 如果找到了满足条件的表达式，就把标志变量设为1
                }
                if (express_2(i, j, k, t, p, q, r) == 24)
                {
                    printf("(%d %c (%d %c %d)) %c %d = 24\n", i, p, j, q, k, r, t);
                    flag = 1;
                }
                if (express_3(i, j, k, t, p, q, r) == 24)
                {
                    printf("%d %c ((%d %c %d) %c %d) = 24\n", i, p, j, q, k, r, t);
                    flag = 1;
                }
                if (express_4(i, j, k, t, p, q, r) == 24)
                {
                    printf("%d %c (%d %c (%d %c %d)) = 24\n", i, p, j, q, k, r, t);
                    flag = 1;
                }
                if (express_5(i, j, k, t, p, q, r) == 24)
                {
                    printf("(%d %c %d) %c (%d %c %d) = 24\n", i, p, j, q, k, r, t);
                    flag = 1;
                }
            }
        }
    }

    if (flag == 0) // 如果所有的循环结束后，标志变量仍然为0，就输出"没有值等于24"
    {
        printf("这四张牌组合不了24\n");
    }

    if (flag == 1)
    { // 如果标志变量为1
        printf("\n");
        printf("所有能够出现24点的表达式有这些：\n");
    }
    }
}
    // main()函数是程序的入口点。它首先打印欢迎信息，然后调用num()函数让用户输入四个数。然后，通过三层嵌套循环，遍历所有可能的运算符组合，对每种组合，计算五种表达式的值，如果某个表达式的值等于24，就打印出这个表达式。

    int main()
    {
        printf("#**************************************#\n");
        printf("#                                      #\n");
        printf("#              欢迎来到                #\n");
        printf("#                                      #\n");
        printf("#             24点小游戏               #\n");
        printf("#                                      #\n");
        printf("#**************************************#\n");

        printf("请按回车开始游戏：\n");
        getchar();

        printf("请选择游戏模式：\n");
        printf("1. 输入四个数字，电脑给出解法\n");
        printf("2. 电脑给出四个数字，你自己解答\n");
        int mode;
        scanf("%d", &mode);
        if (mode == 1)
        {
            game1();
        }
        else if (mode == 2)
        {
            game2();
        }
        else
        {
            printf("无效的游戏模式！\n");
        }

        return 0;
    }

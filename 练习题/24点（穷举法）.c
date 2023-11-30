#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

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
char solutions[1000][100];          // 存储所有可能的解决方案
int solution_count = 0;             // 记录解决方案的数量

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


void find_solutions(int i, int j, int k, int t)
{
    int x, y, z;
    char p, q, r;

    for (x = 0; x < 4; x++)
    {
        p = ope[x];
        for (y = 0; y < 4; y++)
        {
            q = ope[y];
            for (z = 0; z < 4; z++)
            {
                r = ope[z];
                int result1, result2, result3, result4, result5;
                result1 = express_1(i, j, k, t, p, q, r);
                result2 = express_2(i, j, k, t, p, q, r);
                result3 = express_3(i, j, k, t, p, q, r);
                result4 = express_4(i, j, k, t, p, q, r);
                result5 = express_5(i, j, k, t, p, q, r);

                if (result1 == 24)
                {
                    sprintf(solutions[solution_count++], "((%d %c %d) %c %d) %c %d", i, p, j, q, k, r, t);
                }
                if (result2 == 24)
                {
                    sprintf(solutions[solution_count++], "(%d %c (%d %c %d)) %c %d", i, p, j, q, k, r, t);
                }
                if (result3 == 24)
                {
                    sprintf(solutions[solution_count++], "%d %c ((%d %c %d) %c %d)", i, p, j, q, k, r, t);
                }
                if (result4 == 24)
                {
                    sprintf(solutions[solution_count++], "%d %c (%d %c (%d %c %d))", i, p, j, q, k, r, t);
                }
                if (result5 == 24)
                {
                    sprintf(solutions[solution_count++], "(%d %c %d) %c (%d %c %d)", i, p, j, q, k, r, t);
                }
            }
        }
    }
}

void game1()
{
    num(); // 获取输入的数字

    int i, j, k, t;
    i = a[0];
    j = a[1];
    k = a[2];
    t = a[3];

    solution_count = 0;         // 重置解决方案计数器
    find_solutions(i, j, k, t); // 查找所有可能的解决方案

    if (solution_count == 0)
    { // 如果没有找到解决方案，就输出"没有值等于24"
        printf("这四张牌组合不了24\n");
    }
    else
    {
        printf("所有能够出现24点的表达式有这些：\n");
        for (int i = 0; i < solution_count; i++)
        {
            printf("%s\n", solutions[i]);
        }
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

    solution_count = 0;         // 重置解决方案计数器
    find_solutions(i, j, k, t); // 查找所有可能的解决方案

    printf("请用加减乘除运算，使得这四个数的结果为24：\n");
    printf("%d %d %d %d\n", i, j, k, t);

    

    // 在用户输入答案后，检查答案是否在解决方案中
    char user_solution[100];
    printf("请输入您的答案：\n");
    scanf("%s", user_solution);

   
    int s;
    for (s = 0; s < solution_count; s++)
{
    if (strcmp(user_solution, solutions[s]) == 0) 
    {
        printf("恭喜你，答案正确！\n");
        return;
    }
}

    printf("很遗憾，答案错误。\n");
    printf("是否查看答案？(y/n)\n");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        printf("所有可能的解决方案如下：\n");
        for (i = 0; i < solution_count; i++)
        {
            printf("%s\n", solutions[i]);
        }
    }
}
// main()函数是程序的入口点。它首先打印欢迎信息，然后调用num()函数让用户输入四个数。然后，通过三层嵌套循环，遍历所有可能的运算符组合，对每种组合，计算五种表达式的值，如果某个表达式的值等于24，就打印出这个表达式。

int main()
{
    int mode;
    char playAgain;

    printf("#**************************************#\n");
    printf("#                                      #\n");
    printf("#              欢迎来到                #\n");
    printf("#                                      #\n");
    printf("#             24点小游戏               #\n");
    printf("#                                      #\n");
    printf("#**************************************#\n");

    do {
        printf("请按回车开始游戏：\n");
        getchar();

        printf("请选择游戏模式：\n");
        printf("1. 输入四个数字，电脑给出解法\n");
        printf("2. 电脑给出四个数字，你自己解答\n");
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

        printf("你想再玩一次吗？ (y/n)\n");
        scanf(" %c", &playAgain);
    } while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}

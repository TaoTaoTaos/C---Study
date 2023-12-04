#include <stdio.h>

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
double cal(int x, int y, char ope)
{
    double z;
    if (ope == '+')
        z = x + y;
    else if (ope == '-')
        z = x - y;
    else if (ope == '*')
        z = x * y;
    else if (ope == '/')
    {
        if (y != 0)
            z = (double)x / y;
        else
            z = 1e9;  // 如果除数为0，返回一个大数
    }

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

int main()
{
    num();
    find_solutions(a[0], a[1], a[2], a[3]);

    if (solution_count == 0)
    {
        printf("没有找到解决方案。\n");
    }
    else
    {
        printf("找到了%d个解决方案：\n", solution_count);
        for (int i = 0; i < solution_count; i++)
        {
            printf("%s\n", solutions[i]);
        }
    }

    return 0;
}
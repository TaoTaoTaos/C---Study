#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
//----------------------------------------------------------------
//    调用
//    geme1,2是穷举法
//    game3,4是递归法
//----------------------------------------------------------------

/*穷举程序的主要步骤如下：

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
            z = 1e9; // 如果除数为0，返回一个大数
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
    int question_bank[6][4] = {{1, 2, 3, 4}, {6, 1, 4, 1}, {1, 1, 3, 8}, {1, 3, 2, 4}, {6, 2, 2, 1}, {2, 3, 4, 1}};

    // 电脑从题库中随机选择一道题目
    srand(time(NULL));               // 设置随机数种子
    int question_index = rand() % 6; // 生成一个0到5的随机数作为题目索引

    // 将选中的题目的值赋给变量i，j，k和t
    int i = question_bank[question_index][0];
    int j = question_bank[question_index][1];
    int k = question_bank[question_index][2];
    int t = question_bank[question_index][3];

    solution_count = 0;         // 重置解决方案计数器
    find_solutions(i, j, k, t); // 查找所有可能的解决方案

    printf("请用加减乘除运算，使得这四个数的结果为24：\n");
    printf("%d %d %d %d\n", i, j, k, t);

    // 在用户输入答案后，检查答案是否在解决方案中
    char user_solution[100];
    printf("请输入您的答案：\n");

    printf(" 五种允许的格式： \n");
    printf("((A_B)C)D \n");
    printf("(A(B_C))D \n");
    printf(" A((B_C)D) \n");
    printf("A(B(C_D)) \n");
    printf("(A_B)_(C_D) \n");

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
//================================================================================================

double A[4];           // 存储四个数字
char B[4][50];         // 存储四个数字对应的字符
char answers[100][50]; // 存储所有可能的答案
int answer_count = 0;  // 存储答案的数量

// 题库，包含6道题目，每道题目有4个数字
int question_bank[6][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {2, 2, 3, 3}, {1, 3, 2, 4}, {1, 4, 2, 5}, {2, 2, 2, 2}};

// 递归函数F，参数为整数n
void F(int n)
{
    // 如果n为1，检查A[0]是否为24，如果是，打印B[0]并增加计数
    if (n == 1)
    {
        if (fabs(A[0] - 24) < 1e-6)
        {
            // 检查是否已经存在相同的答案
            for (int i = 0; i < answer_count; i++)
            {
                if (strcmp(answers[i], B[0]) == 0)
                {
                    return; // 如果找到相同的答案，就返回
                }
            }

            // 如果没有找到相同的答案，就存储当前的答案
            strcpy(answers[answer_count], B[0]);
            answer_count++;
        }
    }

    // 对于n个数，两两组合进行四则运算
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double a, b;            // 定义两个浮点数a和b
            char x[50], y[50];      // 定义两个长度为50的字符串x和y
            a = A[i];               // 将A[i]的值赋给a
            b = A[j];               // 将A[j]的值赋给b
            A[j] = A[n - 1];        // 将A[n-1]的值赋给A[j]
            strcpy(x, B[i]);        // 将B[i]的值复制给x
            strcpy(y, B[j]);        // 将B[j]的值复制给y
            strcpy(B[j], B[n - 1]); // 将B[n-1]的值复制给B[j]

            // 对a和b进行加法运算，并递归调用函数F
            A[i] = a + b;
            sprintf(B[i], "(%s+%s)", x, y);
            F(n - 1);

            // 对a和b进行减法运算，并递归调用函数F
            A[i] = a - b;
            sprintf(B[i], "(%s-%s)", x, y);
            F(n - 1);
            A[i] = b - a;
            sprintf(B[i], "(%s-%s)", y, x);
            F(n - 1);

            // 对a和b进行乘法运算，并递归调用函数F
            A[i] = a * b;
            sprintf(B[i], "(%s*%s)", x, y);
            F(n - 1);

            // 如果b不为0，对a和b进行除法运算，并递归调用函数F
            if (b != 0)
            {
                A[i] = a / b;
                sprintf(B[i], "(%s/%s)", x, y);
                F(n - 1);
            }
            // 如果a不为0，对b和a进行除法运算，并递归调用函数F
            if (a != 0)
            {
                A[i] = b / a;
                sprintf(B[i], "(%s/%s)", y, x);
                F(n - 1);
            }

            // 还原A[i]、A[j]、B[i]、B[j]的值
            A[i] = a;
            A[j] = b;
            strcpy(B[i], x);
            strcpy(B[j], y);
        }
    }
}

void game3()
{
    printf("请输入四个数字（1-13）：\n");
    for (int i = 0; i < 4; ++i)
    {
        scanf("%lf", &A[i]); // 读取用户输入的数字并存入数组A
    }
    printf("\n");
    // 将用户输入的数字转换为对应的字符并存入数组B
    for (int i = 0; i < 4; i++)
    {
        sprintf(B[i], "%.0lf", A[i]);
    }
    // 调用函数F，参数为n
    F(4);

    printf("\n总共有 %d 种解法\n", answer_count);
    for (int i = 0; i < answer_count; i++)
    {
        printf("%s\n", answers[i]); // 打印所有的答案
    }
}

void game4()
{
    // 电脑从题库中随机选择一道题目
    srand(time(NULL));                // 设置随机数种子
    int question_index = rand() % 10; // 生成一个0到9的随机数作为题目索引
    for (int i = 0; i < 4; ++i)
    {
        A[i] = question_bank[question_index][i]; // 从题库中取出一道题目并存入数组A
        sprintf(B[i], "%.0lf", A[i]);            // 将数字转换为字符并存入数组B
    }
    // 打印出电脑生成的四个数字
    printf("电脑生成的四个数字是：\n");
    for (int i = 0; i < 4; ++i)
    {
        printf("%.0lf ", A[i]);
    }
    printf("\n");

    // 提示用户输入答案
    printf("请输入您的答案：(请在答案中带有小括号，即每次运算一步，就把自己的这步运算用小括号括起来）\n");
    printf("**比如 1 2 3 4 答案格式为 (((1+2)+3)*4) \n");
    char answer[50];     // 定义一个长度为50的字符串answer，用于存储用户输入的答案
    scanf("%s", answer); // 读取用户输入的答案并存入answer

    // 调用函数F，参数为n
    F(4);

    // 检查用户输入的答案是否正确
    int correct = 0; // 定义一个整数correct，用于标记答案是否正确，初始值为0
    for (int i = 0; i < answer_count; i++)
    {
        if (strcmp(answer, answers[i]) == 0)
        {
            correct = 1; // 如果用户输入的答案在answers中，将correct设为1
            break;
        }
    }
    // 根据correct的值打印结果
    if (correct)
        printf("恭喜，您的答案是正确的！\n");
    else
    {
        printf("很遗憾，您的答案是错误的。\n");
    }

    printf("是否查看答案？(y/n)\n");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        for (int i = 0; i < answer_count; i++)
        {
            printf("%s\n", answers[i]); // 打印所有的答案
        }
    }
}

#include <stdio.h>

int main()
{
    int mode, method;
    char playAgain;

    do
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

        printf("请选择解题方法：\n");
        printf("1. 穷举法\n");
        printf("2. 递归法\n");
        scanf("%d", &method);

        printf("请选择游戏模式：\n");
        printf("1. 输入四个数字，电脑给出解法\n");
        printf("2. 电脑给出四个数字，你自己解答\n");
        scanf("%d", &mode);

        if (method == 1)
        {
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
        }
        else if (method == 2)
        {
            if (mode == 1)
            {
                game3();
            }
            else if (mode == 2)
            {
                game4();
            }
            else
            {
                printf("无效的游戏模式！\n");
            }
        }
        else
        {
            printf("无效的解题方法！\n");
        }

        printf("你想再玩一次吗？(Y/N)\n");
        getchar(); // 清除缓冲区中的换行符
        scanf("%c", &playAgain);

        // 重置数据
        mode = 0;
        method = 0;

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}

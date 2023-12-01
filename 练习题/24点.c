#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int n = 4;
// 定义一个整数n，值为4
int A[4] = {0};
// 定义一个长度为4的整数数组A，所有元素初始化为0
char oper[4] = {'+', '-', '*', '/'};
// 定义一个长度为4的字符数组oper，存储四种运算符
char B[4][50];
// 定义一个二维字符数组B，可以看作是4个长度为50的字符串
int count = 0;
// 定义一个整数count，用于计数，初始值为0

/*这个递归函数F的主要目标是找出所有可能的通过加、减、乘、除运算使得四个数字的结果为24的方式。

函数的工作原理如下：

如果n等于1，那么检查A[0]是否等于24。如果是，那么打印B[0]并增加计数器count。
对于n个数，两两组合进行四则运算。这是通过两个嵌套的for循环实现的，其中i和j是数组A的索引。
对于每一对数字a和b（a是A[i]，b是A[j]），执行以下步骤：
执行加法运算a + b，并递归调用函数F(n - 1)。
执行减法运算a - b和b - a，并分别递归调用函数F(n - 1)。
执行乘法运算a * b，并递归调用函数F(n - 1)。
如果b不为0，执行除法运算a / b，并递归调用函数F(n - 1)。
如果a不为0，执行除法运算b / a，并递归调用函数F(n - 1)。
在每次运算后，都会更新A[i]和B[i]的值。A[i]存储运算结果，B[i]存储运算表达式。
在每次运算前后，都会保存和恢复A[i]、A[j]、B[i]、B[j]的值，以确保在每次递归调用中，数组A和B的其他元素不会被改变。
这个函数通过递归的方式枚举了所有可能的运算顺序和运算方式，从而找出所有可能的解。最后，函数F(n)会返回到main()函数中，打印出总共有多少种解法。*/

char answers[100][50]; // 存储所有可能的答案
int answer_count = 0;  // 存储答案的数量
// 递归函数F，参数为整数n
void F(int n)
{
    // 如果n为1，检查A[0]是否为24，如果是，打印B[0]并增加计数
    if (n == 1)
    {
        if (A[0] == 24)
        {
            strcpy(answers[answer_count], B[0]); // 将答案存储在answers中
            answer_count++;                      // 增加答案的数量
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

void game1()
{
    printf("请输入四个数字（1-13）：\n");
    for (int i = 0; i < 4; ++i)
    {
        scanf("%d", &A[i]); // 读取用户输入的数字并存入数组A
    }
    printf("\n");
    // 将用户输入的数字转换为对应的字符并存入数组B
    for (int i = 0; i < 4; i++)
    {
        if (A[i] == 1)
            strcpy(B[i], "A");
        else if (A[i] == 11)
            strcpy(B[i], "J");
        else if (A[i] == 12)
            strcpy(B[i], "Q");
        else if (A[i] == 13)
            strcpy(B[i], "K");
        else
            sprintf(B[i], "%d", A[i]);
    }
    // 调用函数F，参数为n
    F(n);

    printf("\n总共有 %d 种解法\n", answer_count);
    for (int i = 0; i < answer_count; i++)
    {
        printf("%s\n", answers[i]); // 打印所有的答案
    }
}

void game2()
{
    // 电脑随机生成四个数字
    srand(time(NULL)); // 设置随机数种子
    for (int i = 0; i < 4; ++i)
    {
        A[i] = rand() % 13 + 1; // 生成一个1到13的随机数并存入数组A
    }
    // 打印出电脑生成的四个数字
    printf("电脑生成的四个数字是：\n");
    for (int i = 0; i < 4; ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // 提示用户输入答案
    printf("请输入您的答案：\n");
    char answer[50];     // 定义一个长度为50的字符串answer，用于存储用户输入的答案
    scanf("%s", answer); // 读取用户输入的答案并存入answer

    // 调用函数F，参数为n
    F(n);





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
        printf("您想查看答案吗？（1-是，2-否）：\n");
        int choice;           // 定义一个整数choice，用于存储用户是否想查看答案
        scanf("%d", &choice); // 读取用户的选择并存入choice
        if (choice == 1)
        {
            printf("正确答案是：\n");
            for (int i = 0; i < answer_count; i++)
            {
                printf("%s\n", answers[i]); // 打印所有的答案
            }
        }
    }
}

int main()
{
    int mode;        // 定义一个整数mode，用于存储用户选择的游戏模式
    char play_again; // 定义一个字符play_again，用于存储用户是否想再玩一次

    do
    {
        // 打印欢迎信息
        printf("#**************************************#\n");
        printf("#                                      #\n");
        printf("#              欢迎来到                #\n");
        printf("#                                      #\n");
        printf("#             24点小游戏               #\n");
        printf("#                                      #\n");
        printf("#**************************************#\n");

        // 提示用户选择游戏模式
        printf("1. 输入四个数字，电脑给出解法\n");
        printf("2. 电脑给出四个数字，你自己解答\n");
        scanf("%d", &mode); // 读取用户输入的游戏模式并存入mode

        if (mode == 1)
        {
            game1();
        }
        else if (mode == 2)
        {
            game2();
        }

        // 提示用户是否想再玩一次
        printf("你想再玩一次吗？（y/n）：\n");
        scanf(" %c", &play_again);                    // 读取用户的选择并存入play_again
    } while (play_again == 'y' || play_again == 'Y'); // 如果用户选择'y'或'Y'，则继续循环

    return 0; // 主函数返回0
}

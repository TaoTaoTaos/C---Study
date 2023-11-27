/*
要求：
输入1到13的4个整数，看通过加减乘除四种运算，能不能得到24这个结果，如果可以，则输出所有组合情况，而且要用括号表示运算的优先级，如果不行，则输出没有可行的结果。

思路和算法的原理：
1. 首先，我们需要一个函数来生成所有可能的 运算符 组合。
2. 然后，我们需要一个函数来生成所有可能的 数字 组合。
3. 最后，我们需要一个函数来计算每个数字和运算符组合的结果，并检查是否等于24。

*/

#include <stdio.h>




/*
1.生成所有可能的运算符组合的函数
我们可以使用递归来生成所有可能的运算符组合。首先，我们创建一个数组来存储运算符，然后我们使用递归函数来添加每个可能的运算符到数组中，直到数组的长度等于数字的数量减一。
*/

char operators[] = {'+', '-', '*', '/'};// 运算符数组

void generate_operator_combinations(char *combination, int length, int n)
{
    // 如果组合的长度等于n-1，那么就输出这个组合
    if (length == n - 1)
    {
        combination[length] = '\0';
        printf("%s\n", combination);
        return;
    }

    // 对于每一个可能的运算符，我们都尝试把它添加到组合中，然后递归地生成剩余的组合
    for (int i = 0; i < 4; i++)
    {
        combination[length] = operators[i];
        generate_operator_combinations(combination, length + 1, n);
    }
}



/*
2.生成所有可能的数字组合的函数
我们可以使用递归来生成所有可能的数字组合。首先，我们创建一个数组来存储数字，然后我们使用递归函数来添加每个可能的数字到数组中，直到数组的长度等于4。
*/

void generate_number_combinations(int *numbers, int *combination, int length, int n)
{
    // 如果组合的长度等于n，那么就输出这个组合
    if (length == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", combination[i]);
        }
        printf("\n");
        return;
    }

    // 对于每一个可能的数字，我们都尝试把它添加到组合中，然后递归地生成剩余的组合
    for (int i = 0; i < n; i++)
    {
        int is_used = 0;
        for (int j = 0; j < length; j++)
        {
            if (combination[j] == numbers[i])
            {
                is_used = 1;
                break;
            }
        }
        if (!is_used)
        {
            combination[length] = numbers[i];
            generate_number_combinations(numbers, combination, length + 1, n);
        }
    }
}


//计算函数，因为我们是通过遍历char数组来获取运算符的，所以要有这个函数来转化
double calculate(double a, double b, char operator)
{
    switch (operator)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b != 0)
        {
            return a / b;
        }
        else
        {
            return 0;
        }
    default:
        return 0;
    }
}

// 计算每个数字和运算符组合的函数
void calculate_combinations(int *numbers, char *operators, int n)
{
    // 创建一个栈来存储数字
    double *stack = (double *)malloc(n * sizeof(double));
    int top = -1;

    // 遍历数字和运算符的数组
    for (int i = 0; i < n; i++)
    {
        // 如果我们遇到一个数字，我们就把它压入栈中
        if (operators[i] == '\0')
        {
            stack[++top] = numbers[i];
        }
        else
        {
            // 如果我们遇到一个运算符，我们就从栈中弹出两个数字，进行运算，然后把结果压入栈中
            double b = stack[top--];
            double a = stack[top--];
            double result = calculate(a, b, operators[i]);
            stack[++top] = result;
        }
    }

    // 最后，栈中的数字就是表达式的结果
    double result = stack[top--];

    
    if (result - 24 < 0.000000000000000001)
    {
        printf("Yes\n");
        
    }
    else
    {
        printf("No\n");
    }

    free(stack);
}
int main()
{
    // 输入1到13的4个整数
    int numbers[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // 生成所有可能的运算符组合
    char operator_combinations[4];
    generate_operator_combinations(operator_combinations, 0, 4);

    // 生成所有可能的数字组合
    int number_combinations[4];
    generate_number_combinations(numbers, number_combinations, 0, 4);

    // 计算每个数字和运算符组合的结果，并检查是否等于24
    calculate_combinations(numbers, operator_combinations, 4);

    return 0;
}

/*
总结并解释题目所考察的知识点：
这个问题主要考察了如何使用递归来生成所有可能的组合，以及如何使用栈来计算表达式的值。

//!关键问题1：如何生成所有可能的运算符组合？
解释：我们可以使用递归来生成所有可能的运算符组合。首先，我们创建一个数组来存储运算符，然后我们使用递归函数来添加每个可能的运算符到数组中，直到数组的长度等于数字的数量减一。

//!关键问题2：如何生成所有可能的数字组合？
解释：我们可以使用递归来生成所有可能的数字组合。首先，我们创建一个数组来存储数字，然后我们使用递归函数来添加每个可能的数字到数组中，直到数组的长度等于数字的数量。

//!关键问题3：如何计算每个数字和运算符组合的结果？
解释：我们可以使用栈来计算每个数字和运算符组合的结果。首先，我们创建一个栈来存储数字和运算符，然后我们遍历数字和运算符的数组，如果我们遇到一个数字，我们就把它压入栈中，如果我们遇到一个运算符，我们就从栈中弹出两个数字，进行运算，然后把结果压入栈中，最后，栈中的数字就是表达式的结果。
*/

#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001 // 定义一个非常小的值，用于处理浮点数的比较

char ops[3]; //char类型数组ops  存放+ - * /  保存操作的顺序和使用的运算符
int order[4]; // order数组用于保存数字的顺序

int compute(int *nums, int n)  
{
    if (n == 1)
    {
        if (fabs(nums[0] - 24) < EPSILON)
        {
            printf("可行的解法: ");
            for (int i = 0; i < 3; i++)
            {
                printf("%d %c ", order[i], ops[i]);
            }
            printf("%d\n", order[3]);
            return 1;
        }
        else
        {
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a = nums[i];
            int b = nums[j];
            nums[j] = nums[n - 1];
            order[j] = order[n - 1];

            nums[i] = a + b;
            ops[n - 2] = '+';
            if (compute(nums, n - 1))
                return 1;

            nums[i] = a - b;
            ops[n - 2] = '-';
            if (compute(nums, n - 1))
                return 1;

            nums[i] = b - a;
            ops[n - 2] = '-';
            if (compute(nums, n - 1))
                return 1;

            nums[i] = a * b;
            ops[n - 2] = '*';
            if (compute(nums, n - 1))
                return 1;

            if (b != 0)
            {
                nums[i] = a / b;
                ops[n - 2] = '/';
                if (fabs(nums[i] - 24) < EPSILON && compute(nums, n - 1))
                    return 1;
            }

            if (a != 0)
            {
                nums[i] = b / a;
                ops[n - 2] = '/';
                if (fabs(nums[i] - 24) < EPSILON && compute(nums, n - 1))
                    return 1;
            }

            nums[i] = a;
            nums[j] = b;
            order[j] = order[n - 1];
        }
    }

    return 0;
}

int main()
{
    int nums[4];
    printf("请输入四个数字：\n");
    for (int i = 0; i < 4; i++) 
    {
        scanf("%d", &nums[i]);
        order[i] = nums[i];
    }
    
    if (!compute(nums, 4)) 
    {
        printf("无可行的解法\n");
    }
    return 0;
}

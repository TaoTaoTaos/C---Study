// 题目要求：使用递归法求斐波那契数列
// 思路：斐波那契数列的定义是：第0项是0，第1项是1，第n项是第n-1项和第n-2项的和。我们可以使用这个定义来写一个递归函数。

#include <stdio.h>

// 定义一个递归函数来计算斐波那契数列的第n项
int fibonacci(int n)
{
    // 第0项是0
    if (n == 0)
    {
        return 0;
    }
    // 第1项是1
    else if (n == 1)
    {
        return 1;
    }
    // 第n项是第n-1项和第n-2项的和
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    // 输出斐波那契数列的前10项
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}

// 总结：这个题目主要考察了递归函数的使用，以及如何根据斐波那契数列的定义来写递归函数。
// 关键注释：return fibonacci(n - 1) + fibonacci(n - 2); 这行代码是递归的关键，它实现了斐波那契数列的定义。

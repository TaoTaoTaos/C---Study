// 题目要求：设计一个算法，计算有n个节点的二叉树有多少种。

// 思路：我们可以使用卡特兰数的性质来解决这个问题。对于有n个节点的二叉树，其种类数等于第n个卡特兰数。

#include <stdio.h>

// 计算阶乘
long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// 计算卡特兰数
long long catalan(int n)
{
    // Cn = (2n)! / ((n+1)! * n!)
    long long c = factorial(2 * n) / (factorial(n + 1) * factorial(n));
    return c;
}

// 计算有n个节点的二叉树的种类数
long long countBinaryTrees(int n)
{
    // 二叉树的种类数等于第n个卡特兰数
    return catalan(n);
}

int main()
{
    int n = 3;
    printf("有%d个节点的二叉树有%lld种\n", n, countBinaryTrees(n));
    return 0;
}

// 总结：本题主要考察了卡特兰数的应用和阶乘的计算。通过计算第n个卡特兰数，我们可以得到有n个节点的二叉树的种类数。在这个过程中，阶乘的计算是关键，它可以帮助我们计算卡特兰数的值。
// //!关键注释：在这个问题中，关键的部分是如何计算卡特兰数。我们需要计算(2n)!、(n+1)!和n!，然后用(2n)!除以((n+1)! * n!)，得到的结果就是第n个卡特兰数，也就是有n个节点的二叉树的种类数。

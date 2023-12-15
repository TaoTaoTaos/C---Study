/*
题目要求：
输入两个正整数m和n，求其最大公约数和最小公倍数。

思路：
1. 使用辗转相除法求最大公约数。
2. 使用公式：两数之积 = 最大公约数 * 最小公倍数，求最小公倍数。
*/

#include <stdio.h>

// 定义一个函数，使用辗转相除法求最大公约数
int gcd(int a, int b)
{                           //! 辗转相除法，也叫欧几里得算法，是求最大公约数的一种方法。
    return b == 0 ? a : gcd(b, a % b); //! 当b等于0时，a就是最大公约数。否则，继续递归调用gcd函数，直到b为0。
}

int main()
{
    int m, n;
    printf("请输入两个正整数：");
    scanf("%d%d", &m, &n); // 输入两个正整数

    int g = gcd(m, n);               // 调用gcd函数求最大公约数
    printf("最大公约数是：%d\n", g); // 输出最大公约数

    int l = m * n / g;               // 使用公式求最小公倍数
    printf("最小公倍数是：%d\n", l); // 输出最小公倍数

    return 0;
}

/*
总结：
本题主要考察了辗转相除法（欧几里得算法）的应用，以及最大公约数和最小公倍数的求解方法。
关键注释：
1. "return b == 0 ? a : gcd(b, a % b);" 这是辗转相除法的核心代码，通过递归实现。
2. "int l = m * n / g;" 这是求最小公倍数的公式，两数之积等于最大公约数和最小公倍数的乘积。
*/

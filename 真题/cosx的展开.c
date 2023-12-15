#include <stdio.h>
#include <math.h>

double factorial(int n)
{
    double fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

double cos_taylor(double x)
{
    double term = 1, sum = 1;
    for (int n = 1; fabs(term) > 1e-5; n++)
    {
        term *= -x * x / ((2 * n - 1) * (2 * n));
        sum += term;
    }
    return sum;
}

int main()
{
    double x;
    printf("请输入x的值：\n");
    scanf("%lf", &x);
    printf("cos(%f)的泰勒展开式的近似值为：%f\n", x, cos_taylor(x));
    return 0;
}

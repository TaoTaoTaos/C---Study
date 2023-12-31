// 题目要求：编写一个计算梯形面积的函数。函数头是: float area(float t,float b,float h)，其中变量t、b和h分别表示梯形的上底、下底和高。编写主函数从键盘输入梯形的上底、下底和高的值，调用上述函数输出梯形面积（保留小数点后两位)。
// 思路：首先，我们需要定义一个计算梯形面积的函数，该函数接收三个参数：上底、下底和高。然后，我们在主函数中从键盘输入这三个值，并调用上述函数计算梯形的面积。

#include <stdio.h>

// 定义一个计算梯形面积的函数
float area(float t, float b, float h) {
    // 计算梯形面积的公式是：(上底+下底)*高/2
    return (t + b) * h / 2;
}

int main() {
    // 定义变量存储上底、下底和高的值
    float t, b, h;

    // 从键盘输入上底、下底和高的值
    printf("请输入梯形的上底、下底和高的值：\n");
    scanf("%f %f %f", &t, &b, &h);

    // 调用函数计算梯形的面积
    float result = area(t, b, h);

    // 输出梯形面积，保留小数点后两位
    printf("梯形的面积是：%.2f\n", result);//! .2f==保留后两位小数

    return 0;
}

// 总结：这个题目主要考察了函数的定义和调用，以及如何从键盘输入数据。同时，也考察了如何使用printf函数控制输出的格式。
// 关键注释：float area(float t, float b, float h) 这行代码是函数定义的关键，它定义了一个计算梯形面积的函数。
// return (t + b) * h / 2; 这行代码是计算梯形面积的关键，它实现了梯形面积的计算公式。
// scanf("%f %f %f", &t, &b, &h); 这行代码是从键盘输入数据的关键，它读取了用户输入的上底、下底和高的值。
// printf("梯形的面积是：%.2f\n", result); 这行代码是输出结果的关键，它将计算出的梯形面积输出到屏幕上，保留了小数点后两位。

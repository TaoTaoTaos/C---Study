//编写程序求所有满足下列条件的三位数:它除以11等于它各位数字的平方
//例如,550除以11商50,
//而5^2+5^2+0=50

#include <stdio.h>

int main() {
    for (int i = 100; i < 1000; i++) { // 遍历所有的三位数
        int a = i / 100; // 百位数
        int b = (i % 100) / 10; // 十位数
        int c = i % 10; // 个位数

        if (i / 11 == a*a + b*b + c*c) { // 如果这个数除以11的余数等于它各位数字的平方和
            printf("%d\n", i); // 打印这个数
        }
    }

    return 0;
}

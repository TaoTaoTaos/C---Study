#include <stdio.h> // 引入标准输入输出库

int main() {
    int i; // 定义一个整数变量i，用于循环

    printf("1-99之间的同构数有：\n");
    for(i = 1; i < 100; i++) { // 从1到99循环
        if(i == (i * i) % 100) 
        
            //!当我们对一个数 n 使用 % 100 运算，实际上就是求 n 的最后两位数字。
            //!同理，想要一个数字 n 的最后一位数字，可以用 n % 10 运算。
        { 

            printf("%d ", i); // 输出这个同构数
        }
    }

    return 0;
}

#include <stdio.h>

// 题目要求：设计一个函数，使得给出一个16位整数的原码，能够得到该数的补码。
short complement(short num) {
    // 如果num为正数，直接返回num
    if (num >= 0) {
        return num;
    } else {
        // 如果num为负数，先取绝对值，然后取反，最后加1
        return ~(-num) + 1;
    }
}

int main() {
    short num = -12345;
    printf("The complement of %d is %d\n", num, complement(num));
    return 0;
}

//!解决该问题的关键是理解补码的计算方法：对于正数，原码、反码和补码都是一样的；对于负数，补码是原码取反后加1。在C语言中，可以使用按位取反运算符~来取反，然后加1得到补码。
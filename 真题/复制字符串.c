// 题目要求：编写一程序,将一字符串的第K个字符开始的全部字符复制成为另外一个字符串。
// 思路：首先，我们需要创建一个函数来复制字符串。然后，在主函数中，我们将获取用户输入的字符串和K值，并调用复制函数。最后，我们将输出复制的结果。

#include <stdio.h>

// 复制函数
void copy_string(char *source, char *target, int k)
{
    // 使用指针从源字符串的第k个字符开始复制
    source = source + k - 1;
    while (*source != '\0')
    {
        *target = *source;//! 指针指向数组的第一位
        source++;
        target++;
    }
    *target = '\0';
}

int main()
{
    char source[100], target[100]; // 定义源字符串和目标字符串
    int k;                         // 定义K值

    printf("请输入字符串：\n");
    gets(source); // 获取用户输入的字符串
    printf("请输入K值：\n");
    scanf("%d", &k); // 获取用户输入的K值

    copy_string(source, target, k); // 调用复制函数

    printf("复制的结果是：%s\n", target); // 输出复制的结果

    return 0;
}

// 总结：本题主要考察了字符串的操作和函数的使用。我们使用了指针来复制字符串，这是C语言中的一个重要概念，可以方便地复制字符串。同时，我们也学习了如何创建和使用函数，这是编程中的一个重要概念。通过将复制过程封装到一个函数中，我们可以使代码更加清晰和易于理解。
// 关键注释：
// 1. source = source + k - 1; 这行代码是复制操作的关键。我们通过改变源字符串的指针位置，从第k个字符开始复制。
// 2. copy_string(source, target, k); 这行代码是调用复制函数的地方。我们将用户输入的字符串和K值传递给函数，然后函数会将复制的结果存储在目标字符串中。

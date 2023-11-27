/*
题目要求：
检查一个字符串是否是回文。如果是回文，它会输出“回文”，否则，它会输出“不是回文”。

思路：
1. 初始化两个指针，一个指向字符串的开始，一个指向字符串的结束。
2. 同时移动这两个指针，一个向后移动，一个向前移动。
3. 如果两个指针指向的字符不相等，那么这个字符串就不是回文。
4. 如果两个指针相遇或者交叉，那么这个字符串就是回文。
*/

#include <stdio.h>
#include <string.h>
//!字符串的本质是一个数组
int main() {
    char str[100];
    printf("请输入一个字符串：");
    scanf("%s", str); //输入一个字符串

    int len = strlen(str); //! 获取字符串的长度
    int i = 0, j = len - 1; //! 初始化两个指针，一个指向字符串的开始，一个指向字符串的结束

    while (i < j) { //! 当两个指针没有相遇或者交叉时，继续循环
        if (str[i] != str[j]) { //! 如果有两个指针指向的字符不相等，那么这个字符串就不是回文
            printf("不是回文\n");
            return 0;
        }
        i++; //! 指向字符串开始的指针向后移动
        j--; //! 指向字符串结束的指针向前移动
    }

    printf("回文\n"); //! 如果两个指针相遇或者交叉，那么这个字符串就是回文
    return 0;
}

/*
总结：
本题主要考察了回文的定义和判断方法。
关键注释：
1. "if (str[i] != str[j])" 这是判断两个指针指向的字符是否相等的条件，如果不相等，那么这个字符串就不是回文。
2. "i++; j--;" 这是移动两个指针的代码，一个向后移动，一个向前移动。
*/

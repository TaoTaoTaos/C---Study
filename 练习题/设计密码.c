#include <stdio.h> // 引入标准输入输出库

int main() { // 主函数
    char c1 = 'C', c2 = 'h', c3 = 'i', c4 = 'n', c5 = 'a'; // 定义并初始化五个字符变量

    c1 = c1 + 4; // 将c1的ASCII值增加4
    c2 = c2 + 4; // 将c2的ASCII值增加4
    c3 = c3 + 4; // 将c3的ASCII值增加4
    c4 = c4 + 4; // 将c4的ASCII值增加4
    c5 = c5 + 4; // 将c5的ASCII值增加4

    printf("%c%c%c%c%c\n", c1, c2, c3, c4, c5); // 输出转换后的字符

    return 0; // 返回0，表示程序正常结束
}

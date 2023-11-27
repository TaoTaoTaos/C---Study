#include <stdio.h>

int main() {
    //! 输入一行字符，分别统计出其中英文字母、数字、空格和其他字符的个数。
    char ch;
    int letters = 0, space = 0, digit = 0, other = 0;
    printf("请输入一行字符：\n");
    while((ch = getchar()) != '\n') { // 读取字符，直到遇到换行符
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) // 判断是否为英文字母
            letters++;
        else if (ch >= '0' && ch <= '9') // 判断是否为数字
            digit++;
        else if (ch == ' ') // 判断是否为空格
            space++;
        else // 其他字符
            other++;
    }
    printf("字母的数量为：%d\n", letters);
    printf("数字的数量为：%d\n", digit);
    printf("空格的数量为：%d\n", space);
    printf("其他字符的数量为：%d\n", other);
    return 0;
}

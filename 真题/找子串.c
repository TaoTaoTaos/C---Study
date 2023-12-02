#include <stdio.h>  // 包含标准输入输出库
#include <string.h> // 包含字符串处理函数库

// cmpsubstr函数，用于判断子串在主串中的位置
int cmpsubstr(char *mainstr, char *substr)
{
    int len_main = strlen(mainstr); // 计算主串长度
    int len_sub = strlen(substr);   // 计算子串长度
    for (int i = 0; i <= len_main - len_sub; i++)
    { // 遍历主串
        int j;
        for (j = 0; j < len_sub; j++)
        { // 遍历子串
            if (mainstr[i + j] != substr[j])
            { // 如果字符不匹配，跳出循环
                break;
            }
        }
        if (j == len_sub)
        { // 如果找到子串，返回子串在主串中的位置
            return i;
        }
    }
    return -1; // 如果未找到子串，返回-1
}


int main()
{                                   // 主函数
    char mainstr[100], substr[100]; // 定义主串和子串
    printf("请输入主串：");         // 提示输入主串
    gets(mainstr);                  // 获取主串
    printf("请输入子串：");         // 提示输入子串
    gets(substr);                   // 获取子串

    int position = cmpsubstr(mainstr, substr); // 调用cmpsubstr函数，获取子串在主串中的位置
    if (position != -1)
    {                                                   // 如果找到子串
        printf("子串在主串中的位置是：%d\n", position); // 输出子串在主串中的位置
    }
    else
    {                           // 如果未找到子串
        printf("未找到子串\n"); // 输出未找到子串
    }

    return 0; // 程序结束，返回0
}
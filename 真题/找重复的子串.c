#include <stdio.h> // 包含标准输入输出库
#include <string.h> // 包含字符串处理函数库

//一个函数，它可以找到字符串中重复的子串，并将其简化为计数和子串的形式。我们需要找到重复的子串，而不仅仅是重复的字符。


void simplify_string(char *str)// 定义简化字符串的函数
 { 
    int len = strlen(str); // 使用strlen函数获取字符串长度

    // 外层使用for循环遍历字符串中的每个字符
    for (int i = 0; i < len; i++)
     {
        // 内层对于每个字符，尝试所有可能的子串长度
   for (int length = 1; length <= len - i; length++)//!length变量代表正在检查的子串长度
         {
            //!length子串的长度每次加一
            int count = 0; // 初始化计数器
 
            // 使用while循环和strncmp函数检查子串是否在后面的字符串中重复
            //!while循环，第i个字符 与 后面的子串的第i个字符比较
            while  
            (i + count * length + length <= len  
                     &&
            strncmp(str + i, str + i + count * length, length) == 0) 
                    //!strncmp函数如果两个相等，返回0
                    //! strncmp函数用于比较字符串的前n个字符是否相同
                    //! 这里比较的是前length个
                    //!从 str 的第一位 和  i + count * length，
                    //! count为找到重复的子串数量， count从0开始
                   {
                          count++; // 如果子串重复，增加计数器
                   }

            // 如果找到了重复的子串
            if (count > 1) 
            {
                printf("%d(", count); // 使用printf函数打印重复次数和左括号
                
                for (int j = 0; j < length; j++) // 使用for循环打印子串
                { 
                    printf("%c", str[i + j]); // 使用printf函数打印子串中的字符
                }
                printf(")"); // 使用printf函数打印右括号
                i += count * length - 1; //! 跳过所有重复的部分
                break; // 跳出内层for循环 
            }

            // 如果没有找到重复的子串，打印当前字符
            if (length == len - i) 
            {
                printf("%c", str[i]); // 使用printf函数打印字符
            }
        }
    }
    printf("\n"); // 在字符串结束后打印换行符
}

int main() { // 定义主函数
    char str[] = "CCCCCCCCCCCCCADCADCADAAAC"; // 定义输入的字符串
    simplify_string(str); // 调用simplify_string函数简化字符串
    return 0; // 主函数返回0，表示程序正常结束
}

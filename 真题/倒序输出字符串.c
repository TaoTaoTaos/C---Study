#include <stdio.h>
#include <string.h> // 使用字符串

int main(){
    printf("请输入字符串：");
    char str[100];
    scanf("%s", str); //!  scanf()函数用于从输入流中读取一个字符串，

    int len = strlen(str); //! strlen 获取字符串长度
    for (int i = len - 1; i >= 0; i--)   // 从字符串末尾开始打印
    { 
    //!字符串末尾是'\0' 不输出 
        printf("%c", str[i]);
    }
    printf("\n"); // 输出换行符，使结果更美观

    return 0;
}


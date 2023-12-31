// 题目要求：判断两个正整数是否是同数异形体
// 思路：我们可以通过统计两个数中每个数字出现的次数来判断它们是否是同数异形体。如果两个数中每个数字出现的次数都相同，那么它们就是同数异形体。

#include <stdio.h>

int main() {
    // 定义两个要比较的正整数
    int num1 = 123, num2 = 321;
    // 定义一个数组来存储每个数字出现的次数

    int count1[10] = {0}, count2[10] = {0};

    // 计算num1中每个数字出现的次数
    while (num1) 
    {
        count1[num1 % 10]++;   //! %10来取到数字的个位，并让数组count1中对应位置的数字+1
        num1 /= 10;            //! 除以10来去掉这一位，继续算下一位
    }//!                      一直重复，num1为变为0

    // 计算num2中每个数字出现的次数
    while (num2)
     {
        count2[num2 % 10]++;
        num2 /= 10;
    }

    // !比较两个数中每个数字出现的次数,也就是比较两个数组是否相等
    for (int i = 0; i < 10; i++) 
    {
        if (count1[i] != count2[i])
         {
            printf("不是同数异形体\n");
            return 0;
        }
    }

    printf("是同数异形体\n");
    return 0;
}

//! 这个问题主要考察了对数组的使用和对循环的控制。关键在于如何统计每个数字出现的次数，我们可以通过取余和除法操作来得到每个数字，然后用数组来存储每个数字出现的次数。最后，我们只需要比较两个数组是否相同即可。

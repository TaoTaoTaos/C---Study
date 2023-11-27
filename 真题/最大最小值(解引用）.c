//!使用指针作为函数参数来找出一维数组中的最大和最小元素

//!指针作为函数参数，意思就是 main 函数中把值的地址传进去， 在find函数中用*来解引用
#include <stdio.h>  // 引入标准输入输出库

// 函数声明
void findMinMax(int* arr, int n, int* min, int* max);

int main() {
    int arr[] = {1, 2, 3, 4, 5};  // 定义一个一维数组
    int min, max;  // 最小值和最大值变量

    // 调用函数，传入数组，数组长度，最小值和最大值的地址
    findMinMax(arr, sizeof(arr)/sizeof(arr[0]), &min, &max);//!这里把地址传进去

    printf("最小值: %d\n", min);  // 输出最小值
    printf("最大值: %d\n", max);  // 输出最大值

    return 0;
}

// 函数定义
void findMinMax(int* arr, int n, int* min, int* max) //!函数里用*解引用
{
    *min = *max = arr[0];  //!  初始化最小值和最大值为数组的第一个元素
    for(int i = 1; i < n; i++) 
    {  // 遍历数组中的每一个元素
        if(arr[i] < *min)
         {  // 如果当前元素小于最小值，则更新最小值
            *min = arr[i];
        }
        if(arr[i] > *max)
         {  // 如果当前元素大于最大值，则更新最大值
            *max = arr[i];
        }
    }
}
//这个程序首先会接收两个长度为5的数组，然后对这两个数组进行升序排序，最后将这两个数组合并成一个新的数组。

#include <stdio.h>  // 引入标准输入输出库
#include <stdlib.h> // 引入标准库

// 函数声明
void sort(int arr[], int n); // 对数组进行排序
void merge(int arr1[], int arr2[], int arr3[], int n, int m); // 合并两个数组

int main() {
    int arr1[5], arr2[5], arr3[10]; // 定义两个长度为5的数组和一个长度为10的数组
    int i;

    // 输入第一个数组
    printf("请输入第一个数组的5个元素：\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", & arr1[i]);
    }

    // 输入第二个数组
    printf("请输入第二个数组的5个元素：\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", & arr2[i]);
    }

    // 对两个数组进行排序
    sort(arr1, 5);
    sort(arr2, 5);

    // 合并两个数组
    merge(arr1, arr2, arr3, 5, 5);

    // 输出合并后的数组
    printf("合并后的数组是：\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}

// 使用冒泡排序对数组进行排序
void sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];       //! j 走一步排序一次，它不停带着一个大的值往后走
                arr[j] = arr[j+1];
                arr[j+1] = temp;   
            }
        }
    }
}

// 合并两个已排序数组
//这个合并数组的算法是基于两个//!  已排序数组的特性。
//它从两个数组的第一个元素开始，比较它们的大小，将较小的元素放入新的数组，并将对应的索引向前移动一位。然后，再次比较两个数组当前索引位置的元素，将较小的元素放入新的数组，以此类推，直到一个数组的所有元素都被放入新的数组。然后，将另一个数组剩余的元素依次放入新的数组。这样，新的数组就是两个输入数组的有序合并。


void merge(int arr1[], int arr2[], int arr3[], int n, int m) //!n和m是数组的长度
{
    int i = 0, j = 0, k = 0;

    // 当两个数组都有元素时

    while(i<n && j<m) 
    {
        if(arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    // 当第一个数组还有元素时
    while(i < n)
        arr3[k++] = arr1[i++];

    // 当第二个数组还有元素时
    while(j < m)
        arr3[k++] = arr2[j++];
}
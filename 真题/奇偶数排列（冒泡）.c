#include <stdio.h> // 引入标准输入输出库

int main() {
    int n, i, j, temp;
    int arr[100], odd[100], even[100]; // 假设输入的整数不超过100个
    int odd_count = 0, even_count = 0;

    printf("请输入整数的个数：\n");
    scanf("%d", &n); // 读取整数的个数

    printf("请输入这些整数：\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  //!用scanf()函数读取整数，并放入到数组arr中
        if(arr[i] % 2 == 0) { // 如果是偶数
            even[even_count++] = arr[i]; // !添加到偶数数组
        } else { // 如果是奇数
            odd[odd_count++] = arr[i]; // !添加到奇数数组
        }
        //!输入进数组的同时，记录了数组的长度count，后面就可以用count来打印了；
    }




    // 使用冒泡排序法对偶数数组进行从小到大排序
    for(i = 0; i < even_count - 1; i++)//!外层循环，i 表示已完成排序的个数 ，i从0开始
    //!因为每一轮会产生一个最大的，所以i++，全部排序都完成时候，就结束了
    {

        for(j = 0; j < even_count - 1 - i; j++) //!内层循环，j 一直前进到count - 1 - i

        //! 同时因为i遍历一次，就会有一个最大值产生，所以 j 这个值会减小
        {
            if(even[j] > even[j + 1])
             {
                temp = even[j];             //!内层循环，j 前进一位，内层就比较一次
                even[j] = even[j + 1];
                even[j + 1] = temp;
            }
        }
    }

    // 使用冒泡排序法对奇数数组进行从大到小排序
    for(i = 0; i < odd_count - 1; i++) {
        for(j = 0; j < odd_count - 1 - i; j++) {
            if(odd[j] < odd[j + 1]) {
                temp = odd[j];
                odd[j] = odd[j + 1];
                odd[j + 1] = temp;
            }
        }
    }

    printf("偶数从小到大排序的结果是：\n");
    for(i = 0; i < even_count; i++) {
        printf("%d ", even[i]); // 输出偶数排序后的结果
    }
    printf("\n");

    printf("奇数从大到小排序的结果是：\n");
    for(i = 0; i < odd_count; i++) {
        printf("%d ", odd[i]); // 输出奇数排序后的结果
    }

    return 0;
}

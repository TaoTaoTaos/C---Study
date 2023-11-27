#include<stdio.h>

double Jiecheng(int n)//!递归求阶乘 ，传入一个n ，一直乘n-1，直到 n == 0
{
    if(n==0)
        return 1;
    else
        return n * Jiecheng(n-1);
}

int main()
{
    int n;
    double res=1.0;
    printf("请输入n，计算e的前n项展开值");
    scanf("%d",&n);

    for (int i = n; i > 0; i--){
        double temp=Jiecheng(i);
        res += 1/temp;
        printf ("%f\n",res);
    }
    printf ("%f\n",res);
    return 0;
}

#include <stdio.h>

/*水仙花数字.打 印 “水仙花数”。所谓水仙花数,是指这样一个 3位 数,其 个、十、百位数字的
立方和等于该数本身,例如:153=1^3+5^3+3^3,
因 此 153是 一个水仙花数。下述程序用于打印输出所有水仙花数*/

int main(){

for (int i=0;i<=9;++i)
{
    for (int j=0;j<=9;++j){
        for(int k=0;k<=9;++k){
            int temp;
            temp=100*i+10*j+k;

if(i*i*i+j*j*j+k*k*k==temp)
printf("%d\n", temp);

        }
    }
}


return 0;

}


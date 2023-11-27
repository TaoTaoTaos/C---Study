#include <stdio.h>
int Jiecheng(n);
int main(void) {

int n;
n=10;
int result = 0;
int temp=0;
for (int i = n; i > 0; i--){

   
    temp=Jiecheng(i);
    result += temp;

}
printf("%d\n", result);

return 0;
}


int Jiecheng(int n){

if (n == 0)
return 1;
else

return n * Jiecheng(n-1);  

}
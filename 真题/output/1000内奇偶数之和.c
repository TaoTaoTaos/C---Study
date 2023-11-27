#include <stdio.h>

int main() {
int j,k;
for (int i = 1000; i >0 ; i--) {

if (i%2==0)
{
    j+=i;
}

else
{
     k+=i;
}

}
printf("%d\n",k);
printf("%d\n",j);
return 0;

}
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 1, j = 10, value;
    value = --i + j++;

    //上面语句相当于
    // i = i - 1;
    // value = i + j;
    // j = j + 1;

    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("value = %d\n", value);

    exit(0);
}
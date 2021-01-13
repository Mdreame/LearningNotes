#include <stdio.h>
#include <stdlib.h>

//斐波那契数列
void fibonacci(void){

    int i,j,len,tmp;
    int fib[10] = {1, 1};

	len = sizeof(fib) / sizeof(fib[0]);	//数组长度

    for(i = 2; i < len; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for(i = 0; i < len; i++)
        printf("%d ", fib[i]);
	printf("\n");

	//逆序处理
	i = 0;
	j = len - 1;
	while(i < j){
		tmp = fib[i];
		fib[i] = fib[j];
		fib[j] = tmp;

		i++;
		j--;
	}

	for(i = 0; i < len; i++)
		printf("%d ", fib[i]);
    return;
}

int main(){
	
	fibonacci();

	exit(0);
}

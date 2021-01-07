#include <stdio.h>
#include <stdlib.h>

#define N 3

int main(){
	int i;
//	char str[N] = {'a','b','c'};	//单个字符初始化
	char str[N] = "abc";	//字符串常量初始化
		
	for(i = 0; i < N; i++)
		printf("%c ", str[i]);

	printf("\n");

	exit(0);
}

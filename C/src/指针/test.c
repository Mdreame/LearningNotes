#include <stdio.h>
#include <stdlib.h>

int main(){
	int i = 1;
	int *p = &i;

	printf("i = %d\n", i);
	printf("&i = %d\n", &i);
	printf("p = %d\n", p);
	printf("&p = %d\n", &p);
	printf("*p = %d\n", *p);
	exit(0);
}

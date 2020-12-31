#include <stdio.h>
#include <stdlib.h>

#define LEFT 1
#define RIGHT 100

int main(){
	int i;
	int sum = 0;

	i = LEFT;
/*
	while(i <= RIGHT){
		sum += i;
		i++;
	}
*/
#if 0
	do{
		sum += i;
		i++;
	}while(i<101);
#endif

loop:
	sum += i;
	i++;

	if(i <= RIGHT)
		goto loop;
	printf("sum = %d\n", sum);

	exit(0);
}

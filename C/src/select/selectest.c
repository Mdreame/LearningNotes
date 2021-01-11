#include <stdio.h>
#include <stdlib.h>

#define INVESTMENT 100
#define RATE_A 0.1
#define RATE_B 0.05

int main(){
	int i;
	float sum_a, sum_b = INVESTMENT;
	
	do{
	sum_a += INVESTMENT * RATE_A;
	sum_b *=  RATE_B + 1;
	i++;
	}while(sum_a <= sum_b);

	printf("sum_a = %f, sum_b = %f, i = %d\n", sum_a, sum_b, i);
	exit(0);
}

#include <stdio.h>
#include <stdlib.h>

#define WATER_WEIGHT 3.0e-23
#define KQ 			 950

static void water(void){
	float num,sum;
	
	printf("please input a number for water:\n");

	scanf("%f", &num);
	sum = KQ * num / WATER_WEIGHT;
	printf("sum = %f", sum);

}

int main(){

	water();

	exit(0);
}

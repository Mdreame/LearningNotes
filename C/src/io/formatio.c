#include <stdio.h>
#include <stdlib.h>

#define STRSIZE 32
int main(){
	float f = 123.46781;
	char str[STRSIZE] = "helloworld";
	double dou = 123.321;

	printf("%f\n", f);
	printf("%lf\n", dou);
	printf("%10.4f\n", f);
	printf("%5s\n", str);	
	printf("%20.5s\n", str);
}



#include <stdio.h>
#include <stdlib.h>

//N must greater than 2
#define N	5

int print_starts(){
	int mid_num = 2 * N - 1;
	for(int i = 1; i <= N; i++){
		for(int space_num = 0; space_num < N - i; space_num++){
			printf(" ");
		}
		for(int starts_num = 1; starts_num < (i * 2); starts_num++){
			printf("*");
		}
		printf("\n");
	}

}

int main(){
	print_starts();	

	exit(0);
}

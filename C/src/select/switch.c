#include <stdio.h>
#include <stdlib.h>

int main(){
	int score;

	printf("please input score:\n");
	scanf("%d", &score);

	switch(score/10){
		case 9:
			puts("A");
			break;
		case 8:
			puts("B");
			break;
		case 7:
			puts("C");
			break;
		case 6:
			puts("D");
			break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
			puts("E");
			break;
		case 0:
			puts("0");
			break;
		default:
			fprintf(stderr,"Input Error!\n");

	}
	exit(0);
}

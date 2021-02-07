#include <stdio.h>
#include <stdlib.h>

int main(){

//	int i;			
	int a[3] = {1, 2, 3};
	int y;
	int *p = &a[1];

#if 0
	for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
		printf("%d\n", a[i]);
	printf("\n");
#endif
	
	y = (*--p)++;
	printf("y = %d\n", y);
	printf("a[0] = %d\n", a[0]);

	exit(0);
}

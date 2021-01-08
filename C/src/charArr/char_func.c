#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 4 
int main(){

	char str[STRSIZE] = "ab";

	
	strncpy(str, "abcdefg", STRSIZE);
	str[STRSIZE-1] = '\0';
	puts(str);
	printf("%d\n",strlen(str));		
	printf("%d\n", sizeof(str));

	exit(0);
}

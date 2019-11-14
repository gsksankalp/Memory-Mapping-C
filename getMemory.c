#include <stdio.h>
#include <stdlib.h>

int main() 
{
	for (int i = 0; i < 5; i++) {
		char *ptr = malloc(500);	
/*		char *ptr = malloc(50000000);*/
		printf("Got memory! ()Address = %p)\n", ptr);
	}
	return 0;
}

/*> clang getMemory.c */
/*> strace ./a.out */

#include <stdio.h>
#include <unistd.h>

int main() 
{
	void *first = sbrk(0); /* Tell me where the break is? */
	void *second = sbrk(4096); /* Move the program break up by 4096 and tell me where brk used to be? */
	void *third = sbrk(0);
	
	printf("First: %p\n", first);
	printf("Second: %p\n", second);
	printf("Third: %p\n", third);
	
	return 0;
}

/* > clang brkExample.c */
/* > ./a.out */

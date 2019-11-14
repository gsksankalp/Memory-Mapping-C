#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <ctype.h>
#include <stdint.h>


#define PAGESIZE 4096

int main() 
{
	/* uint8_t: shorthand for a type of unsigned integer of length 8 bits */
	
/*	uint8_t* first = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);*/
	
	uint8_t* first = mmap((void *)0xFEEDBEEF, 4*PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	
	uint8_t* second = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	
	printf("First: %p\n", first);
	printf("Second: %p\n", second);
	
	return 0;
}

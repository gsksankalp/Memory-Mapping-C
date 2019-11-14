#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <ctype.h>


int main (int argc, char *argv[])
{
	int fd = open("test.txt", O_RDWR, S_IRUSR | S_IWUSR); /* fd = file descriptor */
	struct stat sb;
	
	if (fstat(fd, &sb) == -1) {
		perror("couldn't get file size\n");
	}
	printf("file size is %ld\n", sb.st_size);
	
	char *file_in_memory = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	printf("Printing file, as an array of characters...\n\n");
	for (int i = 0; i < sb.st_size; i++) {
		if ((i % 2) == 0) {
			file_in_memory[i] = toupper(file_in_memory[i]);
		}
		printf("%c", file_in_memory[i]);
	}
	printf("\n");
	
	munmap(file_in_memory, sb.st_size);
	close(fd);
	
	return 0;
}

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
	int fd = open(argv[1], O_RDONLY);
	struct stat sb;
	
	if (fstat(fd, &sb) == -1) {
		perror("couldn't get file size\n");
	}
	printf("file size is %ld\n", sb.st_size);
	
	char *file_in_memory = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	
	srand(45);
	
	for (int i = 0; i < 5000; i++) {
		int index = rand() % sb.st_size; /* get a random byte */
		printf("%c", file_in_memory[index]);
	}
	
	close(fd);
	
	return 0;
}
}
/* gcc speedTestUsingMMAP.c -o m1 */
/* time ./m1 random.txt > /dev/null */

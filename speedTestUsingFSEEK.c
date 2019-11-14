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
	FILE *fp = fopen(argv[1], "r");
	struct stat sb;
	
	if (stat(argv[1], &sb) == -1) {
		perror("couldn't get file size.\n");
	}
	
	srand(45);
	
	for (int i = 0; i < 5000; i++) {
		int index = rand() % sb.st_size;
		fseek(fp, index, SEEK_SET);
		printf("%c", fgetc(fp));
	}
	
	fclose(fp);
	return 0;
}
/* gcc speedTestUsingFSEEK.c -o m2 */
/* time ./m2 random.txt > /dev/null */

#include <stdio.h>
#include <stdlib.h> /* exit */
#include <sys/types.h> /*fstat stat lstat*/
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h> 	/*fstatat */
#include <sys/stat.h>
#define MAXLEN 1
void readAndPrintBinaryFile(const char* file);
void statOfFile(const char* file) ;
int main(int argc, char **argv) {
	if (argc > 1) {
		readAndPrintBinaryFile(argv[1]);
		statOfFile(argv[1]);
	}

	return 0;
}


void readAndPrintBinaryFile(const char* file) {

	FILE *infile = fopen(file, "rb");
	if ( infile == NULL ) {
		printf("Fail to open file!\n");
		return;
	}
	int rc;
	unsigned char buf[MAXLEN];
	while ( (rc = fread(buf, sizeof(unsigned char), MAXLEN, infile)) != 0 )
	{
		printf("%x ", buf[0]);
	}
	printf("\n EOF \n");
	fclose(infile);
}
void statOfFile(const char* file) {
	struct stat buf;
	int fd;
	fd = open(file, O_RDONLY);
	fstat(fd, &buf);
	printf("%s file size %lld\n ", file, buf.st_size);
}


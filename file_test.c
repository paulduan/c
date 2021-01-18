#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1
void readAndPrintBinaryFile(const char* file);
int main(int argc, char **argv) {
	readAndPrintBinaryFile(argv[1]);
	return 0;
}


void readAndPrintBinaryFile(const char* file) {

	FILE *infile = fopen(file, "rb");
	if ( infile == NULL ) {
		printf("Fail to open file!\n");
		exit(0);  //退出程序（结束程序）
	}
	int rc;
	unsigned char buf[MAXLEN];
	while ( (rc = fread(buf, sizeof(unsigned char), MAXLEN, infile)) != 0 )
	{
		printf("%x ", buf[0]);
	}
	fclose(infile);
}
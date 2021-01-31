#include <stdio.h>
void testFunc(void) {
	printf("File = %s\nLine = %d\nFunc=%s\nDate=%s\nTime=%s\n",
	       __FILE__, __LINE__, __FUNCTION__, __DATE__, __TIME__);
#if defined(__linux__)
	printf("linux os");
#elif defined(__sun)
	printf("mac os");
#endif
}



int main(int argc, char **argv) {
	testFunc();
}
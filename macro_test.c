#include <stdio.h>
void testFunc(void) {
	printf("File = %s\nLine = %d\nFunc=%s\nDate=%s\nTime=%s\n",
	       __FILE__, __LINE__, __FUNCTION__, __DATE__, __TIME__);
}
void osMacro(void) {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	//define something for Windows (32-bit and 64-bit, this part is common)
#ifdef _WIN64
	//define something for Windows (64-bit only)
#else
	//define something for Windows (32-bit only)
#endif
#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
	// iOS Simulator
#elif TARGET_OS_IPHONE
	// iOS device
#elif TARGET_OS_MAC
	// Other kinds of Mac OS
	printf("mac os\n");
#else
#   error "Unknown Apple platform"
#endif
#elif __linux__
	// linux
	printf("linux os\n");
#elif __unix__ // all unices not caught above
	// Unix
#elif defined(_POSIX_VERSION)
	// POSIX
#else
#   error "Unknown compiler"
#endif
}


int main(int argc, char **argv) {
	testFunc();
	osMacro();
}
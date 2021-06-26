#include <unistd.h>
#include <string.h>

int printf(const char* format, ...) {
    write(STDOUT_FILENO, "my printf\n", 10);
    write(STDOUT_FILENO, format, strlen(format));
    return 0;
}
// main.c
#include <stdio.h>

int main() {
    printf("hello\n");
    return 0;
}


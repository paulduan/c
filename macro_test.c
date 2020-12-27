#include <stdio.h>
void testFunc(void){
    printf("File = %s\nLine = %d\nFunc=%s\nDate=%s\nTime=%s\n", 
        __FILE__, __LINE__, __FUNCTION__, __DATE__, __TIME__);
}



int main(int argc, char **argv) {
}
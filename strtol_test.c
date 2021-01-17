#include <stdio.h>
#include <stdlib.h>
void strToXX();
int main(int argc, char *argv[]) {
	strToXX();
	return 0;
}
//1.不仅可以识别十进制整数，还可以识别其它进制的整数，取决于base参数，比如strtol("0XDEADbeE~~", NULL, 16)返回0xdeadbee的值，strtol("0777~~", NULL, 8)返回0777的值。
//2.endptr是一个传出参数，函数返回时指向后面未被识别的第一个字符。例如char *pos; strtol("123abc", &pos, 10);，strtol返回123，pos指向字符串中的字母a。如果字符串开头没有可识别的整数，例如char *pos; strtol("ABCabc", &pos, 10);，则strtol返回0，pos指向字符串开头，可以据此判断这种出错的情况，而这是atoi处理不了的。
//3.如果字符串中的整数值超出long int的表示范围（上溢或下溢），则strtol返回它所能表示的最大（或最小）整数，并设置errno为ERANGE，例如strtol("0XDEADbeef~~", NULL, 16)返回0x7fffffff并设置errno为ERANGE
void strToXX()
{
	char *string, *stopstring;
	double x;
	int base;
	long l;
	unsigned long ul;
	string = "3.1415926 This stopped it";
	x = strtod(string, &stopstring);
	printf("string = %s\n", string);
	printf("strtod = %f\n", x);
	printf("Stopped scan at: %s\n", stopstring);
	string = "-1011 This stopped it";
	l = strtol(string, &stopstring, 10);
	printf("string = %s\n", string);
	printf("strtol = %ld\n", l);
	printf("Stopped scan at: %s\n", stopstring);
	string = "10110134932";
	printf("string = %s\n", string);
	/*Convertstringusingbase2,4,and8:*/
	for (base = 2; base <= 8; base *= 2)
	{
		/*Convertthestring:*/
		ul = strtoul(string, &stopstring, base);
		printf("strtol = %ld(base %d)\n", ul, base);
		printf("Stopped scan at: %s\n", stopstring);
	}
}
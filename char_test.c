#include <stdio.h>
#include <wchar.h>
#include <locale.h>
void printUnicode();
int main(int argc, char **argv) {
	//0 ~ 2^8-1
	unsigned char a = 'a';
	//-2^7 ~ 2^7-1
	char b = 'b';
	printf("%d, %c\n", a, a);
	printf("%d, %c\n", b, b);
	printUnicode();
	return 0;
}

void printUnicode(){
	char charStr[]={ 0xe4,0xb8,0xad,0xe6,0x96,0x87,0x00};
	printf("%s\n", charStr);  // 这里要用 L 和 l
    wchar_t str[] = L"中文";  // 使用 wchar_t 定义 Unicode 编码的字符类型，L 表示每个字符为两个字节
    setlocale(LC_ALL, "zh_CN.UTF-8");  // 设置语言环境为简体中文
    wchar_t c = L'中';
    wprintf(L"%lc\n", str[0]);  // 这里要用 L 和 l
    wprintf(L"%lc\n", c);  // 这里要用 L 和 l
    printf("end\n");
}
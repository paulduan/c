#include <stdio.h>

/*
1.全局变量
全局变量定义在函数体外部，在全局数据区分配存储空间，且编译器会自动对其初始化。

普通全局变量对整个工程可见，其他文件可以使用extern外部声明后直接使用。也就是说其他文件不能再定义一个与其相同名字的变量了（否则编译器会认为它们是同一个变量）。

静态全局变量仅对当前文件可见，其他文件不可访问，其他文件可以定义与其同名的变量，两者互不影响。
在定义不需要与其他文件共享的全局变量时，加上static关键字能够有效地降低程序模块之间的耦合，避免不同文件同名变量的冲突，且不会误使用。
*/
void fn(void)
{
	int n = 10;

	printf("n=%d\n", n);
	n++;
	printf("n++=%d\n", n);
}

void fn_static(void)
{
	/*
	2.局部变量
	静态局部变量使用static修饰符定义，即使在声明时未赋初值，编译器也会把它初始化为0。且静态局部变量存储于进程的全局数据区，即使函数返回，它的值也会保持不变。
	变量在全局数据区分配内存空间；编译器自动对其初始化
	其作用域为局部作用域，当定义它的函数结束时，其作用域随之结束
	*/
	static int n = 10;

	printf("static n=%d\n", n);
	n++;
	printf("n++=%d\n", n);
}
/*
3.函数
函数的使用方式与全局变量类似，在函数的返回类型前加上static，就是静态函数。其特性如下：

静态函数只能在声明它的文件中可见，其他文件不能引用该函数
不同的文件可以使用相同名字的静态函数，互不影响
*/
int main(int argc, char **argv) {
	fn();
	printf("--------------------\n");
	fn_static();
	printf("--------------------\n");
	fn();
	printf("--------------------\n");
	fn_static();

	return 0;
}



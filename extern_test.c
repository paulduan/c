#include <stdio.h>
#define EXTERN
#include "header.h"
int x=1;
int y=2;
/*
定义和声明
1.<strong>Declaration</strong> of a variable or function simply declares that the variable or function exists somewhere in the program, but the memory is not allocated for them. The declaration of a variable or function serves an important role–it tells the program what its type is going to be. In case of function declarations, it also tells the program the arguments, their data types, the order of those arguments, and the return type of the function. So that’s all about the declaration.
2.Coming to the <strong>definition</strong>, when we define a variable or function, in addition to everything that a declaration does, it also allocates memory for that variable or function. Therefore, we can think of definition as a superset of the declaration (or declaration as a subset of definition).
*/

/*
0.the extern keyword extends the visibility of the C variables and C functions
1.A declaration can be done any number of times but definition only once.
2.the extern keyword is used to extend the visibility of variables/functions.
3.Since functions are visible throughout the program by default, the use of extern is not needed in function declarations or definitions. Its use is implicit.
4.When extern is used with a variable, it’s only declared, not defined.
5.As an exception, when an extern variable is declared with initialization, it is taken as the definition of the variable as well. eg. extern int var = 0
 */
/*
用法说明
1.extern char *a;// conflicting types for ‘a’ 指向类型T的指针并不等价于类型T的数组,例子分析如下，如果a[] = "abcd",则外部变量a=0x61626364 (abcd的ASCII码值)，*a显然没有意义 显然a指向的空间（0x61626364）没有意义，易出现非法内存访问。
2.头文件中只应该包含变量和函数的声明而不是定义，否则重复引用同一个头文件会掉在重复定义的错误，即使使用条件编译也只是把重复定义错误延迟到了链接阶段因为宏名有效范围仅限于本c源文件
3.经常的用法是，在一个.c文件定义全局变量，在.h文件中用extern声明这个全局变量，这样别的程序就用通过引用.h文件使用这个全局变量了
 * */
extern char a[];
int main(int argc, char **argv) {
	int r = add();
	extern int x; //只是声明，不是定义
	printf("x is %d, x+y=%d\n",x,add());
	char c[]="abcd";
	printf("c %s\n",c);
}


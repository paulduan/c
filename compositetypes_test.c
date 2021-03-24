#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
//void enumer();
void structer();
//void unioner();
typedef struct redisObject {
	unsigned type: 4;
	unsigned encoding: 4;
	unsigned lru: 24;
	/* LRU time (relative to global lru_clock) or LFU data (least significant 8 bits frequency and most significant 16 bits access time). */
	int refcount; //4
	void *ptr; //8
} robj;
unsigned a;
int main(int argc, char **argv) {
	printf("size of unsigned %lu\n", sizeof(a) );
	printf("size of robj %lu\n", sizeof(robj) );
	printf("size of void * %lu\n", sizeof(void *) );
	printf("size of int %lu\n", sizeof(int) );

	//enumer();
	structer();
	//unioner();
}
/*Flexible Array Member(FAM) is a feature introduced in the C99 standard of the C programming language.

For the structures in C programming language from C99 standard onwards, we can declare an array without a dimension and whose size is flexible in nature.
Such an array inside the structure should preferably be declared as the last member of structure and its size is variable(can be changed be at runtime).
The structure must contain at least one more named member in addition to the flexible array member.
 the char type FAM member  has character size ，Does not contain ‘\0’
*/
struct sdshdr16 {
	uint64_t len; /* used */
	uint64_t alloc; /* excluding the header and null terminator */
	unsigned char flags; /* 3 lsb of type, 5 unused bits */
	char buf[];
};
struct __attribute__ ((__packed__)) sdshdr16packed {
	uint64_t len; /* used */
	uint64_t alloc; /* excluding the header and null terminator */
	unsigned char flags; /* 3 lsb of type, 5 unused bits */
	char buf[];
};

void structer() {
	printf("size of sdshdr16 %lu\n", sizeof(struct sdshdr16) );
	printf("size of sdshdr16 packed %lu\n", sizeof(struct sdshdr16packed) );
}
/*
结构体对齐，默认对齐原则：
1.数据类型对齐值：
char型数据自身对齐值为1
short为2，int、float为4，double为8(windows)
解释：
char变量只要有一个空余的字节即可存放
short要求首地址能被2整除
int、float、double同理
2.结构体的对齐值：
其成员中自身对齐值最大的那个值。
解释：
结构体最终对齐按照数据成员中最长的类型的整数倍

指定对齐原则：
使用#pragma pack改变默认对其原则
格式：
#pragma pack (value)时的指定对齐值value。
结构体最终对齐按照指定对齐值的整数倍
注意：
1.value只能是：1 2 4 8等
2.指定对齐值与数据类型对齐值相比取较小值
如：如果指定对齐值：
设为1：则short、int、float等均为1
设为2：则char仍为1，short为2，int 变为2
*/
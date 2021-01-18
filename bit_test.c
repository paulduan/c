#include <stdio.h>
#include<stdlib.h> //__WORDSIZE
void test64or32();
void testBigOrLittleEnd();
int isLittleEndian(void);
int isLittleEndian02(void);
int isLittleEndian03(void);
void isLittleEndian04(void);
void move(void);
//对于 跨越多字节的 程序对象 我们必须建立两个规则，1这个对象的地址是什么(使用字节中的最小字节) 2多字节如何排序(大端or小端)
//intel兼容机都是小端
//最小字节存高位的是大端，最小字节存低位的是小端
//栈内存从高地址向低地址分配，每次分配一段，比如声明一个int i =0x12345678 就会 分配 f,e,d,c 4个字节，78放在c,56放在d,&i==c

int main(int argc, char **argv) {
    test64or32();
    testBigOrLittleEnd();
    isLittleEndian04();
    move();
}
void move(void) {
    int lval = 0xFEDCBA92 << 32;
    printf("%x\n", lval);
    //算数右移，左边补最高位
    //逻辑右移，左边补0
}
void test64or32() {

    //method 1
    void*number = 0;
    printf("%lu \n", sizeof(&number));

    //method 2
    printf("size:%d \n", __WORDSIZE);

    //method 3
#ifdef __x86_64__
    printf("64bits machine \n");
#elif __i386__
    printf("32 bits machine \n");
#endif
}
int isLittleEndian(void)
{
    int i = 0x12345678;
    char *c = (char *)&i;
    printf("c0 %p \n", c);  //0x7ffee926a84c
    printf("c1 %p \n", c + 1); //0x7ffee926a84d
    printf("c2 %p \n", c + 2); //0x7ffee926a84e
    printf("c3 %p \n", c + 3); //0x7ffee926a84f
    return ((c[0] == 0x78) && (c[1] == 0x56) && (c[2] == 0x34) && (c[3] == 0x12));
}
void isLittleEndian04(void)
{
    int i = 0x12345678;
    int i2 = 0x78abcdef;
    char *c = (char *)&i;
    char *c2 = (char *)&i2;
    printf("c0 %p,%x \n", c, c[0]);
    printf("c1 %p,%x  \n", c + 1, c[1]);
    printf("c2 %p,%x  \n", c + 2, c[2]);
    printf("c3 %p,%x  \n", c + 3, c[3]);
    printf("c20 %p,%x \n", c2, c2[0]);
    printf("c21 %p,%x  \n", c2 + 1, c2[1]);
    printf("c22 %p,%x  \n", c2 + 2, c2[2]);
    printf("c23 %p,%x  \n", c2 + 3, c2[3]);
    int b[2] = {0x12345678, 0x89abcdef};
    /* char *c = (char *)&b;
     printf("c0 %p,%x \n", c,c[0]);
     printf("c1 %p,%x  \n", c+1,c[1]);
     printf("c2 %p,%x  \n", c+2,c[2]);
     printf("c3 %p,%x  \n", c+3,c[3]);
     printf("c4 %p,%x  \n", c+4,c[4]);
     printf("c5 %p,%x  \n", c+5,c[5]);
     printf("c6 %p,%x  \n", c+6,c[6]);
     printf("c7 %p,%x  \n", c+7,c[7]);
     */
}

// 1: Little Endian; 0: Big Endian.
int isLittleEndian02(void)
{
    typedef union {
        int i;
        char c;
    } myUnion;
    myUnion u;
    u.i = 1;
    return (u.i == u.c);
}
int isLittleEndian03(void)
{
    int a = 1;
    char * p = (char *)&a;

    if (1 == *p)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void testBigOrLittleEnd() {
    if (isLittleEndian() == 1)
    {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
    if (isLittleEndian02() == 1)
    {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
    if (isLittleEndian03() == 1)
    {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
}
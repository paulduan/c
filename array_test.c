#include <stdio.h>
#include <stdlib.h> //srand  rand
#include <time.h> //time


typedef struct Book
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book;
void arrayName();
void printArray(double *param1,double param2[10],double param[],int len);
int * returnArray();
void print2Array(double param1[][2][3]);
int main(int argc, char **argv) {
	Book a[]={{"C 语言", "RUNOOB", "编程语言", 12},{"java 语言", "hi", "编程语言", 123}};
  char arr6[] = "abcdef";
  char arr5[3] = {'a', 98, 'c'};
  printf("arr6 is %s len is %lu \n", arr6,sizeof(arr6));
  printf("arr5 is %s len is %lu \n", arr5,sizeof(arr5));

	int len = sizeof(a) / sizeof(a[0]);
	printf("len of array:%d\n", len);
	arrayName();
	double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
  double balance2[1][2][3] = {{{1.0,2.0,3.0},{1.1,1.2,1.3}}};//1层 两行 3列
  print2Array(balance2);
	printArray(balance,balance,balance,5);
	int *arr = returnArray();
	for ( int i = 0; i < 10; i++ )
    {
       printf( "*(arr + %d) : %d\n", i, *(arr + i));
    }
    return 0;
}

void arrayName(){
  double balance[10];
  double balance2[3][4];
	double *p = balance; //类型是 double (*)
  double (*p1)[10] = &balance; //类型是 double (*)[10],没办法进行+1操作
  double (*p2)[3][4] = &balance2; //类型是 double (*)[3][4],没办法进行+1操作
  double (*p3)[4] = &balance2[0]; //p3+1
  double *b=*(p3+1);
	//balance 是一个指向 &balance[0] 的指针，即数组 balance 的第一个元素的地址。因此，下面的程序片段把 p 赋值为 balance 的第一个元素的地址
	/* 输出数组中每个元素的值 */
   printf( "使用指针的数组值\n");
   for ( int i = 0; i < 5; i++ )
   {
       printf("*(p + %d) : %f\n",  i, *(p + i));
   }
 
   //使用数组名作为常量指针是合法的，反之亦然。因此，*(balance + 4) 是一种访问 balance[4] 数据的合法方式
   printf( "使用 balance 作为地址的数组值\n");
   for ( int i = 0; i < 5; i++ )
   {
       printf("*(balance + %d) : %f\n",  i, *(balance + i) );
   }
   printf("指针：%p,%p, %p\n",p,&balance,&(balance[0]) );
 
}
void print2Array(double param1[][2][3]){
}

//如果您想要在函数中传递一个一维数组作为参数，您必须以下面三种方式来声明函数形式参数，
//这三种声明方式的结果是一样的，因为每种方式都会告诉编译器将要接收一个整型指针
void printArray(double *param1,double param2[10],double param3[],int len){
	//int len = sizeof(param2) / sizeof(param2); 不能计算出长度，因为param2就是一个指针的长度
	for(int loop = 0; loop < len; loop++)
      	printf("param1 %lf\n", param1[loop]);
    for(int loop = 0; loop < len; loop++)
      	printf("param2 %lf\n", param2[loop]);
    for(int loop = 0; loop < len; loop++)
      	printf("param3:%lf\n", param3[loop]);
}


//C 语言不允许返回一个完整的数组作为函数的参数。但是，您可以通过指定不带索引的数组名来返回一个指向数组的指针。
//另外，C 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
int * returnArray(){
  static int  r[10];
  int i;
 
  /* 设置种子 */
  srand( (unsigned)time( NULL ) );//是初始化随机函数种子 
  for ( i = 0; i < 10; ++i)
  {
     r[i] = rand();//如果不使用srand，用rand（）产生的随机数，在多次运行，结果是一样的。
     printf( "r[%d] = %d\n", i, r[i]);
 
  }
 
  return r;
}
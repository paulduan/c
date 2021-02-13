#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
void integer();
void floating();
int main(int argc, char **argv) {
	integer();
	floating();
}


/*Integer Types

+----------------------------------------------------------------------------------------------------------+
|  Type            Storage size                        Value range                                         |
|                                                                                                          |
|  char            1 byte                              -128 to 127 or 0 to 255                             |
|                                                                                                          |
|  unsigned char   1 byte                              0 to 255                                            |
|                                                                                                          |
|  signed char     1 byte                              -128 to 127                                         |
|                                                                                                          |
|  int             2 or 4 bytes                        -32,768 to 32,767 or -2,147,483,648 to 2,147,483,647|
|                                                                                                          |
|  unsigned int    2 or 4 bytes                        0 to 65,535 or 0 to 4,294,967,295                   |
|                                                                                                          |
|  short           2 bytes                             -32,768 to 32,767                                   |
|                                                                                                          |
|  unsigned short  2 bytes                             0 to 65,535                                         |
|                                                                                                          |
|  long            8 bytes or (4bytes for 32 bit OS)   -9223372036854775808 to 9223372036854775807         |
|                                                                                                          |
|  unsigned long   8 bytes                             0 to 18446744073709551615                           |
+----------------------------------------------------------------------------------------------------------+
*/
void integer() {
	printf("Storage size for char : %lu \n", sizeof(char));
	printf("CHAR_BIT    :   %d\n", CHAR_BIT);
	printf("CHAR_MAX    :   %d\n", CHAR_MAX);
	printf("CHAR_MIN    :   %d\n", CHAR_MIN);
	printf("Storage size for int : %lu \n", sizeof(int));
	printf("INT_MAX     :   %d\n", INT_MAX);
	printf("INT_MIN     :   %d\n", INT_MIN);
	printf("Storage size for long : %lu \n", sizeof(long));
	printf("Storage size for long long : %lu \n", sizeof(long long));

	printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
	printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
	printf("Storage size for short : %lu \n", sizeof(short));
	printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
	printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
	printf("SHRT_MAX    :   %d\n", SHRT_MAX);
	printf("SHRT_MIN    :   %d\n", SHRT_MIN);
	printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
	printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
	printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
	printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);
}

/*Floating-Point Types
+---------------------------------------------------------------------------------+
| Type          Storage size          Value range              Precision          |
|                                                                                 |
| float         4 byte                1.2E-38 to 3.4E+38       6 decimal places   |
|                                                                                 |
| double        8 byte                2.3E-308 to 1.7E+308     15 decimal places  |
|                                                                                 |
| long double   10 byte               3.4E-4932 to 1.1E+4932   19 decimal places  |
+---------------------------------------------------------------------------------+
*/
void floating() {
	printf("Storage size for float : %lu \n", sizeof(float));
	printf("Storage size for double : %lu \n", sizeof(double));
	printf("Storage size for long double : %lu \n", sizeof(long double));
	printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
	printf("FLT_MIN     :   %g\n", (float) FLT_MIN);
	printf("-FLT_MAX    :   %g\n", (float) - FLT_MAX);
	printf("-FLT_MIN    :   %g\n", (float) - FLT_MIN);
	printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
	printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
	printf("-DBL_MAX     :  %g\n", (double) - DBL_MAX);
	printf("Precision value: %d\n", FLT_DIG );
}
/*The void Type
The void type specifies that no value is available. It is used in three kinds of situations −
Sr.No.	Types & Description
1		Function returns as void
		There are various functions in C which do not return any value or you can say they return void. A function with no return value has the return type as void. For example, void exit (int status);

2		Function arguments as void
		There are various functions in C which do not accept any parameter. A function with no parameter can accept a void. For example, int rand(void);

3		Pointers to void
		A pointer of type void * represents the address of an object, but not its type. For example, a memory allocation function void *malloc( size_t size ); returns a pointer to void which can be casted to any data type.
*/





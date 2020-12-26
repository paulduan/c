time:time_test.c
	gcc -E -o ./pre/time.i time_test.c
	gcc -S -o ./asm/time.s time_test.c
	gcc -o ./bin/time time_test.c

array:array_test.c
	gcc -E -o ./pre/array.i array_test.c
	gcc -S -o ./asm/array.s array_test.c
	gcc -o ./bin/array array_test.c
string:string_test.c
	gcc -E -o ./pre/string.i string_test.c
	gcc -S -o ./asm/string.s string_test.c
	gcc -o ./bin/string string_test.c

clean:
	rm -rf ./bin/ ./asm ./pre
	mkdir bin asm pre

.PHONY: clean

